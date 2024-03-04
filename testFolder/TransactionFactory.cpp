#include "TransactionFactory.h"

Transaction* TransactionFactory::createTransaction(const string trans_line){ // DONE
    
    stringstream str(trans_line);
    char command;

    // Cannot support command types being more than 1 character
    str >> command;
    str.ignore(); // Space

    switch (command) {

        case CommandType::inventory:
        return createInventory(str);
        break;

        case CommandType::history: 
        return createHistory(str);
        break;

        case CommandType::borrow:
        return createBorrow(str);
        break;
        
        case CommandType::return_:
        return createReturn(str);
        break;

        default: 
        cerr << "TransactionFactory::createTransaction() | Invalid Transaction Command: " << command << endl;
        return nullptr;
        break;
    }
}

Transaction *TransactionFactory::createInventory(stringstream& str){ // DONE
   
    Transaction* newInventory = new Inventory();

    newInventory->setCommandType(CommandType::inventory);

    return newInventory;
}

Transaction *TransactionFactory::createHistory(stringstream& str){ // DONE
    
    Transaction* newHistory = new History();
    
    newHistory->setCommandType(CommandType::history);
    
    if (!newHistory->setData(str)) {
       
        delete newHistory;
        newHistory = nullptr;
    }
    
    return newHistory;
}

Transaction *TransactionFactory::createReturn(stringstream& str) // DONE
{
    Transaction* newReturn = new Return();

    newReturn->setCommandType(CommandType::return_);
    
    if (!newReturn->setData(str)) {
        
        delete newReturn;
        newReturn = nullptr;
    }

    return newReturn;
}

Transaction *TransactionFactory::createBorrow(stringstream& str) // DONE
{
    Transaction* newBorrow = new Borrow();
    
    newBorrow->setCommandType(CommandType::borrow);
    
    if (!newBorrow->setData(str)) {
        
        delete newBorrow;
        newBorrow = nullptr;
    }
    
    return newBorrow;
}
