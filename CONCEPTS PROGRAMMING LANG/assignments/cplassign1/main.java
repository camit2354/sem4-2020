import java.util.EventListener;
import java.util.Scanner;

class register
 {
  public String name;
  public String mobno;
  public String email;
  public String username;
  public String password;

  public register(String n,String m,String e,String u,String p)
  {
    name=n;
    mobno=m;
    email=e;
    username=u;
    password=p;
  }

}

class micro 
{   public String carname;
    public String carno;
    public String carcolor;
    public String carmodel;

  
}

class mini
{
 public String carname;
 public String carno;
 public String carcolor;
 public String carmodel;
 

}

class auto 
{
    public String carname;
    public String carno;
    public String carcolor;
    public String carmodel;
}

public class main 
{
      static int DistanceMultiplyer=1;
      static int VehicleMultiplyer=1;
      static int TotalFare=0;

     static void Initialize()
     {  register[] Ruser= new register[5] ;
         Ruser[0] = new register("aman","9999999999","aman@gmail.com","aman","9999");
         Ruser[1] = new register("amit","8888999999","amit@gmail.com","aman","8888");
         Ruser[2] = new register("amar","7777999999","amar@gmail.com","aman","7777");
         Ruser[3] = new register("raj","66666699999","raj@gmail.com","aman","6666");
         Ruser[4] = new register("jay","8989999999","jay@gmail.com","aman","8989");

        /* micro[] MicroCar=new micro[2];
         MicroCar[0] =new micro();
         MicroCar[1] =new micro();

         micro[] MiniCar=new mini[2];
         MiniCar[0] = new mini();
         MiniCar[1] = new mini();

         micro[] AutoCar=new auto[2];
         AutoCar[0] = new auto();
         AutoCar[0] = new auto(); */


    
     }

     static void Login()
     {  
           
      
      
      
      int done =0;
      int choice =0; Scanner ScannerObj = new Scanner(System.in);
      System.out.println("\n USERNAME:");
      String USERNAME = ScannerObj.nextLine();

      System.out.println("\n PASSWORD:");
      String PASSWORD = ScannerObj.nextLine();

      for (int i = 0; i < 5 && done ==0; i++) 
      {
       if(USERNAME.equals(Ruser[0].username)&&PASSWORD.equals(Ruser[0].password))
       {
         done=1;
       }
      }

      while(done!=1)
      {
        System.out.println("\n enter valid USERNAME and PASSWORD:\n");


        System.out.println("\n USERNAME:");
       USERNAME = ScannerObj.nextLine();

      System.out.println("\n PASSWORD:");
      PASSWORD = ScannerObj.nextLine();

      for (int i = 0; i < 5 && done ==0; i++) 
      {
       if(USERNAME.equals(Ruser[i].username)&&PASSWORD.equals(Ruser[i].password))
       {
         done=1;
       }
      }
      }

     
      System.out.println("  \n 1) CONTINUE  2)EXIT\n ");
      System.out.println("\n PLEASE ENTER YOUR CHOICE :");
      choice = ScannerObj.nextInt();
      if(choice==1)
      {
         path();
      }
      else
      {
        System.out.println("\n ........THANKS FOR VISITING OUR WEBSITE ....... \n"); 
        return ;
      }
     }

     static void Registration()
     {    int done =1;
           int choice =0;
           Scanner ScannerObj = new Scanner(System.in);
              System.out.println("\n NAME:");
              String NAME = ScannerObj.nextLine();

              System.out.println("\n MOBNO:");
              String MOBNO = ScannerObj.nextLine();

              System.out.println("\n EMAIL:");
              String EMAIL= ScannerObj.nextLine();

              System.out.println("\n  USERNAME:");
              String USERNAME = ScannerObj.nextLine();

              System.out.println("\n PASSWORD:");
              String PASSWORD = ScannerObj.nextLine();



              System.out.println("  \n 1) CONTINUE  2)EXIT\n ");
              System.out.println("\n PLEASE ENTER YOUR CHOICE :");
              choice = ScannerObj.nextInt();
              if(choice==1)
              {
                 path();
              }
              else
              {
                System.out.println("\n ........THANKS FOR VISITING OUR WEBSITE ....... \n"); 
                return ;
              }

    
     }

     static void Path()
     {    Scanner ScannerObj = new Scanner(System.in);
      System.out.println("  \n 1) RAMNAGAR \n  2)VILASNAGAR \n  3)GANDHINAGAR 4)BARDI 5)SHIVAJINAGAR \n ");
       System.out.println("\n STARTPOINT::-PLEASE ENTER YOUR CHOICE :");
      int choiceStart = ScannerObj.nextInt();         

      System.out.println("  \n 1) RAMNAGAR \n  2)VILASNAGAR \n  3)GANDHINAGAR 4)BARDI 5)SHIVAJINAGAR \n ");
      System.out.println("\n ENDPOINT::-PLEASE ENTER YOUR CHOICE :");
      int choiceEnd= ScannerObj.nextInt();

      while(choiceStart==choiceEnd)
      {   System.out.println("\n YOUR CHOICE IS NOT VALID \n");
          System.out.println("\n ENDPOINT::-PLEASE ENTER valid CHOICE :");
          choiceEnd= ScannerObj.nextInt();

      }

      DistanceMultiplyer=Math.abs(choiceStart-choiceEnd);
    
      ChooseVehicle();
     }

     static void ChooseVehicle()
     {  Scanner ScannerObj = new Scanner(System.in);
      System.out.println("  \n 1) MACRO 2) MINI 3) AUTO \n ");
      System.out.println("\n VEHICLETYPE::-PLEASE ENTER YOUR CHOICE :");
     int choice = ScannerObj.nextInt();  

     if(choice==1)
      {
        VehicleMultiplyer=5;
      }
      else if(choice==2)
      {
        VehicleMultiplyer=4;
      }
      else if(choice==3)
      {
        VehicleMultiplyer=2;
      }

      CalculateFare();
     }  
     
     static void CalculateFare()
     {

      Scanner ScannerObj = new Scanner(System.in);

          TotalFare=DistanceMultiplyer*VehicleMultiplyer*10;
          System.out.println("\n YOUR TotalFare:"+TotalFare+"\n");

          System.out.println("  \n 1) CONFIRM 2) EXIT \n ");
           System.out.println("\n ::-PLEASE ENTER YOUR CHOICE :");
           int choice = ScannerObj.nextInt();

           while(choice!=1&&choice!=2)
           {
 
             System.out.println("\n PLEASE ENTER VALID CHOICE :");
              choice = ScannerObj.nextInt();        
                    
           }
                      
           if(choice==1)
           {
            System.out.println("\n YOUR CAB IS BOOKED \n");
           }
           else if(choice ==2)
           {

            System.out.println("\n You choosed to EXIT  \n");
            System.out.println("\n ........THANKS FOR VISITING OUR WEBSITE ....... \n"); 
           }         
       

     }  

 
     public static void main(String[] args)
     {
      System.out.println("\n WELCOME TO .....MAHARASHTA.... CAR RENTALS  \n");

      int choice =0;
      Scanner ScannerObj = new Scanner(System.in);

      System.out.println("  \n 1) LOGIN \n  2)REGISTER \n  3)EXIT \n ");
      System.out.println("\n PLEASE ENTER YOUR CHOICE :");
      choice = ScannerObj.nextInt();      


      while(choice!=1&&choice!=2&&choice!=3)
      {
        System.out.println("\n PLEASE ENTER --valid-- CHOICE :");
        choice = ScannerObj.nextInt();
      }
     
      if(choice==1)
      {
         Login() ;
      }
      else if(choice==2)
      {
         Registration(); 
      }
      else if(choice==3)
      {
        System.out.println("\n ........THANKS FOR VISITING OUR WEBSITE ....... \n"); 
      }
      


     }
}