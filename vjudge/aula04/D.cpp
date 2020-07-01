/*https://codeforces.com/problemset/problem/219/A*/
#include <bits/stdc++.h>
using namespace std;

int k;
string s;
string s1;
int letras[27];

int main(){

	cin >> k >> s;

	for(int i = 0; i < 27; i++)
		letras[i] = 0;

	for(int i = 0; i < s.size(); i++)
		letras[s[i] - 'a']++;


	for(int i = 0; i < 27; i++){
		if(letras[i] == 0)continue;
		if(letras[i] % k  == 0){
			s1.insert(s1.end(),letras[i] / k, i+'a');
		}else{
			cout << "-1" << endl;			
			return 0;
		}
	}
	for(int i = 0; i < k; i++)
		cout << s1;
	

	cout << endl;
return 0;
}