#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2005;
const int MX = 2000;

int n, m;
int a[N];
int b[N];

void init(int n) { rep(i, 1, n) b[i] = b[i - 1] + i; }
void solve() {
  cin >> n;
  int id = lower_bound(b + 1, b + MX + 1, n) - b;
  int l = 2, r = id + 1;
  if (b[id] == n)
    cout << id << endl;
  else {
    int x = b[id] - n;
    if (x == 1)
      cout << id + 1 << endl;
    else
      cout << id << endl;
  }
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(MX);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}