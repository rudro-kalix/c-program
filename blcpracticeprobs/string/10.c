#include <stdio.h>
int main() {
    char s[200];
    int i=0;
    gets(s);
    while(s[i]!='\0'){
        if(s[i]>='a'&&s[i]<='z') s[i]-=32;
        else if(s[i]>='A'&&s[i]<='Z') s[i]+=32;
        i++;
    }
    printf("%s",s);
}
