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
	int x, y;
} a[N];
bool cmp(Node a, Node b) {
	if (a.x > a.y) swap(a.x, a.y);
	if (b.x > b.y) swap(b.x, b.y);
	if (a.x != b.x) return a.x < b.x;
	else return a.y < b.y;
}
void solve() {
  cin >> n;
  rep(i, 1, n) cin >> a[i].x >> a[i].y;
  sort(a + 1, a + n + 1, cmp);
  rep(i, 1, n) cout << a[i].x << ' ' << a[i].y << ' ';
  cout << endl;
  return; 
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}