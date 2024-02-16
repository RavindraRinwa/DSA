#include<iostream>
using namespace std;

void CountSort(string s){
     int freq[26] = {0}; // not forget to intialize to zero
     int n = s.size();
     //step 1
     for(int i = 0;i<n;i++){
         freq[s[i]-'a']++;
     }

     //step 2
     for(int i = 1;i<26;i++){ // have patience and think at ans each point
         freq[i]+=freq[i-1];
     }
 
     //step 3
     char ans[26]; // not string array is a character array
     for(int i = n-1;i>=0;i--){
         ans[--freq[s[i]-'a']]=s[i];
     }
     for(int i = 0;i<n;i++){
        cout<<ans[i];
     }
}
int main(){
   string s = "ravindrarinwa";
   CountSort(s);
   return 0;
}