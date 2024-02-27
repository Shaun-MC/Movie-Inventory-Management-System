#include "MovieManager.h"

MovieManager::MovieManager() { // Unsure if nessecary - data types already initialize themselves


}

// Assumption: ifile is already open when passed into the file
void MovieManager::ReadCustomers(ifstream& ifile) {

    if (ifile.eof()) { // Guard clause, no more data to read

        return;
    }

    int key = 0;
    string f_name = "", l_name = "", line = "";

    while (!ifile.eof()) {
        
        getline(ifile, line);
        ifile.ignore(); // Positions stream onto the next line

        parseCustomerLine(line, key, f_name, l_name);

        customers.insert(key, f_name, l_name);
    }
}

void MovieManager::parseCustomerLine(string line, int& key, string& f_name, string& l_name) const {

    stringstream parse(line);

    parse >> key;
    parse.ignore();

    parse >> f_name;
    parse.ignore();

    parse >> l_name;
    parse.ignore();
}