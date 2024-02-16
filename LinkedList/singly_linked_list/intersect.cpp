#include<iostream>
#include<list>
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

int getlength(Node*head){
    Node*temp = head;
    int length = 0;
    while(temp!=NULL){
        temp = temp->next;
        length++;
     }
     return length;
}

Node* checkintersect(Node*head,Node*head2){
    //  length of list
    int l1 = getlength(head);
    int l2 = getlength(head2);

    int diff = l1>l2? l1-l2:l2-l1;
    bool flag = l1>l2? 1:0;


    if(flag){
        Node*temp = head;
        int count = 0;
        while(count!=diff){
           temp = temp->next;
           count++;
        }
         Node*ptr1 = temp;Node*ptr2 = head2;
       while(ptr1!=NULL && ptr2!=NULL && ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
       if(ptr1==ptr2){
           cout<<"Yes";
       }
       else{
           cout<<"No";
       }
    }
    else{
        Node*temp = head2;
        int count = 0;
        while(count!=diff){
           temp = temp->next;
           count++;
        } 

        Node*ptr2 = temp;Node*ptr1 = head;
       while(ptr1!=NULL && ptr2!=NULL && ptr1!=ptr2){
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
       if(ptr1==ptr2){
           cout<<"Yes";
       }
       else{
           cout<<"No";
       }
    }
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
    insert(head2,10);
    insert(head2,11);
    head2->next->next = head->next->next->next;

    checkintersect(head,head2);

}
