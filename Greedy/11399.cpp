#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<int> v;

    cin >> n;
    v.resize(n);

    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    int waiting = 0;
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        waiting += v[i];
        total += waiting;
    }

    cout << total << "\n";

    return 0;
}
