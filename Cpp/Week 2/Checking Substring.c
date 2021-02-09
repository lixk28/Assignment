#include <stdio.h>
#include <string.h>

int indexOf(const char *s1, const char *s2)
{
    for(int i = 0; i < strlen(s2); i++)
    {
        int temp, j;
        for(j = 0, temp = i; j < strlen(s1) && temp < strlen(s2); j++, temp++)
        {
            if(s1[j] == s2[temp])
                continue;
            else
                break;
        }
        if(j == strlen(s1))
            return temp-strlen(s1);
    }
    return -1;
}

int main() {
  int t;
  scanf("%d%*c", &t);
  while (t--) {
    // Prompt the user to enter a string
    printf("Enter the first string: ");
    char s1[80];
    fgets(s1, 80, stdin);

    // Prompt the user to enter a string
    printf("Enter the second string: ");
    char s2[80];
    fgets(s2, 80, stdin);

    printf("%d\n", indexOf(s1, s2));
  }
  return 0;
}
