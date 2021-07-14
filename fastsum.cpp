#include <bits/stdc++.h>
using namespace std;

#define FastIO ios_base::sync_with_stdio(false),cout.tie(nullptr),cin.tie(nullptr);
#define endl "\n"

int n;
int sum(int back) {
    if(back == 1) {
        return 1;
    }
    if(back%2 == 1) {
        return sum(back-1) + back;
    }
    return 2*sum(back/2) + (back/2)*(back/2);
}
int main(void) {
    cin >> n;
    cout << sum(n) << endl;
    return 0;
}