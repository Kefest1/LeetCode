#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int expandAroundCenter(char* s, int left, int right) {

    while (left >= 0 && right < strlen(s) && s[left] == s[right]) {
        left--;
        right++;
    }

    return right - left - 1;

}

char* longestPalindrome(char* s) {
    int len = strlen(s);
    if (len < 1)
        return "";

    int start = 0, end = 0;

    for (int i = 0; i < len; i++) {
        int len1 = expandAroundCenter(s, i, i);
        int len2 = expandAroundCenter(s, i, i + 1);
        int maxLen = len1 > len2 ? len1 : len2;

        if (maxLen > end - start) {
            start = i - (maxLen - 1) / 2;
            end = i + maxLen / 2;
        }

    }

    int palLen = end - start + 1;
    char* res = (char*)malloc((palLen + 1) * sizeof(char));
    strncpy(res, s + start, palLen);
    res[palLen] = '\x0';

    return res;
}



int main(void) {
    char s1[] = "babad";

    char* result1 = longestPalindrome(s1);
    printf("Longest Palindrome: %s\n", result1);
    free(result1);


    char s2[] = "cbbd";
    char* result2 = longestPalindrome(s2);
    printf("Longest Palindrome: %s\n", result2);
    free(result2);
    return 0;
}
