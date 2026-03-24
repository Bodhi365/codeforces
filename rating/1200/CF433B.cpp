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
ll s1[N], s2[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) b[i] = a[i];
  sort(b + 1, b + n + 1);
  rep(i, 1, n) {
    s1[i] = s1[i - 1] + a[i];
    s2[i] = s2[i - 1] + b[i];
  }
  cin >> m;
  while (m--) {
    int op, l, r;
    cin >> op >> l >> r;
    if (op == 1) cout << s1[r] - s1[l - 1] << endl;
    else cout << s2[r] - s2[l - 1] << endl;
  } 
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  solve();
  return 0;
}