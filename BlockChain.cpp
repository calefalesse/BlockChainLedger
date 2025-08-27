// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#include "BlockChain.h"
#include "Block.h"
#include "BCLedger.h"
#include <iostream>


// Constructor
BlockChain::BlockChain(){
    m_front = NULL; // pointing to nothing
    m_back = NULL; 
    m_size = 0;

    // int index = 0;
    std::string data = "Genesis Block";
    std::string prevHash1 = "0 ";
    
    Block* genesis = new Block(data, prevHash1);
    genesis->time = genesis->getTime();
    genesis->currHash = genesis->computeHash();

    m_front = genesis;
    m_back = genesis;
    m_size = 1;

}

// Destructor
BlockChain::~BlockChain(){
    deleteList();
}

// return size 
int BlockChain::size(){
    return m_size;
}

// check if empty
bool BlockChain::isEmpty(){
    return size() == 0;
}

// adds block to back of chain
void BlockChain::addBlock(std::string data){

    // assign old currHash and assign to prevHash
    std::string prevHash = m_back->currHash;

    Block* newBlock = new Block(data, prevHash);
    newBlock->computeHash();
    
    if (!isEmpty()) {
        newBlock->m_prev = m_back;
        m_back->m_next = newBlock;
    } else {
        m_front = newBlock;
        m_back = newBlock;
    }
    m_back = newBlock;
    ++m_size;
}

void BlockChain::deleteList(){
    while (!isEmpty()){
        // save current front 
        Block* toRemove = m_front;
        // move front to next block
        m_front = m_front->m_next;
        // delete old front 
        delete toRemove;
        BlockChain::m_size--;
    }
    m_front = NULL;
    m_back = NULL;
    m_size = 0;

}

bool BlockChain::validate(){
    // start at block 2
    Block* current = m_front->m_next;
    std::cout << "Validating blockchain... " << std::endl;

    while (current) {
        if (current->prevHash != current->m_prev->currHash) {
            std::cout << "Result: Block " << current->index << " has an invalid previous hash!\n";
            return false;
        }
        if (current->currHash != current->computeHash()) {
            std::cout << "Result: Block " << current->index << " has an invalid current hash!\n";
            return false;
        }
        // move to next block
        current = current->m_next;
    }
    // if no errors 
    std::cout<< "Result: BlockChain is valid. " << std::endl;
    return true;

}

std::string BlockChain::display(std::string fileName){
    // display the contents of block chain following this format:
    if (isEmpty()){
        std::string errorMessage = "Block Chain is empty.";
        return errorMessage;
    }

    std::string blockContents = "";

    Block* current = m_front;
    while(current != NULL){
        blockContents += 
            "\nIndex: " + std::to_string(current->index) + "\n" +
            "Timestamp: " + current->time + "\n" +
            "Data: " + current->m_data + "\n" +
            "Previous Hash: " + current->prevHash + "\n" +
            "Hash: " + current->currHash + "\n";

        current = current->m_next;
    }
    return blockContents;

}