#include <cstdio>
#include <cstdlib>
#include <cstdint>

const int MAXN = 200000;
int x[MAXN], y[MAXN];
int results[MAXN];

int64_t cross(int x1, int y1, int x2, int y2)
{
    return (int64_t)x1 * y2 - (int64_t)x2 * y1;
}

int compare(const void *a, const void *b)
{
    return (*(int *)a) - (*(int *)b);
}

int main()
{
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &x[i]);
    }
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &y[i]);
    }

    qsort(x, n, sizeof(int), compare);
    qsort(y, n, sizeof(int), compare);

    int m;
    scanf("%d", &m);

    for (int i = 0; i < m; i++)
    {
        int px, py;
        scanf("%d", &px);
        scanf("%d", &py);

        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right)
        {
            int mid = (left + right) / 2;

            if (cross(px, py - y[mid], x[mid], -y[mid]) <= 0)
            {
                ans = mid + 1;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        results[i] = ans;
    }

    for (int i = 0; i < m; i++)
    {
        printf("%d\n", results[i]);
    }

    return 0;
}
