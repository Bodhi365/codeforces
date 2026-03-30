#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int cnt[30];

bool check(int x) {
	int need = 0;
	per(i, 29, 0) {
		need <<= 1;
		if (x & (1 << i)) need++;
		need = max(0, need - cnt[i]);
	}
	return need == 0;
}
void solve() {
  cin >> n;
  rep(i, 0, 29) cnt[i] = 0;
  rep(i, 1, n) {
  	int op, x;
  	cin >> op >> x;
  	if (op == 1) cnt[x]++;
  	else cout << (check(x) ? "YES" : "NO") << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}