// function is called when object is deleted
// can not pass any parameter
// name ---> ~(class name)

#include<iostream>
using namespace std;

class Rectangle{
public:
       int l,b;

       Rectangle(){  // deafult constructure
        l = 0;b = 0;
       }

       Rectangle(int x,int y){  // parameterised constructor
              l = x; b = y;
       };

       Rectangle(Rectangle &r){// copy constructor -initialise an obj by anthor existing obj
          l  = r.l;
          b = r.b;
       };

       ~Rectangle(){   // call end of the function automaticly
         cout<<"Destructor is called";
       }
};


int main(){

    //  Rectangle r1;
    //  cout<<r1.l<<" "<<r1.b<<endl;

     Rectangle *r1 = new Rectangle();  // understate this
     cout<<r1->l<<" "<<r1->b<<endl;
     delete r1;   // only when use when you declar pointer veriable

    Rectangle r2(3,4);
    cout<<r2.l<<" "<<r2.b<<endl;


    Rectangle r3(r2);
    cout<<r3.l<<" "<<r3.b<<endl;

    return 0;
}