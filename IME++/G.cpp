#include <bits/stdc++.h>
using namespace std;

int v[412345];
int seg[412345], segMax[412345], segMin[412345];

void uptade(int node, int l , int r , int idx, int val){
	if(l == r){
		segMin[node] = val;
		segMax[node] = val;
		seg[node] = val;
		return;
	}
 
	int mid = (l+r)/2;
	int nodel = 2*node;
	int noder = 2*node + 1;
	
	if(idx <= mid)
		uptade(nodel, l, mid, idx, val);
	else
		uptade(noder, mid + 1, r, idx , val);

	segMin[node] = min(segMin[nodel], segMin[noder]);
	segMax[node] = max(segMax[nodel], segMax[noder]);
	seg[node] = seg[nodel] + seg[noder];
	
}

void build(int node, int l , int r){
	if(l == r){
		segMax[node] = v[l];
		segMin[node] = v[l];
		seg[node] = v[l];
		return;
	}
	
	int mid = (l + r)/2;
	int nodel = 2*node;
	int noder = 2*node + 1;

	build(nodel, l ,  mid);
	build(noder, mid + 1, r);

	segMax[node] = max( segMax[nodel], segMax[noder]);
	segMin[node] = min( segMin[nodel], segMin[noder]);
	seg[node] = seg[nodel] + seg[noder];

}

int consu(int node, int l , int r, int start, int end){
	if( l == start && r == end)
		return seg[node];

	int mid = (l+r)/2;
	int nodel = 2*node;
	int noder = 2*node + 1;

	if(end <= mid)
		return consu(nodel, l, mid, start, end);
	else if( start > mid )
		return consu(noder, mid + 1, r , start, end);
	else
		return consu(nodel, l, mid, start, mid) + consu (noder, mid + 1, r , mid + 1, end);

}


int consuMax(int node, int l , int r, int start, int end){
	if( l == start && r == end)
		return segMax[node];

	int mid = (l+r)/2;
	int nodel = 2*node;
	int noder = 2*node + 1;

	if(end <= mid)
		return consuMax(nodel, l, mid, start, end);
	else if( start > mid )
		return consuMax(noder, mid + 1, r , start, end);
	else
		return max(consuMax(nodel, l, mid, start, mid),consuMax(noder, mid + 1, r , mid + 1, end));

}

int consuMin(int node, int l , int r, int start, int end){
	if( l == start && r == end)
		return segMin[node];

	int mid = (l+r)/2;
	int nodel = 2*node;
	int noder = 2*node + 1;

	if(end <= mid)
		return consuMin(nodel, l, mid, start, end);
	else if( start > mid )
		return consuMin(noder, mid + 1, r , start, end);
	else
		return min(consuMin(nodel, l, mid, start, mid) , consuMin(noder, mid + 1, r , mid + 1, end) );

}


int main (){
	int n, q;
	scanf("%d%d", &n, &q);
	
	for(int i = 1 ; i  <= n ; i++)
		scanf("%d", &v[i]);
	
	build(1 , 1, n);
		
	for(int i = 0 ; i < q; i++){
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if( a == 1){
			printf("%d\n", consu(1, 1, n , b, c) - consuMax(1, 1, n , b, c) - consuMin(1, 1, n , b, c)); 
		}else{
			uptade(1, 1, n, b, c);
		}
	}
	return 0;
}
