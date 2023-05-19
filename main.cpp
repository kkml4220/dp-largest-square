#include <iostream>

using namespace std;

#define MAX 1400

int dp[MAX][MAX], map[MAX][MAX];

int solver(int h, int w)
{
    int maxWidth = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (map[i][j] == 0)
                dp[i][j] = 1;
            else
                dp[i][j] = 0;
        }
    }

    for (int i = 1; i < h; i++)
    {
        for (int j = 1; j < w; j++)
        {
            if (map[i][j])
                dp[i][j] = 0;
            else
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth, dp[i][j]);
            }
        }
    }

    return maxWidth * maxWidth;
}

int main(int argc, char *agrv[])
{
    int h, w;

    // 入力
    cin >> h;
    cin >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> map[i][j];

    // 出力
    cout << solver(h, w) << endl;

    return 0;
}