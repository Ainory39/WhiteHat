#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  int num;    // 장치 식별 번호
  int gas;    // 장치의 가스 보유량
}LIST;

int main(void) {
  int n;
  int i,j,min;    // min : 선택 정렬을 위한 변수
  LIST temp;      // swap을 위한 구조체 변수

  scanf("%d", &n);
  LIST list[n]; //입력 받은 수만큼의 장치 개수
  
  for(i=0;i<n;i++)
  {
    scanf("%d %d", &list[i].num, &list[i].gas); // 장치의 정보 입력
  }
  
  for(i=0;i<n-1;i++)
  {
    min=i;      // 현재 선택된 i의 값을 min에 대입
    for(j=i+1;j<n;j++)    // i의 다음 요소부터 검사
    {
      if(list[j].num < list[min].num)   // min의 식별번호보다 j의 식별번호 값이 더 작다면
        min=j;      // j의 값을 min에 대입
    }
    if(i!=min)    // 한번이라도 min의 값이 바뀌었다면
    {   // 현재 i의 식별번호와 i의 다음 요소들 중 최소값을 가지는 식별번호와 swap하여 정렬
      temp = list[i];
      list[i] = list[min];
      list[min] = temp;
    }
  }
  for(i=0;i<n;i++)
  {// 출력
    printf("%d %d\n", list[i].num, list[i].gas);
  }

  return 0;
}
