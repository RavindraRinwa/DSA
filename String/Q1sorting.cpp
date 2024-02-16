#include<iostream>
// #include<string>
using namespace std;

int partionAlgo(string &s,int first,int last){

    int i = first-1,j = first;
    for(;j<last;j++){
        if(s[j]<s[last]){
            i++;
            swap(s[j],s[i]);
        }
    }
    i++;
    swap(s[i],s[last]);
    return i;

}
void QuickSortString(string &s,int first,int last){
       if(first>last){
           return ;
        }
        else{
           int  pi = partionAlgo(s,first,last);
           QuickSortString(s,first,pi-1);
           QuickSortString(s,pi+1,last);
        }
}
int main(){
    string s = "ravindrarinwa";
    int first = 0;
    int end = s.size()-1;
    QuickSortString(s,first,end);

    cout<<s;
}