#include <iostream>
#include <stddef.h>
#include "linkedList.h"

using namespace std;

int main(){
    LinkedList<int> list;
    list.push(4);
    list.push(42);
    list.push(3);
    list.push(56);
    list.push(48);
    list.push(4);
    list.append(6);
    list.append(32);
    list.append(61);
    list.append(27);
    list.insertItem(100, list.length()); 
    list.print();

    list.deleteItem(2);
    list.print();

    for (size_t i = 0; i < list.length(); i++){
        int item;
        list.getNTH(i, item);
        cout << item << ", ";
    }
    cout << endl;  
    cout << endl;

    list.count(4);
    cout << endl;


    Node<int>* newNode = new Node<int>(5, NULL);
    list.sortedInsert(newNode);
    cout << "SortedInsert: "<< endl;
    list.print();
    cout << endl;

    cout << "Remove duplicates: "<< endl;
    list.removeDuplicates();
    list.print();
    cout << endl;

    list.reverse();
    cout << "Reverse: "<< endl;
    list.print();
    cout << endl;

    list.deleteList();
    cout << "Delete list: "<< endl;
    list.print();
    

    return 0;

}