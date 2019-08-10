/*
//Name: Elvis Rodriguez
//Creation: 10/31/2017
//Version: Midterm-Applebees
//Description: Displays a list of appetizers and allows the user to select one.
               If the user’s selection is invalid, it gives the user the “Two
               Caesar Side Salads” option. Displays a list of entr´ees and
               allows the user to select two separately. For any invalid
              selection, it gives the user the “Chicken Tenders Basket” option.
              Calculates the user’s subtotal, tax (8.87), total, 15%, 18% and
              20% gratuity; and then, Displays a spatially formatted receipt
              with the user’s order and the above values rounded to two decimal
              places. Prints the receipt to a file named “receipt.txt” as well
              as displays it on the screen.
*/
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
using namespace std;

#include "restaurant.h"
/*
//Name: main()
//Parameter(s): None
//Return: int
//Label     Task                                                                                  Goto
//01        (start)                                                                               02
//02        [init float subtotal, 20 --> subtotal]                                                03
//03        [init float tax, total]                                                               04
//04        [init int length]                                                                     05
//05        [init string userAppetizer, userEntree1, userEntree2]                                 06
//06        [init string list(appetizers)]                                                        07
//07        [ "Two Caesar Side Salads" --> appetizers[0] ]                                        08
//08        [ "Spinach + Artichoke Dip" --> appetizers[1] ]                                       09
//09        [ "Crunchy Onion Rings" --> appetizers[2] ]                                           10
//10        [ "Boneless Wings" --> appetizers[3] ]                                                11
//11        [ "Mozzarella Sticks" --> appetizers[4] ]                                             12
//12        [init string list(entrees)]                                                           13
//13        [ "Chicken Tenders Basket" --> entrees[0] ]                                           14
//14        [ "Oriental Chicken Salad" --> entrees[1] ]                                           15
//15        [ "Shrimp Cavatappi [+3.50]" --> entrees[2] ]                                         16
//16        [ "The American Standard" --> entrees[3] ]                                            17
//17        [ "Blackened Tilapia" --> entrees[4] ]                                                18
//18        [ "Whisky Bacon Burger" --> entrees[5] ]                                              19
//19        [ "Baby Back Ribs [+3.50]" --> entrees[6] ]                                           20
//20        [ "Cedar Grilled Lemon Chicken" --> entrees[7] ]                                      21
//21        [ "Fiesta Lime Chicken" --> entrees[8] ]                                              22
//22        [ "Three-Cheese Chicken Cavatappi" --> entrees[9] ]                                   23
//23        [menuA()]                                                                             24
//24        [(end(appetizers) - begin(appetizers)) --> length]                                    25
//25        [choice(appetizers, length, userAppetizer)]                                           26
//26        [menuB()]                                                                             27
//27        [(end(entrees) - begin(entrees)) --> length]                                          28
//28        [choice(entrees, length, userEntree1)]                                                29
//29        [choice(entrees, length, userEntree2)]                                                30
//30        [getCalculate(subtotal, tax, total, entrees, userEntree1, userEntree2) --> subtotal]  31
//31        [receipt(userAppetizer, userEntree1, userEntree2, subtotal, tax, total)]              32
//32        (exit: 0)
*/
int main() {
  float subtotal = 20;
  float tax, total;
  int length;
  string userAppetizer, userEntree1, userEntree2;

  string appetizers[] = {
    "Two Caesar Side Salads                   (800 Cal.)",
    "Spinach + Artichoke Dip                  (960 Cal.)",
    "Crunchy Onion Rings                      (1300 Cal.)",
    "Boneless Wings                           (1160 Cal.)",
    "Mozzarella Sticks                        (910 Cal.)"
  };

  string entrees[] = {
    "Chicken Tenders Basket                   (1150 Cal.)",
    "Oriental Chicken Salad                   (1420 Cal.)",
    "Firecracker Shrimp Cavatappi             (1970 Cal.) [Plus 3.50]",
    "The American Standard                    (1010 Cal.)",
    "Blackened Tilapia                        (510 Cal.)",
    "Whisky Bacon Burger                      (1240 Cal.)",
    "Double-Glazed Baby Back Ribs - Half Rack (550 Cal.) [Plus 3.50]",
    "Cedar Grilled Lemon Chicken              (580 Cal.)",
    "Fiesta Lime Chicken                      (1140 Cal.)",
    "Three-Cheese Chicken Cavatappi           (1280 Cal.)"
  };

  menuA();
  length = end(appetizers) - begin(appetizers);
  choice(appetizers, length, userAppetizer);

  menuB();
  length = end(entrees) - begin(entrees);
  choice(entrees, length, userEntree1);
  choice(entrees, length, userEntree2);

  subtotal = getCalculate(subtotal, tax, total, entrees, userEntree1, userEntree2);

  receipt(userAppetizer, userEntree1, userEntree2, subtotal, tax, total);
  return 0;
}
