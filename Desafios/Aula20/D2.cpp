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

int freq[212345];
vector<int> resp;
int n, k;

int verifica(int val){

	int cont = 0;

	for(int i = 1; i <= 200000; i++)
		cont += (freq[i]/val);
return cont;
}


int bs(){

	int l, r, freq;
	l = 1;
	r = 200001;
	
	while(l < r){
	
		freq = (l + r) / 2;
		int cont = verifica(freq);		

		if(cont >= k)
			l = freq + 1;
		else
			r = freq;
	}
	
return l-1;
}

int main(){

	cin >> n >> k;
	
	int aux;
	FI(n){
		cin >> aux;
		freq[aux]++;
	}

	int frequencia = bs();
	int cont = 0;

	for(int i = 1; i <= 200000; i++){
		if(freq[i] / frequencia != 0)
			for(int j = 0; j < freq[i] / frequencia && cont < k; j++){
				resp.pb(i);
				cont++;
			}

		if(cont == k)
			break;
	}

	for(auto x : resp)
		cout << x << " ";
	cout << "\n";

return 0;
}

