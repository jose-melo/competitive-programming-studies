#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

ll n;
vector<ll> v;

int main(){

    cin >> n;

    ll aux;
    for(int i = 0; i < n; i++){
        cin >> aux;
        v.push_back(aux);
    }

    double sum_pos = 0;
    double sum_neg = 0;
    double sum_zero = 0;

    for(auto x : v){
        if(x > 0)sum_pos++;
        if(x < 0)sum_neg++;
        if(x == 0)sum_zero++;
    }
    
    printf("%.6lf\n", sum_pos / (double)n);
    printf("%.6lf\n", sum_neg / (double)n);
    printf("%.6lf\n", sum_zero / (double)n);

    return 0;
}