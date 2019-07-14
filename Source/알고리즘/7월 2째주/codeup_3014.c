#include <stdio.h>
#include <stdlib.h>
// swap 정의
#define SWAP(x, y, temp) ((temp)=(x), (x)=(y), (y)=(temp))

int partition(int list[], int left, int right)
{
  int pivot, temp;
  int low, high;
  low = left;
  high = right+1;

  // 가장 첫번째 값을 피벗 값으로 지정
  pivot = list[left];

  do{
    do{
      low++;  //low가 피벗 값보다 작고, right를 넘지 않는다면 증가
    }while(low<=right && list[low]<pivot);
    
    do{
      high--; //high가 피벗 값보다 크고, left를 넘지 않는다면 감소
    }while(high>=left && list[high]>pivot);

    if(low < high)    // low와 high가 교차하지 않았다면 swap
    {
      SWAP(list[low], list[high], temp);
    }

  }while(low<high);

  // low와 high가 교차했다면 left와 high를 swap
  SWAP(list[left], list[high], temp);

  // 피벗 값이 위치한 high를 반환
  return high;
}

void quick_st(int *list, int left, int right)
{
  int temp;
  // 배열의 요소 개수가 2개라면 검사 후 swap
  if(sizeof(list)/sizeof(int) == 2)
  {
    if(list[0] > list[1]) SWAP(list[0], list[1], temp);
  }

  if(left < right)
  {
    //피벗 값 저장
    int p = partition(list, left, right);

    //피벗 값을 제외한 나머지 2개의 리스트를 퀵 정렬
    quick_st(list, left, p-1);
    quick_st(list, p+1, right);
  }
}

int main(void) {
  
  int n;
  scanf("%d", &n);
  int *num = (int*)calloc(n, sizeof(int));


  for(int i=0; i<n; i++)
  {
    scanf("%d ", &num[i]);
  }

  if(n!=1) quick_st(num, 0, n-1);

  for(int i=0; i<n; i++)
  {
    printf("%d ", num[i]);
  }
  
  return 0;
}
