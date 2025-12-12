#include <stdio.h>
int main() {
    char s[200];
    int i=0,a=0,d=0,sp=0;
    gets(s);
    while(s[i]!='\0'){
        if((s[i]>='A'&&s[i]<='Z')||(s[i]>='a'&&s[i]<='z')) a++;
        else if(s[i]>='0'&&s[i]<='9') d++;
        else sp++;
        i++;
    }
    printf("%d %d %d",a,d,sp);
}
