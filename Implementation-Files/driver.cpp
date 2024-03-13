#include <iostream>
#include <fstream>
#include "ValidateSystemInput.h"
#include "MovieManager.h"
using namespace std;

int main(int args, char* argv[]) {
    // Create a MovieManager object to manage the inventory
    MovieManager inventory;
    ifstream customer_list, movie_list, transaction_list;

    // Validate the number of files passed into the system
    if (!Validate::CheckfileAmount(args)) {
        cerr << "Invalid amount of files passed into the system." << endl;

    } else {
        // Parse and disperse the files provided as command-line arguments
        Validate::DispurseFiles(customer_list, movie_list, transaction_list, argv);

        // Read customer data from the customer list file and close it
        inventory.ReadCustomers(customer_list); 
        customer_list.close();

        // Read movie data from the movie list file and close it
        inventory.ReadMovies(movie_list); 
        movie_list.close();

        // Read transaction data from the transaction list file and close it
        inventory.ReadTransactions(transaction_list);
        transaction_list.close();
    }

    return 0;
}
