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

int T, n;
vector<pii> a, b;

int main(){

    cin >> T;
    

    while(T--){
       
        cin >> n;

        a.clear();
        b.clear();

        int aux;
        for(int i = 1; i <= 2*n; i++){
            cin >> aux;
           if(aux%2 == 0)
                a.pb(mp(aux, i));
            else
                b.pb(mp(aux, i));

        }

        if(b.size() >= 2){
            
            if(b.size() % 2){
                b.pop_back();
                a.pop_back();
            }else{
                b.pop_back();
                b.pop_back();
            }
        }else{
            if(b.size() == 1){
                b.pop_back();
                a.pop_back();
            }else{
                a.pop_back();
                a.pop_back();
            }
            
        }

        
        if(!a.empty()){
            for(int i = 0; i < a.size()-1; i+=2)
                cout << a[i].se << " " << a[i+1].se << endl;
        
            
        }        


        if(!b.empty())
            for(int i = 0; i < b.size()-1; i+=2)
                cout << b[i].se << " " << b[i+1].se << endl;


    }



}

