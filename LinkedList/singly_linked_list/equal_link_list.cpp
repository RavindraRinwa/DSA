#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node*next;

    Node(int data) {
         val = data;
         next = NULL;
    }
};

class Node2{
    public:
    int val2;
    Node*next2;

    Node2(int data){
        val2 = data;
        next2 = NULL;
    }
};


void insert(Node*&head,int val){
    Node*new_node = new Node(val);
    new_node->next = head;
    head = new_node;
}


void display(Node*head){
    Node*temp = head;
    while(temp!=NULL){
        cout<<temp->val<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

bool checklinklist(Node*head,Node*head2){
    Node*ptr1 = head;
    Node*ptr2 = head2;

    while(ptr1!=NULL && ptr2!=NULL ){
        if(ptr1->val!=ptr2->val){
             return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    
   return (ptr1==NULL && ptr2==NULL);
}


int main(){

    Node*head = NULL;
    insert(head,1);
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    insert(head,7);
    insert(head,8);
    display(head);

    Node*head2 = NULL;
    insert(head2,1);
    insert(head2,2);
    insert(head2,3);
    insert(head2,4);
    insert(head2,5);
    insert(head2,6);
    insert(head2,7);
    insert(head2,8);
    display(head2);

    if(checklinklist(head,head2)){
        cout<<"The linklist are equal";
    }
    else{
        cout<<"The linklist are not equal";
    }
}
