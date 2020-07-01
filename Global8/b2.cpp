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

	fastio;

	string s = "codeforces";
	vector<int> val{1, 2, 1, 2, 1, 1, 1, 1, 1, 1};

	string rev;
	int idx = 9;
	ll k, pal = 1, cont = 1;
	cin >> k;

	while(cont < k){
		cont += pal*12;
		pal++;
	}

	if(cont > k){
		pal--;
		cont -= pal*12;
	}
	while(cont < k){
	
		rev.pb(s[idx]);
		cont += val[idx]*pal;
		
		if(idx == 0){
			idx = 9;
			pal++;
			rev.clear();
		}else{
			idx--;
		}
		
	}
	reverse(rev.begin(), rev.end());
	for(int i = 1; i < pal; i++)
		s.append("codeforces");
	
	s.append(rev);
	cout << s << endl;




}
