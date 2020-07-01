#include <bits/stdc++.h>

#define _USE_MATH_DEFINES

using namespace std;
using namespace std::chrono;

int main(){

	int n;

	year_month_day dmy;

	parse("%d %m %Y", dmy);

	printf("%A\n", weekaday{dmy});

}
