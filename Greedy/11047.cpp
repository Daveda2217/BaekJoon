#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, k;
    cin >> n >> k;
    vector<int> v;
    v.resize(n);

    for (auto &i : v)
        cin >> i;

    int ans = 0;

    for (auto i = v.rbegin(); i < v.rend(); i++)
    {
        ans += k / (*i);
        k %= (*i);
    }

    cout << ans << "\n";
    return 0;
}

/*
vector reverse traverse를 기억하자!
*/