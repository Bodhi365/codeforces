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
  rep(i, 1, n) cin >> a[i];
  if (a[1]) {
    cout << n + 1 << ' ';
    rep(i, 1, n) cout << i << ' ';
    cout << endl;
    return;
  }
  if (!a[n]) {
    rep(i, 1, n + 1) cout << i << ' ';
    cout << endl;
    return;
  }
  int k = 2;
  while (k < n && !a[k]) k++;
  rep(i, 1, k - 1) cout << i << ' ';
  cout << n + 1 << ' ';
  rep(i, k, n) cout << i << ' ';
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