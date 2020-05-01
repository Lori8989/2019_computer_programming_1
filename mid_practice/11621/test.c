#include<stdio.h>
#include<string.h>
 
char s[2002];
int ans;
int len;
 
int check(int l,int r){
    int size= r+l+1;
    int mid= size/2;
    for(int i=l;i<mid;i++){
        if(s[i]!=s[size-i-1])
            return 0;
    }
    return 1;
}
 
 
void a(int l,int r){
    if(l<0 || r>len){
        return;
    }else{
        if(check(l,r)==1){
            ans++;
            return a(l-1,r+1);
        }else
            return;
    }
}
 
int main(void){
    while(scanf("%s",s)!=EOF){
        ans=0;
        len=strlen(s);
        int m=len/2;
        int count=0;
        if(len%2==1){      //奇數
            a(m,m+2);
            a(m-2,m);
            a(m-1,m+1);
            a(m-2,m+1);
            a(m-1,m+2);
            for(int i=0;i<len;i++){
                if(s[i]==s[i+1]) count++;
            }
 
            ans=ans+count;
            printf("%d\n",ans);
        }else{
            a(m,m+2);
            a(m-2,m);
            a(m-1,m+1);
            a(m-2,m+1);
            a(m-3,m);
            a(m-1,m+2);
 
            for(int i=0;i<len;i++){
                if(s[i]==s[i+1]) count++;
            }
 
            ans=ans+count;
            printf("%d\n",ans);
        }
        count=0;
        ans=0;
    }
    return 0;
}