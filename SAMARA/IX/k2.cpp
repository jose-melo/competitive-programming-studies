#include <bits/stdc++.h>
using namespace std;


string s;


int main(){

	int p, q, a = -1, b = -1;
	bool control = true;
	cin >> s;

	p = 0;
	q = s.size() - 1;
	while(p < q){
		if(s[p] != s[q]){
			a = p;
			b = q;
			break;
		}
		p++;
		q--;
	}

	if(a == -1){
		printf("YES\n");
		cout << (s.size())/2 + (s.size()%2) << endl;
		return 0;
	}

	control = true;
	p = 0;
	q = s.size() - 1;
	while(p < q){
		if(p == a)p++;
		if(s[p] != s[q])
			control = false;
		p++;
		q--;
	}

	if(control){
		printf("YES\n");
		printf("%d\n", a+1);
		return 0;
	}

	control = true;
	p = 0;
	q = s.size() - 1;
	while(p < q){
		if(q == b)q--;
		if(s[p] != s[q])
			control = false;
		p++;
		q--;
	}

	if(control){
		printf("YES\n");
		printf("%d\n", b+1);
		return 0;
	}

	cout << "NO\n";
return 0;
}





