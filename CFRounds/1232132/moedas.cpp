#include <bits/stdc++.h>
#define pb push_back
const int INF = 0x3f3f3f3f;
 
 
using namespace std;
 
int v[140], memo[50040];
int n , val;
 
int moeda(int idx, int val){
    if(val==0) return 0;
    if(val < 0 || idx >= n) return INF;
    
    //printf("idx = %d, val = %d\n", idx, val);

    if(memo[val]==INF){
        memo[val] = min(1 + moeda(idx, val - v[idx]), moeda(idx+1, val));
    }
    return memo[val];
}
 
int main (){
    int ok=1;
    while(ok=1){
       cin >> val;
       if(val==0)
        break;
       cin >> n;
       memset(memo, INF, sizeof(int)*(val) + sizeof(int));
       for(int i=0; i<n; i++)
            scanf("%d", &v[i]);
 
        int resultado=moeda(0, val);
        if(resultado==INF)
            printf("Impossivel\n");
        else
            printf("%d\n", resultado);
    }
}