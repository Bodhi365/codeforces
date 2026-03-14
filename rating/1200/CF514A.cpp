#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

void solve() {
  ll n, p = 1, res = 0;
  cin >> n;
  while (n) {
    ll x = n % 10;
    n /= 10;
    if (n || x != 9) x = min(x, 9 - x);
    res += p * x;
    p *= 10;
  }
  cout << res << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}