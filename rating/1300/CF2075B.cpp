#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 5005;

int n, k;
int a[N], id[N];
bool cmp(int i, int j) {
	return a[i] > a[j];
}
void solve() {
  cin >> n >> k;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) id[i] = i;
  sort(id + 1, id + n + 1, cmp);
  ll ans = 0;
  if (k == 1) {
  	ll x, y;
  	if (id[1] == 1) x = a[1] + a[id[2]];
  	else x = a[1] + a[id[1]];
  	if (id[1] == n) y = a[n] + a[id[2]];
  	else y = a[n] + a[id[1]];
  	ans = max(x, y); 
  } else {
  	rep(i, 1, k + 1) ans += a[id[i]];
  }
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