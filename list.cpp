#include "list.hpp"
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>

//default ctor
list::list() : size{8}, arr{new int[size]}, sorted{false}, index{0} { }

//parameterised ctor
list::list(int pSize) : size{pSize}, arr{new int[pSize]}, sorted{false}, index{0} { }

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

//getters and setters
int list::getSize() { return size; }
void list::setSize(int size)  { this->size = size; }
bool list::getSorted() { return sorted; }
void list::setSorted(bool sorted) { this->sorted = sorted; }
int list::getIndex() { return index; }
void list::setIndex(int index) { this->index = index; }


//Other class methods
void list::extend()
{
    int newLen = getSize() * 2;
    int *newArr = new int [newLen];

    for(int i = 0; i < getSize(); i++)
    {
        newArr[i] = arr[i];
    }
    arr = newArr;
    setSize(newLen);   
}

void list::shrink()
{
    int shrinkCheck = getSize()/2;
    
    if(arr[shrinkCheck] != 0)
    {
        std::cerr << "Array is currently too small to shrink" << std::endl;
        return;
    }

    int newLen = getSize()/2;
    int *newArr = new int [newLen];

    for(int i = 0; arr[i] != 0; i++)
    {
        newArr[i] = arr[i];
    }
    arr = newArr;
    setSize(newLen); 
}

void list::insert(int number)
{
    if(getIndex() >= size)
    {
        std::cout << "list is full! cannot perform insert" << std::endl;
        return;
    }

    if(getSorted() == false)
    {
        arr[getIndex()] = number;
        setIndex(getIndex()+1);
    }

    if(sorted == true)
    {
        for(int i = getIndex()-1; i >= 0; i--)
        {
            arr[i+1] = arr[i];

            if(arr[i] < number)
            {
                arr[i] = number;
                break;
            }
        }
    }
}

bool list::remove(int number)
{
    int ind = list::search(number);
    if (ind == getSize())
    {
        std::cout << "integer: " << number <<  " not found" << std::endl;
        return false;
    }

    if(getSorted() == true)
    {
        while(arr[ind] != '\0')
            {
                arr[ind] = arr[ind+1];
                ind++;
            }
    }
    else if(getSorted() == false)
    {
        arr[ind] = arr[getIndex()-1];
        arr[getIndex()-1] = 0;
    }
    std::cout << "integer: " << number <<  " removed from list" << std::endl;
    setIndex(getIndex()-1);
    return true;
}

void list::sort()
{
    setSorted(true);
    std::sort(arr, arr + getIndex());
    std::cout << "list sorted!" << std::endl;
}


void list::unsort()
{
    int temp;
    setSorted(false);
    for(int i = 0; i < getIndex()+1; i++)
    {
        int newInd = rand() % getIndex() + 1;
        temp = arr[i];
        arr[i] = arr[newInd];
        arr[newInd] = temp;
    }
    std::cout << "list unsorted!" << std::endl;
}

int list::search(int number)
{
    if(getSorted() == true)
    {
        int ind = getIndex();
        int left = 0, right = getIndex(), mid;

        //binary search
        while(left <= right)
        {
            mid = (left + right) / 2;

            if(arr[mid] == number)
            {
                return mid;
            }
            //ignore the left half
            if(arr[mid] < number)
            {
               left = mid + 1;
            }
            //ignore the right half
            else if(arr[mid] > number)
            {

                right = mid - 1;
            }
        }
    }

    if(getSorted() == false)
    {
        for(int i = 0; i < getSize(); i++)
        {
            if(number == arr[i])
            {
                return i;
            }
        }
    }
    return getSize();
}

void list::display()
{
    std::cout << "Number of integers: " << getIndex() << std::endl;
    for(int i = 0; i < getSize(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}