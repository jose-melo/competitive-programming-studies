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
#define tsludkfh cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back
#define debugv(v) for(auto x : v)cout << x << endl;

map<string, int> nomes;
int numAcc[300], tempo[300], penalidades[300][20];
int n, m, p, t_ant;
bool esta1;

bool esta_primeiro(int nome, int prob, int t, int ok){

	if(ok){
		numAcc[nome]++;
		tempo[nome] += (t + penalidades[nome][prob]); 
	}else{
		penalidades[nome][prob] += 20;
	}

	FOR(i, 1, n){
		if(numAcc[i] > numAcc[0])	
			return false;
		
		if(numAcc[i] == numAcc[0])
			if(tempo[i] < tempo[0])
				return false;
	}
	
return true;
}


int main(){

	cin >> n >> m >> p;

	string aux;
	FI(n){
		cin >> aux;
		nomes[aux] = i;
	}
	
	t_ant = 0;
	esta1 = true;
	int nome, prob, t, ok;	

	int resp = 0;	
	FI(m){
		cin >> aux;
		nome = nomes[aux];		
		
		cin >> aux;
		prob = aux[0] - 'A';	
		
		cin >> t;
		
		cin >> aux;
		if(aux[0] == 'O')
			ok = 1;	
		else
			ok = 0;
	
		if(esta1)
			resp += (t - t_ant);	

		esta1 = false;

		if(esta_primeiro(nome, prob, t, ok)){
			esta1 = true;
			t_ant = t;
		}

	}	
	
	if(esta1)
		resp += (300 - t_ant);
	
	cout << resp << "\n";
return 0;
}










