#include "ValidateSystemInput.h"

// Check if the correct number of files are passed into the system
bool Validate::CheckfileAmount(const int files) {
    return files == 4;
}

// Open the input files based on their types
void Validate::DispurseFiles(ifstream& cust, ifstream& movie, ifstream& trans, char* file_names[]) { 
    for (int i = 1; i < 4; i++) {
        ifstream temp(file_names[i]);
        const int file_type = CheckFile(temp);
        temp.close();

        switch(file_type) {
            case 1: 
                cust.open(file_names[i]);
                break;

            case 2:
                movie.open(file_names[i]);
                break;

            case 3:
                trans.open(file_names[i]);
                break;
        }
    }
}

// Check the type of file based on its first element
int Validate::CheckFile(ifstream& curr) { 
    string firstElement = "";
    int ret = 0;

    curr >> firstElement;

    if (isdigit(firstElement[0])) { 
        ret = 1;

    } else {
        switch (firstElement[0]) {

            case 'D':
            case 'C':
            case 'F':
                ret = 2; 
                break;

            case 'B':
            case 'R':
            case 'H':
            case 'I':
                ret = 3;
                break;
        }
    }

    return ret;
}