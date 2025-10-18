#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
const int K = 50;

ll n, a, b;
ll ans;
vector<ll> pf;
ll inv[K], ncr[K];

void find_pf (ll n) {
  pf.clear();
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      pf.push_back(i);
      while (n % i == 0) n /= i;
    }
  }
  if (n > 1) pf.push_back(n);
}

void yo (ll x) {
  ll y = b / x;
  ll ways = 1;
  for (auto p: pf) {
    int cnt = 0;
    while (x % p == 0) x /= p, cnt++;

    int cnt2 = 0;
    while (y % p == 0) y /= p, cnt2++;

    assert(cnt < K);
    assert(cnt2 < K);

    ll now = ncr[cnt] * ncr[cnt2] % mod;
    ways = ways * now % mod;
  }
  ans = (ans + ways) % mod;
}

void solve () {
  cin >> n >> a >> b;

  for (int k = 0; k < K; ++k) {
    ncr[k] = 1;
    ll p = n + k - 1;
    ll q = k;
    while (q) {
      ncr[k] = ncr[k] * (p % mod) % mod;
      ncr[k] = ncr[k] * inv[q] % mod;
      p--, q--;
    }
  }

  find_pf(b);
  ans = 0;

  for (ll i = 1; i * i <= b; ++i) {
    if (b % i == 0) {
      if (i <= a) {
        yo(i);
      }
      if (b / i != i) {
        if (b / i <= a) {
          yo(b / i);
        }
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);

  inv[1] = 1;
  for(ll i = 2; i < K; ++i) {
    inv[i] = -(mod / i) * inv[mod % i] % mod;
    inv[i] += mod;
    assert(inv[i] >= 0 and inv[i] < mod);
  }

  int t; cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
}