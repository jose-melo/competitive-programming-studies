#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define t cout << "TESTE" << endl
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)


int main(){


	int n, a, b;
	int checa[3123], v[3123];
	bool ok;
	fastio;	

	while(scanf("%d", &n) != EOF){
		ok = true;
		for(int i = 0; i <= n; i++)
			checa[i] = 0;
		
		scanf("%d", &a);
		for(int i = 1; i < n; i++){
			scanf("%d", &b);
			checa[abs(b-a)] = 1;
			a = b;
		}
		
		ok = true;
		for(int i = 1; i < n; i++)
			if(checa[i] == 0)
				ok = false;


		if(ok)
			cout << "Jolly" << endl;
		else
			cout << "Not jolly" << endl;

	}	
	return 0;
}

