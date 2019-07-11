#include <stdio.h>
//비교적 효율적인 버블정렬
int main(void) {
  int i, j;
  int temp;
  int count=0;
  int flag=0;
  int arr[11] = {1,2,3,4,5,6,7,8,9,10,11};
  

  for(i=10;i!=0; i--)
  {
    flag=0;
    for(j=0;j<i-1; j++)
    {
      if(arr[j]>arr[j+1])
      {
        temp = arr[j];
        arr[j] = arr[j+1];
        arr[j+1] = arr[j];
        flag++;
      }
    }
    count++;
    if(flag==0) break;
  }

  printf("\n\ncount : %d", count);

  return 0;
}
