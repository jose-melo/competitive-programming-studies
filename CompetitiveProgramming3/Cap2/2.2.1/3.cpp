#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
#define pii pair<int, int>
#define INF 0x3f3f3f3f
#define fi first
#define se second
#define f(n) for(int i = 0; i < n; i++)
#define f2(n) for(int i = 1; i <= n; i++)
#define debug(x) if(on)cout << x << endl
#define on true
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

int n;
int S[112345];

int main(){

	cin >> n;


	f(n)
		cin >> S[i];

	int cont = 1;
	int mx = -1;
	for(int i = 0; i < n-1; i++){
		if(S[i+1] >= S[i]){
			cont++;
		}else{
			if(cont > mx)
				mx = cont;
			cont = 1;
		}
	}

	if(cont > mx)
		mx = cont;


	cout << mx << endl;

	return 0;
}
