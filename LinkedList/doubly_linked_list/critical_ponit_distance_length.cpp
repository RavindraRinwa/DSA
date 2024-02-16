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

vector<int>maxMinDistanceBWCrticalPoint(Node*head,Node*tail){
    vector<int>ans(2,-1);
    Node*currptr = tail->prev;
    int distance = 0;
    int first_distance = 0;
    int second_distance = 0;
    int last_distance = -1;
    int counter = 0;
    bool flag = true;

    while(currptr!=head){
         Node*prevptr = currptr->prev;
         Node*nextptr = currptr->next;
         
         if((prevptr->val < currptr->val && currptr->val > nextptr->val)  || (prevptr->val > currptr->val && currptr->val < nextptr->val)  ){
             last_distance = distance;
             counter++;
             if(counter==1){
               first_distance = distance;
            }
            if(counter==2){
                second_distance = distance;
            }
         }
         
         distance++;
         currptr = prevptr;
    }
    if(counter<2){
        return ans;
    }

    ans[0] = second_distance-first_distance;
    ans[1] = last_distance-first_distance;
    return ans;
}

int main()
{

    doublyLinkedList dll;

    dll.insertAtend(1);
    dll.insertAtend(5);
    dll.insertAtend(4);
    dll.insertAtend(2);
    dll.insertAtend(6);
    dll.insertAtend(3);
    // dll.insertAtend(8);
    // dll.insertAtend(4);
    dll.display();
    
    vector<int>ans = maxMinDistanceBWCrticalPoint(dll.head,dll.tail);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}