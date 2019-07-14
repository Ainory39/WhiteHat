#include <stdio.h>
#include <stdlib.h>

typedef struct list{
  char name[99];
  int year;
  int month;
  int day;
  
}LIST;

int main(void) {
  int i, n;
  register int j,k; //j: 2차 for문용 변수, k : 스케줄명의 사전식 정렬을 위한 3차 for문용 변수
  
  LIST temp; //temp : swap을 위한 구조체 변수

  scanf("%d",&n);
  LIST *list = (LIST*)calloc(n, sizeof(LIST));
  for(i=0; i<n; i++)
  {
    scanf("%s %d %d %d", list[i].name, &list[i].year, &list[i].month, &list[i].day);
  }

  
  //선택 정렬 알고리즘
  int min; // min : 선택 정렬 알고리즘을 위한 변수
  for(i=0; i<n-1; i++)
  {
    min = i;
    for(j=i+1; j<n; j++)
    {
      if(list[min].year>list[j].year)
        min = j;
      else if(list[min].year == list[j].year)   //비교하려는 두 대상의 연도가 같다면 다음 조건
      {
        if(list[min].month > list[j].month) // month가 더 이른 것을 min에 대입
          min=j;
        else if(list[min].month == list[j].month) // month가 같다면 다음 조건
        {
          if(list[min].day > list[j].day) // day가 더 이른 것을 min에 대입
            min = j;
          else if(list[min].day == list[j].day)
          {
            for(k=0; list[min].name[k]!=0 || list[j].name[k]!=0; k++)  // min번째 문자와 j번째 문자 중 하나라도 비어있지 않을 경우 검사
            {
              if(list[min].name[k] > list[j].name[k])   //k번째 문자가 정렬되었다면 k+1번째 문자는 정렬이 필요없으므로 탈출
              {
                min = j;
                break;
              }
              else if(list[min].name[k] < list[j].name[k]) break; //두 스케줄명이 정렬이 필요없다면 탈출
            }
          }
        }
      }

    }
    if(i!=min)
    {
      temp = list[i];
      list[i] = list[min];
      list[min] = temp;
    }
  }
  
  for(i=0; i<n; i++)
  {
    printf("%s\n", list[i].name);
  }

  return 0;
}
