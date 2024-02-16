#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    
    // insertion
    //1.
    unordered_map<string,int>m;
    pair<string,int>p = make_pair("ravi",1);
    m.insert(p);

     //2.
    pair<string,int>pair2("ravi",2);
    m.insert(pair2);

    //3.
    m["ravi"] = 3;
    m["ravi"] = 4;

    // searching
    cout<<m["ravi"]<<endl;
    cout<<m.at("ravi")<<endl;

    //IMP
//    cout<<m.at("unknownkey")<<endl;
   // give error because entry is not made in map
    cout<<m["unknownkey"]<<endl;  // if entry in not present then this type
    // access make a entry 
    // but second access give error if we choose first this method
    // because this type access does not create a key for new element
    cout<<m.at("unknownkey")<<endl;

    cout<<m.size()<<endl;

    cout<<m.count("bro")<<endl;//give number of entry
    
    cout<<m.count("ravi")<<endl;
    // m.erase("ravi");
    cout<<m.count("ravi")<<endl;


     for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
     }

     //iterator

     unordered_map<string,int>::iterator it = m.begin();

     while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
     }

     cout<<m.size()<<endl;

}


/*

1.Hash Value
2.Hash Function
3.Hash Table

 eg.Hash value 683%10 = 3 ---> if %10 is hash function
 // then 3 is hash value

Hash Function
1. Divison Method   eg.k%m
2.mid square  eg. k = 60  then k^2 = 3600 then 60 index allocate to 60

3.Digit Folding Method  k1k2k3k4k5    k1k2+k3k4+k5  --> like this


HashMap Collisions

Method to handel collision
1.open hashing(close addressing)
(i)seprate chaining --> drow back (some bucket is empty) && if all value same hash value then searching time co
//complexity became O(n)
2.closed hashing
(i)Linear Probing  --> drow back = culstring  h(k) = (k+i)%m

(ii)Quadratic Probing -->  h(k) = (k+i^2)%m  0<=i<=M  M--> size of hash map

(iii) Double Hashing  --->  (h1(k)+ih2(k))



Load Factor  = (n/m)  where n = no of element  && m = no of bucket
general value of load factor is 0.75



*/