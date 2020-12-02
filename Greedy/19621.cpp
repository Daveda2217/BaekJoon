#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int ans;

void dfs(int curr, int sum = 0)
{
    if (curr >= n)
    {
        ans = max(ans, sum);
    }
    else
    {
        dfs(curr + 2, sum + v[curr]);
        dfs(curr + 3, sum + v[curr]);
        // curr+4에 대해서는 구할 필요가 없다.
        // curr+2를 선택하는 것이 더 많은 인원을 수용할 수 있기 때문이다.
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    v.resize(n);

    for (auto &i : v)
    {
        int s, e, p;
        cin >> s >> e >> p;
        i = p;
    }

    dfs(0); // 첫번째 회의를 선택하는 것이 좋을지
    dfs(1); // 두번째 회의를 선택하는 것이 좋을지

    cout << ans << "\n";

    return 0;
}
