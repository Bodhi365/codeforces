#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 2e5 + 5;
const int INF = 1e9;

int n, m;
int a[N];
struct Node {
	int l, r;
} lst[N];
int del(int i) {
	int l = lst[i].l, r = lst[i].r;
	lst[l].r = r, lst[r].l = l;
	return min(a[l], a[r]);
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i];
  rep(i, 1, n) lst[i].l = i - 1, lst[i].r = i + 1;
  lst[1].l = n, lst[n].r = 1;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  rep(i, 1, n) pq.push(pii(a[i], i));
  ll ans = 0;
  rep(i, 1, n - 1) {
  	int id = pq.top().second;
  	pq.pop();
  	ans += del(id);
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