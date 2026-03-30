#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
string s;
int a[N];

void solve() {
  cin >> n;
  cin >> s;
  for (int l = 1, r = 1; r <= n + 1; r++) {
  	if (r == n + 1 || s[r - 1] == '1') {
  		int cnt = r - l;
  		if (cnt == 1) {
  			cout << "NO" << endl;
  			return;
  		}
  		for (int j = l, k = r - 1; j < r; j++, k--) a[j] = k;
  		if (r <= n) a[r] = r; 
  		l = r + 1;
  	}
  }
  cout << "YES" << endl;
  rep(i, 1, n) cout << a[i] << ' ';
  cout << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}