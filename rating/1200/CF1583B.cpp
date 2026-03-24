#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
int vis[N];


void solve() {
  cin >> n >> m;
  rep(i, 1, n) vis[i] = 0;
  rep(i, 1, m) {
    int a, b, c;
    cin >> a >> b >> c;
    vis[b] = 1;
  }
  int rt = 0;
  rep(i, 1, n) if (!vis[i]) {
    rt = i;
    break;
  }
  rep(i, 1, n) {
    if (i == rt) continue;
    cout << i << ' ' << rt << endl;
  } 
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}