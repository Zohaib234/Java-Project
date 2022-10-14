package com.Muzafar.project;

import java.sql.SQLException;
import java.util.Scanner;

public class Start {
    public  static  void intro(){
        System.out.println("welcome to MA-Book Store");
        System.out.println("........................");
        System.out.println("choice any of given operations");
        System.out.println("........................");
        System.out.println("1.   Add a Book");
        System.out.println("2.   View Books");
        System.out.println("3.   Delete a Book");
        System.out.println("4.   Update a Book");
        System.out.println("5.   exit program");

    }

    public static void main(String [] args) throws SQLException {

        Scanner s = new Scanner(System.in);

          Loader loader = new Loader('.');
        intro();
        System.out.print("please wait");
        int choice;


        choice = s.nextInt();
        if(choice==1){
            NewBook book = new NewBook();
            book.addBook();
        }
        else if(choice==2){
            Books books = new Books();
            books.viewBooks();
        }
        else if(choice==3){
           Books book = new Books();
           book.deleteBook();
        }
        else if(choice==5){
            System.exit(0);

        } else if (choice==4) {
           Books b = new Books();
           b.updateBook();
        }

        System.out.println("press any key to continue");
        s.nextLine();
        if(s.hasNextLine()){
            main(null);
        }






    }
}
