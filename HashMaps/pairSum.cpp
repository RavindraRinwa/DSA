#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
int main(){


  unordered_map<int,int>ans;

    int n;
    cout<<"Enter the size of array:";
    cin>>n;
    cout<<"Enter the number:";
    
    int s[n];

    for(int i = 0;i<n;i++){
        cin>>s[i];
    }

    int target;
    cout<<"Enter the value of target:";
    cin>>target;
//mapping
    for(int i = 0;i<n;i++){
        ans[s[i]] = i;
    }

     vector<int>res;

    for(int i = 0;i<n;i++){
        int diff = target-s[i];
        if(ans.find(diff)!=ans.end()){
            cout<<i<<" "<<ans[diff]<<" ";
            return 0;
        }
    }

    cout<<"-1";
    return 0;
}