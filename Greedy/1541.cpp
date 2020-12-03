#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin >> s;

    int num = 0;
    bool flag = false;

    vector<int> number;
    vector<char> operation;

    for (auto i : s)
    {
        if (isdigit(i))
        {
            num *= 10;
            num += i - '0';
        }
        else
        {
            // operation
            if (flag)
            {
                int temp = number.back();
                number.pop_back();
                number.push_back(temp + num);
                flag = false;
            }
            else
            {
                number.push_back(num);
            }
            if (i == '+')
            {
                flag = true;
            }
            num = 0;
        }
    }
    if (flag)
    {
        int temp = number.back();
        number.pop_back();
        number.push_back(temp + num);
        flag = false;
    }
    else
    {
        number.push_back(num);
    }
    int ans = number[0];
    for (int i = 1; i < number.size(); i++)
    {
        ans -= number[i];
    }
    cout << ans << "\n";

    return 0;
}

/*
vector에서는 1~n-1까지 더한 값을 알고싶을때
accumulate(v.begin()+1, v.end(),0) 함수를 사용하면 편리하다!
*/
