/*
int up[N][LOG];
for 1 to N...
    up[v][0] = parent[v]
for j = 1...LOG-1:
     for v = 0 to N-1..
        up[v][j] = up[ up[v][j-1] ][j-1]  // j-1 previous power

time & space complexity --> O(N*log(N))


// lca
if(depth[a]<depth[b]){
    swap(a,b);
}   // a is always at greater depth

int d = depth[a]-depth[b];

for(int i=LOG-1;i>=0;i--){
    if(d&(1<<i)){
        a = up[a][i];
    }
}

if(a==b){
    return a;
}

for(int i=LOG-1;i>=0;i--){
    if(up[a][i]!=up[b][i]){
        a = up[a][i];
        b = up[b][i];
    }
}

return up[a][0];


*/