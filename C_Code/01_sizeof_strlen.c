#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char str[20] = "abcdefg";
    char *s = (char *) malloc(20);
    strcpy(s, str);
    // 7 20 7 8
    printf("%d %d %d %d\n", strlen(str), sizeof(str), strlen(s), sizeof(s));

    printf("%ld\n", sizeof('a')); // 4
    return 0;
}