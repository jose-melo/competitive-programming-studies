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
#define debugv(v) for(auto x : v)cout << x << endl;


ll v[212345];
ll cont;

void intercala(int a, int mid, int r){

	int p = a, q = mid;
	int k = 0;
	ll aux[212345];

	while(p != mid && q != r){
		if(v[p] <= v[q]){
			aux[k] = v[p];
			k++;
			p++;
		}
		else{
			aux[k] = v[q];
			k++;
			q++;
			cont += (mid - p);
		}
	}


	while(p != mid)
		aux[k++] = v[p++];
		

	while(q != r)aux[k++] = v[q++];

	for(int i = a; i < a + k; i++)
		v[i] = aux[i-a];

}

void merge(int l, int r){


	if(l >= r - 1)
		return;

	int mid = (l + r)/2;

	merge(l, mid);
	merge(mid, r);
	intercala(l, mid, r);
}

int main(){

	fastio;

	int T, N;
	cin >> T;

	while(T--){

		cin >> N;

		FI(N)
			cin >> v[i];
		
		cont = 0;
	
		merge(0, N);

		cout << cont << "\n";
	}



return 0;

}


