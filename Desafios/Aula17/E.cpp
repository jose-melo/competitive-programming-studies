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

int n;
int pais[212345];
int filhos[212345];
int pais2[212345];
int filhos2[212345];

void build(){

	FOR(i, 1, n+1){
		pais[i] = i;
		filhos[i] = i;
		pais2[i] = i;
		filhos2[i] = i;

	}
return;
}

int findFilho(int node){
	if(filhos2[node] == node)
		return node;
	
	filhos2[node] = findFilho(filhos2[node]);

return filhos2[node];
}

int findPai(int node){

	if(pais2[node] == node)
		return node;

	pais2[node] = findPai(pais2[node]);
return pais2[node];
}

bool isSameSet(int a, int b){
	return findPai(a) == findPai(b);
}

void UNION(int a, int b){
	

	if(!isSameSet(a, b)){
		
		int filhoB = findFilho(b);
		int paiA = findPai(a);
		int filhoA = findFilho(a);
		int paiB = findPai(b);
	
		pais2[paiB] = paiA;
		filhos2[paiA] = filhoB;	
	
		pais2[paiB] = filhoA;
		filhos2[filhoA] = paiB;	

		pais[paiB] = filhoA;
		filhos[filhoA] = paiB;	
	}

}

int main(){

	cin >> n;

	int a, b;

	build();
	
	FI(n-1){
		cin >> a >> b;
		UNION(a, b);
	}
	int idx = findPai(1);
	
	FOR(i, 1, n+1){
		cout << idx << " ";
		idx = filhos[idx]; 
	}

	cout << "\n";
return 0;
}


