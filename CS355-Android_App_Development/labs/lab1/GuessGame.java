import java.lang.Math;
import java.util.Scanner;

public class GuessGame {

  public static void main (String[] args) {

    Scanner scanner = new Scanner(System.in);
    double decimalNumber = Math.random() * 100 + 1;
    int number = (int)decimalNumber;
    int guess = 0;

    do {
      System.out.print("Enter your guess: ");
      guess = scanner.nextInt();

      if (guess<number) {
        System.out.println("Guess was too low");
        System.out.println("Try Again!");
      } else if (guess>number) {
        System.out.println("Guess was too high");
        System.out.println("Try Again!");
      } else {
        System.out.println("Correct, the number was " + number);
      }
    } while (guess != number);

  }
}
