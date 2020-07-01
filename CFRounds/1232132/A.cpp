#include <bits/stdc++.h>
using namespace std;

int n;
long long int num[1010];


int main(){

	cin >> n;

	for(int i = 0; i < n; i++)
		cin >> num[i];


	for(int i = 0; i < n; i++)
		if(num[i] % 2)
			cout << num[i] << " ";
		else
			cout << num[i]-1 << " ";

		printf("\n");

return 0;
}