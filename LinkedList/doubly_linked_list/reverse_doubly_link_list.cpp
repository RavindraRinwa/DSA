/*

Advantage of doubly linklist over singly linklist

1.traversal can be done in both way
2.insertion and deletion more efficient

Disadvantage

1.Extra space //tip not use when question say that you should slove in
constant
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node
{

public:
    int val;
    Node *prev;
    Node *next;

    Node(int data)
    {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

class doublyLinkedList
{

public:
    Node *head;
    Node *tail;
    doublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(int val)
    {

        Node *new_node = new Node(val);
        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return;
    }

    void insertAtend(int val)
    {
        Node *new_node = new Node(val);
        if (tail == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }
        tail->next = new_node;
        new_node->prev = tail;
        new_node->next = NULL;
        tail = new_node;
        return;
    }
   
    void display()
    {

        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << "<->";
            temp = temp->next;
        }
        cout << endl;
    }

};

void reverseDoublyLinkList(Node*&head,Node*&tail){
    Node*currptr = head;
    Node*nextptr;

    while(currptr!=NULL){
        nextptr = currptr->next;
        currptr->next = currptr->prev;
        currptr->prev = nextptr;
        currptr = nextptr;
        
    }
    Node*temp = head;
    head = tail;
    tail = head;
      
}
int main()
{

    doublyLinkedList dll;

    dll.insertAtend(1);
    dll.insertAtend(2);
    dll.insertAtend(3);
    dll.insertAtend(4);
    dll.insertAtend(5);
    dll.insertAtend(6);
    dll.insertAtend(7);

    dll.display();
    reverseDoublyLinkList(dll.head,dll.tail);
    dll.display();

    return 0;
}