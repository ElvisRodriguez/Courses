/*
//Name: Elvis Rodriguez
//Creation: 11/17/2017
//Version: 6.R
//Description: opens a file for reading, creates a new file, and copies the
               content of the original file to the newly created file.
*/

#ifndef CP_COMMAND_H
#define CP_COMMAND_H

/*
//Name: Copy()
//Parameter(s): string file_name
//Returns: None
//Label   Task                                                              Goto
//01      (start: file_name)                                                02
//02      [init original_file: ifstream]                                    03
//03      [init copied_file: ofstream]                                      04
//04      [init line: str]                                                  05
//05      [open file_name as original_file]                                 06
//06      < original_file.good() == false >                                 07,10
//07      /print("ERROR\n")/                                                08
//08      /print("Your file doesn't exist..access it")/                     09
//09      (exit)                                                            10
//10      [open copied.txt as copied_file]                                  11
//11      < original_file.is_open() and copied_file.is_open() >             12,14
//12      < getline(original_file, line) >                                  13,14
//13      /print to copied_file(line, "\n")/                                12
//14      [original_file.close()]                                           15
//15      [copied_file.close()]                                             16
//16      /print("Copy Successful\n")/                                      17
//17      (exit)
*/
void Copy(string file_name) {
  ifstream original_file;
  ofstream copied_file;
  string line;

  original_file.open(file_name);

  if (original_file.good() == false) {
    cout << "ERROR\n";
    cout << "Your file doesn't exist, or you may not have permission to access it\n";
    return;
  }
  copied_file.open("copied.txt");

  if (original_file.is_open() && copied_file.is_open()) {

     while ( getline(original_file, line) ) {
     copied_file << line << "\n";
     }
  }

   original_file.close();
   copied_file.close();

   cout << "Copy Successful\n";
 }

#endif //CP_COMMAND_H
