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
  int x;
  char c;
} a[4];
bool cmp(Node a, Node b) {
  return a.x > b.x;
}
string f(int x, int y, int z, char a, char b, char c) {
  if (x >= y + z) {
    string res;
    rep(i, 1, y) {
      res.push_back(a);
      res.push_back(b);
    }
    rep(i, 1, z) {
      res.push_back(a);
      res.push_back(c);
    }
    if (x > y + z) res.push_back(a);
    return res;
  } else {
    int k = y + z - x;
    string res = f(x - k, y - k, z - k, a, b, c);
    rep(i, 1, k) {
      if (res.size() >= 2) {
        char c1 = res[res.size() - 2];
        char c2 = res[res.size() - 1];
        res.push_back(c1);
        res.push_back(c2);
        res.push_back(a + b + c - c1 - c2);
      } else {
        res.push_back(b);
        res.push_back(a);
        res.push_back(c);
      }
    }
    return res;
  }
}
void solve() {
  cin >> a[1].x >> a[2].x >> a[3].x;
  a[1].c = 'R', a[2].c = 'G', a[3].c = 'B';
  sort (a + 1, a + 4, cmp);
  string ans = f(a[1].x, a[2].x, a[3].x, a[1].c, a[2].c, a[3].c);
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