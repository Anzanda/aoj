#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)

int c, h, w;
char** board;
int whiteCount;
int whiteTotal;
int dc[8] = {1, 1, 0, 1, 0, 1, -1, 0};
int dr[8] = {0, 1, 1, 0, 1, 1, 1, 1};
bool isRange(int r, int c) {
    if(r < 0 || r > h-1 || c < 0 || c > w-1) {
        return false;
    }
    return true;
}
int dfs(int r, int c) {
    if(!isRange(r,c)) {//base condition
        if(whiteCount == whiteTotal) {
            return 1;
        }
        return 0;
    }
    if(board[r][c] == '#') {
        if((c+1)%w == 0) {
            return dfs(r+1, 0);
        } else {
            return dfs(r, c+1);
        }
        
    }   
    board[r][c] = '#';
    whiteCount += 1;
    int ret = 0;
    for(int i=0; i<4; i++) {
        pair<int ,int> pos[2];
        bool flag = false;
        for(int j=0; j<2; j++) {
            int nr = r + dr[i*2+j];
            int nc = c + dc[i*2+j];
            if(isRange(nr, nc)) {
                if(board[nr][nc] == '.') {
                    pos[j] = {nr, nc};
                    continue;
                } 
            }
            flag = true;
            break;
        }
        if(!flag) {
            whiteCount += 2;
            board[pos[0].first][pos[0].second] = '#';
            board[pos[1].first][pos[1].second] = '#';
            if((c+1)%w == 0) {
                ret += dfs(r+1, 0);
            } else {
                ret += dfs(r, c+1);
            }
            whiteCount -= 2;
            board[pos[0].first][pos[0].second] = '.';
            board[pos[1].first][pos[1].second] = '.';
        }
    }
    board[r][c] = '.';
    whiteCount -= 1;
    return ret;
}
int main(void) {
    FastIO;
    cin >> c;
    while(c--) {
        cin >> h >> w;
        board = (char**)malloc(sizeof(char*)*h);
        for(int i=0; i<h; i++) {
            board[i] = (char*)malloc(sizeof(char)*w);
        }
        for(int i=0; i<h; i++) {
            cin >> board[i];
        }
        whiteTotal = 0;
        for(int i=0; i<h; i++) {
            for(int j=0; j<w; j++) {
                if(board[i][j] == '.')  whiteTotal++;
            }
        }
        cout << dfs(0, 0) << endl;
    }
}
