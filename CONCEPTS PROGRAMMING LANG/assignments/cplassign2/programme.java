import javax.sound.midi.Soundbank;
import javax.swing.*;
import java.sql.SQLOutput;
import java.util.Scanner;
public class programme {
    public static void main(String args[])
    {
        int p;
        int i=1;
        Scanner sc=new Scanner(System.in);
        int m=sc.nextInt();
        int n=sc.nextInt();
       p = ackerman(m,n);
        System.out.println("The Value Of Functon Is:"+p);

    }
    static int ackerman(int m,int n)
    {
         if(m>0&&n==0)
         {ackerman(m-1,1);}
         else if (m>0&&n>0)
         {ackerman(m-1,ackerman(m,n-1));}
        else if(m==0)
            return(n+1);
    }

