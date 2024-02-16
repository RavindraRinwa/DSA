#include <iostream>
using namespace std;

class Node
{

public:
    int val;
    Node *next;

    Node(int data)
    {
        val = data;
        next = NULL;
    }
};
class circularLinkList
{

public:
    Node *head;

    circularLinkList()
    {
        head = NULL;
    }

    void insertAtEnd(int val){

        Node*new_node = new Node(val);

        if(head==NULL){
            head = new_node;
            new_node->next = head;
            return;
        }
        Node*temp = head;
        while(temp->next!=head){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->next = head;
    }

    void deletionAtStart(){
          Node*temp = head;
          while(temp->next!=head){
              temp = temp->next;
          }
          head = head->next;
          temp->next = head;
    }

    void display()
    {
        Node *temp = head;
        do
        {
            cout << temp->val << "->";
            temp = temp->next;
        } while (temp != head);

        cout<<temp->val<<endl;
        cout<<endl;
    }
};

int main()
{
    circularLinkList cll;
    cll.insertAtEnd(1);
    cll.insertAtEnd(2);
    cll.insertAtEnd(3);
    cll.insertAtEnd(4);
    cll.insertAtEnd(5);
    cll.insertAtEnd(6);
    cll.display();
    cll.deletionAtStart();
    cll.display();
}