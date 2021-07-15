#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr);
#define endl "\n"

int c, len, idx;
string tree;
string ans;
string reverse(int& idx) {
    string ret = "";
    ret += tree[idx];
    idx += 1;
    if(tree[idx-1] != 'x') {
        return ret;
    }
    string str[4];
    for(int i=0; i<4; i++) {
        str[i] = reverse(idx);
    }
    ret += (str[2] + str[3] + str[0] + str[1]);
    return ret;
}
int main(void) {
    cin >> c;
    while(c--) {
        cin >> tree;
        len = tree.length();
        ans = "";
        idx = 0;
        cout << reverse(idx) << endl;
    }
}
//