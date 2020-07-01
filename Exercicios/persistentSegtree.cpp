#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define MAX_N 101000

ll input[MAX_N];
ll sorted_input[MAX_N];

struct Vertex{
	
	Vertex *l, *r;
	ll sum;

	Vertex(ll a) : l(nullptr), r(nullptr), sum(a){}
	Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0){
		if(l) sum += l->sum;
		if(r) sum += r->sum;
	}
};

Vertex* roots[MAX_N];

Vertex* build(ll a, ll b){

	if(a == b){
		return new Vertex(0);
	}

	ll m = (a + b) / 2;

	return new Vertex(build(a, m), build(m+1, b));
}

Vertex* update(Vertex* node, ll a, ll b, ll pos){

	if(node == nullptr)return node;

	if(a > b)return nullptr;

	if(a == b){
		return new Vertex(node->sum + 1);
	}

	ll m = (a+b) / 2;

	if(pos <= m)
		return new Vertex(update(node->l, a, m, pos), node->r);	
return new Vertex(node->l, update(node->r, m+1, b, pos));
}

ll query(Vertex* root, Vertex* root_ant, ll a, ll b, ll k){

	//printf("query root->sum = %lli, root_ant->sum = %lli a = %lli b = %lli k = %lli\n",root->sum, root_ant->sum, a, b, k);

	if(root == nullptr || root_ant == nullptr)return 0;

	if(a > b){
		//printf("retornou 0\n");
		return 0;
	}

	if(a == b){
		//printf("retornou %lli\n", sorted_input[a]);
		return sorted_input[a-1];		
	}
	
	ll m = (a + b) / 2;

	if(k <= (root->l->sum - root_ant->l->sum)){
		ll aux	= query(root->l, root_ant->l, a, m, k);
		
		//printf("retornou %lli\n", aux);

		return aux;
	}
	
	ll aux2 = query(root->r, root_ant->r, m+1, b, k - (root->l->sum - root_ant->l->sum));
	//printf("retornou %lli\n", aux2);
return aux2;
}

void inorder(Vertex* root){
	if(root != nullptr){
		//printf("%lli ", root->sum);
		inorder(root->l);
		inorder(root->r);
	}
}

ll removeDuplicates(ll arr[], ll n) 
{ 
    
    if (n==0 || n==1) 
        return n; 
  
    ll temp[n]; 
  
    
    ll j = 0; 
    for (ll i=0; i<n-1; i++) 
  
    
        if (arr[i] != arr[i+1]) 
            temp[j++] = arr[i]; 
  
  
    temp[j++] = arr[n-1]; 
  
    for (ll i=0; i<j; i++) 
        arr[i] = temp[i]; 
  
    return j; 
} 


int main(){

	ll n, m, i, j, k;

	scanf("%lli %lli", &n, &m);

	for(ll o = 0; o < n; o++){
		scanf("%lli", &input[o]);
		sorted_input[o] = input[o];
	}

	sort(sorted_input, sorted_input + n);

	int g = removeDuplicates(sorted_input, n);

	/*printf("input: ");
	for(int h = 0; h < n; h++)
		printf("%lli ", input[h]);
	printf("\n");

	printf("sorted_input: ");
	for(int h = 0; h < n; h++)
		printf("%lli ", sorted_input[h]);
	printf("\n");*/

	roots[0] = build(1, n);

	/*printf("roots[0]: ");
	inorder(roots[0]);
	printf("\n");*/

	for(ll p = 1; p <= n; p++){

		ll pos = lower_bound(sorted_input, sorted_input + n, input[p-1]) - sorted_input;

		//printf("num = %lli pos = %lli\n", input[p-1], pos+1);

		roots[p] = update(roots[p-1], 1, n, pos+1);

		/*printf("roots[%lli]: ", p);
		inorder(roots[p]);
		printf("\n");*/

	}
	

	while(m--){
		scanf("%lli %lli %lli", &i, &j, &k);
		printf("%lli\n", query(roots[j], roots[i-1], 1, n, k));
	}

return 0;
}