#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;

int contaA(int l, int r){

	int cont = 0;

	for(int i = l; i <= r; i++)
		if(s[i] == 'a')
			cont++;
return cont;
}

int contaB(int l, int r){

	int cont = 0;

	for(int i = l; i <= r; i++)
		if(s[i] == 'b')
			cont++;
return cont;
}

int bsA(int ini, int fim){

	int mid, l, r, b;
	l =  ini;
	r = fim;
	int x = k;
	x++;
	int contA = 0;

	while(l < r){
		mid = (l+r+1)/2;
		b = contaB(l, mid);
		if(b < x){
			contA += mid-l;
			l = mid;
			x -= b;
			continue;
		}
		if(b > x){
			r = mid-1;
			continue;
		}
		if(b ==x){
			contA += mid-l;
			break;
		}
	}
return contA;		
}

int binarySearchB(int l, int r) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (contaA(l, mid) == k) 
            return mid; 
  
        if (contaA(l, mid) > k) 
            return binarySearchB(l, mid - 1); 
  
        return binarySearchB(mid + 1, r); 
    } 
  
    return -1; 
} 
int binarySearchA(int l, int r) 
{ 
    if (r >= l) { 
        int mid = l + (r - l) / 2; 
  
        if (contaA(l, mid) == k) 
            return mid; 
  
        if (contaA(l, mid) > k) 
            return binarySearchA(l, mid - 1); 
  
        return binarySearchA(mid + 1, r); 
    } 
  
    return -1; 
} 
  
int bsB(int ini, int fim){

	int mid, l, r, a = 0;
	l =  ini;
	r = fim;
	int x = k;
	int contB = 0;
	while(l < r){
		mid = (l+r+1)/2;
		a += contaA(l, mid);
		if(a < x){
			contB += mid-l;
			l = mid;
			continue;
		}
		if(a >x){
			r = mid-1;
			continue;
		}
		if(a == x){
			contB += mid-l;
			break;
		}
	}
return contB;		
}


int main(){

	cin >> n >> k;

	cin >> s;
	
	int maxB = -1;

	cout << binarySearchB(0, n-1) << endl;


}


