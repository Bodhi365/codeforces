#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

ll n, m, a, b;

void solve() {
  cin >> n >> m >> a >> b;
  ll ans;
  if (m * a > b) {
    ans = n / m * b + min(b, n % m * a);
  } else {
    ans = n * a;
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}