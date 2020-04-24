#include<stdlib.h>
#include<stdio.h>

int main(){
    int t = 0;
    scanf("%d", &t);
    
    for(int i = 0; i < t; i++){
        int n = 0, m = 0, k = 0;
        long int seq[5003] = {0};
        scanf("%d %d %d", &n, &m, &k);
        // printf("%d %d %d\n", n, m, k);

        for(int j = 0; j < n; j++){
            scanf("%ld", &(seq[j]));
        }

        int ordered = k <= m - 1? k : m - 1;
        int unordered = m - k - 1 <= 0? 0 : m - k - 1;
        // printf("Ordered: %d, Unordered: %d\n", ordered, unordered);

        long max_ordered = 0;
        for(int i = 0; i <= ordered; i++){
            int start_o = ordered - i;
            int end_o = n - 1 - i;

            // printf("start_o: %d end: %d\n", start_o, end_o);
            
            long int min_unordered = 1000000003;
            for(int j = 0; j <= unordered; j++){
                int start_u = start_o + unordered - j;
                int end_u = end_o - j;
                // printf("Unordered start: [%d]-%ld end: [%d]-%ld\n", start_u, seq[start_u], end_u, seq[end_u]);

                long int local_max = seq[start_u] > seq[end_u]? seq[start_u] : seq[end_u];
                if(min_unordered > local_max){min_unordered = local_max;}
            }

            if(min_unordered > max_ordered){max_ordered = min_unordered;}
        }

        printf("%ld\n", max_ordered);
    }

    return 0;
}