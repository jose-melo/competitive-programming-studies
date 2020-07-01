#include <bits/stdc++.h>
using namespace std;

int k, n;
int v[100];
string s;

int tudoCerto(int mid){

	int a = 0, b = 0;

	for(int i = 0; i < mid; i++)
		if(s[i] == 'a')
			a++;
		else
			b++;

	
	if(a <= k || b <= k)
		return 1;

     int idx=0;
     for(int i = mid; i < n; i++){
         if(s[idx++]=='a')
         	a--;
         else 
			b--;
 
        if(s[i]=='a') 
			a++;
		else
			b++;
 
         if(a<=k||b<=k)
         	return 1;
 
 
 }
 return 0;
}

int buscaBinaria(int l, int r){

	while(l < r){
		
		int mid = l + (r-l+1) / 2;
	
		if(tudoCerto(mid))
			l = mid;
		else
			r = mid-1;
	}
return l;
}


int main(){

	cin >> n;
	cin >> k;

	cin >> s;


	cout << buscaBinaria(0, n) << endl; 
return 0;
}






