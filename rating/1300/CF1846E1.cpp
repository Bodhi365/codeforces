#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
set<int> ans;

void init() {
	for (int k = 2; k <= 1000; k++) {
		for (int sum = 1 + k + k * k, b = k * k; sum <= 1e6; b = b * k, sum += b) {
			ans.insert(sum);
		}
	}
}
void solve() {
  cin >> n;
  cout << (ans.count(n) ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init();
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}