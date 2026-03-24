#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
ll sum[N];
int f(int x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}
void init(int n) {
	rep(i, 1, n) {
		sum[i] = sum[i - 1] + f(i);
	}
}
void solve() {
  cin >> n;
  cout << sum[n] << endl;
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