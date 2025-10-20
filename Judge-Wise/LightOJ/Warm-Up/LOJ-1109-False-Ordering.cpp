#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

vector<pii> nod(1001);		//number of divisor

int mysort(pii a, pii b){
	if(a.second == b.second)	return a.first>b.first;
	return a.second<b.second;
}
void preprocess(){
	for (int i = 0; i < 1001; ++i){
		nod[i].second = 1;
	}	
	nod[0].second = 0;
	nod[1].second = 1;
	for (int i = 1; i <= 1000; ++i){
		nod[i].first = i;
	}
	for (int i = 1; i <= 500; ++i){
		for (int j = 2*i; j <= 1000; j+=i){
			nod[j].second++;
		}
	}
	sort(nod.begin(), nod.end(), mysort);
}

int main(){
	preprocess();
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		int n;
		scanf("%d", &n);
		printf("Case %d: %d\n", ++tc, nod[n].first);
	}
	return 0;
}