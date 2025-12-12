#include <stdio.h>
int main() {
    char s1[100],s2[100];
    int i=0;
    gets(s1);
    while(s1[i]!='\0'){
        s2[i]=s1[i];
        i++;
    }
    s2[i]='\0';
    printf("%s",s2);
}
