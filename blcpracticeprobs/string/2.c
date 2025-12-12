#include <stdio.h>
int main() {
    char s[100];
    int i=0;
    gets(s);
    while(s[i]!='\0'){
        printf("%c\n",s[i]);
        i++;
    }
}
