#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;

int n, m;
struct Pt {
  double x, y;
} o, p, a, b;

double f(Pt a, Pt b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

void solve() {
  cin >> p.x >> p.y;
  cin >> a.x >> a.y;
  cin >> b.x >> b.y;
  double d11 = f(o, a);
  double d12 = f(o, b);
  double d21 = f(p, a);
  double d22 = f(p, b);
  double mx = f(a, b) / 2;
  double d1 = min(d11, d12);
  double d2 = min(d21, d22);
  if (d1 == d11 && d2 == d21 || d1 == d12 && d2 == d22) {
    cout << fixed << setprecision(10) << max(d1, d2) << endl;
  } else {
    cout << fixed << setprecision(10) << max({d1, d2, mx}) << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}