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
vector<int> v;
int freq[10];


int main(){

	cin >> n;
	int aux, ok = 1;
	for(int i = 0;i  < n; i++){
		cin >> aux;
		if(aux == 5 || aux == 7){
			ok = 0;
		}
		v.pb(aux);
	}

	if(ok == 0){
		cout << "-1\n";
		return 0;
	}

	for(auto x : v)
		freq[x]++;

	int f2, f1, f4 = freq[4];
	if(freq[2] >= f4 && freq[1] >= f4){

		f2 = freq[2] - f4;
		f1 = freq[1] - f4;

		if(freq[6] == f2 + freq[3] && freq[6] == f1){


			for(int i = 0; i < freq[4]; i++)
				cout << "1 2 4\n";

			for(int i = 0; i < f2; i++)
				cout << "1 2 6\n";

			for(int i = 0; i < freq[3]; i++)
				cout << "1 3 6\n";

			return 0;

		}

	}

	cout << "-1\n";
	
}
