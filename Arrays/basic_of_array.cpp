// data structure which stroes a collection of  items(item have same data type)
// contiguous block of memory 
#include<iostream>
using namespace std;
int main(){
    char vowels[5] = {'a','e','i','o','u'};  // -> U can not use " " at any elements   
    for(char element:vowels)
        cout<<element;

    char ravi[4] ; // {"r","a","v","i"}; -> can not intialize as 
    
    // U can not take input  as 
    // for(char element:vowels)
    //  {cin>>element;} //  in element variable store a then replace a to e then replace to i and so..  
    // for storing element in vowels you take ***-> char &element 
    // now element access vowels elements
    for(char &element:ravi)
     cin>>element;
    for(char rinwa:ravi)
    cout<<rinwa<<" ";

    // for calulate size you can use sizeof(array)
}