#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 1e6 + 5;

ll n, m;
int np[N];
int primes[N], tot;
set<ll> st;

void init(int n) {
  np[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (!np[i]) primes[++tot] = i, st.insert(1ll * i * i);
    rep(j, 1, tot) {
      ll k = 1ll * primes[j] * i;
      if (k > n) break;
      np[k] = 1;
      if (i % primes[j] == 0) break;
    }
  }
}
void solve() {
  cin >> n;
  if (st.count(n)) cout << "YES" << endl;
  else cout << "NO" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(1e6);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}