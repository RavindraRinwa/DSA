// class A ----> class B
#include<iostream>
using namespace std;

class parent{
    public:
    parent(){
        cout<<"Parent class"<<endl;
    }

};

class Child:public parent{
    public:
    Child(){
        cout<<"child class"<<endl;
    }
};

int main(){

   Child c;
   return 0;
}