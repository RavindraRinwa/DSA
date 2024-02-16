#include<iostream>
#include<map>
using namespace std;

int main(){
    map<string,int>phoneDirectory;
    phoneDirectory["R R"] = 63670;
    phoneDirectory["D R"] = 38974;
    phoneDirectory["R R R"] = 48335;
    

    for(auto element:phoneDirectory){
        cout<<element.first<<" "<<element.second<<" ";
    }
    // insertion time complexity O(log(n))
   return 0;
}