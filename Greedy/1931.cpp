#include <bits/stdc++.h>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    if (a.second == b.second)
    {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    v.resize(n);

    for (auto &i : v)
        cin >> i.first >> i.second;

    sort(v.begin(), v.end(), cmp);
    // 끝나는 시간이 짧은 순으로 정렬 -> greedy하다.

    int end = v[0].second;
    int ans = 1;
    // 첫 회의는 항상 포함 -> greedy하다.

    for (int i = 1; i < n; i++)
    {
        if (end <= v[i].first)
        { // 다음 회의 시작시간이 전 회의 끝나는 시간보다 같거나 크다면 ok
            ans++;
            end = v[i].second; // 끝나는 시간 update
        }
    }

    cout << ans << "\n";
    return 0;
}
