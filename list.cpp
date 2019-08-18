#include "list.hpp"
#include <utility>
#include <cstdlib>
#include <iostream>

//default ctor
list::list() : size{8}, arr{new int[size]}, sorted{false}, index{0} { }
//parameterised ctor
list::list(int pSize) : size{pSize}, arr{new int[pSize]}, sorted{false}, index{0}  { }
//copy ctor
list::list(list const & that) : size{that.size}, arr{new int [size]{}} { }
//move ctor
list::list(list && that) noexcept : size{std::move(that.size)}, arr{std::move(that.arr)}
{   that.arr = nullptr; }
//copy assignment
list & list::operator = (list const & that)
    {
        if(this == &that) return *this;
        if (list::size != that.size)
        { delete [] arr; size = that.size; arr = new int [size];
            for(int i = 0; i < size; i++)
            { arr[i] = that.arr[i]; }
        }
    }
 //move assignment
list & list::operator = (list && that) noexcept
{
    size = std::move(that.size); arr = std::move(that.arr);
    that.arr = nullptr;
    return *this;
}
//dtor
list::~list() { delete [] arr; }

int list::getSize() { return size; }

void list::extend()
{
    int newLen = size * 2;
    int *newArr = new int [newLen];

    for(int i = 0; i < size; i++)
    {
        newArr[i] = arr[i];
    }
    arr = newArr;
    size = newLen;   
}

void list::shrink()
{
    int shrinkCheck = size/2;
    
    if(arr[shrinkCheck] != 0)
    {
        std::cerr << "Array is currently too small to shrink" << std::endl;
    }

}

void list::insert(int number)
{
    if(sorted == false)
    {
        arr[index] = number;
        index++;
    }

    //if(sorted == true)
}

void remove();
void sort();
void unsort();
void search();
void list::display()
{
    for(int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}