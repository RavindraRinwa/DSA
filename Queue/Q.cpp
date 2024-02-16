#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr,int k,int n){
     
     deque<int>maxi;
     deque<int>mini;
     int ans = 0;
     mini.push_back(0);
     maxi.push_back(0);

     for(int i = 0;i<k;i++){
         
         while(!maxi.empty() && arr[maxi.front()]<=arr[i]){
            maxi.pop_front();
           
         }

         while(!mini.empty() && arr[mini.front()]>=arr[i]){
             mini.pop_front(); 
             
         }
         mini.push_back(i);
         maxi.push_back(i);
        
     }

     ans+=arr[maxi.front()]+arr[mini.front()];

     for(int i = k;i<n;i++){

        // removal
        while(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }

        while(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }

       // addition
        while(!maxi.empty() && arr[maxi.front()]<=arr[i]){
            maxi.pop_front();
            
         }
         while(!mini.empty() && arr[mini.front()]>=arr[i]){
             mini.pop_front();
         }

         maxi.push_back(i);
         mini.push_back(i);

         ans+=arr[maxi.front()]+arr[mini.front()];

     }
 
   return ans;

}


int main(){
   
   int arr[] = {2,5,-1,-7,-3,-1,-2};
   int k = 4;
   cout<<solve(arr,k,7)<<endl;
}