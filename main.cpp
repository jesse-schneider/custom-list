#include "list.hpp"
#include <cstdlib>
#include <iostream>

//using namespace std;

main(int argc, char * argv[])
{

list l;
list p(10);

std::cout << l.getSize() << std::endl;
std::cout << p.getSize() << std::endl;

l.insert(7);
l.insert(9);
l.insert(8);
l.insert(11);
l.insert(12);
l.display();
l.shrink();
l.extend();
l.shrink();
l.display();

}