#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)

int c,n;
char board[5][5];
int dx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy[8] = {0, -1, -1, -1, 0, 1, 1, 1};
string str;
int len;
bool isRange(int r, int c) {
    if(r < 0 || r >= 5 || c < 0 || c >= 5) {
        return false;
    }
    return true;
}
bool dfs(int r, int c, int idx) {
    if(!isRange(r, c)) {
        return false;
    }
    if(board[r][c] != str[idx]) {
        return false;
    }
    // cout << "(" << r << ", " << c << ")\n";
    if(idx == len-1) {
        return true;
    }
    for(int i=0; i<8; i++) {
        int nx = r + dx[i];
        int ny = c + dy[i];
        if(dfs(nx, ny, idx+1)) {
            return true;
        }
    }
    return false;
}
int main(void) {
    FastIO;
    cin >> c;
    while(c--) {
        for(int i=0; i<5; i++) {
            cin >> board[i];
        }
        cin >> n;
        vector<pair<string, bool>> knows;
        for(int i=0; i<n; i++) {
            string str;
            cin >> str;
            knows.push_back({str,false});
        }
        for(int i=0; i<n; i++) {
            str = knows[i].first;
            len = knows[i].first.length();
            for(int j=0; j<5; j++) {
                for(int k=0; k<5; k++) {
                    knows[i].second |= dfs(j,k,0);
                }
            }
        }
        for(auto el: knows) {
            cout << el.first << " ";
            if(el.second) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}