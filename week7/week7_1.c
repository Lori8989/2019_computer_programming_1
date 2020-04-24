#include <stdio.h>
#include <stdlib.h>

int compare(char *a, int startA, int endA, char *b, int startB, int endB){
    int lenA = endA - startA + 1;
    int lenB = endB - startB + 1;

    int re_is_same = 1;

    if(lenA % 2 == 1){
        for(int iA = startA, iB = startB; iA <= endA, iB <= endB; iA++, iB++){
            if(a[iA] != b[iB]){re_is_same = 0; break;}
        }
    }else{
        int midA = (startA + endA) / 2;
        int midB = (startB + endB) / 2;
        if(compare(a, startA, midA, b, startB, midB) && compare(a, midA + 1, endA, b, midB + 1, endB)){
            re_is_same = 1;
        }else if(compare(a, startA, midA, b, midB + 1, endB) && compare(a, midA + 1, endA, b, startB, midB)){
            re_is_same = 1;
        }else{
            re_is_same = 0;
        }
    }

    return re_is_same;
}

int main(){
    char t;
    int i = 0;
    int j = 0;
    int is_newline = 0;
    char a[100005] = {0};
    char b[100005] = {0};

    while((t = getchar()) != EOF){
        if(t == '\n'){
            is_newline = 1;
        }else if(!is_newline){
            a[i] = t;
            i++;
            // printf("%c", t);
        }else{
            b[j] = t;
            j++;
            // printf("%c", t);
        }
    }

    if(compare(a, 0, i - 1, b, 0, j - 1)){
        printf("YES\n");
    }else{
        printf("NO\n");
    }

    return 0;
}