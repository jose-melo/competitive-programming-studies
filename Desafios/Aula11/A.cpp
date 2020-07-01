#include <bits/stdc++.h>
using namespace std;

int main(){

	int n;
	int v[200];
	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> v[i];

	int max = -1, xo;
	for(int i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			xo = v[i];
			if(xo > max)max = xo;
			for(int k = i+1; k <= j; k++)
				xo = xo ^ v[k];
			if(xo > max)
				max = xo;		
		}
	}

	cout << max << "\n";
return 0;
}

