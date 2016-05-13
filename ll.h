#ifndef LL_H
#define LL_H

class Node{
    public:
        Node(char* name,int age);
        Node();
        int menu();
        Node* add(Node* myList);
        Node* deleteNode(Node* myList);
        void showList(Node* myList);

        ///addLetter
        Node(char letter);
        Node* addLetter(Node* myList);
        void showLetterList(Node* myList);
        ///delete a duplicate the appear one time, not all
        Node* deleteLetter(Node* myList);
        ///delete all duplicate in ll
        Node* deleteAllDupliLetter(Node* myList);

    private:
        Node* next;
        int age;
        char* name;
        char letter;

};

class ll
{
    public:
        ll();
        virtual ~ll();
    protected:
    private:

};

#endif // LL_H

