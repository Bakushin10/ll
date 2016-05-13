#include "ll.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

Node::Node(char* name,int age){

   // name = new char[25];
    this->name = name;
    this->age =age;
}

Node::Node(char letter){
    this->letter = letter;
}

Node::Node(){

}

int Node::menu(){

    int choice;
    cout<<"1.add \n";
    cout<<"2. delete\n";
    cout<<"3. close\n";
    cout<<":";
    cin >>choice;

    return choice;

}

Node* Node::add(Node* head){

    Node* temp = NULL;
    char* name = new char[25];
    int Myage = 0;

    cout<<"enter a name : ";
    cin >> name;
    cout<<"enter your age : ";
    cin>> Myage;

    ///create new node
    Node* newNode = new Node(name,Myage);


    ///if head is NULL(first time)
    if(head == NULL){
        cout<<"head is null\n";
         return newNode;
    }
    else{
    ///if there is any node in the list
        temp = head;
        cout<<"head is NOT null\n";
        while(temp->next != NULL){
                temp = temp->next;
        }
        temp->next = newNode;
        return head;
    }

}//end of add

void Node::showList(Node* myList){

    int i=1;
    Node* temp = myList;
    cout<<"\n\n";

    if(myList == NULL){
        cout<<"Nothing in the lsit\n";
        return;
    }
    while(temp != NULL) {
        cout<<i<<". "<<"Name :"<<temp->name<<" age: " << temp->age<<endl;
        temp = temp->next;
        i++;
    }
    cout<<"\n";
}

Node* Node::deleteNode(Node* myList){

    Node* delNode = 0;
    Node* temp = myList;
    char* delName = new char[25];

    cout<<"Enter name to delete: ";
    cin >> delName;

    ///when there is at least one node in the node
    if(myList != NULL){

        if(strcmp(myList->name,delName) == 0){
            delNode = temp->next;
            delete(temp);
            return delNode;
        }

        while(temp->next != NULL){

            if(strcmp(temp->next->name,delName) == 0){
                delNode = temp->next;
                temp->next = temp->next->next;
                delete (delNode);
                return myList;
            }

            temp = temp->next;
        }
    }

    ///when node is empty
    return myList;
}


////
void Node::showLetterList(Node* myList){

    int i=1;
    Node* temp = myList;
    cout<<"\n\n";

    if(myList == NULL){
        cout<<"Nothing in the lsit\n";
        return;
    }
    while(temp != NULL) {
        cout<<temp->letter;
        temp = temp->next;
        i++;
    }
    cout<<"\n";
}

Node* Node::addLetter(Node* myList){

    char letter;
    cout<<"enter a letter (a-z)";
    cin >> letter;

    Node* pNew = new Node(letter);
    Node* iter = 0;

    if(myList == NULL)
        return pNew;

    iter = myList;

    while(iter->next != NULL){
        iter= iter->next;
    }
    iter->next = pNew;

    return myList;
}


Node* Node::deleteAllDupliLetter(Node* myList){

    int* abc = new int[27];
    Node* iter = 0;
    iter = myList;

    for(int i=0;i<27;i++){
        abc[i] = 0;
    }
    while(iter != NULL){
        int num = iter->letter -'a';
        abc[num]++;
        iter = iter->next;
    }


    if(myList == NULL){
        return myList;
    }
    ///as long as first node needs to be deleted, first is true
    bool first = true;
    int num = myList->letter-'a';

    ///takes care of when first one nedds to be deleted
    while(first){
        if(abc[num]>1 && myList->next != NULL){
            myList = myList->next;
            num = myList->letter-'a';
            continue;
        }
            first = false;
    }

    ///takes care of anything between first node and last node
    iter = myList;
    while(iter->next!=NULL){
        num = iter->next->letter -'a';
        if(abc[num]>1){
            iter->next = iter->next->next;
            cout<<"skip\n";
            continue;
        }
            iter= iter->next;
    }

    ///takes care of the last node
    num = iter->letter-'a';
    if(abc[num]>1){
        Node* del = iter;
        del = iter->next;
        myList = del;
        delete(iter);
    }

    cout<<"\n";
    Node* savelist = myList; /// save the head of the list
    cout<<"delete all dupulicates\n";
    while(myList != NULL){
        cout<<myList->letter<<"-> ";
        myList= myList->next;
    }

    return savelist;
}//end of deletelettr2

Node* Node::deleteLetter(Node* myList){

    ///keep track of duplicate
    int* abc = new int[27];
    Node* iter = 0;

    for(int i=0;i<27;i++){
        abc[i] = 0;
    }

    if(myList == NULL)
        return myList;

    iter = myList;

    while(iter != NULL){
        int num = iter->letter -'a';
        abc[num]++;
        iter = iter->next;
    }

    iter = myList;
    bool first = true;
    int num;

    Node* current = myList;

    while(current != NULL){
        Node* runner = current;
        while(runner->next != NULL){
            if(runner->next->letter == current->letter){
                runner->next = runner->next->next;
            }else{
                runner = runner->next;
            }
        }
        current = current->next;
    }

    return myList;
}//end of deleteLetter

ll::ll(){
    //ctor
}

ll::~ll()
{
    //dtor
}



