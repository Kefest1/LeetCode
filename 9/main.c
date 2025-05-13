#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    int pal = 0;
    int buffer = x;

    while (buffer != 0) {
        int mod = buffer % 10;
        pal *= 10;
        pal += mod;

        buffer /= 10;
    }

    return pal == x;
}

int main(void) {
    printf("%d\n", isPalindrome(-145411));

    return 0;
}
