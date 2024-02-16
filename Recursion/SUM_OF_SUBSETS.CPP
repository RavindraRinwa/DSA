#include<iostream>
#include<vector>
using namespace std;
int SumOfSubsets(int *arr,vector<int>&res,int n,int idx,int sum){
    if(idx==n){
        res.push_back(sum);
    }
    else{
         SumOfSubsets(arr,res,n,idx+1,sum+arr[idx]); // number when include
         SumOfSubsets(arr,res,n,idx+1,sum);// number when not include
    }
}
int main(){
    int arr[4] = {2,4,6};
    int n = 4;
    vector<int>res;
    SumOfSubsets(arr,res,n,0,0);

    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
}