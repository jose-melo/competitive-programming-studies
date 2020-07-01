#include <bits/stdc++.h>
using namespace std;

#define INF 0x3f3f3f3f
#define MAX_STAGE 1000
#define ll long long int

typedef struct sho
{
	int start, end, gold;
	
} show;

int memo[(1<<10)+10][86410];
int memo2[(1<<10)+10][10];
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

void pd(){

	int time, stage_state, stage;
	memo[0][0] = 0;

	for(stage_state = 0; stage_state < (1<<num_stages); stage_state++)
		memo[stage_state][0] = -INF;

	for(time = 0; time <= 86400; time++){
		for(stage_state = 0; stage_state < (1<<num_stages); stage_state++){
			memo[stage_state][time] = max(memo[stage_state][time], memo[stage_state][time-1]);

			for(stage = 0; stage < num_stages; stage++){
				if(stage_state & (1<<stage)){
					
					for(auto showw = shows[stage].begin();showw != shows[stage].end(); showw++){
						if(showw->end == time){
							if(stage_state != (1<<num_stages)-1){
								memo[stage_state][time] = max(memo[stage_state][time], 
										max(memo[stage_state][showw->start] + showw->gold,
										 memo[stage_state ^ (1<<stage)][showw->start] + showw->gold));
														
							printf("memo = %d stage_state = %d time = %d\n", memo[stage_state][time], stage_state, time);				
							break;
						}
					}
				}				
			}
		}
	}
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

	//for(int i = 0; i < num_stages; i++)
	//	sort(shows[i].begin(), shows[i].end(), comp);

	//for(auto pointer = shows.begin(); pointer != shows.end(); pointer++)
	//	printf("%d %d %d %d\n", pointer->start, pointer->end, pointer->gold, pointer->stage);
	
	for(int i = 0; i <= (1<<num_stages);i++)
		for(int j = 0; j < 86400; j++)
			memo[i][j] = -INF;


	pd();

	//printf("memomo = %d\n", memo[6][80]);

	int resposta = -1;	
	for(int i = 0; i < 86400; i++)
		resposta = max(resposta, memo[(1<<num_stages) - 1][i]);

	if(resposta > 0)
		cout << resposta << endl;
	else
		cout << "-1" << endl;

return 0;
}







