#include <bits/stdc++.h>

using namespace std;

int n;
int ans;
int col[16];

bool cond(int x)
{
    for (int i = 0; i < x; i++)
    {
        if (col[i] == col[x] || abs(col[i] - col[x]) == x - i)
        {
            // 같은 y에 존재하거나 대각선 위치에 존재한다면
            // 대각선 -> x좌표의 차 == y좌표의 차
            return false;
        }
    }
    return true;
}

void queen(int x)
{
    if (x == n)
    {
        ans++;
    }
    else
    {
        for (int y = 0; y < n; y++)
        {
            col[x] = y; // (x,y)에 체스를 두겠다.
            if (cond(x))
            {
                queen(x + 1); // 조건을 만족하면 계속 진행
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    queen(0);
    cout << ans << "\n";

    return 0;
}
