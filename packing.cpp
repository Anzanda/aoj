#include <bits/stdc++.h>
using namespace std;

#define FastIO cin.tie(0)->sync_with_stdio(0)
#define endl "\n"
#define INF 987645321

const int MAX = 100;

int T;
int n, w;
string item[MAX];
int weight[MAX];
int value[MAX];
int dp[MAX][1000+7];
vector<int> choices;
int ans;
void input() {
	cin >> n >> w;
	for(int i=0; i<n; i++) {
		cin >> item[i] >> weight[i] >> value[i];
	}
}
int rundp(int r, int c) {
	if(r == -1) {
		if(c == 0)	
			return 0;
		return -1;
	}
	int &ret = dp[r][c];
	if(ret != -1) {
		return ret;
	}
	if(c - weight[r] >= 0) {
		if(rundp(r-1, c-weight[r]) != -1) 
			ret = rundp(r-1, c-weight[r])  + value[r];
	} 
	ret = max(ret, rundp(r-1, c));
	return ret;
}
void reconstruct(int r, int c) {
	if(r == -1) {
		return;
	}
	if(c - weight[r] < 0) {
		reconstruct(r-1, c);
		return;
	}
	if(rundp(r-1, c-weight[r]) + value[r] == dp[r][c]) {
		choices.push_back(r);
		reconstruct(r-1, c-weight[r]);
	} else {
		reconstruct(r-1, c);
	}
}
void solve() {
	memset(dp, -1, sizeof dp);
	choices = vector<int>();
	ans = 0;	
	for(int i=0; i<=w; i++) {
		ans = max(ans, rundp(n-1, i));
	}
	cout << "ans: " << ans << endl;
	for(int i=0; i<=w; i++) {
		if(dp[n-1][i] == ans) {
			reconstruct(n-1, i);
			break;
		}
	}
	for(int i=0; i<(int)choices.size(); i++) {
		cout << item[choices[i]] << endl;
	}
	
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
