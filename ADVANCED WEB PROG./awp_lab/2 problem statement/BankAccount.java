/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package practice;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author Pooja
 */
class Account {

    int acc_no;
    String acc_type;
    int balance;
    int mod_balance;

    Account(int acc_no, String acc_type, int balance) {
        this.acc_no = acc_no;
        this.acc_type = acc_type;
        this.balance = balance;
    }

    int getacc_no() {
        return this.acc_no;
    }

    String getacc_type() {
        return this.acc_type;
    }

    int getbal() {
        return this.balance;
    }

    void setbal(int bal) {
        this.balance = bal;
    }

    int getmod_bal() {
        return this.mod_balance;
    }

    void setmod_bal(int mod_bal) {
        this.mod_balance = mod_bal;
    }
}

class Bal_Check {

    ArrayList<Account> al;
    boolean valueSet = false;
    int mod_bal;
    Account a;
    boolean status = false;

    public Bal_Check(ArrayList<Account> al) {
        this.al = al;
    }

    synchronized boolean chck_Bal(int i) {
        while (valueSet) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
        a = al.get(i);
        if ("Salary".equals(a.getacc_type())) {
            if ((a.getbal() - 35000) >= 15000) {
                status = true;
            }
        } else {
            status = false;
        }
        valueSet = true;
        notify();
        return status;

    }

    synchronized void createFD(int i) {
        while (!valueSet) {
            try {
                wait();
            } catch (InterruptedException e) {
                System.out.println("Interrupted");
            }
        }
        if (status == true) {
            a = al.get(i);

            a.setmod_bal(a.getbal() - 35000);
            a.setbal(a.getbal() - a.mod_balance);
            al.set(i, a);
        }
        valueSet = false;
        notify();
    }

    void showDetails() {
        for (Account a: al ) {
            System.out.println("--------------------");
            System.out.println("Account no.: "+a.getacc_no());
            System.out.println("Account type: "+a.getacc_type());
            System.out.println("New Account Balance: "+a.getbal());
            System.out.println("MOD balance: "+a.getmod_bal());
            System.out.println("--------------------");
        }

    }
}

class BalanceStatus implements Runnable {

    Bal_Check b;
    int al_size;
    Thread t=new Thread(this, "BalanceStat");
    public BalanceStatus(Bal_Check b, int al_size) {
        this.b = b;
        this.al_size = al_size;
        t.start();
    }

    @Override
    public void run() {
        for (int i = 0; i < al_size; i++) {
            b.chck_Bal(i);
        }
    }

}

class FixedDeposit implements Runnable {

    Bal_Check b;
    int al_size;
    Thread t=new Thread(this, "FD");

    public FixedDeposit(Bal_Check b, int al_size) {
        this.b = b;
        this.al_size = al_size;
        t.start();
    }

    @Override
    public void run() {
        for (int i = 0; i < al_size; i++) {
            b.createFD(i);
        }
    }
}

public class BankAccount {

    public static void main(String[] args) {

        ArrayList<Account> acc_al = new ArrayList<>();

        Account a1 = new Account(101, "Salary", 30000);
        Account a2 = new Account(102, "Savings", 45000);
        Account a3 = new Account(103, "Salary", 50000);
        Account a4 = new Account(104, "Savings", 100000);
        Account a5 = new Account(105, "Salary", 60000);

        acc_al.add(a1);
        acc_al.add(a2);
        acc_al.add(a3);
        acc_al.add(a4);
        acc_al.add(a5);

        Bal_Check b = new Bal_Check(acc_al);
        System.out.println("Initial account details:");
        b.showDetails();
        BalanceStatus bs=new BalanceStatus(b, acc_al.size());
        FixedDeposit fd=new FixedDeposit(b, acc_al.size());

        try {
            bs.t.join();
             fd.t.join();
        } catch (InterruptedException ex) {
            
        }
       System.out.println("\nAccount details after performing the check:");
        b.showDetails();
        
    }

}
