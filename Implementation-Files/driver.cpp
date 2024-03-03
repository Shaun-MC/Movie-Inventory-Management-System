#include <iostream>
#include <fstream>

using namespace std;

#include "Input-Files/ValidateSystemInput.h"
#include "MovieManager.h"

int main(int args, char* argv[]) {

    MovieManager inventory;
    ifstream customer_list, movie_list, transaction_list;

    if (!Validate::checkfileAmount(args)) {

        cerr << "Invalid amount of files passed into the system." << endl;

    } else {

        Validate::dispurseFiles(customer_list, movie_list, transaction_list, argv);

        inventory.ReadCustomers(customer_list);
        customer_list.close();

        inventory.ReadMovies(movie_list);
        movie_list.close();

        // inventory.ReadTransactions(transaction_list);
        // transaction_list.close();
    }

    return 1;
}

