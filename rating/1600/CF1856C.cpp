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

bool check(int x) {
  rep(i, 1, n) {
    int j = i, cnt = 0;
    while (j <= n && a[j] + j < x + i && cnt <= m) cnt += x + i - j - a[j], j++;
    if (j <= n && cnt <= m) return true;
  }
  return false;
}
void solve() {
  cin >> n >> m;
  rep(i, 1, n) cin >> a[i];
  int l = 1, r = 2e8;
  while (l <= r) {
    int mid = (l + r) >> 1;
    bool res = check(mid);
    if (res) l = mid + 1;
    else r = mid - 1;
  }
  cout << r << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}