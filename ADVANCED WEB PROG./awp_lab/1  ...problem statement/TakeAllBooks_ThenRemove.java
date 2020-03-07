
package practice;


import java.io.*;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;



/*Journals interface*/
interface Journals1 {

    void getJournals();
}

/* SubjectBooks Interface*/
interface SubjBooks1 {

    void getSubjBooks();
}


/* Book Class implementing the JOurnals and SubjBook Interface */
class Book1 implements Journals1, SubjBooks1 {

    ArrayList<String> booksList = new ArrayList<>();
    /* Arraylist containing all the books and journals data */
    ArrayList<String> studList = new ArrayList<>();
    /* Arraylist containing only student selected books data */
    boolean valueSet = false;

    /* booolean value for Thread methods */

 /* read the Journals data from the repsective file and feed the same data in the booksList ArrayList */
    @Override
    public void getJournals() {
        String filename = "filename with path";
        String line;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            while ((line = br.readLine()) != null) {
                booksList.add(line.trim());
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    /* read the SubjectBooks data from the repsective file and feed the same data in the booksList ArrayList */
    @Override
    public void getSubjBooks() {
        String filename = "filename with path";
        String line;
        try {
            BufferedReader br = new BufferedReader(new FileReader(filename));
            while ((line = br.readLine()) != null) {
                booksList.add(line.trim());
            }
        } catch (FileNotFoundException e) {
            System.out.println(e.getMessage());
        } catch (IOException ex) {
            System.out.println(ex.getMessage());
        }
    }

    /* getBooks methods takes 3 books name form the student at a time  */
    synchronized void getBooks(int MAX_COUNT) {
        while (valueSet) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
        System.out.println("\n-------Enter Book name:-------");
        Scanner sc = new Scanner(System.in);
        int i = 0;
        while (i < MAX_COUNT) {
            studList.add(sc.nextLine());
            /* take 3 books */
            i++;
        }
        valueSet = true;
        notify();
    }

    /* Removes the students selected books from the main ArrayList (i.e. booksList) */
    synchronized void updateList() {
        while (!valueSet) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
        System.out.println("Books List Updated!!");
        studList.forEach(booksList::remove);
        /* another way of interating through the ArrayList 
		to reomve the elements from the another ArrayList */

		/* can use this way also to remove the elements from the ArrayList
        
            for(String book:studList){
                booksList.remove(new String(book));
            }
         */
        valueSet = false;
        notify();
    }

    /* Show the total no. of books to the Student before asking for selection */
    void showBooks() {
        for (String book : booksList) {
            System.out.println(book);
        }
    }

}

class Person1 {

    String name;
    int id;
    String email;
    String password;

    /*dont remove this constructor as Person is the concrete class 
    extended by the student class and librarian class, and as they donot have
    their own default constructor, this is necessary*/
	
    Person1() {
    }

    /* Initialize the student values */
    Person1(String name, int id, String email, String password) {
        this.name = name;
        this.id = id;
        this.email = email;
        this.password = password;
    }

    /* Initialize the librarian values */
    Person1(String name, int id, String email) {
        this.name = name;
        this.id = id;
        this.email = email;
    }

    /* returns the name */
    public String getname() {
        return this.name;
    }

    /* returns the id */
    public int getid() {
        return this.id;
    }

    /* returns the email */
    public String getemail() {
        return this.email;
    }
}

class Student1 extends Person1 implements Runnable {

    final int MAX_COUNT = 3; //max books a student can issue

    Book1 b;
    Thread t = new Thread(this, "Student"); //creates a student thread

    Student1(Book1 b) {
        this.b = b;
        t.start(); //starts a student thread
    }

    Student1(String name, int id, String email, String password) {
        super(name, id, email, password);
    }

    /* get student details */
    void getdetails() {
        System.out.println(getname());
        System.out.println(getid());
        System.out.println(getemail());
    }

    @Override
    public void run() {
        b.getBooks(this.MAX_COUNT);
        /* calling Book class getBooks method by the Student thread */
    }

    /* verify the student id and password */
    boolean verify(int id, String pass) {
        return (id == super.id) && (pass.equals(super.password));
    }

    /* Shows students details with the books selected by them */
    void showdetails(Student1 stud) {
        ArrayList<String> studList = b.studList;
        System.out.println("\nStudent details:");
        System.out.println("Name: " + stud.getname());
        System.out.println("Id: " + stud.getid());
        System.out.println("Email: " + stud.getemail());
        System.out.println("\nBooks Issued:");

        /* another way of traversing the Arraylist
        and print the elements accordingly,
        
        s represents the element of an ArrayList*/
        studList.forEach((s) -> {
            System.out.println(s);
        });
    }

}

class Librarian1 extends Person1 implements Runnable {

    int MAX_COUNT = 3;

    Book1 b;
    Thread t = new Thread(this, "Librarian");

    Librarian1(Book1 b) {
//        super("ABC",1107,"abc@gmail.com");
        this.b = b;
        t.start();
    }

    Librarian1(String name, int id, String email) {
        super(name, id, email);
    }

    @Override
    public void run() {
        b.updateList();
        /* Librarian thread calling the Updatelist method of Book class */
    }

    /* show librarian details who issued the books */
    void showdetails(Librarian1 l) {
        System.out.println("\nBooks issued by: " + l.getname());
    }
}

public class TakeAllBooks_ThenRemove {

    public static void main(String arg[]) {
        Scanner sc = new Scanner(System.in);
        int id;
        String pass;

        /* object creation to initialize the values */
        Student1 s = new Student1("Pooja", 101, "p@gmail.com", "abc123");
        Librarian1 l = new Librarian1("ABC", 1107, "abc@gmail.com");

        /* create a Book1 class object */
        Book1 b1 = new Book1();
        /* calling methods to ffed the ArrayList
        with the Journals and SubjectBooks data*/
        b1.getJournals();
        b1.getSubjBooks();

        /* Program execution begins */
        System.out.println("-------Welcome-------");
        System.out.println("Enter id:");
        id = sc.nextInt();
        System.out.println("Enter password:");
        pass = sc.next();

        /* validates the id and password */
        boolean status = s.verify(id, pass);
        if (status == true) {
            System.out.println("\n!!!Login Successful!!!\n");

            System.out.println("Books list: (Choose any 3)");
            /* Show books list to students to select any three */
            b1.showBooks();

            /* create objects using the one parameter constructor
            to start the thread*/
            Student1 s1 = new Student1(b1);
            Librarian1 l1 = new Librarian1(b1);

            /* wait until the threads execution completes */
            try {
                s1.t.join();
                l1.t.join();
            } catch (InterruptedException ex) {
                Logger.getLogger(TakeOne_RemoveOne_ThreeTimes.class.getName()).log(Level.SEVERE, null, ex);
            }
            /* this try-catch block is necessary,
            if you have some code which must execute 
            after the threads execution gets complete.*/
            
            /*
                If this block is not written then,
                the lines written below will get executed
                before threads execution gets complete.
            */
            
            System.out.println("-------------------------");

            /* Show students details with books name and
            librarian details who issued the books */
            s1.showdetails(s);
            l1.showdetails(l);
            System.out.println("\n-------------------------");
            System.out.println("Books Remaining");
            /* Showing the remianing books left in the ArrayList
            after removing student issued books */
            b1.showBooks();

        } else {
            System.out.println("Incorrect Credentials");
        }

    }

}
