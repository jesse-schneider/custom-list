class list {
   public:
        list();
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

    private:
        int size; 
        int *arr = new int[size];

};
