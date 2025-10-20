#include<bits/stdc++.h>
using namespace std;

struct student
{
	string name;
	int vol;
};

bool comp(student a, student b){
	return a.vol > b.vol;
}

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		int n;	cin >> n;
		student a[n];
		for (int i = 0; i < n; ++i){
			cin >> a[i].name;
			int x, y, z;	cin >> x >> y >> z;
			a[i].vol = x*y*z;
		}
		sort(a, a+n, comp);
		if(a[0].vol != a[1].vol)	cout << a[0].name << " took chocolate from " << a[n-1].name << endl;
		else	puts("no thief");
	}
	return 0;
}