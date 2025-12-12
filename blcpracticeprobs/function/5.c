#include <stdio.h>

int palindrome(char s[]){
    int i=0,j=0;
    while(s[j]!='\0') j++;
    j--;
    while(i<j){
        if(s[i]!=s[j]) return 0;
        i++; j--;
    }
    return 1;
}

int main(){
    char s[100];
    gets(s);
    if(palindrome(s)) printf("Palindrome");
    else printf("Not Palindrome");
    return 0;
}
