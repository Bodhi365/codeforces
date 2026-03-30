#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 505;

int n, m;
int a[N][N];

void solve() {
  cin >> n;
  int s = (n + 1) / 2;
  a[s][s] = 0;
  for (int l = (n + 1) / 2, r = (n + 1) / 2, k = 1; k < n * n;) {
  	if (l + r < n + 1) {
  		rep(i, l, r) a[i][r + 1] = k++;
  		rep(i, l, r) a[r + 1][i] = k++;
  		r++;
  		a[r][r] = k++;
  	} else {
  		rep(i, l, r) a[i][l - 1] = k++;
  		rep(i, l, r) a[l - 1][i] = k++;
  		l--;
  		a[l][l] = k++;
  	}
  }
  rep(i, 1, n) rep(j, 1, n) cout << a[i][j] << " \n"[j == n];
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}