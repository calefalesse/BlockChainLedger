// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <chrono>
#include "Block.h"

int Block::count = -1;
// Constructor 
Block::Block(std::string data, std::string prevHash1){
    m_data = data; 
    m_next = NULL;
    m_prev = NULL;
    time = getTime();
    index = Block::count + 1;
    ++Block::count;
    prevHash = prevHash1;
    currHash = computeHash();
}

Block::Block(int index, std::string time, std::string data, std::string currHash1, std::string prevHash1){
    index = index;
    time = time;
    m_data = data; 
    currHash = currHash1;
    prevHash = prevHash1;
}

// Destructor
Block::~Block(){
    m_next = NULL;
    m_prev = NULL;
}

// get time stamp
std::string Block::getTime(){
    time_t t = std::time(0);   
    std::string timestamp = ctime(&t);

    /* CODE GIVEN FROM DR.EEL */
    // Remove the trailing newline character if present.
    if (!timestamp.empty() && timestamp[timestamp.size()-1] == '\n') {
        timestamp.erase(timestamp.size()-1);
    }
    /* CODE GIVEN FROM DR.EEL */
    return timestamp;
}

std::string Block::computeHash(){
    std::string contents = std::to_string(index) + time + m_data + prevHash;
    int sum = 0;

    // convert string to ASCII value and sum 
    for (char c : contents) {
        sum += (int)c;
    }
    // std::cout << "Computed hash: " << intToHexStream(sum) << std::endl; 
    return intToHexStream(sum);
}

/* CODE GIVEN FROM PA4 SPEC */
std::string Block::intToHexStream(int num) {
    std::stringstream ss;
    ss << std::hex << num;
    return ss.str();
}
/* END OF CODE GIVEN FROM PA4 SPEC */
