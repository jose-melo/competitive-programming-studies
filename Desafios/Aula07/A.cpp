#include <bits/stdc++.h>
using namespace std;

int n;
int v[200];

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int eh_impar;
	
	cin >> v[1];
	eh_impar = v[1] % 2;
	cin >> v[2];

	if(v[2] % 2 != eh_impar){
		cin >> v[3];
		if(v[3]%2 == eh_impar){
			cout << "2\n";
			return 0;
		}else{
			cout << "1\n";
			return 0;
		}
	}

	for(int i = 3; i <= n; i++){
		cin >> v[i];	
		if(v[i]%2 != eh_impar){
			cout << i << "\n";
			return 0;
		}
	}	
return 0;
}

