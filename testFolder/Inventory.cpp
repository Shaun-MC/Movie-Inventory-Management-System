#include "Inventory.h"

Inventory::Inventory(){
    
    this->commandType = CommandType::inventory;
}

Inventory::~Inventory(){}

bool Inventory::processInventory(MediaCollection &movies){
    
    movies.display();

    return true;
}

//Need the ostream??
