#include <stdio.h>
#include <string.h>
int main(){
    char main[100];
    char small[100];
    gets(main);
    gets(small);
    if (strstr(main, small) != NULL)
    {
        printf("yes");
    }
    else{
        printf("no");
    }
    
}