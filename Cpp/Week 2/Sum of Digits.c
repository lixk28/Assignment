#include <stdio.h>

int sumDigits(unsigned int n)
{
    int sum = 0;
    while(n != 0)
    {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main() {
  int t;
  unsigned int n;
  scanf("%d", &t);
  while (t--) {
    scanf("%u", &n);
    printf("%d\n", sumDigits(n));
  }
  return 0;
}
