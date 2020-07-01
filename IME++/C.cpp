#include <bits/stdc++.h>
using namespace std;
int n ,x ,d;
int mask[20];

bool checkmin(int bits){
	long long int total = 0;
	for(int i = 0 ; i < n; i++){
		if(bits&(1<<i))
			total += mask[i];
	}
	
	if( total < x )
		return false;
	return true;
}


bool checkdif(int bits ){
	int i, j;
	for(i = 0 ; i < n; i++){
		if(bits&(1<<i))
			break;
	}	

	for(j = n-1 ; j >= 0 ; j--){
		if(bits&(1<<j))
			break;
	}
      
	if(i == j)
		return true;
	
	if(mask[j] - mask[i] <  d)
		return true;

	return false;

}


int main (){

	cin >> n;
	cin >> x;
	cin >> d;

	for(int i = 0 ; i < n ; i++)
		cin >> mask[i];

	sort(mask, mask+n);

	int cont = 0;

	for(int i = 1 ; i < (1<<n) ; i++){
		
		int ok = 1;

		if(!checkmin(i))
			ok = 0;

		if(!checkdif(i))
			ok = 0;

		if( ok == 1 )
			cont++;

	}
	
	printf("%d\n", cont);
	
}

