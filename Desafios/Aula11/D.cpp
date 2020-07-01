#include <bits/stdc++.h>
using namespace std;

#define ll long long int

string s;
ll memo[312345];

ll pd(int tam){

	int idx = tam - 1;

	if(tam == 1)
		if((s[idx] - '0') % 4 == 0)
			return 1;
		else
			return 0;

	if(memo[tam] != -1)
		return memo[tam];


	memo[tam] = pd(tam-1);

	if((s[idx]-'0') % 4 == 0)memo[tam]++;
	
	if((((s[idx-1]-'0')*10)+(s[idx]-'0')) % 4 == 0){
		if(tam > 2)
			memo[tam] += (tam-2);
		memo[tam] += 1;		
	}
return memo[tam];
}




int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> s;

	for(int i = 0; i <= s.size(); i++)
		memo[i] = -1;	

	cout << pd(s.size()) << "\n"; 

return 0;
}



