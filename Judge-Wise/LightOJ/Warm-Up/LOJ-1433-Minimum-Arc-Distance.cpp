#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int T, tc = 0;  cin >> T;
    while(T--){
        int Ox, Oy, Ax, Ay, Bx, By;
        scanf("%d %d %d %d %d %d", &Ox, &Oy, &Ax, &Ay, &Bx, &By);
        double r = hypot(Ox-Ax, Oy-Ay);
        double OA = hypot(Ox-Ax, Oy-Ay);
        double OB = hypot(Ox-Bx, Oy-By);
        double AB = hypot(Bx-Ax, By-Ay);
        double theta = acos((OA*OA+OB*OB-AB*AB) / (2.0*OA*OB));
        printf("Case %d: %.6lf\n", ++tc, r*theta);
    }
}