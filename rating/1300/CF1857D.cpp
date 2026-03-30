#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N], id[N];
bool cmp(int i, int j) {
	if (a[i] - b[i] == a[j] - b[j]) return i < j;
	else return a[i] - b[i] > a[j] - b[j];
}

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  int num = 1;
  while (num <= n && a[id[num]] - b[id[num]] == a[id[1]] - b[id[1]]) num++;
  cout << num - 1 << endl;
  rep(i, 1, num - 1) cout << id[i] << ' ';
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