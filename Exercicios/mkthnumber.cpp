#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define MAX_N 100000

vector<ll> seg[4*MAX_N];
ll input[MAX_N];


void build(ll node, ll a, ll b){

	//printf("build node = %d, a = %d b = %d\n", node, a, b);

	if(a > b)return;

	if(a == b){
		seg[node].push_back(input[a]);
		return;
	}

	ll m = (a + b) / 2;

	build(2*node, a, m);
	build(2*node + 1, m + 1, b);


	merge(seg[2*node].begin(), seg[2*node].end(), seg[2*node+1].begin(), seg[2*node+1].end(), back_inserter(seg[node]));


	/*printf("seg[node]: ");
		for(auto x = seg[node].begin(); x < seg[node].end(); x++)
			printf("%d ", *x);
	printf("\n");*/


return;
}


vector<ll> query(ll node, ll a, ll b, ll l , ll r){

	//printf("query\n");

	vector<ll> res, filho1, filho2;

	res.clear();
	if(a > r || b < l || a > b)return res;

	if(a >= l && b <= r)
		return seg[node];
	
	ll m = (a + b) / 2;

	filho1 = query(2*node, a, m, l, r);
	filho2 = query(2*node+1, m+1, b, l, r);

	merge(filho1.begin(), filho1.end(), filho2.begin(), filho2.end(), back_inserter(res));
return res;
}


int main(){

	ll n, i, j, k;
	int m;

	//printf("teste\n");

	scanf("%lli %d", &n, &m);

	//printf("teste\n");

	for(ll p = 1; p <= n; p++)
		scanf("%lli", &input[p]);

	//printf("teste2\n");

	build(1, 1, n);

	//printf("teste3\n");

	for(int o = 1; o <= m; o++){
		scanf("%lli %lli %lli", &i, &j, &k);

		vector<ll> ans = query(1, 1, n, i, j);

		/*printf("ans: ");
		for(auto x = ans.begin(); x < ans.end(); x++)
			printf("%d ", *x);
		printf("\n");*/

		printf("%lli\n", ans[k-1]);
	}

return 0;
}



