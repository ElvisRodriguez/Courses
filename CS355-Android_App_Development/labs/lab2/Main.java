import java.io.*;
import java.lang.*;
import java.util.*;

public class Main {
  public static void main (String [] args) {
    Scanner in = new Scanner(System.in);
    System.out.println("Welcome!");
    System.out.println("Choose A Game:");
    System.out.println("1) Poem.");
    System.out.println("2) Fortune  Teller.");
    System.out.println("3) Mad Libs.");
    System.out.print("Your Option: ");
    int option = in.nextInt();
    String name = "";
    switch (option) {
      case 1:
        System.out.print("Enter your name: ");
        name = in.next();
        System.out.println(Games.Poem(name));
        break;
      case 2:
        System.out.print("Enter your name: ");
        name = in.next();
        System.out.println(Games.fortuneTeller(name));
        break;
      case 3:
        String [] storyElements = new String[9];
        String [] requests = {
          "Adjective", "Adjective",
          "Verb ending in -ing", "Body Part (plural)",
          "Plural Noun", "Plural Noun", "Noun",
          "Plural Noun", "Plural Noun"
        };
        String storyElement = "";
        for (int i = 0; i < storyElements.length; i++) {
          System.out.print(requests[i] + ": ");
          storyElement = in.next();
          storyElements[i] = storyElement;
        }
        System.out.println(Games.madLibs(storyElements));
        break;
    }
  }
}
