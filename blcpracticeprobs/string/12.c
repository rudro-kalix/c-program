#include <stdio.h>
int main() {
    char s1[100],s2[100];
    int i=0,f=1;
    gets(s1);
    gets(s2);
    while(s1[i]!='\0'||s2[i]!='\0'){
        if(s1[i]!=s2[i]){
            f=0;
            break;
        }
        i++;
    }
    if(f) printf("Equal");
    else printf("Not Equal");
}
