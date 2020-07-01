#include <bits/stdc++.h>
using namespace std;


#define  ii pair <int, int>
#define MAX_N 10500
#define INF 100000000

int V, E, T, S;

vector<ii> listAdj[MAX_N];

int d[MAX_N];

void initialize(){

	for(int i = 0; i <= V; i++)
		d[i] = INF;

}