#include <bits/stdc++.h>
using namespace std;

int S[112345];

int main(){

	int n;

	scanf("%d", &n);


	for(int i = 0; i < n; i++)
		scanf("%d", &S[i]);

	sort(S, S + n);

	for(int i = 1; i < n; i++){
		if(S[i] == S[i-1]){
			printf("There's duplicates\n");
			return 0;
		}
	}

	printf("There's no duplicates\n"); 

	return 0;
}
