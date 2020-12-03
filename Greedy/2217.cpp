#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int> v;
    v.resize(n);

    for (auto &i : v)
        cin >> i;
    sort(v.begin(), v.end());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int k = v[i] * (n - i);
        ans = max(ans, k);
    }
    cout << ans << "\n";

    return 0;
}
