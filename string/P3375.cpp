#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;

int main(){
    char s1[N],s2[N];
    scanf("%s\n%s",s1+1,s2+1);
    int len1 = strlen(s1+1);
    int len2 = strlen(s2+1);

    int nxt[N];
    for(int i=2,j=0;i<=len2;i++){
        while(j && s2[j+1]!=s2[i]) j=nxt[j];
        if(s2[j+1]==s2[i]) j++;
        nxt[i]=j;
    }

    for(int i=1,j=0;i<=len1;i++){
        while(j && s2[j+1]!=s1[i]) j=nxt[j];
        if(s2[j+1]==s1[i]) j++;
        if(j==len2){
            printf("%d\n",i-len2+1);
            j=nxt[j];
        }
    }

    for(int i=1;i<=len2;i++){
        printf("%d ",nxt[i]);
    }
   

    return 0;
}