#include <bits/stdc++.h>
using namespace std;

#define MAX_N 300

int main(){

	int cases, num;
	string input;

	scanf("%d", &cases);

	while(cases--){

		input.clear();

		scanf("%d", &num);
		cin >> input;

		//cout << input << "\n";

		if(num == 2){
			if(input[1] > input[0]){

				printf("YES\n");
				printf("2 \n");
				printf("%c ", input[0]);
				printf("%c\n", input[1]);
			}else{
				printf("NO\n");
			}
		}else{
			printf("YES\n");
			printf("2 \n");
			printf("%c ", input[0]);
			cout << input.substr(1, input.size() - 1) << "\n";
		}
		input.clear();
	}
}



