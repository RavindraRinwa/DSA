#include<iostream>
#include<vector>
using namespace std;
bool EqualSumSubVector(vector <int>&v){
    int sum_of_elements = 0,sum_of_pre_and_suf = 0,sum_of_prefix = 0;

    for(int i = 0;i<v.size();i++){
        sum_of_elements+=v[i];  
    }
    
    sum_of_pre_and_suf  = sum_of_elements/2;
    int j;
    for( j = 0;j<v.size();j++){
        sum_of_prefix+=v[j];
        if(sum_of_pre_and_suf==sum_of_prefix){
            return true;
        }
        else
        return false;
    }

}

int main(){

    int n,element;
    cin>>n;
    vector<int>v;  // vector<int>v(n+1,0)  size--->n  every element---> 0
    for(int i = 0;i<n;i++){
        cin>>element;
        v.push_back(element);
    }

    if(EqualSumSubVector(v)){
         cout<<"the suffix sum = prefix sum exit";
    }
    else{
        cout<<"No pair for suffix sum = prefix sum";
    }
}