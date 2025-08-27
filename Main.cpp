// Calef Alesse
// Student ID: 2439923
// calesse@chapman.edu
// CPSC 350- 03
// PA04 Block Chain

#include <iostream>
#include "BlockChain.h"
#include "BCLedger.h"

namespace BCPrint{

    static int BCPrint(){

        // objects 
        BlockChain blockChain;
        BCLedger ledger;

        // local variables
        int choice;
        std::string fileName;

        std::string menu = 
            "\nMenu:\n"
            "1. Add a New Block\n"
            "2. Display the Blockchain\n"
            "3. Validate the Blockchain\n"
            "4. Save Blockchain to File\n"
            "5. Load Blockchain from File\n"
            "6. Exit\n"
            "\nEnter your choice: ";

        do{

        std::cout << menu << std::endl;
        std::cin >> choice;
        std::cin.ignore(1,'\n');


            switch (choice) {
                // add block
                case 1: {
                    std::string newData;
                    std::cout << "Enter data: " << std::endl;
                    std::getline(std::cin, newData);

                    blockChain.addBlock(newData);
                    break;
                }
                // display blockchain
                case 2: {
                    std::string output = blockChain.display(fileName); 
                    std::cout << "\nBlockchain State \n" << output;
                    break;
                }
                // validate blockchain
                case 3: {
                    blockChain.validate();
                    break;
                }
                // save blockchain to file
                case 4: {
                    std::cout << "Enter filename to save the blockchain: ";
                    std::cin >> fileName;
                    // save to file
                    ledger.saveToFile(&blockChain, fileName);
                    std::cout << "Blockchain saved to file: " << fileName << std::endl;
                    break;
                }
                // load blockchain from file
                case 5: {
                    std::cout << "\nEnter filename to load the blockchain: ";
                    std::cin >> fileName;  

                    ledger.loadFromFile(&blockChain, fileName);
                    std::cout << "Blockchain loaded from file: " << fileName << "\n" << std::endl;
                    // std::cout << "Block chain back from Main: " << blockChain.m_back->m_data << std::endl;
                    std::cout << blockChain.display(fileName) << std::endl;
                    break;
                }

                case 6: {
                    std::cout << "Exiting program." << std::endl;
                    break;
                }
                default: {
                    std::cout << "Not an option, please choose again: " << std::endl;
                    break;
                }

            }

        } while (choice != 6);
        return 0;
    }
}
int main(){
    BCPrint::BCPrint(); 
    return 0;
}

