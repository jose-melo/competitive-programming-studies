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

int freq[300], v;
int em[310][310];
vector<int> resp;

bool comp(int a, int b){
	int i = 1 ;

	if (freq[a] > freq[b]) return true;
	if (freq[a] < freq[b]) return false;

	while( i <= v){
		
		if(em[a][i] > em[b][i] )
			return true;
		else if(em[a][i] < em[b][i] )
			return false;

		i++;
	}

	return true;

return false;
}

bool eh_igual(int idx){
	
	for (int i = 1; i <= v; i++)
		 if (em[resp[idx]][i] != em[resp[idx-1]][i])
			 return false;

	return true;
}

int main(){
	
	int T, n, k;

	cin >> T;

	while(T--){

		cin >> n >> k >> v;
		
		int aux;
		FI(n){
			cin >> aux;
			int val;
			if(val == 0)
				continue;
			FOR(i, 1, aux+1){
				cin >> val;

				if(i > v || val < 1 || val > k)continue;
			
				freq[val]++;
				em[val][i]++;	
			}
		}

		FOR(i, 1, k + 1)
			resp.pb(i); 

		sort(resp.begin(), resp.end(), comp);
			
		int idx = 0;

		for(idx = 0 ; idx < v ; idx++){
			printf("%d ", resp[idx]);
		}	

		while ( idx < resp.size() && eh_igual(idx)){
			printf("%d ", resp[idx]);
			idx++;
		}
		
		FOR(i, 0, 200){
			freq[i] = 0;
			FOR(j, 0, 200) 
				em[i][j] = 0;
		}

		resp.clear();	

		cout << "\n";
	}
}





