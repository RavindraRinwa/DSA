/*

Advantage of doubly linklist over singly linklist

1.traversal can be done in both way
2.insertion and deletion more efficient

Disadvantage

1.Extra space // tip not use when question say that you should slove in
constant
*/
#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class Node{

    public:
    int val;
    Node*prev;
    Node*next;

    Node(int data){
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class doublyLinkedList{

    public: 
     Node*head;
     Node*tail;
     doublyLinkedList(){
         head = NULL;
         tail = NULL;
     }
    void insert(int val){

    Node*new_node = new Node(val);
    if(head==NULL){
        head = new_node;
        tail = new_node;
        return;
    }

     new_node->next = head;
     head->prev = new_node;
     head  = new_node;
     return;

}


     void insertAtend(int val){
         Node*new_node = new Node(val);
        if(tail==NULL){
            head = new_node;
            tail = new_node;
            return ;
     }
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = NULL;
        tail = new_node;
        return ;
     }

    void insertAtKthPosition(int val,int pos){

        if(pos==1){
            insert(val);
        }

       Node*new_node = new Node(val);

       if(head==NULL){
          head = new_node;
          tail = new_node;
          return;
       }
      
       Node*temp = head;
       int counter = 1;
       while(counter!=pos-1){
           counter++;
           temp = temp->next;
       }

       if(temp==tail){
          insertAtend(val);
       }

    //    temp->next = new_node; 
    //    new_node->next = temp->next->next;
    //    new_node->prev = temp;
    //    temp->next->next->prev = new_node;

    /* if we do like this then temp->next->next is missing from over range
     because of firs line */
       new_node->next = temp->next;
       temp->next->prev = new_node;
       temp->next = new_node;
       new_node->prev = temp;

       return ;

    }
    void display(){

    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"<->";
        temp = temp->next;
    }
    cout<<endl;
}

};



int main(){
    
    doublyLinkedList dll;

    dll.insert(1);
    dll.insert(2);
    dll.insert(3);
    dll.display();
    dll.insertAtend(9);
    dll.display();
    dll.insertAtKthPosition(7,2);
    dll.display();

    return 0;
}