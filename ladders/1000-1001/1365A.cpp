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

int t, n, m;
int v[55][55];

int main(){

    cin >> t;

    while(t--){

        cin >> n >> m;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> v[i][j];
            }
        }
        int ok, conta = 0, contb = 0;

        for(int i = 0; i < n; i++){
            ok = 1;
            for(int j = 0; j < m; j++){
                if(v[i][j] == 1)
                    ok = 0;
            }
            if(ok)
                conta++;
        }
       
        for(int j = 0; j < m; j++){
            ok = 1;
            for(int i = 0; i < n; i++)
                if(v[i][j] == 1)
                    ok = 0;
            if(ok)
                contb++;

        } 
       
        conta = min(conta, contb);

        if(conta % 2)
            cout << "Ashish\n";
        else
            cout << "Vivek\n";
 

    }



}

