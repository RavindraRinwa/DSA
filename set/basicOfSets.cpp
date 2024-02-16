// STL container use to store unique value
// value stored in ordered state(increasing order ,decreasing order)
// no indexing 
// elements are identify by own value
// once the value of element stored in set then they can't modify in set


// Advantage of Set
// 1.to store unique values
// 2. ordered store
// 3. dynamic Size
// 4. insertion deletion and Searching in O(log(n)) time complexity
// search implemention by binary search


// Disadvantages
//1.cannot access elements using indexing
//2.more memory than array
//3.not suitable of large data set because insertion and deletion in O(log(n)) time complexity

// declaration of set
//#include<set>
// set<data-type>set-name
// set<int>set1 = {1,2,3,0}


// bydeafult --> stored in increasing mannar
//set<data-type,greater>set-name;
// greater is key word use to store element in decaresing order

#include<iostream>
#include<set>
using namespace std;

int main(){

    set<int>s;

    s.insert(2);
    s.insert(8);
    s.insert(3);

    cout<<s.size()<<endl;

    // iterator for traversal set
    // set-name.begin()--> iterator pointing to first element of
    //set
    //set-name.end() --> iterator pointing to position after the last element is true statement

    set<int>::iterator it;

    for(it = s.begin();it!=s.end();it++){  // it<s.end() can not use
        cout<<*it<<" ";
     }

   // deleting element form starting position
   // set-name.erase(3);
   // set-name.erase(pos);
   // set-name.erase(staring pos,end pos)  -->including first position
   // but excluding last position

     // find(value) -->if present then return the value of iterator which point
     // to element otherwise return end iterator

     if(s.find(8)!=s.end()){
         cout<<"Present Ravindra";
     }
     else{
        cout<<"Appacent";
     }
