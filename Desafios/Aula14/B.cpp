#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back

vector<int> res;
int n, k;


int main(){

	fastio;

	cin >> n >> k;

	if(k > n){
		cout << "NO\n";
		return 0;
	}

	for(int i = 0; i <= log2(n); i++)
		if(n & (1<<i))
			res.push_back(1<<i);

	if(k < res.size()){
		cout << "NO\n";
		return 0;
	}
	int num, cont, idx = res.size()-1;
	while(res.size() != k){
		num = res[idx];
		cont = 0;
		if(num % 2 == 0){
			res.erase(idx + res.begin());	
			res.insert(idx+res.begin(), num/2);
			res.insert(idx+res.begin(), num/2);
			idx = res.size()-1;
		}else{idx--;}
	}
	

	cout << "YES\n";
	for(auto x : res)
		cout << x << " ";
	cout << "\n";
return 0;
}

