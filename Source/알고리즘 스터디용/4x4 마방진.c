#include <stdio.h>
#define MAX 4
int main()
{
  int ma[MAX][MAX]=
  {{1,2,3,4},
   {5,6,7,8},
   {9,10,11,12},
   {13,14,15,16}};

  /*
    4x4 마방진 알고리즘 : 
    4x4칸의 표에 중복되지 않게끔 수를 채워 넣는다. 이를 표1이라고 한다.
    표1의 수를 역순으로 4x4칸의 표2에 저장한다.

    이때 표2의 대각선 요소들을 표 1에 대입하면
    4x4 마방진이 완성된다.
  */

  int ma_2[MAX][MAX];
  for(int x=0, i=MAX-1; i>=0; x++, i--)
  {//i와 j는 ma를, x와 j는 ma_2를 위한 변수
    for(int y=0, j=MAX-1; j>=0; y++, j--)
    { // ma의 요소들을 반대로 ma_2에 저장하는 작업
      ma_2[x][y] = ma[i][j];
    }
  }

  for(int i=0; i<MAX; i++)
  {
    for(int j=0; j<MAX; j++)
    {
      printf("%2d ", ma[i][j]);
    }
    printf("  ");
    for(int j=0; j<MAX; j++)
    {
      printf("%2d ", ma_2[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  for(int i=0; i<MAX; i++)
  {
    for(int j=0; j<MAX; j++)
    {
      if(i==j || i+j==3) //i와 j가 같거나, i+j가 3라면 대각선 요소이므로 이를 제외한 값들을 ma에 대입한다.
        ma[i][j] = ma_2[i][j];
    }
  }

  for(int i=0; i<MAX; i++)
  {
    for(int j=0; j<MAX; j++)
    {
      printf("%2d ", ma[i][j]);
      //printf("%d,%d ", i, j);
    }
    printf("\n");
  }

  return 0;
}
