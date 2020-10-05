#ifndef _likedList_
#define _likedList_
#include <stddef.h>
#include <iostream>

using namespace std;
template<class T>
class Node{
    private:
    T val;
    Node<T> *next;

    public:
    ~Node<T>(){};
    Node<T>(T pVal, Node<T> *pNext){
        val=pVal;
        next=pNext;
    };

    T get_val(){return val;};
    void set_val(T pVal){val=pVal;};
    Node<T> *get_next(){return next;};
    void set_next(Node<T> *pNext){next=pNext;};

};

template<class T>
class LinkedList{
    protected:
    Node<T> *head; //el primer nodo de la lista

    public:
    ~LinkedList(){
        //tiene que ir nodo por nodo y eliminar su memoria.
    };
    LinkedList(){
        head=NULL;
    };
    //calcula la longitud de la lista
    int length(){ 
        int length=0;
        Node<T> *ptr = head;
        while(ptr != NULL){
            length++;
            ptr=ptr->get_next();
        }

        return length;
    };

    void print(){
        Node<T> *ptr=head;
        while(ptr != NULL){
            cout <<ptr->get_val() << ", ";
            ptr=ptr->get_next();
        }
        cout << endl;
    }


    //añadir un nodo al principio. Empuja a head
    void push(T pVal){
        Node<T> *node = new Node<T>(pVal,head);
        head=node;

    };
    
    //añadir nodo al final
    void append(T pVal){
        Node<T> *ptr= head;
        while(ptr->get_next() != NULL){
            ptr=ptr->get_next();
        }
        Node<T> *node = new Node<T>(pVal,NULL);
        ptr->set_next(node);
    };

    //añadir nodo entre dos nodos
    int insertItem(T pVal, int index){
        if(index > length() ){
            return -1;
        }
        if (index < 0){
            return -2;
        }
        if(index ==0){
            push(pVal);
            return 1;
        }

        int i=0;
        Node<T> *ptr=head;
        Node<T> *pre=NULL;
        while(ptr != NULL && index > i){
            pre=ptr;
            ptr=ptr->get_next();
            i++;
        }
        Node<T> *node= new Node<T>(pVal, ptr);
        pre->set_next(node);
        return 1;

    };

    //indica si la lista está vacía
    bool is_empty(){

        return head== NULL ? true : false;
    }


    int deleteItem(int index){
        if (is_empty()){
            return -1;
        }
        if(index>=length()){
            return -2;
        }
        if(index < 0){
            return -3;
        }
        if (index==0){
            Node<T> *temp=head;
            head=head->get_next();
            delete temp;
            return 1;
        }

        int i=0;
        Node<T> *ptr=head;
        Node<T> *pre= NULL;
        while (ptr->get_next() != NULL && index > i){
            pre=ptr;
            ptr=ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
        return 1;

    };


    int getNTH(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;
            
        int i = 0;
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && index > i)
        {
            ptr = ptr->get_next();
            i++;
        }
        item = ptr->get_val();
        return 1;
    };

    int count(T searchFor){
        int length=0;
        int counter=0;
        Node<T> *ptr = head;
        while(ptr != NULL){
            if (ptr->get_val()==searchFor){
                counter ++;
            }
            length++;
            ptr=ptr->get_next();
        }
        cout << "El número " <<searchFor << " aparece " << counter << " veces" << endl;
        return counter;
    };

    void deleteList(){
        Node<T> *ptr = head;
        Node<T> *last_ptr = NULL;
        while (ptr->get_next() != NULL){
            last_ptr = ptr;
            ptr = ptr->get_next();
            delete last_ptr;
        }
        // lista vacía
        if (ptr != NULL){
            delete ptr;
        }
        head = NULL;
    };



    void sortedInsert(Node<T> *newNode){
        if(head == NULL){
            head = newNode;
        }
        else if(head->get_val() >= newNode->get_val()){
            newNode->set_next(head);
            head = newNode;
        }
        else{
            Node<T> *ptr = head;
            Node<T> *last_ptr = NULL;
            while (ptr->get_next() != NULL){
                if(ptr->get_val() >= newNode->get_val()){
                    last_ptr->set_next(newNode);
                    newNode->set_next(ptr);
                    return;
                }
                last_ptr = ptr;
                ptr = ptr->get_next();
            }
        }
    }

   void removeDuplicates(){
       int i=0;
       Node<T> *ptr = head;
       Node<T> *last_ptr = head;
       while (ptr != NULL){
           if(last_ptr->get_val() == ptr->get_val()){
               last_ptr = ptr;
               deleteItem(i);
           }
           ptr = ptr->get_next();
           i++;
       }
   }


    void reverse(){
        if(head == NULL){
            return;
        }
        Node<T> *ptr = head->get_next();
        Node<T> *last_ptr = head;
        while (ptr != NULL) {
            last_ptr->set_next(ptr->get_next());
            ptr->set_next(head);
            head = ptr;
            ptr = last_ptr->get_next();
        }
    }

};

#endif