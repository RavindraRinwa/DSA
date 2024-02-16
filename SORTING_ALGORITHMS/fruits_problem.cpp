#include<iostream>
using namespace std;
void SortByLexo(string *str,int n){

     for(int i = 0;i<n-1;i++){  
        int k = 0; bool flag = false;  
         for(int j = 0;j<n-1-i;j++){
              
            if(str[j][k]>str[j+1][k]){  // strcmp
                 string temp = str[j];
                 str[j] = str[j+1];
                 str[j+1] = temp;
                 flag = true;
                  k = 0;
                 continue;
            }

             if(str[j][k]==str[j+1][k]){
                  k++;
                  j--;
             }
         }
         if(flag==false){break;}
     }
}

int main(){
   string str[7] = {"Aaple","Aapgo","Banana","Payaya","Watermelon","Lime","Kiwi"};
   SortByLexo(str,7);
   for(int i = 0;i<7;i++){
        cout<<str[i]<<" ";
   }
}