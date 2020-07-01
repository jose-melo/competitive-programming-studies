#include <bits/stdc++.h>
using namespace std;


#define MAX_N 100100;
#define ll long long int
#define ii pair<int, int>

struct {
	vector<pair<int, int>> v;
	int add;
} noh;

int seg[4*MAX_N];
int lazy[4*MAX_N];
int input[MAX_N];
noh seg2[4*MAX_N];

pair<pair<int, int>, int> op[MAX_N];


void build(int node, int l, int r){

	if(l > r)return;

	if(l == r){
		seg2[node].v = make_pair(op[l].first.first, op[l].first.second);
		seg2[node].add = op[l].second;
		return;		
	}

	int m = (l + r) / 2;

	build(2*node, a, m);
	build(2*node + 1, m+1, b);

	copy(seg2[2*node].v.begin(), seg2[2*node].v.end(), back_inserter(seg2[node].v));
	copy(seg2[2*node+1].v.begin(), seg2[2*node].v.end(), back_inserter(seg2[node].v));


	seg[2*node] + seg[2*node+1];
return;
}

void push(int node){

	if(lazy[node]){
		seg[node] += lazy[node];
		lazy[2*node] = lazy[2*node+1] = lazy[node];
		lazy[node] = 0;
	}
return;	
}

void update(int node, int a, int b, int l, int r, int add){

	push(node);

	if(a > b || l > r)return;

	if(a >= l &&  b <= r){
		lazy[node] += add;
		push(node);
		return;
	}

	int m = (a + b) / 2;

	update(2*node, a, m, l, r, add);
	update(2*node + 1, m+1, b, l, r, add);
return;
}


void build2(int node, int l, int r){

	if(l > r)return;

	if(l == r){
		seg2[node] = input[l];
		return;		
	}

	int m = (l + r) / 2;

	build(2*node, a, m);
	build(2*node + 1, m+1, b);

	seg[node] = seg[2*node] + seg[2*node+1];
return;
}

void update2(int node, int a, int b, int l, int r, int add){

	push(node);

	if(a > b || l > r)return;

	if(a >= l &&  b <= r){
		lazy[node] += add;
		push(node);
		return;
	}

	int m = (a + b) / 2;

	update(2*node, a, m, l, r, add);
	update(2*node + 1, m+1, b, l, r, add);
return;
}


int main(){

	int n, m, k, a, b, c;

	scanf("%d %d %d", &m, &n, &k);

	for(int i = 1; i <= n; i++)
		scanf("%d", &input[i]);			
	
	for(int i = 1; i <= m; i++){
		scanf("%d %d %d", &a, &b, &c);
		op[i].fisrt = make_pair(a, b);
		op[i].second = c;
	}

	build(0, 1, n);

	for(int i = 0; i < k; i++){

		scanf("%d %d", &a, &b);

		for(int i = a; i <= b; i++)
			update(1, 1, n, op[i].first.first, op[i].first.second, op[i].second);
	}

}











