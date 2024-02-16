// binding  of methods & variables together into a single unit --> [class]
// how ?   --> data is only accessible from the class methods
// also leade to data abstraction / hiding .
// class -> Abstract data type(ADT)
#include<iostream>
using namespace std;

class ABC{
    int x;
    public:
    void set(int n){x = n;}

     int get(){return x;}
};
int main(){
    ABC obj1;
    obj1.set(3);
    cout<<obj1.get()<<endl;
}