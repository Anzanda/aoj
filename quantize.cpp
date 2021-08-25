#include <bits/stdc++.h>
using namespace std;

#define INF 987654321
#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)

const int MAX = 100;

using ll = long long;

int T;
int N, K;
int arr[MAX];
ll dp[MAX][MAX][10];
ll pSum[MAX+1];
ll pSumSquare[MAX+1];
/* 
 * dp[i][j][k]
 * i, j: 범위에 대해서
 * k: k개를 선택했을 때 최솟값
 */
void input() {
	cin >> N >> K;
	for(int i=0; i<N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+N);
	for(int i=1; i<=N; i++) {
		pSum[i] = pSum[i-1] + arr[i-1];
		pSumSquare[i] = pSumSquare[i-1] + arr[i-1]*arr[i-1];
	}
}
ll findMinSquare(int lf, int rg) {
	ll tmp = round((0. + pSum[rg+1] - pSum[lf]) / (rg - lf + 1));
	return pSumSquare[rg+1] - pSumSquare[lf] - 2 * tmp * (pSum[rg+1] - pSum[lf])
		+ tmp * tmp * (rg - lf + 1);
}
ll rundp(int lf, int rg, int k) {
	int elemCount = rg - lf + 1;
	if(elemCount < k) { 
		return INF;
	}
	ll &ret = dp[lf][rg][k];
	if(ret != -1) {
		return ret;
	}
	ret = INF;
	if(k == 1) {
		ret = findMinSquare(lf, rg);
		return ret;
	}
	for(int i=lf; i<rg; i++) {
		ll tmp = findMinSquare(lf, i);
		ret = min(ret, tmp + rundp(i+1, rg, k-1));
	}
	return ret;
}
void solve() {
	memset(dp, -1, sizeof dp);
	cout << rundp(0, N-1, K) << endl;
}
int main(void) {
	cin >> T;
	while(T--) {
		input();
		solve();
	}
	return 0;
}
