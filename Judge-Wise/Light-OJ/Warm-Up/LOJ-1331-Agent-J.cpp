#include<bits/stdc++.h>
using namespace std;

#define dbg(a)	cerr << #a << " = " << a << endl;

int main(){
	int T, tc = 0;
	scanf("%d", &T);
	while(T--){
		printf("Case %d: ", ++tc);
		double r1, r2, r3;	cin >> r1 >> r2 >> r3;
		double a = r1+r2, b = r2+r3, c = r3+r1;
		double A = acos((b*b + c*c - a*a) / (2 * b * c) );
		double B = acos((a*a + c*c - b*b) / (2 * a * c) );
		double C = acos((b*b + a*a - c*c) / (2 * a * b) );
		double s = (a+b+c)/2;
		cout << fixed << setprecision(6) << sqrt(s*(s-a)*(s-b)*(s-c)) - 0.5*r3*r3*A - 0.5*r2*r2*C - 0.5*r1*r1*B << endl; 
	}
	return 0;
}