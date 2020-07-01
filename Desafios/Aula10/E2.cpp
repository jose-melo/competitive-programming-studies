#include <bits/stdc++.h>
using namespace std;


int main(){
	
	int n, k;
	string s;

	cin >> n >> k;
	cin >> s;
	int i;
	int maxA = -1, startA = 0, endA = s.size(), contA = 0, pA = 0, qA = s.size();
	for(i = 0; i < s.size(); i++){
		if(s[i] == 'b'){
			if(contA > maxA){
				maxA = contA;
				startA = pA;
				endA = i-1;
			}
			contA = 0;
			pA = i+1;
		}else{
			contA++;
		}
	}
	if(contA > maxA){
		maxA = contA;
		startA = pA;
		endA = i-1;
	}
	
	int maxB = -1, startB = 0, endB = s.size(), contB = 0, pB = 0, qB = s.size();
	for(i = 0; i < s.size(); i++){
		if(s[i] == 'a'){
			if(contB > maxB){
				maxB = contB;
				startB = pB;
				endB = i-1;
			}
			contB = 0;
			pB = i+1;
		}else{
			contB++;
		}
	}
	if(contB > maxB){
		maxB = contB;
		startB = pB;
		endB = i-1;
	}


	int addA = 0, addB = 0;
	while(addA <= k && startA >= 0 && endA < n){
		endA++;
		startA--;
		while(startA >= 0 && addA <= k){
			if(s[startA] == 'b')
				addA++;
			if(addA <= k)maxA++;
			startA--;
		}

		while(endA < n && addA <= k){
			if(s[endA] == 'b')
				addA++;
			if(addA <= k)maxA++;
			endA++;
		}
	}


	while(addB <= k && startB >= 0 && endB < n){
		startB--;
		endB++;
		while(startB >= 0 && addB <= k){
			if(s[startB] == 'a')
				addB++;
			if(addB <= k)maxB++;
			startB--;
		}

		while(endB < n && addB <= k){
			if(s[endB] == 'a')
				addB++;
			if(addB <= k)maxB++;
			endB++;
		}
	}
	cout << max(maxA, maxB) << "\n";	

}

