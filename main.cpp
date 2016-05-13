#include <iostream>
#include "ll.h"

using namespace std;

int main(){

    Node* myList = 0;
    Node* temp =0;
    bool valid = true;

    while(valid){
        switch(myList->menu()){
            case 1:{
             // myList = myList->add(myList);
             // myList->showList(myList);
              myList = myList->addLetter(myList);
              myList->showLetterList(myList);
                break;
            }
            case 2:{
               //myList = myList->deleteNode(myList);
               //myList->showList(myList);
               //myList = myList->deleteLetter(myList);

              myList = myList->deleteAllDupliLetter(myList);
              myList->showLetterList(myList);
                break;
            }
            case 3:{
                valid = false;
                break;
            }
        }
    }

    return 0;
}

