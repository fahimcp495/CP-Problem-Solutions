#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	char c = getchar();
	while(T--){
		printf("Case %d: ", ++tc);
		string a, b;	
		getline(cin, a);
		getline(cin, b);
		map<char, int> mpa;
		map<char, int> mpb;
		for (int i = 0; a[i]; ++i){
			if(a[i] != ' ')	mpa[toupper(a[i])]++;
		}

		for (int i = 0; b[i]; ++i){
			if(b[i] != ' ')	mpb[toupper(b[i])]++;
		}

		bool match = true;
		for(auto at : mpa){
			if(at.second != mpb[at.first])	match = false;
		}

		for(auto at : mpb){
			if(at.second != mpa[at.first])	match = false;
		}

		if(match)	puts("Yes");
		else		puts("No");
	}
	return 0;
}