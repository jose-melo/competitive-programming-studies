#include <bits/stdc++.h>
using namespace std;


#define ll long long int
#define MAX_N 25100
#define MAX_LEN 17

map<string, int> pal;

int main(){

	int maxLength = 1, length;

	string w1;

	//ifstream in;
    //in.open("test_case.txt"); 

   // getline(cin, w1);
	while(cin >> w1){

		length = 1;

		for(int i = 0; i < w1.size(); i++)
			for(char ch = 'a'; ch <= 'z'; ch++){

				string w2(w1);

				w2.insert(i, 1, ch);

				//cout << w2 << "\n";

				if(w2 > w1)
					break;

				if(pal.find(w2) != pal.end()){
					//printf("pal[w2] = %d\n",pal[w2] );
					length = max(length, pal[w2] + 1);
				}
			}


		for(int i = 0; i < w1.size(); i++){

			string w2(w1);

			w2.erase(i, 1);

			//cout << w2 << "\n";

			if(pal.find(w2) != pal.end()){
				//printf("pal[w2] = %d\n",pal[w2] );
				length = max(length, pal[w2] + 1);
			}
		}


		for(int i = 0; i < w1.size(); i++)
			for(int ch = 'a'; ch <= 'z' && ch != w1[i]; ch++){

				string w2(w1);

				w2[i] = ch;

				//cout << w2 << "\n";

				if(w2 > w1)
					break;

				if(pal.find(w2) != pal.end()){
					//printf("pal[w2] = %d\n",pal[w2] );
					length = max(length, pal[w2] + 1);
				}
			}

		pal.insert(make_pair(w1, length));
		maxLength = max(maxLength, length);
	
		//printf("maxLength = %d\n", maxLength);

   		//getline(cin, w1);
	}

	cout << maxLength << "\n";
return 0;
}



