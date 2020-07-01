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

int t, cont1, cont2, ok;
ll a, b;

int main(){

    cin >> t;


    while(t--){

        ok = 1;

        cin >> a >> b;
        cont1 = cont2 = 0;
    
        for(int bit = 0; bit <= log2(a); bit++){
            if((a&(1LL<<bit)) != 0){
                cont1 = bit;
                break;
            }
        }
        
        for(int bit = 0; bit <= log2(b); bit++){
            if((b&(1LL<<bit)) != 0){
                cont2 = bit;
                break;
            }
        }


       
        a = a>>cont1;
        b = b>>cont2;
        
        if(a != b)
            ok = 0;
 
        cont1 = abs(cont1 - cont2);

        int resp = 0;

        if(cont1 > 3)
            resp = (cont1 + 2) / 3;
        else 
            resp = 1;

        if(cont1 == 0)
            resp = 0;

        if(ok)
            cout << resp << endl;
        else
            cout << "-1\n";



    }



}

