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

int m[10][10];
vector<int> v{1, 2, 3, 4, 5};

int conta(){

	int cont = 0;

	cont += m[v[0]][v[1]];
	
	cont += m[v[1]][v[0]];
	cont += m[v[1]][v[2]];

	cont += m[v[2]][v[3]];
	cont += m[v[2]][v[1]];
	cont += m[v[2]][v[3]];

	cont += m[v[3]][v[2]];
	cont += m[v[3]][v[4]];
	cont += m[v[3]][v[2]];
	cont += m[v[3]][v[4]];

	cont += m[v[4]][v[3]];
	cont += m[v[4]][v[3]];
	/*
	for(auto x : v)
		cout << x << " ";
	cout << endl;

	cout << "cont = " << cont << endl;*/
	return cont;
}


int main(){

	
	for(int i = 1; i <= 5; i++)
		for(int j = 1; j <= 5; j++)
			cin >> m[i][j];

	
	int mx = -1;
	do{
		
		if(conta() > mx)
			mx = conta();
		
	}while(next_permutation(v.begin(), v.end()));

	cout << mx << endl;	
	




}
