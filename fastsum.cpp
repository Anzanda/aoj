#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr);
#define endl "\n"

int n;
int sum(int start, int end) {
    if(start == end) {
        return 1;
    }
    int mid = (start + end)/2;
    int ret = 2 * sum(start, mid);
    ret += mid*mid;
    if(end%2 == 1) {
        ret -= (end+1);
    }
    return ret;

}
int main(void) {
    cin >> n;
    cout << sum(1, n) << endl;
    return 0;
}