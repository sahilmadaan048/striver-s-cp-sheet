#include <bits/stdc++.h>
using namespace std;

int main()
{

    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    // #endif

    int n, k;
    scanf("%d%d", &n, &k);

    if (k > n)
    {
        printf("NO\n");
        return 0;
    }

    int cnt[40];
    for (int i = 0; i < 40; ++i)
        cnt[i] = 0;

    for (int d = 0; n > 0; n /= 2, ++d)
        if (n & 1)
            cnt[d] = 1;

    for (int i = 0; i < 40; ++i)
        if (cnt[i])
            --k;

    if (k < 0)
    {
        printf("NO\n");
        return 0;
    }

    for (int i = 35; i > 0 && k > 0; --i)
    {
        int add = min(cnt[i], k);
        cnt[i] -= add;
        k -= add;
        cnt[i - 1] += 2 * add;
    }
    printf("YES\n");
    for (int i = 0; i < 40; ++i)
    {
        for (int j = 0; j < cnt[i]; ++j)
            printf("%d ", 1 << i);
    }
}
