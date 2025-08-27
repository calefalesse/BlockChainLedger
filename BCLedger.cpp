// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#include "BCLedger.h"
#include <fstream>
#include <sstream>
#include <iostream>


void BCLedger::saveToFile(BlockChain* chain, std::string fileName){
    std::ofstream file(fileName);

    if(file.is_open()){
        Block* current = chain->m_front;

        while (current!= NULL){
            // append each value to the file through current pointer
            file << current->index << "|" 
                 << current->time << "|"
                 << current->m_data << "|"
                 << current->prevHash << "|"
                 << current->currHash << "\n";
            // move to next block
            current = current->m_next;
        }

    } else {
        std::cerr << "Error opening file. " << std::endl;
        return;
    }
    file.close();

}

void BCLedger::loadFromFile(BlockChain* chain, std::string fileName){

    // clears existing chain
    chain->deleteList();
    std::ifstream loadFile(fileName);
    if (!loadFile.is_open()) {
        std::cerr << "Error: Could not open file " << fileName << "\n";
        return;
    } 

    std::string line;
    while(getline(loadFile, line)){

        // create stringstream
        std::stringstream ss(line);
        std::string value;
        // array to hold values from file
        std::string strValue[5];
        int i = 0;

        // iterate through values and save into an array
        while (getline(ss, value, '|')&& i < 5){
            strValue[i] = value;
            i++;
        }

        // extract values from array using indexing 
        int index = std::stoi(strValue[0]);
        std::string time = strValue[1];
        std::string data = strValue[2];
        std::string prevHash = strValue[3];
        std::string currHash = strValue[4];

        // create new block 
        Block* newBlock = new Block(index, time, data, currHash, prevHash);
        newBlock->time = time;
        newBlock->currHash = currHash;
        
        // Insert the new block into the chain
        if (!chain->isEmpty()) {
            newBlock->m_prev = chain->m_back;
            chain->m_back->m_next = newBlock;
        } else {
            // If chain is empty, set the new block to front of chain
            // Chain should be empty
            chain->m_front = newBlock;
        }
        chain->m_back = newBlock;  // Update the back of the chain
        chain->m_size++;  // Increment size of the chain


    }
    loadFile.close();

}


