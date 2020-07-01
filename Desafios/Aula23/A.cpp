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

int input[110];

int main(){

	int n;

	cin >> n;

	FI(n)
		cin >> input[i];

	int maior = 0;
	int start, end, cont = 0;
	
	int i = 1;
	while(i < n){

		if(input[i-1] + 1 == input[i]){
			cont = 1;
			start = i-1;
			while(input[i-1] + 1 == input[i]){
				cont++;
				i++;
			}
			end = i-1;			

			cont -= 2;

			if((start == 0 && input[0] == 1) || (end == n-1 && input[end] == 1000))
				cont++;

			maior = max(maior, cont);	
	
		}
		i++;
	}


	cout << maior << "\n";
return 0;
}


