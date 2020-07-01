#include <bits/stdc++.h>
using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);



	int n, m, v[112345], soma[112345], a, b;

	cin >> n >> m;
	
	soma[0] = 0;

	for(int i = 1; i <= n; i++){
		cin >> v[i];
		soma[i] = soma[i-1] + v[i];
	}

	for(int i = 1; i <= m; i++){
		cin >> a >> b;
		if((soma[b] -  soma[a-1]) % 2)
			cout << "Nao\n";
		else
			cout << "Sim\n";
	}
return 0;
}


