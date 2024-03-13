# README

## Summary  
  
* Physical media store that allows customers to Borrow and Return media, view their checkout history and search the catalog of available movies
* Similar in concept to a Blockbuster

## Concepts Implemented  

### Polymorphism  

* Used to store the data and execute the action tailord to each movie type (EX: Classics having a 'Major Actor' and Release Month)  
* Used to store the data and execute the actions tailored to each transaction type  

### Factory Builder Design Pattern

* Used when data is passed into the system and specific movie or transaction objects need to be dynamically allocated

## System Constraints

* System can only hold a total of 103 unique customers

## System Design

![alt text](<Design-Files/Class Diagram.pdf>)  
