#include "list.hpp"
#include <cstdlib>
#include <iostream>

//using namespace std;

main(int argc, char * argv[])
{
    list l;

    l.insert(7);
    l.insert(9);
    l.insert(8);
    l.insert(11);
    l.insert(1);
    l.insert(12);
    l.insert(198);
    l.display();
    l.extend();
    l.display();
    l.shrink();
    l.display();
    l.sort();
    l.insert(19);
    l.remove(12);
    l.display();

}