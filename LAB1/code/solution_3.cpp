#include <cstdio>

int matrix[2001][2001];
int prefix_sum[2001][2001];

int main()
{
    int n, m, q;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        prefix_sum[i][0] = 0;
        for (int j = 1; j <= m; ++j)
        {
            prefix_sum[i][j] = matrix[i][j] + prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
        }
    }
    scanf("%d", &q);
    for (int i = 0; i < q; ++i)
    {
        int x, y, a, b;
        scanf("%d %d %d %d", &x, &y, &a, &b);

        int total_sum = prefix_sum[x + a - 1][y + b - 1] - prefix_sum[x - 1][y + b - 1] - prefix_sum[x + a - 1][y - 1] + prefix_sum[x - 1][y - 1];

        printf("%d\n", total_sum);
    }

    return 0;
}