#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr)
#define endl "\n"
#define INF 987654312

int c, n;
vector<int> fence;
bool isRange(int l, int r) {
    if(l < 0 || l > n-1 || r < 0 || r > n-1 || l > r) {
        return false;
    }
    return true;
}
int cutting(int start, int end) {
    if(!isRange(start, end)) {
        return 0;
    }
    if(start == end) {
        return fence[start];
    }
    int mval = INF;
    int midx = -1;
    for(int i=start; i<=end; i++) {
        if(mval > fence[i]) {
            mval = fence[i];
            midx = i;
        }
    }
    int left = cutting(start, midx-1);
    int right = cutting(midx+1, end);
    int center = (end - start +  1) * mval;
    center = max(center, max(left,right));
    return center;
}
int main(void) {
    FastIO;
    cin >> c;
    while(c--) {
        cin >> n;
        fence.clear();
        fence.resize(n);
        for(int i=0; i<n; i++) {
            cin >> fence[i];
        }
        cout << cutting(0, n-1) << endl;
    }   
    return 0;
}