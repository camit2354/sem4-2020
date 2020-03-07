
package practice;


import java.io.*;
import java.util.*;




/*
    In this program threads are working simultaneously.
    Student thread taking one Book name as input and notify the libraian thread,
    and Librarian thread wait untils the book is input by the student,
    then geting the notify() from the student thread
    removes the same from the ArrayList,
    till then the student thread waits.
*/

interface Journals{
    void getJournals();
}

interface SubjBooks{
    void getSubjBooks();
}

class Book implements Journals,SubjBooks{
    
    ArrayList<String> booksList =new ArrayList<>();
    ArrayList<String> studList=new ArrayList<>();
    boolean valueSet=false;
    Student s;
    Librarian l;
    String bookName;
    
    Book(Student s, Librarian l){
        this.s=s;
        this.l=l;
    }
    
    @Override
    public void getJournals(){
        String filename="filename with path";
        String line;
        try{
            BufferedReader br= new BufferedReader(new FileReader(filename));
            while((line=br.readLine())!=null){
                booksList.add(line.trim());
            }
        }catch(FileNotFoundException e){
            System.out.println(e.getMessage());
        } catch(IOException ex) {
             System.out.println(ex.getMessage());
        }      
    }
    
    @Override
    public void getSubjBooks(){
        String filename="filename with path";
        String line;
        try{
            BufferedReader br= new BufferedReader(new FileReader(filename));
            while((line=br.readLine())!=null){
                booksList.add(line.trim());
            }
        }catch(FileNotFoundException e){
            System.out.println(e.getMessage());
        } catch(IOException ex) {
             System.out.println(ex.getMessage());
        }
    }
            
    synchronized void getBooks(int MAX_COUNT){
        
        while(valueSet){
            try{
                wait();
            }catch(InterruptedException e){
                System.out.println("Interrupted");
            }
        }
        System.out.println("\n-------Enter Book name:-------");
        Scanner sc =new Scanner(System.in);
        this.bookName=sc.nextLine();
            studList.add(this.bookName);
        valueSet=true;
        notify();
    }
    
    synchronized void updateList(){
        while(!valueSet){
            try{
                wait();
            }catch(InterruptedException e){
                System.out.println("Interrupted");
            }
        }
        /* Message after removing each book!! */
        System.out.println("Books List Updated!!");
        booksList.remove(this.bookName);
        valueSet=false;
       notify();
    }
    
    void showBooks(){
        for(String book: booksList){
            System.out.println(book);
        }
    }
    
}


class Person{

    String name;
    int id;
    String email;
    String password;
    
    Person(){}
    
    Person(String name, int id, String email, String password){
        this.name=name;
        this.id=id;
        this.email=email;
        this.password=password;
    }
    
    Person(String name, int id, String email){
        this.name=name;
        this.id=id;
        this.email=email;
    }
    
    public String getname(){
        return this.name;
    }
    
    public int getid(){
        return this.id;
    }
    
    public String getemail(){
        return this.email;
    }
}

class Student extends Person implements Runnable{
    
    int MAX_COUNT=3;
    
    Book b;
    Thread t=new Thread(this,"Student");
    
      
    Student(Book b){
//        super("Pooja",101,"p@gmail.com","abc123");
        this.b = b;
        t.start();
    }
    
    Student(String name, int id, String email,String password) {
        super(name, id, email,password);
    }
    
    void getdetails(){
        System.out.println(getname());
        System.out.println(getid());
        System.out.println(getemail());        
    }
    
    @Override
    public void run(){
        /*
            Get one book at a time and 
            remove from ArrayList at the same time.
        */
        int i=0;
        while(i<MAX_COUNT){
            b.getBooks(this.MAX_COUNT);
            i++;
        }
    }

    boolean verify(int id, String pass){
       return (id==super.id) && (pass.equals(super.password));
    }
    
    void showdetails(Student stud){
        ArrayList<String> studList = b.studList;
        System.out.println("\nStudent details:");
        System.out.println("Name: "+stud.getname());
        System.out.println("Id: "+stud.getid());
        System.out.println("Email: "+stud.getemail());
        System.out.println("\nBooks Issued:");
        studList.forEach((s) -> {
            System.out.println(s);
        });
    }
    
}

class Librarian extends Person implements Runnable{
    
    int MAX_COUNT=3;
    
    Book b;
    Thread t=new Thread(this,"Librarian");
    
    Librarian(Book b){
//        super("ABC",1107,"abc@gmail.com");
        this.b = b;
        t.start();
    }
    
    Librarian(String name, int id, String email) {
        super(name, id, email);
    }
    
   
    @Override
    public void run(){
        /*
            Run method calling the updateList() method,
        everytime a student is issuing one books 
        */
        int i=0;
        while(i<MAX_COUNT){
            b.updateList();
            i++;
        }
    }

    void showdetails(Librarian l) {
        System.out.println("\nBooks issued by: "+l.getname());
    }
}


public class TakeOne_RemoveOne_ThreeTimes {
    public static void main(String arg[]){
        Scanner sc =new Scanner(System.in);
        int id;
        String pass;
        
        Student s=new Student("Pooja",101,"p@gmail.com","abc123");
        Librarian l=new Librarian("ABC",1107,"abc@gmail.com");
        Book b=new Book(s,l);
        b.getJournals();
        b.getSubjBooks();
        System.out.println("-------Welcome-------");
        System.out.println("Enter id:");
        id=sc.nextInt();
        System.out.println("Enter password:");
        pass=sc.next();
        
        boolean status=s.verify(id,pass);
        if(status==true){
            System.out.println("\n!!!Login Successful!!!\n");
            System.out.println("Books list: (Choose any 3)");
        b.showBooks();
        
        Student s1=new Student(b);
        Librarian l1=new Librarian(b);
        
        
        try {
            s1.t.join();
             l1.t.join();
        } catch (InterruptedException ex) {
            System.out.println(ex.getMessage());
        }
       
        System.out.println("-------------------------");
        
        s1.showdetails(s);
        l1.showdetails(l);
        System.out.println("\n-------------------------");
        System.out.println("Books Remaining");
        b.showBooks();
        }else{
            System.out.println("Incorrect Credentials");
        }
        
        
        
    }
}
