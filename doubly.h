#ifndef DOUBLY_H
#define DOUBLY_H


class doubly{

    public:
        doubly();
        virtual ~doubly();
        doubly* insert_front(doubly* front);
        doubly* insert_back(doubly* front);
        void showList(doubly* front);

        int menu();
    protected:
    private:
        doubly* prev;
        doubly* next;
        int data;
};

#endif // DOUBLY_H

