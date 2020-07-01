#include <bits/stdc++.h>
using namespace std;


#define ll long long int

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	ll in1, in2, par1, par2, impar1, impar2;



	cin >> n; 
	
	while(n--){

		cin >> in1 >> in2;

		if(in1 % 2 == 0){
			par1 = in1;
			impar1 = in1 + 1;
		}
		else{
			par1 = in1 + 1;

			impar1 = in1;
		}

		if(in2 % 2 == 0){
			par2 = in2;
			impar2 = in2 - 1;
		}
		else{
			par2 = in2 - 1;
			impar2 = in2;
		}

		ll somaPar = ((par1 + par2)/2)*((par2-par1+2)/2);
		ll somaImpar = ((impar1 + impar2)/2)*((impar2-impar1+2)/2);

		ll res = somaPar - somaImpar;


		cout << res << endl;

	}
return 0;
}