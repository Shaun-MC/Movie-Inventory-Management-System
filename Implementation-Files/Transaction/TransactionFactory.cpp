#include "TransactionFactory.h"

// Create a transaction based on the provided transaction line
Transaction* TransactionFactory::CreateTransaction(const string trans_line){ 
    stringstream str(trans_line);
    char command = 0;

    str >> command;
    str.ignore(); 

    switch (command) {

        case CommandType::inventory:
        return CreateInventory(str);
        break;

        case CommandType::history: 
        return CreateHistory(str);
        break;

        case CommandType::borrow:
        return CreateBorrow(str);
        break;
        
        case CommandType::return_:
        return CreateReturn(str);
        break;

        default: 
        cerr << "ERROR: " << command << " Invalid Transaction Type. Try Again." << endl;
        
        Transaction* placeholder = nullptr;
        return placeholder;
        
        break;
    }
}

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Private Member Functions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

// Create an inventory transaction
Transaction* TransactionFactory::CreateInventory(stringstream& str){ 
    Transaction* newInventory = new Inventory();

    newInventory->setCommandType(CommandType::inventory);

    return newInventory;
}

// Create a history transaction
Transaction* TransactionFactory::CreateHistory(stringstream& str){ 
    Transaction* newHistory = new History();
    
    newHistory->setCommandType(CommandType::history);
    
    if (!newHistory->setData(str)) {
        delete newHistory;
        newHistory = nullptr;
    }
    
    return newHistory;
}

// Create a return transaction
Transaction* TransactionFactory::CreateReturn(stringstream& str){
    Transaction* newReturn = new Return();

    newReturn->setCommandType(CommandType::return_);
    
    if (!newReturn->setData(str)) {
        delete newReturn;
        newReturn = nullptr;
    }

    return newReturn;
}

// Create a borrow transaction
Transaction* TransactionFactory::CreateBorrow(stringstream& str) {
    Transaction* newBorrow = new Borrow(); 
    
    newBorrow->setCommandType(CommandType::borrow);
    
    if (!newBorrow->setData(str)) {
        delete newBorrow;
        newBorrow = nullptr;
    }
    
    return newBorrow;
}
