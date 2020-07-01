#include <bits/stdc++.h>
using namespace std;

int n;


int main(){

	cin >> n;

	int max, aux;

	bool ja_imprimi = false;

	for(int i = 0; i < n; i++){

		max = -1;

		for(int j = 0; j < n; j++){
			cin >> aux;
			if(aux > max)	
				max = aux;
		}
	
		if(max == n-1 && !ja_imprimi){
			cout << n << " ";
			ja_imprimi = true;
			continue;
		}
		
		cout << max << " ";

	}

	cout << "\n";

return 0;
}





