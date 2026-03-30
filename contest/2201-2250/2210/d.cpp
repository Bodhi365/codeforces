#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 5e5 + 5;

int n, m;
string s, t;
int a[N];
void parse(string& s, int& x, int& y) {
	x = 0;
	stack<int> st;
	int len = s.size();
	rep(i, 0, len - 1) {
		if (s[i] == '(') st.push(i);
		else {
			int j = st.top();
			st.pop();
			if (j + 1 != i) x++;
			a[i] = j;
			a[j] = i;
		}
	}
	int l = 0, r = len - 1;
	while (l < r && a[l] == r) l++, r--;
	y = l;
}
void solve() {
  cin >> n;
  cin >> s >> t;
  int x1, y1, x2, y2;
  parse(s, x1, y1);
  parse(t, x2, y2);
  if (x1 != x2 || y1 != y2) cout << "NO" << endl;
  else cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}