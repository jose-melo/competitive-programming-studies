#include <bits/stdc++.h>
using namespace std;

int main(){

	FILE *arq;

	arq = fopen("casos.txt", "w");


	for(int i = 1; i < 100000; i++)
		fprintf(arq, "%d %d 99999\n", i, i + 1);

return 0;
}