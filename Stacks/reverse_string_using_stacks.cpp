#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s = "Ravindra";
    stack<char>st;
    for(int i = 0;i<s.size();i++){
         st.push(s[i]);
    }
    string ans = " ";
    for(int i = 0;i<s.size();i++){
        ans+=st.top();
        st.pop();
    }
    cout<<"answer: "<<ans;
}