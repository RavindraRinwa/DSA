// a class inherits propeities of another class 
// A----->B  A called parent or super class   B called child or sub class

// public  data and functions they can be accessed every in program

// protectdf  they are accessible in own class , parent class, derived class

// private   they are accessible only in own class


#include<iostream>
using namespace std;
class parent{
    public:
    int x;

    protected:
    int y;

    private:
    int z;
};

class child1:public parent {   // inheritance of parent class
        //  only z is not accessible
};

class child2:private parent{
    // x will be private
    // y will be protected
    // z will be private
};

class child3:protected parent{
    // x will be protected  
    // y will be protected
    // z will be private
};
int main(){

    parent p;
    p.x;
}