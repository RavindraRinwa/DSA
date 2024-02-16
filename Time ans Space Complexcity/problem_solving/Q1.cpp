/*
#1
int value = 0;
for(int i = 0;i<=n;i*=2){
    value++;
}

TimeComplexity  ----> O(log(n))


#2
int val = 0;
for(int i = 1;i<=N;i+=i){
    val++;
}

TimeComplexity = ----> O(log(n))


#3

int val = 0;
for(int i = 1;i<=N;i*=2){
    for(int j  = 1;j<=i;j++){
        val++;
    }
}

TimeComplexity = -----> O(sqrt(N)) this is right sir has small mistake in his solution


****** MCQ ******

#1 
int val = 0;
for(int i = 1;i<=N;i*=2){
    for(int i = N ;j>i;j--){
        val++;
    }
}

TimeComplexity = -----> O(Nlog(N))

#2
int val = 0;
for(int i = 0;i>0;i/=2){
    for(int j = 0;j<i;j++){
        val++;
    }
}

TimeComplexity  = ----->O(N)


#3

int val = 0;
for(int i = 2;i<=N;i*=i){
    val++;
}

TimeComplexity = ------>O(log(log(N)))

*/