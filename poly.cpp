#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define enld "\n"

const int MAX = 100;
const int MOD = 10000000;

int T;
int n;
int dp[MAX+7][MAX+7];
int ans;
int rundp(int r, int c) {
	int &ret = dp[r][c];
	if(ret != -1) {
		return ret;
	}
	if(r == 1 || r == c) {
		ret = 1;
		return ret;
	}
	ret = 0;
	int next = r-c; // No r==0 or c == 0
	for(int i=1; i<=next; i++) {
		ret += rundp(next, i)*(c + i - 1);
		ret %= MOD;
	}
	return ret;
}
void input() {
	cin >> n;
}
void solve() {
	memset(dp, -1, sizeof dp);
	ans = 0;
	for(int i=1; i<=n; i++) {
		ans += rundp(n, i);
		ans %= MOD;
	}
	cout << ans << endl;
}
int main(void) {
	FastIO;
	cin >> T;
	while(T--) {
		input();
		solve();
	}
	return 0;
}
