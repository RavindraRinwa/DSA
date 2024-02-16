 /* it is the extra memory space requirment of an algorith
 ex. of fabonacci series
 a[0] = 0
 a[1] =1
 for(int i = 2;i<=n;i++){
    arr[i] = arr[i-1]+arr[i-2];
 } 

time complexity O(n) and space complexity is O(n)

for optimize
if(n==0 || n==1) return n;
n = 8
a = 0;
b = 1;
c  = 1;  -----> demi value

for(int i = 2;i<=n;i++){
c = a+b;
a = b;
b = c;
}

retrun c;

Time complexity  ----->O(n)
Sapce complexity ------>O(1)

 */