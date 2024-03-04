#include "TransactionFactory.h"

Transaction *TransactionFactory::createTransaction(ifstream &file){
    Transaction *newTransaction = nullptr;
    char command;
    file >> command;

    if(file.fail()){
        file.clear();
        file.ignore(0, '\n');//0??
        return nullptr;
    }

    switch(command){
        case CommandType::borrow:
        newTransaction = createBorrow(file);
        break;
    
    case CommandType::return_:
        newTransaction = createReturn(file);
        break;
    
    case CommandType::history:
        newTransaction = createHistory(file);
        break;

    case CommandType::inventory:
        newTransaction = createInventory(file);
        break;

    default:       
        string entireTransaction;
        getline(file, entireTransaction, '\n');
        cerr << "Command, invalid command type '" << command << "':"
        << '\n' << "  " << command << entireTransaction << endl;
        break;
    }


    return newTransaction;
    
    
}

Transaction *TransactionFactory::createInventory(ifstream &file){
   Inventory* newInventory = new Inventory();
    return newInventory;
}

Transaction *TransactionFactory::createHistory(ifstream &file){
    History* newHistory = new History();
    newHistory->setCommandType(CommandType::history);
    if (newHistory->setHistoryData(file)) {
        return newHistory;
    }
    delete newHistory;
    return nullptr;
}

Transaction *TransactionFactory::createReturn(ifstream &file)
{
    Return* newReturn = new Return();
    newReturn->setCommandType(CommandType::return_);
    if (newReturn->setData(file)) {
        return newReturn;
    }
    delete newReturn;
    return nullptr;
}

Transaction *TransactionFactory::createBorrow(ifstream &file)
{
    Borrow * newBorrow = new Borrow();
    newBorrow->setCommandType(CommandType::borrow);
    if (newBorrow->setData(file)) {
        return newBorrow;
    }
    delete newBorrow;
    return nullptr;
}
