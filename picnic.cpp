#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)
#define MAXN 10

int c, n, m;
vector<pair<int, int>> v;
bool vst[10];
int vstCount;
int dfs(int now) {
    if(vst[v[now].first] || vst[v[now].second]) {
        return 0;
    }
    // cout << "now: " << now << endl;
    vst[v[now].first] = true;
    vst[v[now].second] = true;
    vstCount += 2;
    int sum = 0;
    if(vstCount == n) {
        sum = 1;
    } else {
        for(int i=now+1; i<m; i++) {
           sum += dfs(i);
        }
    }
    vst[v[now].first] = false;
    vst[v[now].second] = false;
    vstCount -= 2;
    return sum;
}
int main(void) {
    FastIO;
    cin >> c;
    while(c--) {
        cin >> n >> m;
        v.resize(0);
        for(int i=0; i<m; i++) {
            int arr[2];
            for(int j=0; j<2; j++) {
                cin >> arr[j];
            }
            v.push_back({arr[0], arr[1]});
        }
        // for(auto el: v) {
        //     cout << el.first << " " << el.second << endl;
        // }
        int ans = 0;
        for(int i=0; i<m; i++) {
            ans += dfs(i);
        }
        cout << ans << endl;
        v.clear();
    }
    return 0;
}