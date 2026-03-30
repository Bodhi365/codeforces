#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = (1 << 16) + 5;

int n, m;
int a[N];

int lowbit(int x) { return x & -x; }
bool cmp(int x, int y) {
	int x1 = lowbit(x + 1);
	int y1 = lowbit(y + 1);
	if (x1 != y1) return x1 > y1;
	else return x < y;
}
void solve() {
  cin >> n;
  int len = 1 << n;
  rep(i, 0, len - 1) a[i] = i;
  sort(a, a + len, cmp);
  rep(i, 0, len - 1) cout << a[i] << ' ';
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