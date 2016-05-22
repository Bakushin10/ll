#include "doubly.h"
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

doubly::doubly()
{
    //ctor
}

doubly::~doubly()
{
    //dtor
}


doubly* doubly::insert_front(doubly* front){
    int num;
    cout<<"enter a num :";
    cin >> num;

    doubly* pNew = new doubly();
    pNew->data = num;
    pNew->next=front;


    ///nothing comes before this node
    pNew->prev = NULL;

    if(front != NULL)
        front->prev = pNew;

    // Return the new front of the list.
    return pNew;
}

doubly* doubly::insert_back(doubly* front){
    int num;
    cout<<"enter a num:";
    cin >> num;

    doubly* pNew = new doubly();
    pNew->data = num;
    pNew->next = NULL;


    if(front == NULL){
        // In a doubly linked list, this means the previous pointer is to NULL.
        pNew->prev=NULL;
        return pNew;
    }else{
        doubly* iter=front;
        while(iter->next != NULL){
            iter=iter->next;
        }
        
        // Now, this needs to relink to our new first element, pNew.
        iter->next = pNew;
        pNew->prev = iter;
        return front;
    }

}

void doubly::showList(doubly* front){
    doubly* iter = front;

    while(iter != NULL){
        cout<<iter->data<<" -> ";
        iter = iter->next;
    }

        cout<<"\n\n";
}

int doubly::menu(){

    int choice;
    cout<<"1.add \n";
    cout<<"2. delete\n";
    cout<<"3. close\n";
    cout<<":";
    cin >>choice;

    return choice;

}
