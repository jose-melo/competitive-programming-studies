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

int main(){

	int t, n;
	ll tmp;
    vector<ll> v2, v;

	cin >> t;
	while(t--){
		cin >> n;
        bool troll = false;
		FI(n){
			cin >> tmp;
            if(tmp % 5 == 0)troll = true;
            v.pb(tmp);
		}

        if(troll){
            for(int i = 0; i < (int)v.size(); i++){
                if(v[i] % 10 == 5)v[i] += 5;
            }
            //cout << "v: \n";
            //for(auto x: v){
                //cout << x << endl;
            //}
            bool ok = false;
            for(int i = 1; i < (int) v.size(); i++){
                if(v[i] != v[i-1]){
                    cout << "No\n";
                    ok = true;
                    break;
                }
            }
            if(!ok)cout << "Yes\n";
        }else{
            for(int i=0; i < (int)v.size(); i++){
                tmp = v[i];
                while(tmp % 10 != 8)tmp = tmp + (tmp % 10);
                //cout << "tmp: " << tmp << endl;
                tmp /= 10;
                //cout << "tmp: " << tmp << endl;
                tmp = tmp % 10;
                //cout << "tmp: " << tmp << endl;
                v2.pb(tmp%2);
                //cout << "tmp: " << tmp%2 << endl;
            }

            int acc = accumulate(v2.begin(), v2.end(), 0);
            //cout << "acc: " << acc << endl;
            if(acc == n || acc == 0){
                cout << "Yes\n";
            }else{
                cout << "No\n";
            }
        }
        v.clear();
        v2.clear();


	}





}

