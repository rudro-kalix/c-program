#include <stdio.h>
int main() {
    char s[100],sub[100];
    int i,pos,len;
    gets(s);
    scanf("%d %d",&pos,&len);
    for(i=0;i<len;i++) sub[i]=s[pos+i];
    sub[i]='\0';
    printf("%s",sub);
}
