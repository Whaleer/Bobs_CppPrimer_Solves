#include <stdio.h>
#include <assert.h>

char *strcpy(char *dst, const char *src) {
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    while ((*dst++ = *src++) != '\0');
    return ret;
}

int main(){
    char * a = "Bob";
    char * b = "asd";
    strcpy(a,b);
    printf("%s\n", a);

    printf("=========");

    printf("%s\n", b);
}