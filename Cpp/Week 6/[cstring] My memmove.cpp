#include <cstdio>

char* my_memmove(char *dst, const char *src, unsigned int n)
{
  if(src > dst) //如果src地址大于dst地址，从前开始copy
  {
    for(int i = 0; i < n; i++)
      dst[i] = src[i];
  }
  else if(src < dst) //如果src地址小于dst地址，从后开始复制
  {
    const char *tmp1 = src + n - 1;
    char *tmp2 = dst + n - 1;
    for(int i = 0; i < n; i++)
    {
      *tmp2 = *tmp1;
      tmp1--;
      tmp2--; 
    }
  }

  return dst;
}

int main() {
  char buf[32] = {};
  scanf("%31s", buf);

  int src_offset = 0, dst_offset = 0, copy_size = 0;
  scanf("%d%d%d", &src_offset, &dst_offset, &copy_size);

  my_memmove(buf + dst_offset, buf + src_offset, copy_size);

  printf("%-31s\n", buf);

  return 0;
}