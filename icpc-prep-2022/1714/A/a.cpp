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

	int t, n, H, M, tmp1, tmp2;
	vector<int> v;

	cin >> t;

	while(t--){
	
		cin >> n >> H >> M;

		for(int i = 0; i < n; i++){
			cin >> tmp1 >> tmp2;
			tmp2 += 60*tmp1;
			tmp2 = tmp2 - (M + 60*H);
			if(tmp2 < 0)tmp2 += 24*60;
			v.pb(tmp2);
		}

		sort(v.begin(), v.end());

		int res_h = (int)v[0]/60;
		int res_m = v[0] % 60;

		cout << res_h << " " << res_m << endl;
		v.clear();

	}



}

