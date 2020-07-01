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


int  main(){


	int n;
	string s;

	cin >> n >> s;

	int cont1 = 0, cont2 = 0;
	bool troca = true;
	for(int i = 0; i < n; i++){
		if(troca){
			if(s[i] != '1')
				cont1++;
			
			if(s[i] != '0')
				cont2++;
			
			troca = !troca;
		}else{
			if(s[i] != '0')
				cont1++;

			if(s[i] != '1')
				cont2++;

			troca = !troca;
		}
	}

	cout << min(cont1, cont2) << endl;	
return 0;
}


