#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

typedef long long ll;

ll f[20];

void precalc(){
	f[0] = 1;
	for (int i = 1; i <= 20; ++i){
		f[i] = i * f[i-1];
	}
}

int main(){
	precalc();
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		ll n;	cin >> n;
		stack <int> ans;
		for (int i = 20; i >= 0 and n > 0; --i){
			if(n >= f[i]){
				n -= f[i];
				ans.push(i);
			}
		}
		if(n == 0){
			while (!ans.empty()){
				cout << ans.top() << "!";
				ans.pop();
				if(!ans.empty())	cout << "+";
			}
			cout << endl;
		}
		else	cout << "impossible" << endl;
	}
	return 0;
}