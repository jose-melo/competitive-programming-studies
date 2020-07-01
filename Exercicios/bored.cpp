#include <bits/stdc++.h>
using namespace std;



long long int fat(long long int a){

	if(a == 1 || a == 0)return 1;

return fat(a - 1) * a;
}


int main(){

	long long int a, b, fact;

	scanf("%lli %lli", &a, &b);

	if(a < b)
		fact = fat(a);
	else
		fact = fat(b);

	printf("%lli\n", fact);

return 0;
}