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


int main(){

	fastio;

	int N, graus;
	bool acheiMenor = false, acheiMaior = false;
	bool achei = false;

	cin >> N >> graus;
	
	int aux;
	FI(N){
		cin >> aux;
	
		if(aux == graus){
			cout << "1\n";
			return 0;
		}

		if(aux < graus)
			acheiMenor = true;
		
		if(aux > graus)
			acheiMaior = true;

		
	}
	
	if(acheiMaior && acheiMenor){
			cout << "2\n";
			return 0;
	}
	
	cout << "-1\n";
return 0;
}



