#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101000
#define ll long long int
#define INF 1000000000000000000


typedef struct {
	ll info;
	ll num;
} amais;

typedef struct {
	amais pref;
	amais suff;
	ll max;
	ll num;
	amais sum;	
} noh;


noh seg[4*MAX_N];
ll input[MAX_N];

ll n;

void imp(ll node){

	//printf("node = %lli seg[node].pref = (%lli , %lli ) seg[node].suff = (%lli , %lli ) max = %lli  num = %lli  sum = (%lli , %lli )\n", node, seg[node].pref.info, seg[node].pref.num, seg[node].suff.info, seg[node].suff.num, seg[node].max, seg[node].num, seg[node].sum.info, seg[node].sum.num);

return;
}


void build(ll node, ll a, ll b){

	//printf("build node = %lli  a = %lli  b = %lli \n", node, a, b);
	if(node == 0 || a > b)return;
	if(a == b){
		seg[node].max = seg[node].sum.info = input[a];
		seg[node].num = 1;

		if(input[a] > 0){
			seg[node].pref.info = seg[node].suff.info = input[a];
			seg[node].pref.num = seg[node].suff.num = 1;
		}else{
			seg[node].pref.info = seg[node].suff.info = -INF;
			seg[node].pref.num = seg[node].suff.num = 1;
		}

		seg[node].sum.num = 1;

		//imp(node);

		return;
	}

	ll m = (a + b) / 2;

	build(2*node, a, m);
	build(2*node + 1, m+1, b);

	ll aux = max(max(seg[2*node].max, seg[2*node + 1].max), seg[2*node].suff.info + seg[2*node + 1].pref.info);

	if(seg[2*node].max == aux && seg[2*node + 1].max != aux){
		seg[node].num = seg[2*node].num;
	}else{
		if(seg[2*node + 1].max == aux && seg[2*node].max != aux){
			seg[node].num = seg[2*node+1].num;
		}else{
			seg[node].num = seg[2*node].suff.num + seg[2*node+1].pref.num;
		}
	}

	ll aux2 = max(seg[2*node].pref.info, seg[2*node].sum.info + seg[2*node + 1].pref.info);

	if(seg[2*node].pref.info == aux2 && seg[2*node].sum.info + seg[2*node + 1].pref.info != aux2){
		seg[node].pref.num = seg[2*node].pref.num;
	}else{
		seg[node].pref.num = seg[2*node].sum.num + seg[2*node+1].pref.num;
	}

	ll aux3 = max(seg[2*node + 1].suff.info, seg[2*node + 1].sum.info + seg[2*node].suff.info);

	if(seg[2*node + 1].suff.info == aux3 && seg[2*node + 1].sum.info + seg[2*node].suff.info != aux3){
		seg[node].suff.num = seg[2*node + 1].suff.num;
	}else{
		seg[node].suff.num = seg[2*node + 1].sum.num + seg[2*node].suff.num;
	}

	seg[node].max = aux;
	seg[node].pref.info = aux2;
	seg[node].suff.info = aux3;
	seg[node].sum.info = seg[2*node].sum.info + seg[2*node + 1].sum.info;
	seg[node].sum.num = seg[2*node].sum.num + seg[2*node + 1].sum.num;

	//imp(node);
return;
}

noh query(ll node, ll a, ll b, ll l, ll r){

	//printf("query node = %lli  a = %lli  b= %lli  l = %lli  r = %lli \n",node, a, b, l, r);

	noh res,filho1, filho2;

	res.max = -INF;
	res.pref.info = -INF;
	res.suff.info = -INF;
	res.pref.num = res.suff.num = res.num = 0;
	res.sum.info = res.sum.num = 0;

	if(a > r || b < l || a > b){
		//printf("RETORNOU res\n");
		return res;
	}
	if(a >= l && b <= r){
		//imp(node);
		return seg[node];
	}
	

	ll m = (a + b) / 2;

	filho1 = query(2*node, a, m, l, r);
	filho2 = query(2*node + 1, m+1, b, l, r);

	//printf("filho1.max = %lli  filho2.max = %lli  filho1.suff.info = %lli  filho2.pref.info = %lli \n", filho1.max, filho2.max, filho1.suff.info, filho2.pref.info);

	ll aux = max(max(filho1.max, filho2.max), filho1.suff.info + filho2.pref.info);

	if(filho1.max == aux && filho2.max != aux){
		res.num = filho1.num;
	}else{
		if(filho2.max == aux && filho1.max != aux){
			res.num = filho2.num;
		}else{
			res.num = filho1.suff.num + filho2.pref.num;
		}
	}

	ll aux2 = max(filho1.pref.info, filho1.sum.info + filho2.pref.info);

	if(filho1.pref.info == aux2 && filho1.sum.info + filho2.pref.info != aux2){
		res.pref.num = filho1.pref.num;
	}else{
		res.pref.num = filho1.sum.num + filho2.pref.num;
	}

	ll aux3 = max(filho2.suff.info, filho2.sum.info + filho1.suff.info);

	if(filho2.suff.info == aux3 && filho2.sum.info + filho1.suff.info != aux3){
		res.suff.num = filho2.suff.num;
	}else{
		res.suff.num = filho2.sum.num + filho1.suff.num;
	}

	res.max = aux;
	res.pref.info = aux2;
	res.suff.info = aux3;
	res.sum.info = filho1.sum.info + filho2.sum.info;
	res.sum.num = filho1.sum.num + filho2.sum.num;
	

	//printf("res res.pref = (%lli , %lli ) res.suff = (%lli , %lli ) max = %lli  num = %lli  sum = (%lli , %lli )\n", res.pref.info, res.pref.num, res.suff.info, res.suff.num, res.max, res.num, res.sum.info, res.sum.num);

return res;
}


int main(){

	ll t, q, a, b;

	scanf("%lli", &t);


	while(t--){

		scanf("%lli", &n);

		for(ll i = 1; i <= n; i++)
			scanf("%lli", &input[i]);			

		build(1, 1, n);

		scanf("%lli", &q);

		for(ll i = 0; i < q; i++){
			scanf("%lli %lli", &a, &b);
				
			noh ans = query(1, 1, n, a, b);
			
			printf("%lli %lli\n", ans.max, ans.num);
		}
	}


}

