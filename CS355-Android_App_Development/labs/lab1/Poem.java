import java.io.*;
import java.lang.*;
import java.util.*;

class Poem {
  public static void main (String [] args) {
    System.out.println("A short Poem");
    System.out.print("Enter your name: ");
    Scanner in = new Scanner(System.in);
    String studentName = in.next();
    System.out.println("My student " + studentName + ",");
    System.out.println("standing proud,");
    System.out.println("is a fine example for the crowd.");
  }
}
