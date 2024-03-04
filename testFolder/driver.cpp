#include <iostream>
#include <fstream>

using namespace std;

#include "Input-Files/ValidateSystemInput.h"
#include "MovieManager.h"

// The File/#include system currently implemented is very slow, optimize if time allows

int main(int args, char* argv[]) {

    MovieManager inventory;
    ifstream customer_list, movie_list, transaction_list;

    if (!Validate::checkfileAmount(args)) {

        cerr << "Invalid amount of files passed into the system." << endl;

    } else {

        Validate::dispurseFiles(customer_list, movie_list, transaction_list, argv);

        inventory.ReadCustomers(customer_list); // FINE
        customer_list.close();

        inventory.displayCustomers(); 

        inventory.ReadMovies(movie_list); // FINE - The map creates copies of AVLList which it has to delete, slower than it could be
        movie_list.close();

        inventory.ReadTransactions(transaction_list);
        transaction_list.close();
    }

    return 0;
}

