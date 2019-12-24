import java.io.*;
import java.lang.*;
import java.util.*;

public class Games {

  public static String Poem(String name) {
    String fullPoem = "A short Poem\n";
    fullPoem += "My student " + name + ",\n";
    fullPoem += "standing proud,\n";
    fullPoem += "is a fine example for the crowd.";
    return fullPoem;
  }

  public static String fortuneTeller(String name) {
    String [] fortunes = {
      "Today it's up to you to create the peacefulness you long for.",
      "A friend asks only for your time not your money.",
      "If you refuse to accept anything but the best, you very often get it.",
      "A smile is your passport into the hearts of others.",
      "A good way to keep healthy is to eat more Chinese food."
    };
    int random = (int)((Math.random() * 10)) % fortunes.length;
    return "\nHere is you fortune " + name + ":\n" + fortunes[random];
  }

  public static String madLibs(String [] elements) {
    String madLib =
      "A/An " + elements[0] + " fitness revolution is taking place.\n" +
      "Today, millions of people are doing all kinds of " + elements[1] +
      " exercises such as jogging, walking and " + elements[2] +
      " to get their " + elements[3] + " in shape and develp their "
      + elements[4] + ".\n Many go to gyms and health " + elements[5] +
      " to work out by punching a/an " + elements[6] +
      ", lifting " + elements[7] + ", or performing aerobic " +
      elements[8] + ".\n";
    return madLib;
  }
  public static void main (String [] args) {
    System.out.println("Source File Compiled correctly.");
  }
}
