#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_STAGE 1000

typedef struct sho
{
	int start, end, gold, stage;
	
} show;

int memo[(1<<10)+10][86400];
vector<show> shows;

int num_stages, num_shows;

bool comp(show a, show b){
	if(a.start < b.start)
		return true;
return false;
}

bool comp2(show a, int b){
	if(a.start < b)
		return true;
return false;
}

int pd(int stages_state, int atual_time){
	
	//printf("stages_state = %d atual_time = %d\n", stages_state, atual_time);
	auto pointer = lower_bound(shows.begin(), shows.end(), atual_time, comp2);
	if(pointer == shows.end())
		if(stages_state != (1<<num_stages)-1 || stages_state == 0)
			return -INF;
		else
			return 0;

	if(memo[stages_state][atual_time] != -1)
		return memo[stages_state][atual_time];

	memo[stages_state][atual_time] = -INF;
	int stages_state_aux;
	//printf("pointer = %d %d %d %d\n", pointer->start, pointer->end, pointer->gold, pointer->stage);
	for(;pointer != shows.end(); pointer++){
		stages_state_aux = stages_state | (1<<(pointer->stage - 1));
		memo[stages_state][atual_time]  = max(memo[stages_state][atual_time],
								 pd(stages_state_aux, pointer->end) + pointer->gold);
	}
	//printf("returned %d\n", memo[stages_state][atual_time]);
return memo[stages_state][atual_time];
}

int main(){

	int stt, ed, gd;

	cin >> num_stages;

	for(int i = 1; i <= num_stages; i++){
		cin >> num_shows;
		for(int j = 0; j < num_shows; j++){
			cin >> stt >> ed >> gd;
			show adder;
			adder.start = stt;
			adder.end = ed;
			adder.gold = gd;
			adder.stage = i;
			shows.push_back(adder);
		}
	}

	sort(shows.begin(), shows.end(), comp);




	//for(auto pointer = shows.begin(); pointer != shows.end(); pointer++)
	//	printf("%d %d %d %d\n", pointer->start, pointer->end, pointer->gold, pointer->stage);
	
	for(int i = 0; i <= (1<<num_stages);i++)
		for(int j = 0; j < shows.back().end; j++)
			memo[i][j] = -1;

	int resposta = pd(0, 0);
	if(resposta > 0)
		cout << resposta << endl;
	else
		cout << "-1" << endl;

return 0;
}







