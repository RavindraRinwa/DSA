#include<iostream>
#include<stack>
using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
       this->size = size;
       arr = new int[size];
       top = -1;
    }

    void push(int val){
        if(size-top>1){
            top++;
            arr[top] = val;
        }
        else{
            cout<<"The is fully field";
            return ;
        }
        
    }

    void pop(){
         if(top==-1){
            cout<<"The stack is empty";
            return ;
         }
         top--;
    }

    bool isempty(){
        if(top==-1){
            return true;
        }
        return false;
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            cout<<"The stack is empty";
            return -1;
        }
    }


};

int main(){
//    stack<int>s;
//    s.push(2);
//    s.push(3);

//    cout<<"printing top element:"<<s.top();

//    Stack st(5);
   Stack st = Stack(5);
   st.push(1);
   st.push(2);
   st.push(3);
   cout<<st.peek()<<endl;
   st.pop();
   cout<<st.isempty()<<endl;
   cout<<st.peek()<<endl;




   return 0;
}