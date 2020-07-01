#include <bits/stdc++.h>
using namespace std;


int primos[1123456];

void geraPrimos(){

	primos[2] = 0;
	primos[3] = 0;
	for(int i = 4; i < 1000001; i += 2)
		primos[i] = 1;	

	for(int i = 3; i < 1000001; i++)
		if(primos[i] == 0)
			for(int j = 2*i; j < 1000001; j += i)
				primos[j] = 1;

}



int main(){

	int n;

	geraPrimos();

	cin >> n;

	for(int i = 4; i < n; i++){
		if(primos[i] == 0)continue;
		if(primos[n-i] == 1){
			cout << n-i << " " << i << "\n";
			break;
		}
	}
	
return 0;
}
