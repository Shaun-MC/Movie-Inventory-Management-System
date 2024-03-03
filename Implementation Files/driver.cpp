#include <fstream>

#include "MovieManager.h"

int main() {

    ifstream customer_list("data4customers.txt");
    ifstream movie_list("data4movies.txt");
    //ifstream transaction_list("data4commands.txt");

    MovieManager inventory;

    inventory.ReadCustomers(customer_list);
    customer_list.close();

    inventory.ReadMovies(movie_list);
    movie_list.close();

    inventory.displayMedia();
    
    //inventory.ReadTransactions(transaction_list);
    //transaction_list.close();

    return 1;
}

