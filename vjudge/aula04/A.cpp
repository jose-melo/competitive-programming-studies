/*https://codeforces.com/problemset/problem/1073/A*/
#include <bits/stdc++.h>
using namespace std;

int n;
string s;

int main(){

	cin >> n >> s;

	char ant = s[0];
	for(int i = 1; i < n; i++)
		if(s[i] != ant){
			cout << "YES" << endl;
			printf("%c%c\n", ant, s[i]);
			return 0;
		}

	cout << "NO" << endl;
return 0;
}



