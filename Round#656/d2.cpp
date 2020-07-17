#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define mp make_pair
#define se second
#define FI(n) for(int i = 0; i < n; i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)
#define pb push_back


int t, n;
ll cont;

int solve(string s, char ch){


	if(s.size() == 1){
		if(s[0] != ch)
			return 1;
		return 0;
	}

	int cont1 = 0, cont2 = 0;
	int cont11, cont22;

	int tam = s.size();
	cont11 = solve(s.substr(0, tam/2), ch+1);
	cont22 = solve(s.substr(tam/2, tam/2), ch+1);
	
	for(int i = 0; i < tam/2; i ++)
		if(s[i] != ch)cont1++;

	for(int i = tam/2; i < tam; i++)
		if(s[i] != ch)cont2++;

	int resp = min(cont1 + cont22, cont2+cont11);
	return resp;
}



int main(){

	cin >> t;

	while(t--){
	
		cin >> n;
		string s;
		
		cin >> s;

		cout << solve(s, 'a') << endl;

	}


}

