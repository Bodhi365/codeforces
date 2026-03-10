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
  int w, h, a, b, x1, y1, x2, y2;
  cin >> w >> h >> a >> b;
  cin >> x1 >> y1 >> x2 >> y2;
  // x
  if (y1 > y2) swap(x1, x2), swap(y1, y2);
  int y = y1 + b - 1;
  if (y >= y2 && abs(x1 - x2) % a) {
    cout << "No" << endl;
    return;
  }
  if (x1 > x2) swap(x1, x2), swap(y1, y2);
  int x = x1 + a - 1;
  if (x >= x2 && abs(y1 - y2) % b) {
    cout << "No" << endl;
    return;
  } 
  x = abs(x1 - x2), y = abs(y1 - y2);
  if (x % a == 0 || y % b == 0) cout << "Yes" << endl;
  else cout << "No" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}