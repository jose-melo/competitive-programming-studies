#include <bits/stdc++.h>
using namespace std;

#define ll long long int 
ll n, k;

int main(){

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> n >> k;
	double a, bola;	
	a = n;
	bola = k;

	if(k > n && bola/a == 1){
		int i = 1;
		while(n*i < k)
			i++;
	
		cout << i << "\n";
		return 0;	
	}

	cout << ceil(bola/a) << "\n";
	
return 0;
}







