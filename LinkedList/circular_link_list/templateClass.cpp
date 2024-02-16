#include<iostream>
using namespace std;

template<typename T>
class Node{  // template classs
  public:
    T val;
    Node*next;

    Node(T data){
      val = data;
      next = NULL;
    }
};

int main(){

     Node<int>*new_node = new Node <int>(3);
     cout<<new_node->val<<endl;
     Node<char>*new_head = new Node<char> ('a');
     cout<<new_head->val<<endl;

    return 0;
}