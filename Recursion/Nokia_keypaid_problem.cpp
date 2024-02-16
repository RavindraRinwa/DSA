#include<iostream>
#include<vector>
using namespace std;
void CombineFunction(string*str,string &s, vector<string>&li,string result,int idx){
     if(idx==s.length()){
         return li.push_back(result) ;
     }
     else{
        int digit = s[idx]-'0';
        for(int i = 0;i<str[digit].length();i++){
           CombineFunction(str,s,li,result+str[digit][i],idx+1);
        }
     }
}
int main(){
    string str[10] = {"","" ,"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string s = "23";
    vector<string>li;
    int n =2;
    CombineFunction(str,s,li," ",0); 

    for(int i = 0;i<li.size();i++){
        cout<<li[i]<<" ";
    }
}