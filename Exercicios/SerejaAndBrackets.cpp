#include <bits/stdc++.h>
using namespace std;


#define MAX_N 10100000
#define ll long long int

string seg[4*MAX_N];
ll seg_max[4*MAX_N];
string input;

void add(string a, string b){
	a.append(b);
return;
}

ll conta(string v){

	stack<char> pilha;
	
	string :: iterator it = v.begin();

	char ch;
	ll cont = 0;
	while(it < v.end()){
		
		ch = *it;
		if(ch == '(')
			pilha.push(ch);
		else{
			if(!pilha.empty()){
				char aux = pilha.top();
				pilha.pop();
				if(aux == '(')
					cont = cont + 2;
			}
		}
		it++;
	}

return cont;
}

void build(ll node, ll a, ll b){

	//printf("build node = %d a = %d b = %d\n", node, a, b);

	if(a == b){
		seg[node] = input.at(a - 1);
		seg_max[node] = 0;
		return;
	}

	ll m = (a + b) / 2;	

	build(2*node, a, m);
	build(2*node + 1, m + 1, b);

	seg[node] = seg[2*node];

	/*printf("seg: \n");
	cout << seg[node]<< "\n";*/

	seg[node].append(seg[2*node + 1]);

	/*printf("seg: \n");
	cout << seg[node]<< "\n";*/

	ll max = conta(seg[node]);
	seg_max[node] = max;
	//printf("seg_max[node = %d] = %d\n",node, seg_max[node] );

return;
}

string query(ll node, ll a, ll b, ll l, ll r, ll *res){

	//printf("query node = %d a = %d b = %d l = %d r = %d res = %d\n", node, a, b, l, r, *res);

	if(a > r || b < l || l > r){
		string teta = "";
		return teta;}


	if(a >= l && b <= r){
		*res = seg_max[node];
		return seg[node];
	}

	ll m = (a + b) / 2;

	if(a <= l && r <= m)
		return query(2*node, a, m, l, r, res);

	if(m < l && r <= b)
		return query(2*node + 1, m + 1, b, l, r, res);

	string aux;

	aux.append(query(2*node, a, m, l, r, res));
	aux.append(query(2*node + 1, m + 1, b, l, r, res));

	*res = conta(aux);

return aux;
}

int main(){

	ll m, x, y, res;

	getline(cin, input);

	/*printf("input: ");
	cout << input << "\n";*/

	build(1, 1, (ll) input.size());

	scanf("%lli", &m);

	for(ll i = 0; i < m; i++){
		res = 0;
		scanf("%lli %lli", &x, &y);
		query(1, 1, input.size(), x, y, &res);
		printf("%lli\n", res);
	}
return 0;
}





