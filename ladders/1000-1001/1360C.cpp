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

int t, n, aux;
vector<int> v;
int mark[55];

int main(){

    cin >> t;

    while(t--){

        memset(mark, 1, sizeof(mark));
        v.clear();

        cin >> n;

        for(int i = 0; i < n; i++){
            cin >> aux;
            v.pb(aux);
        }

        int cont1 = 0, cont2 = 0;

        for(int i = 0; i < n; i++){
            if(mark[i]){
                if(v[i]%2)
                    cont1++;
                else
                    cont2++;
            }
        } 

        if(cont1 % 2 == 0 && cont2 % 2 == 0){
            cout << "YES\n";
            continue;
        }

        if(cont1 % 2 != cont2 % 2){
            cout << "NO\n";
            continue;
        }

        sort(v.begin(), v.end());

        int ok = 1;
        for(int i = 1; i < v.size(); i++){
            if(abs(v[i] - v[i-1]) == 1){
                cout << "YES\n";
                ok = 0;
                break;
            }
        }
        if(ok)
            cout << "NO\n";

    }



}

