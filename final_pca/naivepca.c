#include <stdio.h>
#include <string.h>

void naivemethod(char text[], char pattern[])
{
    int m = strlen(text);
    int n = strlen(pattern);
    int cnt = 0;

    for (int i = 0; i < m - n+1; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (text[i + j] == pattern[j])
            {
                cnt++;
            }
            else
            {
                break;
            }
            
        }
        if (cnt == n)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}

int main()
{
    char text[] = "ABABDABACDABABCABAB";
    char pattern[] = "ABABCABAB";
    naivemethod(text, pattern);
    return 0;
}