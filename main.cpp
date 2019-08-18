#include "list.hpp"
#include <cstdlib>
#include <iostream>

//using namespace std;

main(int argc, char * argv[])
{
    int length, choice, input;

    std::cout << "Enter the list size, or press 0 for default: " << std::endl;
    std::cin >> length;

    if(length == 0)
        length = 8;
  
    list l(length);
    

    while(1)
    {
    std::cout << "Select the options you would like to perfom:" << std::endl;
    std::cout << "1) insert" << std::endl;
    std::cout << "2) remove" << std::endl;
    std::cout << "3) extend" << std::endl;
    std::cout << "4) shrink" << std::endl;
    std::cout << "5) search" << std::endl;
    std::cout << "6) sort" << std::endl;
    std::cout << "7) unsort" << std::endl;
    std::cout << "8) display" << std::endl;
    std::cout << "9) quit" << std::endl;
    std::cin >> choice;

    switch(choice) {
        case 1:
            std::cout << "enter the integer to insert: " << std::endl;
            std::cin >> input;
            l.insert(input);
            break;
        case 2:
            std::cout << "enter the integer to remove" << std::endl;
            std::cin >> input;
            l.remove(input);
            break;
        case 3:
            l.extend();
            break;
        case 4:
            l.shrink();
            break;
        case 5:
            std::cout << "enter the integer to search for: " << std::endl;
            std::cin >> input;
            std::cout << input << " is located at index " << l.search(input) << std::endl;
            break;
        case 6:
            l.sort();
            break;
        case 7:
            l.unsort();
            break;
        case 8:
            l.display();
            break;
        case 9:
            return EXIT_SUCCESS;
        }   
    }
}