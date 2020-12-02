#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, c;
    cin >> n >> c;
    vector<int> v(n); // 물건에 대한 정보

    for (auto &i : v)
        cin >> i;

    sort(v.begin(), v.end());

    if (binary_search(v.begin(), v.end(), c)) // c와 같은 값이 있는가?
    {
        cout << 1 << "\n";
        return 0;
    }

    vector<int> sum;
    vector<pair<int, int>> idx;

    for (int i = 0; i < n; i++) // 중복되는 것 없이 물건을 2개씩 합친다.
    {
        for (int j = i + 1; j < n; j++)
        {
            sum.push_back(v[i] + v[j]);
            idx.emplace_back(i, j); // 더한 물건에 대한 인덱스 정보도 저장해준다.
        }
    }

    sort(sum.begin(), sum.end());

    if (binary_search(sum.begin(), sum.end(), c)) // c와 같은 값이 있는가?
    {
        cout << 1 << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++) // c-v[i]값이 sum에 있는가?
    {
        auto it = lower_bound(sum.begin(), sum.end(), c - v[i]);
        if (it != sum.end() && *it == c - v[i])
        { // 있으면 중복되지는 않는가?
            auto cur = idx[it - sum.begin()];
            if (cur.first != i && cur.second != i)
            {
                cout << 1 << "\n";
                return 0;
            }
        }
    }

    cout << 0 << "\n";
    return 0;
}
