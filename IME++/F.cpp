#include <bits/stdc++.h>
using namespace std;

int pai[112345], peso[112345];

int find(int x){
	if(pai[x] == x) return x;
	return pai[x] = find (pai[x]);
}

void join (int a, int b){
	a = find(a);
	b = find(b);
	if (a == b) return;
	if(peso[a] < peso[b]) pai[a] = b;
	else if (peso[b] < peso[a]) pai[b] = a;
	else{
		pai[a]=b;
		peso[b]++;
	}
}

int main(){
	int n, q, num;
	map<string, int> associ;
	string nome1, nome2;
	cin >> n >> q;
	for (int i = 0; i < 112345; i++) pai[i] = i;
	for (int i =0; i < 112345; i++) peso[i] = 1;
	for (int i = 0; i < n; i++){
		cin >> nome1;
		associ.insert(make_pair(nome1, i));
	}
	for (int i = 0; i < q; i++){
		cin >> num >>  nome1 >> nome2;
		auto p = associ.find(nome1);
		auto q = associ.find(nome2);
		int num1 = p->second;
		int num2 = q->second;
		if (num == 1) join (num1, num2);
		else{
			if (find(num1) == find(num2)) cout << "yes\n";
			else cout << "no\n";
		}
	}
	return 0;
}
		
