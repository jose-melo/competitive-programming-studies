#include <bits/stdc++.h>
using namespace std;

int n, m, add, y, x;
vector<pair<int, int>> pontos;


int main(){

	cin >> n >> m;

	x = 0;
	y = m;

	while(y >= 0 && x <= n){
		pontos.push_back(make_pair(x, y));
		x++;
		y--;
	}

	cout << pontos.size() << "\n";
	for(auto x : pontos)
		cout << x.first << " " << x.second << "\n";
return 0;
}

