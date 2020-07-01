/*https://codeforces.com/problemset/problem/1038/A*/
#include <bits/stdc++.h>
using namespace std;

int n, k;
int freq[30];
string s;

int main(){

	cin >> n >> k >> s;

	for(int i = 0; i < n; i++)
		freq[s[i]-'A']++;

	sort(freq, freq + k);

	cout << freq[0]*k << "\n";
return 0;
}






