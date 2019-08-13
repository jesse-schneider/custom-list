#include "list.hpp"

list::list() : size{8}, arr{new int[size]}
{
}

list(list const & that);
list(list && that) noexcept;
list & operator = (list const & that);
list & operator = (list && that) noexcept;
~list();

void extend();
void shrink();
void insert();
void remove();
void sort();
void unsort();
void search();
void display();