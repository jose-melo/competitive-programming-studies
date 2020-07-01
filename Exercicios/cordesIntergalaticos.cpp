#include <bits/stdc++.h>
using namespace std;

#define MAX_N 101000
#define ll long long int
#define ii pair<ll, ll>

typedef struct {
	
	ll freq;
	ll nota;
	vector<ii>v;
} info;

info seg[4*MAX_N];
ll input[MAX_N];
ll lazy[4*MAX_N];
ll res[4*MAX_N];

ll n;

void imp_seg(){

	printf("seg:");
	for(ll i = 0; i < 2*n + 20; i++)
		printf("(node: %lli => %lli, %lli)\n",i, seg[i].nota, seg[i].freq);
	printf("\n");
return;
}

void push(ll node){

	//printf("push node = %lli\n", node);


	lazy[2*node + 1] += lazy[node];
	lazy[2*node + 2] += lazy[node];
	vector<ii> au;

	for(auto i = seg[2*node + 1].v.begin(); i < seg[2*node + 1].v.end(); i++){
			ii aux;
			aux.first = i->first;
			aux.first =(aux.first + lazy[node]) % 9;
			aux.second = i->second;
			//seg[2*node + 1].v.erase(i);
			au.push_back(aux);
	}

	seg[2*node + 1].v.clear();	
	for(auto b = au.begin(); b < au.end(); b++)
			seg[2*node + 1].v.push_back(*b);

	au.clear();
	for(auto i = seg[2*node + 2].v.begin(); i < seg[2*node + 2].v.end(); i++){
			ii aux;
			aux.first = i->first;
			aux.first =(aux.first + lazy[node]) % 9;
			aux.second = i->second;
			//seg[2*node+2].v.erase(i);
			au.push_back(aux);
	}

	seg[2*node + 2].v.clear();	
	for(auto b = au.begin(); b < au.end(); b++)
		seg[2*node + 2].v.push_back(*b);


	seg[2*node + 1].nota = (seg[2*node + 1].nota + lazy[node]) % 9;
	seg[2*node + 2].nota = (seg[2*node + 2].nota + lazy[node]) % 9;

	lazy[node] = 0;

return;
}

void make(ll node){

	//printf("make node = %lli\n", node);

	push(node);

	/*if(seg[2*node + 1].nota == seg[2*node + 2].nota){
		seg[node].nota = seg[2*node + 1].nota;
		seg[node].freq = seg[2*node + 1].freq + seg[2*node + 2].freq;


		printf("após make: seg[node].nota = %lli seg[node].freq = %lli\n", seg[node].nota, seg[node].freq);

		return;
	}*/

	
	ll aux[10];
	for(int i = 0; i <= 10; i++)
		aux[i] = 0;

	for(auto i = (seg[2*node + 1].v).begin(); i < (seg[2*node + 1].v).end(); i++){
		aux[i->first] += i->second;
		//printf("1 i->first = %lli i->second = %lli\n", i->first, i->second);
	}

	for(auto i = (seg[2*node + 2].v).begin(); i < (seg[2*node + 2].v).end(); i++){
		aux[i->first] += i->second;
		//printf("2 i->first = %lli i->second = %lli\n", i->first, i->second);
	}
	
	seg[node].v.clear();
	for(int i = 1; i <= 9; i++)
		if(aux[i] != 0)seg[node].v.push_back(make_pair(i, aux[i]));


	ll max = -1;
	int index = -1;
	for(int i = 1; i <= 9; i++){
		if(aux[i] >= max && aux[i] != 0){
			max = aux[i];
			index = i;
			//printf("i = %d max = %lli index = %d\n", i, max, index);
		}
	}

//	seg[node].nota = index;
//	seg[node].freq = max;
		
	//printf("após make: seg[node].nota = %lli seg[node].freq = %lli\n", seg[node].nota, seg[node].freq);

	/*if(seg[2*node + 1].freq > seg[2*node + 2].freq){
		seg[node].nota = seg[2*node + 1].nota;
		seg[node].freq = seg[2*node + 1].freq;
		return;
	}else{

		if(seg[2*node + 1].freq < seg[2*node + 2].freq){
			seg[node].nota = seg[2*node + 2].nota;
			seg[node].freq = seg[2*node + 2].freq;
			return;
		}else{
			seg[node].freq = seg[2*node + 1].freq;

			if(seg[2*node + 1].nota > seg[2*node + 2].nota)
				seg[node].nota = seg[2*node + 1].nota;
			else
				seg[node].nota = seg[2*node + 2].nota;
		}
	}*/
	/*if(max >= seg[node].freq){*/
		seg[node].freq = max;
		seg[node].nota = index;
	/*}*/
return;
}

void build(ll node, ll a, ll b){

	if(a > b)return;

	if(a == b){
		info aux;
		seg[node].freq = 1;
		seg[node].nota = 1;
		seg[node].v.clear();
		seg[node].v.push_back(make_pair(1, 1));
		return;
	}

	ll m = (a + b) / 2;

	build(2*node + 1, a, m);
	build(2*node + 2, m + 1, b);

	make(node);
return;
}

info comv(info a, info b){

	info res;
	res.nota = -10;

	//printf("conv a.nota = %lli b.nota = %lli\n",a.nota, b.nota);

	if(a.nota == -10 && b.nota != -10)return b;
	if(b.nota == -10 && a.nota != -10)return a;
	if(a.nota == -10 && b.nota == -10)return res;
	
	ll aux[10];
	for(int i = 0; i <= 10; i++)
		aux[i] = 0;

	if(a.nota != -10){
		for(auto i = (a.v).begin(); i < (a.v).end(); i++){
			aux[i->first] += i->second;
			//printf("1 i->first = %lli i->second = %lli\n", i->first, i->second);
		}
	}

	if(b.nota != -10){
		for(auto i = (b.v).begin(); i < (b.v).end(); i++){
			aux[i->first] += i->second;
			//printf("2 i->first = %lli i->second = %lli\n", i->first, i->second);
		}
	}
	res.v.clear();
	for(int i = 1; i <= 9; i++)
		if(aux[i] != 0)res.v.push_back(make_pair(i, aux[i]));
	
	ll max = -1;
	int index = -1;
	for(int i = 1; i <= 9; i++){
		if(aux[i] >= max && aux[i] != 0){
			max = aux[i];
			index = i;
			//printf("i = %d max = %lli index = %int\n", i, max, index);
		}
	}

	if(index == -1){
		if(a.nota != -10)return a;
		return b;
	}

	res.freq = max;
	res.nota = index;
return res;
}

info query(ll node, ll a, ll b, ll l, ll r){

	//printf("query node = %lli a = %lli b = %lli l = %lli r = %lli\n", node, a, b, l, r);
	push(node);	//push(2*node + 1);	push(2*node + 2);
	

	info aux_res;
	aux_res.nota = -10;
	
	if(a > r || b < l )return aux_res;


	if(a >= l && b <= r){
		//printf("returned seg[node].nota  %lli\n", seg[node].nota);
		return seg[node];
	}

	ll m = (a + b) / 2;

	if(a <= l && r <= m)
		return query(2*node + 1, a, m, l, r);

	if(m < l && r <= b)
		return query(2*node + 2, m + 1, b, l, r);

	aux_res = comv(query(2*node + 1, a, m, l, min(m, r)), query(2*node + 2, m + 1, b, min(m + 1, l), r));
	

return aux_res;
}

void update(ll node, ll a, ll b, ll l, ll r, ll add){


//	printf("update node = %lli a = %lli b = %lli l = %lli r = %lli\n", node, a, b, l, r);

	push(node);

	if(a > r || b < l){
		return;
	}

	if(a >= l && b <= r){
		/*seg[node].v.pop_back();
		seg[node].v.push_back(make_pair(seg[node].nota, seg[node].freq));*/
		vector<ii> au;

		for(auto i = seg[node].v.begin(); i < seg[node].v.end(); i++){
			//printf("antes: seg[node].v[i] = (%lli, %lli)\n", i->first, i->second);
			ii aux;
			aux.first = i->first;
			aux.first =(aux.first + add) % 9;
			aux.second = i->second;
			//seg[node].v.erase(i);
			au.push_back(aux);
			//printf("dps: seg[node].v[i] = (%lli, %lli)\n", aux.first, aux.second);
		}

		seg[node].v.clear();
		for(auto b = au.begin(); b < au.end(); b++)
			seg[node].v.push_back(*b);

		lazy[node] = add;
		seg[node].nota = (add + seg[node].nota) % 9;
		return;
	}

	ll m = (a + b) / 2;

	if(a <= l && r <= m){
		update(2*node + 1, a, m, l, r, add);
	}else{

		if(m < l && r <= b){
			update(2*node + 2, m + 1, b, l, r, add);
		}else{
			update(2*node + 1, a, m, l, r, add);
			update(2*node + 2, m+1, b, l, r, add);
		}
	}

	make(node);

return;
}

void imp(ll node, ll a, ll b){

//	printf("imp node = %lli a = %lli b = %lli\n",node, a, b);

	if(a == b){
		res[a] = seg[node].nota;
		return;
	}

	ll m = (a + b) / 2;

	imp(2*node + 1, a, m);
	imp(2*node + 2, m + 1, b);

return;
}



int main(){

	ll q, x, y;

	scanf("%lli %lli", &n, &q);

	build(0, 0, n - 1);

	imp_seg();

	for(ll i = 0; i < q; i++){
		scanf("%lli %lli", &x, &y);
		ll auxxi = query(0, 0, n-1, x, y).nota;

		printf("QUERY: %lli\n", auxxi);
		update(0, 0, n-1, x, y, auxxi);

		

		printf("#################################################################################\n");
		for(ll i = 0; i < 5*n; i++)
			push(i);
		imp(0, 0, n-1);
		for(ll i = 0; i < n; i++)
			printf("%lli\n", res[i]);
		printf("################################################################################\n");
		
		/*for(ll i = 0; i < n; i++)
			push(i);*/

		printf("###############Apos update\n");
		imp_seg();
	}

	/*printf("Antes todos os pushes: ");
	imp_seg();*/

	for(ll i = 0; i < 4*n; i++)
		push(i);

	/*printf("Após todos os pushes: ");
	imp_seg();*/

	imp(0, 0, n-1);

	for(ll i = 0; i < n; i++)
		printf("%lli\n", res[i]);

return 0;
}

