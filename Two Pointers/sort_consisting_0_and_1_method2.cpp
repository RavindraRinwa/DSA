#include<iostream>
#include<vector>
using namespace std;

void SortZeroesAndOnes(vector<int>&v){
 int left_ptr = 0,right_ptr = v.size()-1;

   while(left_ptr<right_ptr){
        if(v[left_ptr] == 1 && v[right_ptr] == 0){
           v[left_ptr++] = 0;
           v[right_ptr--] =1;
        }

        if(v[left_ptr]==0)
         left_ptr++;

        if(v[right_ptr] == 1)
            right_ptr--;
        
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

    SortZeroesAndOnes(v);

    for(int ele:v){
        cout<<ele<<" ";
    }
}