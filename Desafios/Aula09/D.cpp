#include <bits/stdc++.h>
using namespace std;

int n, k;
int v[112345];
int foi[112345];

void troca(int i, int j){

	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;
}

int main(){

	cin >> n >> k;
	
	int idx = 1;
	cout << "1 ";
	foi[1] = 1;
	int troca = 1;
	for(int i = k; i > 0; i--){
		if(troca){
			cout << i+idx << " ";
			foi[i+idx] = 1;
			idx = i+idx;
			troca = 0;
		}else{
			cout << idx-i << " ";
			foi[idx-i] = 1;
			idx = idx - i;
			troca = 1;
		}
	}

	for(int i = 1; i <= n; i++)
		if(foi[i] == 0)
			cout << i << " ";


	cout << "\n";
return 0;
}





