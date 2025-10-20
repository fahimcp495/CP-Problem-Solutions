#include<bits/stdc++.h>
using namespace std;

#define IOS 		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define si(n)       scanf("%d", &n)
#define sii(a,b)    scanf("%d %d", &a, &b)
#define siii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define all(a) 	a.begin(),a.end()
#define unq(x)      x.erase(unique(all(x)), x.end()
#define mp 		make_pair
#define sz(a) 		int((a).size())
#define CLR(a)      memset(a,0,sizeof(a))
#define SET(a)      memset(a,-1,sizeof(a))
#define vintitr 	vector<int>::iterator
#define vlnlnitr 	vector<long long>::iterator
#define sintitr 	set<int>::iterator
#define slnlnitr 	set<long long>::iterator
#define aa		first
#define bb		second
#define mod 		1000000007
#define PI 		acos(-1.00)
#define psb 		push_back
#define ppb		pop_back
#define psf		push_front
#define ppf		pop_front
#define in 		insert
#define FOR(i, n) 	for(int i=0; i<n; i++)
#define FORR(i, n)  for(int i=n-1; i>=0; i--)
#define max2(a,b)   ((a)>(b)?(a):(b)
#define min2(a,b)   ((a)<(b)?(a):(b))
#define min3(a,b,c) (min((c),min((a),(b))))
#define max3(a,b,c) (max((a),max((b),(c))))
#define __lcm(a, b)	a*b / __gcd(a, b)
#define D(t)        cerr << #t " = " <<t  << '\n'
#define DBG         cerr << "Hi!" << '\n'


typedef long long	 		ll;
typedef unsigned long long	ull;
typedef long double			ld;
typedef pair<int, int> 		pii;
typedef pair<ll, ll> 		pll;

int cases, caseno = 0;
int m, n, mn, mx, ans;

int main()
{
//	freopen("t.in","r",stdin);
//	freopen("t.out","w",stdout);
	IOS;
	si(cases);
	while(cases--)
	{
		sii(m, n);
		mn = min(m, n);
		mx = max(m, n);
		if (mn == 1)
			ans  = mx;
		else if (mn == 2)
		{
			if (mx%4 == 0)
				ans = mx;
			else if (mx%2 == 1)
				ans = mx+1;
			else if (mx%4 == 2)
				ans = mx+2;
		}
		else
			ans = (int)ceil(m*n/2.0);
		printf("Case %d: %d\n", ++caseno, ans);
	}
	return 0;
}