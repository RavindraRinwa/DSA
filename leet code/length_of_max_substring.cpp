// class Solution {
// public:
//     int count = 0,max_count = 0,false_index = 0;
//     bool flag ;
//     int lengthOfLongestSubstring(string s) { 
//         for(int i = 0;i<s.size();i++){
//             flag = true;
//           for(int j = i-1;j>=false_index;j--){
//               if(s[i]==s[j]){
//               flag = false;
//               count = i-j;
//               false_index= j+1;
//               break;
//           }
//        }
//        if(flag==true){
//               count++;
//           }
//           if(max_count<count){
//               max_count = count;
//           }
//         }
//      return max_count; 
//  }
//