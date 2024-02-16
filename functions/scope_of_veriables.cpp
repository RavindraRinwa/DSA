// in find of primenumber you can use  i*i<num trick
//scope of veriables in c++
//visibility of a variables -> i.e. what all area are there from which we can access a varibals
//type of scope -> global scope
 //             ->function scope  -> local scope
 //             ->block scope  -> local scope 
 //  global scope -> varibals that are outside all blocks or functions in a program ,and they can be accesed
 // any where in the program

// ex. of global scope

#include<iostream>
using namespace std;
string name ="Ravindra Rinwa";
void fun(string){  // string name  or only  string you can use 
    cout<<name<<endl;
}
int main(){
    cout<<name<<endl;
    fun(name);
    return 0;
}

// local variables->variables that are inside a function  & block can be accessed in side it
// only they are unknown outside the block & functions

// block means { ....indside code }

// difference->
//  -> scope 
//  ->life time
//  -> data sharing
// -> stroage -> local->stack frame 
//       -> global -> secondry area 
// Q1.
// int a = 5
//int main()
// {  int a = 4 
//     cout<<a;
//     cout<<::a;}-> then a->5  :: scope revolution operator
//print a = 4 beause local varibals find then not use of global variables
// if we want to access global variables then we use ::a 