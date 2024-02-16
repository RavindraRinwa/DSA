#include<iostream> 
#include<vector>
using namespace std;
void StringSubsequence(string &s,int n,int idx,vector<string>&str1,string res){
    
    if(idx==n){
        return str1.push_back(res);
    }
    else{
        StringSubsequence(s,n,idx+1,str1,res+s[idx]);
        StringSubsequence(s,n,idx+1,str1,res);
    }
}   
int main(){
    string s = "abc";
    vector<string>str;
    StringSubsequence(s,3,0,str,"");

    for(int i = 0;i<str.size();i++){
        cout<<str[i]<<" ";
    }
}