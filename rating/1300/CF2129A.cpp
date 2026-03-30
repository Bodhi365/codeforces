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
	int l, r;
	int id;
} a[N];
bool cmp(Node a, Node b) {
	if (a.l != b.l) return a.l < b.l;
	else return a.r > b.r;
}

void solve() {
  cin >> n;
  rep(i, 1, n) {
  	cin >> a[i].l >> a[i].r;
  	a[i].id = i;
  }
  sort(a + 1, a + n + 1, cmp);
  vector<int> id;
  int l = -1, r = -1;
  rep(i, 1, n) {
  	if (a[i].l > r) {
  		l = a[i].l, r = a[i].r;
  		id.push_back(a[i].id);
  	} else if (a[i].r <= r) {
  		continue;
  	} else {
  		r = a[i].r;
  		id.push_back(a[i].id);
  	}
  }
  cout << id.size() << endl;
  sort(id.begin(), id.end());
  for (int x : id) cout << x << ' ';
  cout << endl;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}