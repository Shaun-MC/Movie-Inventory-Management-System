#include "MovieManager.h"

MovieManager::MovieManager() {

    this->customers = new CustomerCollection();
}

void MovieManager::ReadCustomers(ifstream& customer_file) {

    if (!customer_file) {

        cout << "File Could Not be Opened" << endl;
    }

    int key = 0;
    string line = "", name = "";

    while (!customer_file.eof()) {
        
        getline(customer_file, line);

        parseCustomerLine(line, key, name);

        customers->insert(key, name);
    }
}

void MovieManager::ReadMovies(ifstream& movie_list) {


}

void MovieManager::ReadTransactions(ifstream& transaction_list) {

    return;
}

void MovieManager::parseCustomerLine(const string line, int& key, string& name) const {

    string f_name = "", l_name = "";

    stringstream parse(line);

    parse >> key;
    parse.ignore();

    parse >> l_name;
    parse.ignore();

    parse >> f_name;
    parse.ignore();

    name = f_name + " " + l_name;
}