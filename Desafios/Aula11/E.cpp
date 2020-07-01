#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll memo[112345], input[112345];
ll freq[112345];
int n;

ll pd(int num){
	
	if(num == 0)
		return freq[0];
	
	if(num == 1)
		return freq[1];

	if(memo[num] != -1)
		return memo[num];
	memo[num] = max(pd(num-1), pd(num-2) + (num*freq[num]));

return memo[num];
} 


int main(){

	cin >> n;

	for(int i = 1; i <= n; i++)
		cin >> input[i];

	for(int i = 1; i <= n; i++)
		freq[input[i]]++;


	for(int i = 1; i <= 100010; i++)
		memo[i] = -1;

	cout << pd(100000) << "\n";
return 0;
}


















