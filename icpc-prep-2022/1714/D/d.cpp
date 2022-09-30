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

vector<pii> res;

int solve(int idx, int end, string t, vector<vector<pii>> m,  int n){

	//cout << "res: \n";
	//for(auto x: res){
		//cout << x.fi << " " << x.se << endl;
	//}
	//cout << "idx " << idx << " end: " << end << " n: " << n << endl;
 
	if(end == (int)t.size()){
		return 1;
	}

	int mx = -1;
	int choice_str = -1;
	int choice_pos = -1;
	int new_end = t.size();
	for(int i = 0; i < n; i++){
		//cout << "i " << i << endl;
		//cout << "m[i].size()" << m[i].size() << endl;
		for(int j = 0; j < (int)m[i].size(); j++){
			for(int k = idx; k <= end; k++){
			//cout << "j " << j << endl;
				//cout << "k " << k << endl;
				if((m[i][j].fi == k) && ((m[i][j].se - end) > mx) && (m[i][j].se - end > 0)){
					mx = m[i][j].se - end;
					choice_pos = k;
					choice_str = i;
					new_end = m[i][j].se;
				}
			}
		}
	}

	//cout << "choice: " << choice_str << " " << idx << endl;
	if(mx == -1){
		return 0;
	}
	res.pb(mp(choice_str, choice_pos));
	return solve(end+1, new_end, t, m, n);
}

int main(){
	
	int q, n;
	string t, tmp;
	vector<string> v;
	vector<vector<pii>> m;

	cin >> q;

	while(q--){
		cin >> t;
		cin >> n;
		
		FI(n){
			cin >> tmp;
			v.pb(tmp);
		}

		for(int i = 0; i < (int)v.size(); i++){

			string x = v[i];
			int len = x.size();
			vector<pii> v2;
			
			for(string::iterator j2 = t.begin(); j2 < t.end(); j2++){
				int j = (int)(j2 - t.begin());
				if(t.substr(j, len).compare(x) == 0){
					v2.pb(mp(j, j+len));
				}
			}
			m.pb(v2);
		}

		res.clear();

		//cout << "t: "<< endl;
		//cout << t << endl;
		//cout << "m: " << endl;
		//for(auto x : m){
			//cout << "x: " << endl;
			//for(auto y: x){
				//cout << y.fi << " " << y.se << endl;
			//}
		//}
		//cout << n << endl;

		if(solve(0, 0,t, m, n)){	
			cout << res.size() << endl;
			for(auto x: res){
				cout << x.fi + 1 << " " << x.se + 1 << endl;
			}
		}else{
			cout << "-1" << endl;
		}

		res.clear();
		tmp.clear();
		v.clear();
		m.clear();
		t.clear();

	}




}

