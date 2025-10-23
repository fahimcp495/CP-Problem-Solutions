#include<bits/stdc++.h>
using namespace std;
 
const int N=7;
 
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
 
char ch[] = {'R', 'U', 'L', 'D'};
 
string s;
vector<int> vis(49);
int cnt, ans = 0;
 
void rec(int x, int y, int prev_dir) {
  if(cnt==49){
    ans++;
    return ;
  } else if(x==0 and y==0) {
    return ;
  }
 
  int xx = x+dx[prev_dir];
  int yy = y+dy[prev_dir];
  if(xx<0 or xx>=N or yy<0 or yy>=N or vis[xx*N+yy]) {
    int l = (prev_dir+1);
    int r = (prev_dir-1);
    if(l>=4)  l=0;
    if(r<0) r=3;
    int lx = x+dx[l];
    int ly = y+dy[l];
 
    int rx = x+dx[r];
    int ry = y+dy[r];
    if( (lx>=0 and lx<N and ly>=0 and ly<N and !vis[lx*N+ly])  and (rx>=0 and rx<N and ry>=0 and ry<N and !vis[rx*N+ry])) return ;
  }
 
 
  if(s[cnt-1] != '?') {
    int dir = s[cnt-1]-'0';
    int xx = x+dx[dir];
    int yy = y+dy[dir];
    if(xx<0 or xx>=N or yy<0 or yy>=N or vis[xx*N+yy]) return;
    vis[xx*N+yy]=1;
    cnt++;
    rec(xx, yy, s[cnt-1]);
    vis[xx*N+yy]=0;
    cnt--;
  } else {
    for (int dir = 0; dir < 4; ++dir) {
      int xx = x+dx[dir];
      int yy = y+dy[dir];
      if(xx<0 or xx>=N or yy<0 or yy>=N or vis[xx*N+yy]) continue;
      vis[xx*N+yy]=1;
      cnt++;
      rec(xx, yy, dir);
      vis[xx*N+yy]=0;
      cnt--;
    }
  }
}
 
int main(){
  ios::sync_with_stdio(0), cin.tie(0);
  
  cin >> s;
  for (int i = 0; i < s.size(); ++i){
    if(s[i]=='R') s[i]='0';
    else if(s[i]=='U')  s[i]='1';
    else if(s[i]=='L')  s[i]='2';
    else if(s[i]=='D')  s[i]='3';
  }
 
  if(s[0] != '0') {
    vis.assign(49, 0);
    vis[6]=1;
    vis[5]=1;
    cnt=2;
    rec(0, 5, 3);
  }
  if(s[0] != '3') {
    vis.assign(49, 0);
    vis[6]=1;
    vis[13]=1;
    cnt=2;
    rec(1, 6, 0);
  }
  cout << ans << "\n";
 
  return 0;
}