#include <stdio.h>
int main() {
    char s[200],maxc;
    int i,j,max=0,count;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        count=1;
        for(j=i+1;s[j]!='\0';j++)
            if(s[i]==s[j]) count++;
        if(count>max){
            max=count;
            maxc=s[i];
        }
    }
    printf("%c %d",maxc,max);
}
