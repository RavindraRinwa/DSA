#include<iostream>
#include<vector>
using namespace std;

void TargetSum(vector<int>v,int x){
       int count = 0;
       int start = 0,end = v.size()-1;
       while(start<end){
          if(v[start]+v[end]==x){
            count++;
            start++;
            end--;
            continue;
          }
          else if(v[start]+v[end]<x){
            start++;
          }
          else{
             end--;
          }
       }
       
       cout<<count;
}

int main(){
    int n,ele,x;
    cin>>n;
    
    vector<int>v;

    for(int i = 0;i<n;i++){
        cin>>ele;
        v.push_back(ele);
    }
    
    cout<<"Enter the value of x:";
    cin>>x;

    TargetSum(v,x);
}