import java.lang.Math;
import java.util.Scanner;
import java.lang.String;

public class Fortune {

  public static void main (String[] args) {

    Scanner scanner = new Scanner(System.in);
    String [] fortunes = new String [5];
    fortunes[0] = "Today it's up to you to create the peacefulness you long for.";
    fortunes[1] = "A friend asks only for your time not your money.";
    fortunes[2] = "If you refuse to accept anything but the best, you very often get it.";
    fortunes[3] = "A smile is your passport into the hearts of others.";
    fortunes[4] = "A good way to keep healthy is to eat more Chinese food.";

    System.out.println("Enter your name:");
    String name = scanner.next();

    System.out.println("\nHere is you fortune " + name + ":");
    int random = (int)((Math.random() * 10)) % 5;
    System.out.println(fortunes[random]);
  }
}
