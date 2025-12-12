#include <stdio.h>
int main() {
    char s[200];
    int i=0,words=1;
    gets(s);
    while(s[i]!='\0'){
        if(s[i]==' ' && s[i+1]!=' ') words++;
        i++;
    }
    printf("%d",words);
}
