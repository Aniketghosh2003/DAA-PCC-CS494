// Online C compiler to run C program online
#include <stdio.h>
#include <string.h>

void lpsfind(char s[], int *lps)
{
    int pre = 0, suf = 1;

    while (suf < strlen(s))
    {
        if (s[pre] == s[suf])
        {
            lps[suf] = pre + 1;
            pre++;
            suf++;
        }
        else
        {
            if (pre == 0)
            {
                lps[suf] = 0;
                suf++;
            }
            else
            {
                pre = lps[pre - 1];
            }
        }
    }
}

int KMPSearch(char pattern[], char text[])
{
    int n = strlen(pattern);
    int m = strlen(text);
    int lps[n];
    memset(lps, 0, n);
    lpsfind(pattern, lps);

    int first = 0, second = 0;
    while (first < m && second < n)
    {
        if (text[first] == pattern[second])
        {
            first++;
            second++;
        }
        else
        {
            if (second == 0)
            {
                first++;
            }
            else
            {
                second = lps[second - 1];
            }
        }
    }

    if (second == n)
    {
        return first - second;
    }
    return -1;
}

int main()
{
    // Write C code here
    char text[] = "ababa";
    char pattern[] = "ab";

    int index = KMPSearch(pattern, text);

    printf("\nFound pattern at index is :- %d", index);

    return 0;
}