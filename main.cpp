#include <iostream>
#include "list.h"
#include "operation.h"
#include "my_data.h"

using namespace std;

void mainMenu();
List L;

int main() {
    createList(L);

    mainMenu();

    return 0;
}

void mainMenu() {
    address P;
    infotype X;
    /**
    * IS : List has been created
    * PR : prints menu to user
    *       1. insert new data
    *       2. print all data
    *       3. find and print a data by ID
    *       4. edit data by ID
    *       5. delete data by ID
    *       0. exit
    */
    //-------------your code here-------------
    int choice;
    bool exit = false;
    do {
        cout<<"Menu"<<endl;
        cout<<"1. insert"<<endl;
        cout<<"2. view data"<<endl;
        cout<<"3. find and view"<<endl;
        cout<<"4. find and edit"<<endl;
        cout<<"5. find and delete"<<endl;
        cout<<"0. exit"<<endl;
        cout<<"input choice: ";


        cin>>choice;
        switch(choice) {
        case 1:
            X = create_data();
            P = allocate(X);
            insertFirst(L,P);
            break;
        case 2:
            printInfo(L);
            break;
        case 3:
        if (first(L)==NULL){
            cout<<"No data"<<endl;
            break;
        }
        cout<<" Find ID : ";
        cin>>X.ID;
        P=findElm(L,X);
        if (P!=NULL){
            view_data(info(P));
        }else{
            cout<<" data not found "<<endl;
        }
            break;

        case 4:
            if (first(L)==NULL){
                cout<<" No data. "<<endl;
                break;
            }
            cout<<" Edit Your ID : ";
            cin>>X.ID;
            P = findElm(L,X);
            if (P != NULL){
                edit_data(info(P));
            }else{
                cout<<" Data not found"<<endl;
            }
                break;
        case 5:
            if (first(L)==NULL){
                cout<<" No Data Input "<<endl;
            }
                break;

         cout<<" Delete ID : ";
         cin>>X.ID;
         P = findElm(L,X);
         if(P!=NULL){
            deletebyID(L,X);
         }else{
            cout<<"Data not found"<<endl;
         }
            break;
        case 0:
            cout<<"thank you"<<endl;
            exit = true;
            break;
        }
    }while(!exit);
    }
