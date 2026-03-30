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
int cnt[N];
int ans[N];
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) cnt[i] = ans[i] = 0;
  rep(i, 1, n) {
  	if (a[i] > n) continue;
  	cnt[a[i]]++;
  }
  rep(i, 1, n) {
  	if (!cnt[i]) continue;
  	for (int j = i; j <= n; j += i) {
  		ans[j] += cnt[i];
  	}
  }
  int mx = *max_element(ans + 1, ans + n + 1);
  cout << mx << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}