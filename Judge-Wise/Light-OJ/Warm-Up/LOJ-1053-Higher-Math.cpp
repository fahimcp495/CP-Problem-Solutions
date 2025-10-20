#include<bits/stdc++.h>
using namespace std;

#define IOS 		ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define si(n)       scanf("%d", &n)
#define sii(a,b)    scanf("%d %d", &a, &b)
#define siii(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define siiii(a,b,c,d)	scanf("%d %d %d %d", &a, &b, &c, &d)
#define sl(n)       scanf("%lld", &n)
#define sll(a,b)    scanf("%lld %lld", &a, &b)
#define slll(a,b,c) scanf("%lld %lld %lld", &a, &b, &c)
#define sf(a)		scanf("%lf", &a)
#define sff(a, b)	scanf("%lf %lf", &a, &b)
#define sfff(a,b,c) scanf("%lf %lf %lf", &a, &b, &c)
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
#define __lcm(a, b)	a*b / __gcd(a, b)
#define div2ceil(a, b)	(a%b!=0? (a/b+1):a/b)
#define D(x)        cerr << #x " = " << x << '\n'
#define DBG         cerr << "Hi!" << '\n'


typedef long long	 		ll;
typedef unsigned long long	ull;
typedef long double			ld;
typedef pair<int, int> 		pii;
typedef pair<ll, ll> 		pll;

int a, b, c, m, t, tn = 1;

int main()
{
	//freopen("t.in","r",stdin);
	//freopen("t.out","w",stdout);
	si(t);
	while(t--)
	{
		siii(a, b, c);
		m = max(a, b);
		m = max(m, c);
		if (a == m)
		{
			if (a*a == b*b + c*c)
			{
				printf("Case %d: yes\n", tn++);
			}
			else
			{
				printf("Case %d: no\n", tn++);
			}
		}
		else if (b == m)
		{
			if (b*b == a*a + c*c)
			{
				printf("Case %d: yes\n", tn++);
			}
			else
			{
				printf("Case %d: no\n", tn++);
			}
		}
		else
		{
			if (a*a + b*b == c*c)
			{
				printf("Case %d: yes\n", tn++);
			}
			else
			{
				printf("Case %d: no\n", tn++);
			}
		}

	}
	return 0;
}