#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N];

void solve() {
  cin >> n;
  map<int, int> cnt;
  rep(i, 1, n) {
  	int x;
  	cin >> x;
  	for (int i = 2; i * i <= x; i++) {
  		if (x % i) continue;
  		while (x % i == 0) {
  			x /= i;
  			cnt[i]++;
  		}
  	}
  	if (x > 1) cnt[x]++;
  }
  bool f = true;
  for (auto p : cnt) {
  	if (p.second % n) {
  		f = false;
  		break;
  	}
  }
  cout << (f ? "YES" : "NO") << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}