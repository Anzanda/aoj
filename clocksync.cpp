    #include <bits/stdc++.h>
    using namespace std;

    #define endl "\n"
    #define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)
    #define INF 987654321

    int c;
    vector<int> connect[10];
    int hour[16];
    int ans;
    void init() {
        connect[0].resize(3);
        connect[0] = {0,1,2};
        connect[1].resize(4);
        connect[1] = {3,7,9,11};
        connect[2].resize(4);
        connect[2] = {4,10,14,15};
        connect[3].resize(5);
        connect[3] = {0,4,5,6,7};
        connect[4].resize(5);
        connect[4] = {6,7,8,10,12};
        connect[5].resize(4);
        connect[5] = {0,2,14,15};
        connect[6].resize(3);
        connect[6] = {3,14,15};
        connect[7].resize(5);
        connect[7] = {4,5,7,14,15};
        connect[8].resize(5);
        connect[8] = {1,2,3,4,5};
        connect[9].resize(5);
        connect[9] = {3,4,5,9,13};
    }
    void update(int idx) {
        for(auto el: connect[idx]) {
            hour[el] += 3;
            if(hour[el] > 12) hour[el] %= 12;
        }
    }
    bool isAllTwelve() {
        for(int i=0; i<16; i++) {
            if(hour[i] != 12) {
                return false;
            }
        }
        return true;
    }
    void dfs(int now, int cnt) {
        if(now == 10) {
            if(isAllTwelve()) {
                ans = min(ans, cnt);
            }
            return;
        }
        for(int i=1; i<=3; i++) {
            update(now);
            dfs(now+1, cnt+i);
        }
        update(now);
        dfs(now+1, cnt);
    }
    int main(void) {
        FastIO;
        cin >> c;
        init();
        while(c--) {
            ans = INF;
            for(int i=0; i<16; i++) {
                cin >> hour[i];
            }
            dfs(0, 0);
            if(ans == INF) {
                ans = -1;
            }
            cout << ans << endl;
        }
    }