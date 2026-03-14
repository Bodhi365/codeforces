#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
struct Node {
  int a, b, c;
} a[N];
int x[N], y[N], z[N];
bool cmpa(int i, int j) {
  return a[i].a > a[j].a;
}
bool cmpb(int i, int j) {
  return a[i].b > a[j].b;
}
bool cmpc(int i, int j) {
  return a[i].c > a[j].c;
}

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i].a;
  rep(i, 1, n) cin >> a[i].b;
  rep(i, 1, n) cin >> a[i].c;
  rep(i, 1, n) x[i] = y[i] = z[i] = i;
  sort(x + 1, x + n + 1, cmpa);
  sort(y + 1, y + n + 1, cmpb);
  sort(z + 1, z + n + 1, cmpc);
  int ans = 0;
  rep(i, 1, 3) rep(j, 1, 3) rep(k, 1, 3) {
    if (x[i] != y[j] && x[i] != z[k] && y[j] != z[k]) {
      ans = max(ans, a[x[i]].a + a[y[j]].b + a[z[k]].c);
    }
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}