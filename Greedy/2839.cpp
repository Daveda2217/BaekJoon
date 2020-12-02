#include <bits/stdc++.h>

using namespace std;

/*
설탕을 정확하게 n(kg) 배달.
봉지는 3,5(kg).

최대한 적은 봉지
Ex) 18kg -> 3kg 6개 (X), 5kg 3개, 3kg 1개 (더 적은 봉지)
*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int ans = 9999;

    for (int i = 0; i < n / 5 + 1; i++)
    {
        for (int j = 0; j < n / 3 + 1; j++)
        {
            // 5kg i개, 3kg j개
            if (5 * i + 3 * j == n)
            {
                ans = min(ans, i + j);
            }
        }
    }
    if (ans == 9999)
        cout << -1 << "\n";
    else
        cout << ans << "\n";

    return 0;
}
