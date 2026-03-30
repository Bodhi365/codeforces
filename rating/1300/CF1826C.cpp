#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define endl '\n'
const int N = 1e6 + 5;

int n, m;
int np[N];
int mnp[N];
int primes[N], tot;
void init(int n) {
	np[1] = 1, mnp[1] = n + 1;
	rep(i, 2, n) {
		if (!np[i]) {
			mnp[i] = i;
			primes[++tot] = i;
		}
		rep(j, 1, tot) {
			ll k = 1ll * i * primes[j];
			if (k > n) break;
			np[k] = 1;
			mnp[k] = primes[j];
			if (i % primes[j] == 0) break;
		}
	}
}
void solve() {
  cin >> n >> m;
  if (mnp[n] <= m) cout << "NO" << endl;
  else cout << "YES" << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  init(1e6);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}