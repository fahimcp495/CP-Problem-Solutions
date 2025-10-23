#include<bits/stdc++.h>
using namespace std;

const int M = 10000007;

long long F[10010];

int main(){
    int T, caseno = 0;
    scanf("%d", &T);
    while(T--){
        for (int i = 0; i < 6; ++i){
            scanf("%lld", F+i);
        }
        int n;
        scanf("%d", &n);
        for (int i = 6; i <= n; ++i){
            F[i] = (F[i-1]+F[i-2]+F[i-3]+F[i-4]+F[i-5]+F[i-6])%M;
        }
        printf("Case %d: %lld\n", ++caseno, F[n]%M);
    }
    return 0;
}