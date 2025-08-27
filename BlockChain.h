// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H
#include "Block.h"


class BlockChain{
    public:
        BlockChain();
        ~BlockChain();
        int size();
        bool isEmpty();
        void addBlock(std::string data); // add back
        bool validate();
        void deleteList();
        std::string display(std::string fileName);


        Block* m_front;
        Block* m_back;
        int m_size;

};

#endif
