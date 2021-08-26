#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"

const int MAX = 100;

int T;
int n;
int arr[MAX][MAX];
int dp[MAX][MAX];
int pathDP[MAX][MAX];
void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<=i; j++) {
			cin >> arr[i][j];
		}
	}
}
int rundp1(int r, int c) {
	if(c < 0 || c > n-1) {
		return 0;
	}
	int &ret = dp[r][c];
	if(ret != -1) {
		return ret;
	}
	if(r == n-1) {
		ret = arr[r][c];
		return ret;
	}
	ret = max(rundp1(r+1, c), rundp1(r+1, c+1));
	return ret += arr[r][c];
}
int rundp2(int r, int c) {
	if(c < 0 || c > n-1) {
		return 0;
	}
	int &ret = pathDP[r][c];
	if(ret != -1) {
		return ret;
	}
	if(r == n-1) {
		ret = 1;
		return ret;
	}
	ret = 0;
	for(int i=0; i<=1; i++) {
		if(arr[r][c] + dp[r+1][c+i] == dp[r][c])
			ret += rundp2(r+1, c+i);
	}
	return ret;
}
void solve() {
	memset(dp, -1, sizeof dp);
	memset(pathDP, -1, sizeof pathDP);
	rundp1(0,0);
	rundp2(0,0);
	cout << pathDP[0][0] << endl;
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
