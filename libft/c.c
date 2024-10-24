#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "achaq is here";

    printf("memcpy :%s\n",memcpy(s+7,s+2,5));
    printf("memmove :%s\n",memmove(s+7,s+2,5));
}