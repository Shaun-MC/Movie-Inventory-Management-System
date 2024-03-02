#include "Inventory.h"

Inventory::Inventory(){
    this->commandType = CommandType::Inventory;
}

Inventory::~Invenotory(){
}

void Inventory::inventoryProcess(MovieCollection &movies){
    cout << "Inventory: " << endl;
    movies.display(); //where is display();
}

//Need the ostream??
