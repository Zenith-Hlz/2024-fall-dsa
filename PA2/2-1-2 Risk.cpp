#include <cstdio>
#include <cstdlib>
#include <climits>

// Queap implementation
class Queap
{
    long long *Q; // Queue to store values
    long long *P; // Heap-like structure to store the max values
    long long frontQ, rearQ, frontP, rearP;

public:
    Queap(long long n)
    {
        Q = new long long[n];
        P = new long long[n];
        frontQ = rearQ = frontP = rearP = 0;
    }

    ~Queap()
    {
        delete[] Q;
        delete[] P;
    }

    // Enqueue operation
    void enqueue(long long value)
    {
        Q[rearQ++] = value;

        // Maintain P to keep max values
        while (rearP > frontP && P[rearP - 1] < value)
        {
            --rearP; // Remove smaller elements as they are no longer useful
        }
        P[rearP++] = value;
    }

    // Dequeue operation
    void dequeue()
    {
        if (frontQ < rearQ)
        {
            long long dequeued = Q[frontQ++];
            if (dequeued == P[frontP])
            {
                frontP++; // Remove from P if it was the max element
            }
        }
    }

    // Get max from P (current max of sliding window)
    long long getMax()
    {
        return P[frontP];
    }
};

int compare(const void *a, const void *b)
{
    long long int_a = *(const long long *)a;
    long long int_b = *(const long long *)b;

    if (int_a < int_b)
        return -1;
    if (int_a > int_b)
        return 1;
    return 0;
}

// Function to perform binary search for upper bound
long long upper_bound(long long *arr, long long size, long long value)
{
    long long low = 0, high = size;
    while (low < high)
    {
        long long mid = (low + high) / 2;
        if (arr[mid] <= value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    return low;
}

int main()
{
    long long n;
    scanf("%lld", &n);

    long long *cases = new long long[n + 1];
    cases[0] = 0;
    for (long long i = 1; i <= n; ++i)
    {
        scanf("%lld", &cases[i]);
    }

    long long *m = new long long[n];
    for (long long i = 0; i < n; ++i)
    {
        scanf("%lld", &m[i]);
        m[i] = (m[i] < i) ? m[i] : (i + 1);
    }

    long long *d = new long long[n];
    Queap queap(n);

    // Calculate `d[i]` for each day using the sliding window of `mi` days
    for (long long i = 0; i < n; ++i)
    {
        if (i > 0)
        {
            for (long long j = 0; j <= m[i - 1] - m[i]; j++)
            {
                queap.dequeue(); // Remove out-of-range elements
            }
        }
        queap.enqueue(cases[i]);
        d[i] = queap.getMax();
    }

    // Sort d to make threshold querying efficient
    qsort(d, n, sizeof(long long), compare);

    long long T;
    scanf("%lld", &T);
    for (long long t = 0; t < T; ++t)
    {
        long long p, q;
        scanf("%lld%lld", &p, &q);

        // Use binary search to find the counts
        long long lowRiskCount = upper_bound(d, n, p - 1);
        long long mediumRiskCount = upper_bound(d, n, q - 1) - lowRiskCount;

        printf("%lld %lld\n", lowRiskCount, mediumRiskCount);
    }

    delete[] cases;
    delete[] m;
    delete[] d;

    return 0;
}