#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int res = 0;
    int m = INT32_MAX;
    for (int i = 0; i < n; i++){
        int u; cin >> u;
        if (u - m < res) res = u - m;
        m = min (m, n);
    }
    cout<< res;
    return 0;
}
