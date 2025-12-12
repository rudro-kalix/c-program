#include <stdio.h>
int main() {
    char s[100];
    int i=0;
    gets(s);
    while(s[i]!='\0') i++;
    for(i=i-1;i>=0;i--) printf("%c",s[i]);
}
