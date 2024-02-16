#include<iostream>
#include<vector>
using namespace std;

void Running_sum(vector<int>&v){
    for(int i = 1;i<v.size();i++){
            v[i]+=v[i-1];  // v[i] = v[i]+v[i-1];
    }
         
    for(int ele:v){
        cout<<ele<<" ";
    }
}
int main(){
    int n,element;
    cin>>n;

   vector<int>v;

    for(int i = 0;i<n;i++){
        cin>>element;
        v.push_back(element);
    }

    Running_sum(v);
}