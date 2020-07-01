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

int T;
ll a, b, c;

int main(){

    cin >> T;
    
    while(T--){

        cin >> a >> b >> c;

        if(a >= c){
            cout << "-1 ";
        }else{

            cout << "1 ";
        }


        if(b*a <= c){
            cout << "-1\n";
        }else{
            cout << b << endl;
        }
    
    }



}

