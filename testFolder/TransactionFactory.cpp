#include "TransactionFactory.h"

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Actions
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Transaction* TransactionFactory::CreateTransaction(const string trans_line){ // DONE
    
    stringstream str(trans_line);
    char command = 0;

    // Cannot support command types being more than 1 character
    str >> command;
    str.ignore(); // Space

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
Transaction* TransactionFactory::CreateInventory(stringstream& str){ // DONE
    
    // Doesn't always get deleted
    Transaction* newInventory = new Inventory();

    newInventory->setCommandType(CommandType::inventory);

    return newInventory;
}

Transaction* TransactionFactory::CreateHistory(stringstream& str){ // DONE
    
    Transaction* newHistory = new History();
    
    newHistory->setCommandType(CommandType::history);
    
    if (!newHistory->setData(str)) {
       
        delete newHistory;
        newHistory = nullptr;
    }
    
    return newHistory;
}

Transaction* TransactionFactory::CreateReturn(stringstream& str) // DONE
{
    Transaction* newReturn = new Return();

    newReturn->setCommandType(CommandType::return_);
    
    if (!newReturn->setData(str)) {
        
        delete newReturn;
        newReturn = nullptr;
    }

    return newReturn;
}

Transaction* TransactionFactory::CreateBorrow(stringstream& str) // DONE
{
    Transaction* newBorrow = new Borrow(); // Should be getting deleted in Transaction::Process(...)
    
    newBorrow->setCommandType(CommandType::borrow);
    
    if (!newBorrow->setData(str)) {
        
        delete newBorrow;
        newBorrow = nullptr;
    }
    
    return newBorrow;
}
