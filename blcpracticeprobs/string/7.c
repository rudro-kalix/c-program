#include <stdio.h>
int main() {
    char s[200];
    int i,j,count;
    gets(s);
    for(i=0;s[i]!='\0';i++){
        count=1;
        if(s[i]==' ') continue;
        for(j=i+1;s[j]!='\0';j++){
            if(s[i]==s[j]){
                count++;
                s[j]=' ';
            }
        }
        printf("%c = %d\n",s[i],count);
    }
}
