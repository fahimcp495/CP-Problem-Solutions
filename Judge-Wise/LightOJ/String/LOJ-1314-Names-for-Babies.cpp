#include<bits/stdc++.h>
using namespace std;

struct SA
{
  string s;
  int n,k=0;
  vector<int> p,lcp;
  vector<vector<int>> rnk;
  SA(string s):s(s){}

  //O(nlg^2n)
  vector<int> get_sa(){
    n=s.size();
    p.resize(n);
    rnk.resize(n, vector<int> (20));
    for (int i = 0; i < n; ++i){
      p[i]=i,  rnk[i][k]=s[i];
    }

    auto comp = [&](int i, int j){
      if(rnk[i][k-1]!=rnk[j][k-1])  return rnk[i][k-1]<rnk[j][k-1];
      i+=1<<(k-1), j+=1<<(k-1);
      return (i<n && j<n)? rnk[i][k-1]<rnk[j][k-1]: i>j;
    };
    while (++k){
      sort(p.begin(), p.end(), comp);
      int rnk_idx[n];
      rnk_idx[0]=0;
      for (int i = 0; i < n-1; ++i){
        rnk_idx[i+1]=rnk_idx[i]+comp(p[i], p[i+1]); 
      }
      for (int i = 0; i < n; ++i){
        rnk[p[i]][k] = rnk_idx[i];
      }
      if(rnk_idx[n-1]==n-1) break;
    }
    return p;
  }

  //O(n)
  vector<int> get_lcp(){
    lcp.resize(n-1);
    int cnt=0;
    for (int i = 0; i<n; ++i){
      int idx=rnk[i][k];
      if(idx==n-1) { cnt=0; continue; }
      int j=p[idx+1];
      while(i+cnt<n and j+cnt<n and s[i+cnt]==s[j+cnt]) cnt++;
      lcp[idx]=cnt;
      if(cnt) cnt--;
    }
    return lcp;
  }

  //O(lgn)
  int get_lcp(int i, int j){
    int ret=0;
    for(int l=k-1; l>=0; l--){
      if(rnk[i][l]==rnk[j][l]){
        ret += 1<<l,  i += 1<<l,  j += 1<<l;
      }
    }
    return ret;
  }
};

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int T, tc = 0; cin >> T;
  while(T--){
    cout << "Case " << ++tc << ": ";
    string s; cin >> s;
    int p, q; cin >> p >> q;
    SA sa(s);
    vector<int> v = sa.get_sa();
    vector<int> lcp = sa.get_lcp();
    int n = s.size();
    long long ans = 1LL*(n-p+1)*(n-p+2)/2 - 1LL*(n-q)*(n-q+1)/2;
    for(int& x: lcp){
      if(x>=p){
        ans -= min(x,q)-p+1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}