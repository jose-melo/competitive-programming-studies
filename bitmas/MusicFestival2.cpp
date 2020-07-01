#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_STAGE 1000
#define ll long long int

typedef struct sho
{
	int start, end, gold;
	
} show;

ll memo[(1<<10)+10][86410];
vector<show> shows[11];
int pos[11];
int stage_show[11];

int num_stages, num_shows;

bool comp(show a, show b){
	if(a.start < b.start)
		return true;
return false;
}
/*
bool comp2(show a, int b){
	if(a.start < b)
		return true;
return false;
}*/

ll pd(int stages_state, int atual_time){
	
	/*printf("stages_state = %d atual_time = %d\n", stages_state, atual_time);
	for(int i = 0; i < num_stages; i++){
		printf("%d ", pos[i]);
	}
	printf("\n");*/
	int aux;
	int control = 0;
	int stages_state_aux;

	for(int i = 0; i < num_stages; i++){
		//printf("shows[%d][%d] = %d %d %d\n", i, pos[i], shows[i][pos[i]].start, shows[i][pos[i]].end, shows[i][pos[i]].gold);
		aux = pos[i];
		while(pos[i] < stage_show[i] && shows[i][pos[i]].start < atual_time)
			pos[i]++;
		if(pos[i] < stage_show[i])
			control = 1;
		pos[i] = aux;
	}

	if(control == 0) 
	if(stages_state != (1<<num_stages)-1 || stages_state == 0)
		return -INF;
	else
		return 0;


	if(memo[stages_state][atual_time] != -1)
		return memo[stages_state][atual_time];
	
	memo[stages_state][atual_time] = -INF;
	for(int i = 0; i < num_stages; i++){
		//printf("shows[%d][%d] = %d %d %d\n", i, pos[i], shows[i][pos[i]].start, shows[i][pos[i]].end, shows[i][pos[i]].gold);
		aux = pos[i];
		while(pos[i] < stage_show[i] && shows[i][pos[i]].start < atual_time)
			pos[i]++;

		if(pos[i] < stage_show[i]){
			control = 1;
			stages_state_aux = stages_state | (1<<i);
			pos[i]++;
			memo[stages_state][atual_time]  = max(memo[stages_state][atual_time],
								 pd(stages_state_aux,shows[i][pos[i]-1].end) + shows[i][pos[i]-1].gold);
		}
		pos[i] = aux;
	}

	
//printf("returned %d\n", memo[stages_state][atual_time]);
return memo[stages_state][atual_time];
}

int main(){

	int stt, ed, gd;

	cin >> num_stages;

	for(int i = 0; i < num_stages; i++){
		cin >> num_shows;
		for(int j = 0; j < num_shows; j++){
			cin >> stt >> ed >> gd;
			show adder;
			adder.start = stt;
			adder.end = ed;
			adder.gold = gd;
			shows[i].push_back(adder);
			stage_show[i] = num_shows;
		}
	}

	for(int i = 0; i < num_stages; i++)
		sort(shows[i].begin(), shows[i].end(), comp);

	//for(auto pointer = shows.begin(); pointer != shows.end(); pointer++)
	//	printf("%d %d %d %d\n", pointer->start, pointer->end, pointer->gold, pointer->stage);
	
	for(int i = 0; i <= (1<<num_stages);i++)
		for(int j = 0; j < 86400; j++)
			memo[i][j] = -1;

	ll resposta = pd(0, 0);
	if(resposta > 0)
		cout << resposta << endl;
	else
		cout << "-1" << endl;

return 0;
}







