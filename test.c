#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[20] = "abcd";
    char *s = (char *) malloc(20);
    strcpy(s, str);
    // 4 20 4 8
    printf("%ld %ld %ld %ld\n", strlen(str), sizeof(str), strlen(s), sizeof(s));
    return 0;
}