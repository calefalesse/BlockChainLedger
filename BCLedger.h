// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#ifndef BCLEDGER_H
#define BCLEDGER_H
#include <fstream>
#include <iostream>
#include <string>
#include "BlockChain.h"

class BCLedger{
    public:
        void saveToFile(BlockChain* chain, std::string fileName);
        void loadFromFile(BlockChain* chain, std::string fileName);
        void logMessage(std::string message, std::string fileName);
};


#endif 