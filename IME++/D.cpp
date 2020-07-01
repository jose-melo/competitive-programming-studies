#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	long long int v[30050], soma[10050];
	memset(soma, 0, 10050*sizeof(long long int));
	cin >> n;
	for(int i = 0; i < 2*n; i++)
		cin >> v[i];
	sort(v, v+(2*n));
	for (int i = 0, j = 2*n-1; i < n; i++,j--){
		soma[i] += v[i];
		soma[i] += v[j];
	}
	sort(soma, soma+n);
	cout << soma[n-1] - soma[0] << endl;
	return 0;
}		
