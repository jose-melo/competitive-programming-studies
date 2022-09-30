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
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

int n;
int w[123];


int main(){
	
	cin >> n;

	int sum = 0, a = 0, b = 0;
	for(int i = 0; i < n; i++){
		cin >> w[i];
		sum += w[i];
		if(w[i] == 100)
			a++;
		if(w[i] == 200)
			b++;
	
	}

	if(sum % 2){
		cout << "NO\n";
		return 0;
	}

	sum /= 2;

	for(int i = 0; i <= a; i++){
		for(int j = 0; j <= b; j++){
			if(100*i + 200*j == sum){
				cout << "YES\n";
				return 0;
			}
		}
	}
		


	cout << "NO\n";	


}
