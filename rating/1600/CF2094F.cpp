#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m, k;

void solve() {
  cin >> n >> m >> k;
  if (m % k == 0) {
    rep(i, 1, n) {
      rep(j, 1, m) {
        cout << ((i + j - 2) % k) + 1 << ' ';
      }
      cout << endl;
    }
  } else {
    int id = 1;
    rep(i, 1, n) {
      rep(j, 1, m) {
        cout << id << ' ';
        id = id == k ? 1 : id + 1;
      }
      cout << endl;
    }
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