#include <stdio.h>
#include <string.h>

char str[32];
int num[32];
int remain[1005];

int main()
{

  while (~scanf("%s", str))
  {
    int length = strlen(str);

    for (int i = 0; i < length; i++)
      num[i] = str[i] - '0';

    int index = 0;
    for (int i = 0; i < length;)
    {
      int retain = 0;
      int temp;

      for (int j = 0; j < length; j++)
      {
        temp = (retain * 10 + num[j]) % 2;
        num[j] = (retain * 10 + num[j]) / 2;
        retain = temp;
      }
      remain[index] = retain;
      index++;
      while (num[i] == 0)
        i++;
    }

    for (int k = index - 1; k >= 0; k--)
      printf("%d", remain[k]);
    printf("\n");
  }

  return 0;
}