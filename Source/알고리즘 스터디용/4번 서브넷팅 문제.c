#include <stdio.h>
#include <time.h>

int main()
{
  srand(time(NULL));
  register int i, j, k;
  int ip[4][60]={{0},};
  
  //ip[i][j]=rand()%63+(i*64)+1;
  for(i=0; i<4; i++)
  {
      for(j=0; j<60; j++)
      {
          ip[i][j] = rand()%63+(i*64)+1;    // ip주소 할당
          for(k=0; k<j; k++)
          {
            while(ip[i][j]==ip[i][k])       // ip주소가 중복되었다면 중복되지 않을 때까지 재할당
            {
                ip[i][j] = rand()%63+(i*64)+1;
                k=0;    // 할당된 ip주소를 재검사하기 위해 k초기화
            }
          }
      }
  }
  
  for(i=0; i<4; i++)
  {
    printf("192.168.1.%d 서브넷의 ip : \n", i*64);
    for(j=0; j<60; j++)
    {
        printf("192.168.1.%d/26\n", ip[i][j]);
    }
    printf("\n\n====================\n\n");
  }
}
