#include "ValidateSystemInput.h"

bool Validate::CheckfileAmount(const int files) {

    return files == 4;
}

// Large Memory Leak - ifstream, Memory Leak
// Small memory leak, f.open()
void Validate::DispurseFiles(ifstream& cust, ifstream& movie, ifstream& trans, char* file_names[]) { // DONE
    
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

int Validate::CheckFile(ifstream& curr) { // DONE

    string firstElement = "";
    int ret = 0;

    curr >> firstElement;

    if (isdigit(firstElement[0])) { // Customer File is the only one that starts w/ a digit

        ret = 1;
    } else {

        switch (firstElement[0]) {

            case 'D':
            case 'C':
            case 'F':

            ret = 2; // Movies File
            break;

            case 'B':
            case 'R':
            case 'H':
            case 'I':

            ret = 3; // Transaction File
            break;
        }
    }

    return ret;
}