#include<iostream>
#include<unordered_map>
using namespace std;
int main(){

    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the Strings:";
    string s[n];
    for(int i = 0;i<n;i++){
        cin>>s[i];
    }

    // concept each element should have freq as multiple of number of string

    unordered_map<char,int> ans;

    for(auto str:s){
        for(auto c:str){
            ans[c]++;
        }
    }

    for(auto freq:ans){
        if(freq.second%n!=0){
           cout<<"NO";
           return 0;
        }
    }
    cout<<"Yes";
    return 0;
}