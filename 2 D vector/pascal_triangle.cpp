#include<iostream>
#include<vector>
using namespace std;
int factorial(int num){
    int factorial = 1;
    for(int i = num;i>0;i--){
        factorial*=i;
    }
    return factorial;
}

int main(){
int n;
cin>>n;

vector<vector<int>> ans(n);
                           // ans[i].size()  ---> i th coulume value
for(int i = 0;i<n;i++){   // ans.size()  ----> give row 
    for(int j = 0;j<=i;j++) {
       ans[i].push_back(factorial(i)/(factorial(j)*factorial(i-j)));  // this type push back intialise keep in mind
    }   
  }

for(int i = 0;i<ans.size();i++){
    for(int j = 0;j<ans[i].size();j++){
           cout<<ans[i][j]<<" ";
    }
    cout<<endl;
}
    return 0;
}

// Second Method
// if(j==0 || j==i){
//  pascal[i][j] = 1; 
// }
// else{
// pascal[i][j] = pascal[i-1][j]+pascal[i-1][j-1]; }