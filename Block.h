// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#ifndef BLOCK_H
#define BLOCK_H
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

class Block{
    public:
        Block(std::string data, std::string prevHash1);
        Block(int index, std::string time, std::string data, std::string currHash1, std::string prevHash1);
        ~Block();
        std::string m_data;
        Block* m_next;
        Block* m_prev;
        int index;
        std::string data;
        std::string prevHash;
        std::string currHash;
        // std::string time;
        std::string time;


        // tracks number of blocks "index"
        static int count;

        std::string getTime();
        std::string computeHash();
        std::string intToHexStream(int num);
};



#endif
