#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		int stYr, edYr;
		string mnth;	cin >> mnth;
		int date, year;
		scanf("%d, %d", &date, &year);
		if(mnth == "January"  or mnth == "February"){
			stYr = year; 
		}
		else{
			stYr = year + 1;
		}
		cin >> mnth;
		scanf("%d, %d", &date, &year);
		if(mnth == "January" or (mnth == "February" and date < 29)){
			edYr = year - 1;
		}
		else{
			edYr = year;
		}

		int yrIdx = stYr;
		int ans = 0;

		while (true and yrIdx <= edYr){
			if(yrIdx%400 == 0 or (yrIdx%4 == 0 and yrIdx%100!=0))	ans++;
			yrIdx++;
			if(yrIdx%400 == 1)	break;
		}

		if(yrIdx <= edYr - 400+1){
			ans += (edYr-yrIdx+1)/400 * 97;
			yrIdx += (edYr-yrIdx+1) / 400 * 400;
		}

		while (yrIdx <= edYr){
			if(yrIdx%400 == 0 or (yrIdx%4 == 0 and yrIdx%100!=0))	ans++;
			yrIdx++;
		}
		cout << ans << endl;
	}
	return 0;
}