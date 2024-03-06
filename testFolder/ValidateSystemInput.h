#ifndef VALIDATESYSTEMINPUT_H
#define VALIDATESYSTEMINPUT_H

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Validate {
 public:

  // Function are checking the correct amount of files (4)
  static bool CheckfileAmount(const int files);

  // Opens each of the files based on the a contents of the first character
  static void DispurseFiles(ifstream& cust, ifstream& movie, ifstream& trans, char* file_names[]);

 private:
  
  // Helper Function
  static int CheckFile(ifstream& curr);
};

#endif