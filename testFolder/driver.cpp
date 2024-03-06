#include <iostream>
#include <fstream>

using namespace std;

#include "ValidateSystemInput.h"
#include "MovieManager.h"

// The File/#include system currently implemented is very slow, optimize if time allows
// Warning: Unable to process IntelliSense for file with same canonicalized path as existing file - Error across multiple files 
//          ??Duplicate Includes??

// Current Errors: 
    // Way to many transaction error statements - 'Customer 0 Does Not Exist'
    // Doesn't update the stock amounts for borrowed and retuned (Dramas and Classics only)
    // Certain customers don't have a history - some customers have too many history logs
    // Doesn't run the last History command (H 8888)

int main(int args, char* argv[]) {

    MovieManager inventory;
    ifstream customer_list, movie_list, transaction_list;

    if (!Validate::CheckfileAmount(args)) {

        cerr << "Invalid amount of files passed into the system." << endl;

    } else {

        Validate::DispurseFiles(customer_list, movie_list, transaction_list, argv);

        inventory.ReadCustomers(customer_list); // FINE
        customer_list.close();

        inventory.ReadMovies(movie_list); // FINE - The map creates copies of AVLList which it has to delete, slower than it could be, maybe still the case
        movie_list.close();

        inventory.ReadTransactions(transaction_list);
        transaction_list.close();
    }

    return 0;
}

// H 1000
// H 5000
// H 8000

// H 1000
// H 1111
// H 5000
// H 8000
// H 8888
