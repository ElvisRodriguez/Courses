#ifndef RESTAURANT_H
#define RESTAURANT_H

#define length(array) (sizeof(array)/sizeof(array[0]))
/*
//Name: menuA()
//Parameter(s): None
//Return: None
//Label   Task                                                                  Goto
//01      (start)                                                               02
//02      /print("Applebees Two for Twenty\n")/                                03
//03      /print("Two Entrees + One Appetizer\n\n")/                            04
//04      /print("Appetizers:\n")/                                              05
//05      /print("1:Two Caesar Side Salads (800 Cal.)\n")/                      06
//06      /print("2:Spinach + Artichoke Dip(960 Cal.)\n")/                      07
//07      /print("3:Crunchy Onion Rings(1300 Cal.)\n")/                         08
//08      /print("4:Boneless Wings(1160 Cal.)\n")/                              09
//09      /print("5:Mozzarella Sticks(910 Cal.)\n")/                            10
//10      /print("What would you like? Please choose by number:\n")/            11
//11      (exit)
*/

void menuA() {
    cout << "Applebees Two for Twenty\n";
    cout << "Two Entrees + One Appetizer\n\n";
    cout << "Appetizers:\n";
    cout << "1:  Two Caesar Side Salads                   (800 Cal.)\n";
    cout << "2:  Spinach + Artichoke Dip                  (960 Cal.)\n";
    cout << "3:  Crunchy Onion Rings                      (1300 Cal.)\n";
    cout << "4:  Boneless Wings                           (1160 Cal.)\n";
    cout << "5:  Mozzarella Sticks                        (910 Cal.)\n";
    cout << "What would you like? Please choose by number:\n";
}

/*
//Name: menuB()
//Parameter(s): None
//Return: None'
//Label   Task                                                                    Goto
//01      (start)                                                                 02
//02      /print("Entrees:\n")/                                                   03
//03      /print("1:Chicken Tenders Basket(1150 Cal.)\n")/                        04
//04      /print("2:Oriental Chicken Salad(1420 Cal.)\n")/                        05
//05      /print("3:Firecracker Shrimp Cavatappi(1970 Cal.)[+3.50]\n")/           06
//06      /print("4:The American Standard(1010 Cal.)\n")/                         07
//07      /print("5:Blackened Tilapia(510 Cal.)\n")/                              08
//08      /print("6:Whisky Bacon Burger(1240 Cal.)\n")/                           09
//09      /print("7:Double-Glazed Baby Back Ribs-Half Rack(550 Cal.)[+3.50]\n")/  10
//10      /print("8:Cedar Grilled Lemon Chicken(580 Cal.)\n")/                    11
//11      /print("9:Fiesta Lime Chicken(1140 Cal.)\n")/                           12
//12      /print("10:Three-Cheese Chicken Cavatappi(1280 Cal.)\n")/               13
//13      /print("What would you like? Please choose two items by number:\n")/    14
//14      (exit)
*/
void menuB() {
    cout << "Entrees:\n";
    cout << "1:  Chicken Tenders Basket                   (1150 Cal.)\n";
    cout << "2:  Oriental Chicken Salad                   (1420 Cal.)\n";
    cout << "3:  Firecracker Shrimp Cavatappi             (1970 Cal.) [Plus 3.50]\n";
    cout << "4:  The American Standard                    (1010 Cal.)\n";
    cout << "5:  Blackened Tilapia                        (510 Cal.)\n";
    cout << "6:  Whisky Bacon Burger                      (1240 Cal.)\n";
    cout << "7:  Double-Glazed Baby Back Ribs - Half Rack (550 Cal.) [Plus 3.50]\n";
    cout << "8:  Cedar Grilled Lemon Chicken              (580 Cal.)\n";
    cout << "9:  Fiesta Lime Chicken                      (1140 Cal.)\n";
    cout << "10: Three-Cheese Chicken Cavatappi           (1280 Cal.)\n";
    cout << "What would you like? Please choose two items by number:\n";
}

/*
//Name: choice()
//Parameter(s): string list(menu), int lengthOflist, string& item
//Return: string
//Label   Task                                              Goto
//01      (start: list(menu)), lengthOflist, item)          02
//02      [init int menuNumber]                             03
//03      /input --> item/                                  04
//04      /write(item) --> menuNumber/                      05
//05      < menuNumber <= lengthOflist >                    06, 07
//06      [menu[menuNumber -1] --> item]                    08
//07      [menu[0] --> item]                                08
//08      (exit: item)
*/
string choice(string menu[], int lengthOflist, string& item) {
  int menuNumber;
    getline(cin, item);
    stringstream(item) >> menuNumber;
    if (menuNumber <= lengthOflist)
    {
      item = menu[menuNumber - 1];
    } else {
      item = menu[0];
    }
  return item;
  }

/*
//Name: getCalculate()
//Parameter(s): float subtotal, float& (tax, total), string (list(entrees), entree1, entree2)
//Return: float
//Label   Task                                                                  Goto
//01      (start: subtotal, tax, total, list(entrees), entree1, entree2 )       02
//02      [(subtotal - (subtotal * 0.887)) --> tax]                             03
//03      [(subtotal + tax) --> total]                                          04
//04      < entree1 == entrees[2] or entree[6] >                                05, 06
//05      [(subtotal + 3.5) --> subtotal]                                       06
//06      < entree2 == entrees[2] or entree[6] >                                07, 08
//07      [(subtotal + 3.5) --> subtotal]                                       08
//08      (exit: subtotal)
*/
float getCalculate(float subtotal, float& tax, float& total, string entrees[], string entree1, string entree2) {
  tax = ( subtotal - (subtotal * 0.887) );
  total = ( subtotal + tax );

  if (entree1 == entrees[2] || entree1 == entrees[6]) {
    subtotal += 3.5;
  }
  if (entree2 == entrees[2] || entree2 == entrees[6]) {
    subtotal += 3.5;
  }
  return subtotal;
}
/*
//Name: receipt()
//Parameter(s): string (appetizer, entree1, entree2), float (subtotal, tax, total)
//Return: None
//Label   Task                                                                              Goto
//01      (start: appetizer, entree1, entree2, subtotal, tax, total)                        02
//02      [init ofstream writeReceipt]                                                      03
//03      [init ifstream readReceipt]                                                       04
//04      [writeReceipt.open("receipt.txt")]                                                05
//05      < writeReceipt.is_open()? >                                                       06, 19
//06      /print_to_file(fixed, setprecision(2))/                                           07
//07      /print_to_file("....................RECEIPT.............\n")/                     08
//08      /print_to_file("Appetizer:","........................",appetizer, "\n")/          09
//09      /print_to_file("First Entree:" ,".....................", entree1, "\n")/          10
//10      /print_to_file("Second Entree:", "....................", entree2, "\n")/          11
//11      /print_to_file("Subtotal:", ".........................", subtotal, "\n")/         12
//12      /print_to_file("Tax:", "..............................", tax, "\n")/              13
//13      /print_to_file("Total:", "............................", total, "\n")/            14
//14      /print_to_file("Gratuity Guidelines:", "\n")/                                     15
//15      /print_to_file("15%...............................", (subtotal * 0.15), "\n")/    16
//16      /print_to_file("18%...............................", (subtotal * 0.18), "\n")/    17
//17      /print_to_file("20%...............................", (subtotal * 0.20), "\n")/    18
//18      [writeReceipt.close()]                                                            19
//19      [readReceipt.open("receipt.txt")]                                                 20
//20      < readReceipt.is_open()? >                                                        21, 23
//21      /print(readReceipt.rdbuf(), "\n")/                                                22
//22      [readReceipt.close()]                                                             23
//23      (exit)
*/
void receipt(string appetizer, string entree1, string entree2, float subtotal, float tax, float total) {
  ofstream writeReceipt;
  ifstream readReceipt;

  writeReceipt.open("receipt.txt");

  if (writeReceipt.is_open()) {
    writeReceipt << fixed << setprecision(2);
    writeReceipt << "....................RECEIPT.............\n";
    writeReceipt << "Appetizer:" << "........................" << appetizer << endl;
    writeReceipt << "First Entree:" << "....................." << entree1 << endl;
    writeReceipt << "Second Entree:" << "...................." << entree2 << endl;
    writeReceipt << "Subtotal:" << "........................." << subtotal << endl;
    writeReceipt << "Tax:" << ".............................." << tax << endl;
    writeReceipt << "Total:" << "............................" << total << endl;
    writeReceipt << "Gratuity Guidelines:" << endl;
    writeReceipt << "15%..............................." << (subtotal * 0.15) << endl;
    writeReceipt << "18%..............................." << (subtotal * 0.18) << endl;
    writeReceipt << "20%..............................." << (subtotal * 0.20) << endl;
    writeReceipt.close();
  }

  readReceipt.open("receipt.txt");
  if (readReceipt.is_open()) {
    cout << readReceipt.rdbuf() << endl;
    readReceipt.close();
  }

}

#endif //RESTAURANT_H
