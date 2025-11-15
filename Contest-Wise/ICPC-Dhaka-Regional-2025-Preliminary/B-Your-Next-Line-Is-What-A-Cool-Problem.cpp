#include <bits/stdc++.h>
using namespace std;

void solve(int cn){
	int a,v,l,n;
	cin>>a>>v>>l>>n;

	if(a <= n) {
		cout<<"NO\n";
		return;
	}

	if(v > n) cout<<"YES\n";
	else cout<<"NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int tc;
	cin>>tc;

	for(int cn=1;cn<=tc;cn++) solve(cn);
}