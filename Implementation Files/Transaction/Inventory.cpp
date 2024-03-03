#include "Inventory.h"

Inventory::Inventory(){
    
    this->commandType = CommandType::inventory;
}

Inventory::~Inventory(){}

bool Inventory::processInventory(MediaCollection &movies){
    
    cout << "Inventory: " << endl;
    movies.display(); // where is display();

    return true;
}

//Need the ostream??
