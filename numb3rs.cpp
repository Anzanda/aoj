#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO cin.tie(0)->sync_with_stdio(0)
#define pb push_back

const int MAX = 50;

int gcd(int a, int b) {
	if(b == 0) {
		return a;
	}
	return gcd(b, a%b);
}
struct Fraction {
	int p;
	int q;
	Fraction(int p=0, int q=0)
		:p(p), q(q) {}
	
	Fraction operator *(const Fraction &x) {
		if(x.p == 0 || p == 0) {
			return Fraction(0, 0);
		}
		int nextP = p * x.p;
		int nextQ = q * x.q;
		int g = gcd(nextP, nextQ);
		nextP /= g;
		nextQ /= g;
		return Fraction(nextP, nextQ);
	}
	
	Fraction operator +(const Fraction &x) {
		if(x.p == 0) {
			return Fraction(p, q);
		}
		if(p == 0) {
			return Fraction(x.p, x.q);
		}
		int nextQ = q * x.q / gcd(q, x.q);
		int nextP = (nextQ/q)*(p) + (nextQ/x.q)*(x.p);
		int g = gcd(nextP, nextQ);
		nextP /= g;
		nextQ /= g;
		return Fraction(nextP, nextQ);
	}
	void print() {
		cout << p << "/" << q << endl;
	}
	double toFloat() {
		if(p == 0)	return (double)0.00000000;
		double ret = (double)p/q;
		return ret;
	}
};
int T;
int n, d, p;
int t;
vector<vector<int>> adj;
Fraction dp[MAX+7][MAX+7][100+7];
bool vst[MAX+7][MAX+7][100+7];
void input() {
	cin >> n >> d >> p;
	adj = vector<vector<int>>(n);
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int num;
			cin >> num;
			if(num) {
				adj[i].pb(j);
			}
		}
	}
}
Fraction rundp(int curr, int dst, int day) {
	if(day == 0) {
		if(curr == dst) {
			return Fraction(1, 1);
		}
		return Fraction();
	}
	Fraction &ret = dp[curr][dst][day];
	if(vst[curr][dst][day]) {
		return ret;
	}
	for(auto there: adj[curr]) {
		ret = ret + (rundp(there, dst, day-1) * Fraction(1, adj[curr].size()));
	}
	return ret;
}
void solve() {
	cin >> t;
	for(int i=0; i<t; i++) {
		int dst;
		cin >> dst;
		cout << rundp(p, dst, d).toFloat() << " ";
	}
	cout << endl;
}	
int main(void) {
	FastIO;
	cout << setprecision(8);
	cin >> T;
	while(T--) {
		input();
		solve();
	}
	return 0;
}

