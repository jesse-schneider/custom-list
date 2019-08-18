class list {
   public:
        list();
        list(int pSize);
        list(list const & that);
        list(list && that) noexcept;
        list & operator = (list const & that);
        list & operator = (list && that) noexcept;
        ~list();
        int getSize();
        void setSize(int size);
        bool getSorted();
        void setSorted(bool sorted);
        int getIndex();
        void setIndex(int index);
        void extend();
        void shrink();
        void insert(int number);
        bool remove(int number);
        void sort();
        void unsort();
        int search(int number);
        void display();
        
    private:
        int size;
        int *arr = new int[size];
        bool sorted;
        int index;
};