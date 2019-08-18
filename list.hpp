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
        void extend();
        void shrink();
        void insert(int number);
        void remove();
        void sort();
        void unsort();
        void search();
        void display();
        
    private:
        int size; 
        int *arr = new int[size];
        bool sorted;
        int index;
};