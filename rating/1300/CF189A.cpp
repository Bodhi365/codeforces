#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, a, b, c;

void solve() {
  cin >> n >> a >> b >> c;
  int ans = 0;
  rep(i, 0, n / a) rep(j, 0, (n - i * a) / b) {
  	int sum = i * a + j * b;
  	if (sum > n) continue;
  	int x = n - sum;
  	if (x % c) continue;
  	ans = max(ans, i + j + x / c); 
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}