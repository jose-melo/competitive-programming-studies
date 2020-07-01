#include <bits/stdc++.h>
using namespace std;

#define MAX_N 1000000
#define ll long long int


ll aluno[MAX_N];
ll casas[MAX_N];
set<int> res;

int main(){

	ll n, m, q, a, b;

	scanf("%lli %lli %lli", &n, &m, &q);

	for(ll i = 1; i <= n; i++){
		scanf("%lli", &a);
		aluno[i] = a;
		casas[a]++;
		res.insert(a);
	}

	for(ll i = 1; i <= q; i++){
		scanf("%lli %lli", &a, &b);
		
		casas[aluno[a]]--;
		casas[b]++;
		if(casas[aluno[a]] == 0){
			res.erase(aluno[a]);
				//printf("apaguei %lli\n", aluno[a]);
		}
		
		res.insert(b);
		//printf("inseri %lli\n", b);
		
		aluno[a] = b;
		
		//printf(" m = %lli res.size() = %lli\n", m, (int)res.size());
		printf("%lli\n", m - (int)res.size());
	}

return 0;
}




