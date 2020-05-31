#include <stdio.h>
#include <stdlib.h>
long long int pre[500001], prez[500001], temp[500001];
 
int main(void)
{
    long long int t, a, b, c, d, ans;
    scanf("%lld", &t);
    while (t--)
    {
        pre[0] = 0;
        prez[0] = 0;
        ans = 0;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        for (int i = a; i <= b; i++)
        {
            temp[i + b]++;
            temp[i + c + 1]--;
        }
        printf("B - A: %lld\n", b - a);
        printf("C - B: %lld\n", c - b);
        for (int i = 1; i <= b + c; i++)
        {
            pre[i] = pre[i - 1] + temp[i];
        }
        for (int i = 1; i <= c + d; i++)
        {
            prez[i] = prez[i - 1] + pre[i];
        }
        for (int j = c; j <= d; j++)
        {
            ans += (prez[c + d] - prez[j]);
        }
        printf("%lld\n", ans);
 
        for (int i = 0; i <= 500001; i++)
        {
            temp[i] = 0;
            //prez[i] = 0;
            pre[i] = 0;
        }
    }
 
}