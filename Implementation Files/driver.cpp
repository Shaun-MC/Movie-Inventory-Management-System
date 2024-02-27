#include <iostream>

using namespace std;

#include "MovieManager.h"

int main() {

    //MovieManager inventory;

    inventory.ReadCustomers();

    inventory.ReadMovies();

    inventory.ReadTransactions();

    return 1;
}

