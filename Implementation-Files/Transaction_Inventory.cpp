#include "Transaction_Inventory.h"

// Constructor 
Inventory::Inventory(){
    this->commandType = CommandType::inventory;
}

// Destructor
Inventory::~Inventory(){}

// Process the inventory of movies
void Inventory::ProcessInventory(MediaCollection &movies){
    movies.Display();
}
