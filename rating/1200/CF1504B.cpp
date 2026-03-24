#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 3e5 + 5;

int n, m;
string s, t;
int a[N];
bool check(int l, int r) {
	int cnt = 0;
	rep(i, l, r) if (s[i] != t[i]) cnt++;
	return cnt == 0 || cnt == r + 1 - l;
}
void solve() {
  cin >> n;
  cin >> s >> t;
  s = ' ' + s;
  t = ' ' + t;
  rep(i, 1, n) a[i] = a[i - 1] + (s[i] == '0' ? 1 : -1);
  vector<int> id;
  rep(i, 0, n) if (!a[i]) id.push_back(i);
  int m = id.size();
  rep(i, 1, m - 1) {
 		if (!check(id[i - 1] + 1, id[i])) {
 			cout << "NO" << endl;
 			return;
 		}
  }
  rep(i, id.back() + 1, n) if (s[i] != t[i]) {
  	cout << "NO" << endl;
  	return;
  }
  cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}