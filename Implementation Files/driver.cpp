#include <fstream>

#include "MovieManager.h"

int main() {

    ifstream customer_list("data4customers.txt");
    ifstream movie_list("data4movies");
    ifstream transaction_list("data4commands");

    MovieManager inventory;

    inventory.ReadCustomers(customer_list);

    inventory.ReadMovies(movie_list);

    inventory.ReadTransactions(transaction_list);

    return 1;
}

