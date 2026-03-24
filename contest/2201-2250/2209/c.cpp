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

bool test(int i, int j) {
  cout << "? " << i << ' ' << j << endl;
  cout.flush();
  int res;
  cin >> res;
  return res;
}
void ans(int i) {
  cout << "! " << i << endl;
  cout.flush();
}
void solve2() {
  rep(i, 1, 3) {
    int j = i, k = i + 1;
    if (k > 3) k = 1;
    bool res = test(j, k);
    if (res) {
      ans(j);
      return;
    }
  }
  ans(4);
  return;
}
void solve() {
  cin >> n;
  rep(i, 3, n) {
    int j = 2 * i - 1, k = 2 * i;
    bool res = test(j, k);
    if (res) {
      ans(j);
      return;
    }
  }
  solve2();
  return;
}
int main() {
  //ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}