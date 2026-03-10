#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int a[N], b[N], c[N], id[N];

void solve() {
  cin >> n;
  rep(i, 1, n) cin >> b[i];
  rep(i, 1, n) c[i] = 0; 
  rep(i, 1, n) c[b[i]]++;
  rep(i, 1, n) {
    if (c[i] % i) {
      cout << -1 << endl;
      return;
    }
  }
  int num = 0;
  rep(i, 1, n) {
    if (c[b[i]] % b[i] == 0) id[b[i]] = ++num;
    cout << id[b[i]] << ' ';
    c[b[i]]--;
  }
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