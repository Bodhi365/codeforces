#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N];
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  b[1] = 1;
  rep(i, 2, n) b[i] = b[i - 1] + a[i - 1];
  cin >> m;
  while (m--) {
    int x;
    cin >> x;
    int pos = upper_bound(b + 1, b + n + 1, x) - b - 1;
    cout << pos << endl;
  }
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}