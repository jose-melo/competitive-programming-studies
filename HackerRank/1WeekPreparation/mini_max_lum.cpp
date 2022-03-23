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

vector<ll> v;

int main(){

    ll aux;
    for(int i = 0; i < 5; i++){
        cin >> aux;
        v.push_back(aux);
    }

    sort(v.begin(), v.end());

    ll total_sum = 0;
    for(int i = 0; i < 5; i++){
        total_sum += v[i];
    }    

    cout << total_sum - v[4] << " ";
    cout << total_sum - v[0] << endl;

    return 0;
}

