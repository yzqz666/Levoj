#include <stdio.h>
#include <string.h>

int main() {
    char str[25], substr[4];
    scanf("%s %s", str, substr);

    int idx = 0;
    char max_char = str[0];
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] > max_char) {
            max_char = str[i];
            idx = i;
        }
    }

    int nw = len + 3;

    for (int i = len; i >= idx + 1; i--) {
        str[i + 3] = str[i]; 
    }

    for (int i = 0; i < 3; i++) {
        str[idx + 1 + i] = substr[i];
    }

    str[nw] = '\0';

    printf("%s\n", str);
    return 0;
}