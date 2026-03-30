#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;
const int MOD = 998244353;

int n, m;
int fac[N];
void init(int n) {
	fac[0] = 1;
	rep(i, 1, n) fac[i] = 1ll * fac[i - 1] * i % MOD;
}
void solve() {
	string s;
  cin >> s;
  int l = 0, n = s.size();
  int x = 0, y = 1;
  while (l < n) {
  	int h = l + 1;
  	while (h < n && s[h] == s[l]) h++;
  	int d = h - l;
  	x += d - 1;
  	y = 1ll * y * d % MOD;
  	l = h;
  }
  y = 1ll * y * fac[x] % MOD;
  cout << x << ' ' << y << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(2e5);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}