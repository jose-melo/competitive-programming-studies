#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> casa;

int matriz[500][500];

vector<casa> v{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};


int main(){


	vector<casa> :: iterator it;

	for(it = v.begin(); it < v.end(); it++)
		printf("(%d %d)\n", (*it).first, (*it).second);

return 0;
}