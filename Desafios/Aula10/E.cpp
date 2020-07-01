#include <bits/stdc++.h>
using namespace std;

int n, k;


int main(){


	int l, r;
	string s;

	cin >> n >> k;

	cin >> s;
	
	int maxA = -1;
	int maxB = -1; 
	int contA;
	int totalA = 0, totalB = 0;
	int contB;

	l = 0;
	while(l < s.size()){

		contA = 0;
		totalA = 0;
		r = l;
		while(contA <= k && r < s.size()){
			if(s[r] == 'b')
				contA++;
			if(contA <= k)totalA++;
			r++;
		}
		
		if(totalA > maxA)
			maxA = totalA;

		l++;

	}
	
	l = 0;
	while(l < s.size()){
		
		totalB =0;
		contB = 0;
		r = l;
		while(contB <= k && r < s.size()){
			if(s[r] == 'a')
				contB++;	
			if(contB <= k)totalB++;
			r++;
		}

		if(totalB > maxB)
			maxB = totalB;

		l++;
	}
	
	cout << max(maxA, maxB) << endl;
return 0;
}


