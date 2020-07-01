//https://codeforces.com/problemset/problem/734/A
#include <bits/stdc++.h>
using namespace std;


int main(){

	int n, cont_a = 0, cont_d = 0;
	char ch;
	cin >> n;

	for(int i = 0; i < n; i++){
		scanf(" %c", &ch);
		if(ch == 'A')
			cont_a++;
		else
			cont_d++;
	}

	if(cont_a > cont_d)	
		cout << "Anton" << endl;
	else if(cont_d > cont_a)
		cout << "Danik" << endl;
	else
		cout << "Friendship" << endl;
return 0;
}	