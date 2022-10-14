package com.Muzafar.project;

import java.sql.*;
import java.util.Scanner;

public class Books {
    String BookName;
    String AuthorName;
    int Edition;
    double price;
    Scanner sc = new Scanner(System.in);

    Books(String BookName, String AuthorName, int Edition, double price) {
        this.BookName = BookName;
        this.AuthorName = AuthorName;
        this.Edition = Edition;
        this.price = price;
    }

    public Books() {

    }

    public void viewBooks() {
        String dbURL = "jdbc:mysql://localhost:3306/Java";
        String username = "root";
        String password = "";

        try (Connection conn = DriverManager.getConnection(dbURL, username, password)) {

            if (conn != null) {
                System.out.println("connected to Database");
            }
            String sql = "SELECT * FROM books";

            Statement statement = conn.createStatement();
            ResultSet result = statement.executeQuery(sql);

            int count = 0;

            while (result.next()){
                String bookname = result.getString("BookName");
                String authorname = result.getString("AuthorName");
                double price = result.getDouble("Price");
                int edition = result.getInt("Edition");


                String output = "User #%d: %s - %s - %s - %s";
                System.out.println(String.format(output, ++count, bookname, authorname, price, edition));
            }

        }
        catch (Exception e){
            System.out.println(e.getMessage());

        }
    }

    public void deleteBook(){
        System.out.println("enter Book Name to Delete");
        String book = sc.nextLine();
        String dbURL = "jdbc:mysql://localhost:3306/Java";
        String username = "root";
        String password = "";

        try (Connection conn = DriverManager.getConnection(dbURL, username, password)) {

            if (conn != null) {
                System.out.println("connected to Database");
            }
            String sql = "DELETE FROM books WHERE BookName=?";

            PreparedStatement statement = conn.prepareStatement(sql);
            statement.setString(1, book);

            int rowsDeleted = statement.executeUpdate();
            if (rowsDeleted > 0) {
                System.out.println("A user was deleted successfully!");
            }
        }
        catch (Exception e){
            System.out.println(e.getMessage());

        }
    }

    public void updateBook(){
//        viewBooks();
        System.out.println("chose any of one book to update");
        String dbURL = "jdbc:mysql://localhost:3306/Java";
        String username = "root";
        String password = "";

        System.out.println("enter BookName To update");
        String book = sc.nextLine();
        System.out.println("enter Book Author To Update");
        String author = sc.nextLine();
        System.out.println("enter book edition to update");
        int edition = sc.nextInt();
        System.out.println("enter book price to update");
        double price = sc.nextDouble();

        try (Connection conn = DriverManager.getConnection(dbURL, username, password)) {

            if (conn != null) {
                System.out.println("connected to Database");
            }

            String sql = "UPDATE books SET   AuthorName=?, Price=? , Edition=? WHERE BookName=?";

            assert conn != null;
            PreparedStatement statement = conn.prepareStatement(sql);
//            statement.setString(1,author);
//            statement.setDouble(2,price);
//            statement.setInt(3,edition);
//            statement.setString(4,book);

            int rowsUpdated = statement.executeUpdate();
            if (rowsUpdated > 0) {
                System.out.println("An existing user was updated successfully!");
            }

        }
        catch (Exception e){
            System.out.println(e.getMessage());

        }
    }
}



