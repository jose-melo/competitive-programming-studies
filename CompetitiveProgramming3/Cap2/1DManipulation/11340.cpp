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

	fastio;

	int N, k, M;
	int v;
	char ch;
	int val[300];
	string s;
	int total;

	cin >> N;
	while(N--){

		cin >> k;

		for(int i = 0; i < 300; i++){
			val[i] = 0;
		}

		for(int i = 0; i < k; i++){
			cin >> ch >> v;
			val[ch] = v;	
		}

		

		total = 0;

		cin >> M;
		for(int i = 0; i <= M; i++){		
			getline(cin, s);
			for(int j = 0; j < s.size(); j++){
				total += val[int(s[j])];
			}
		}
		
		double resp  = (total*1.0)/100;
		
		cout << resp << "$\n";
	}

	return 0;
}


