#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct list{
  char str[MAX];
  int num;
  int sum; // 해당 단어의 번호 누적 수
}LIST;

int main(void) {
  int n, m, cnt=0, chk=0;// n: 등록 횟수, m : 질문 횟수, cnt : 현재 등록된 단어 수, chk : 등록된 단어인지 체크.
  char tempStr[MAX];
  int tempNum; //기존에 있던 문자열인지 비교해보고 기존에 없던 것이라면 여기에 저장한 것을 그대로 구조체를 만듬.
  scanf("%d %d", &n, &m); 

  LIST list[n];
  char query[m][MAX];
  

  for(int i=0; i<n; i++)
  {
    scanf("%s %d", tempStr, &tempNum);
    chk=0;
    for(int j=0; j<cnt; j++)
    {
      //입력 받은 단어와 list[j번째 구조체].str이 같다면
      if(strcmp(tempStr, list[j].str)==0)
      {
        list[j].sum+=tempNum; // 해당 구조체의 sum변수에 단어 번호를 누적
        chk=1;		// 등록되었던 단어라는 사실을 기억 
        break;
      }
    }

    if(chk==0) // 단어가 등록되었는지 아닌지 검사 
    {
    	// 아니라면 추가. 
    	cnt++;
        strcpy(list[i].str, tempStr);
        list[i].num = tempNum;
        list[i].sum = tempNum;
    }
  }
  //printf("asdfasdf\n");
  for(int i=0; i<m; i++)
  {
    scanf("%s", query[i]);
  }

  for(int i=0; i<m; i++)
  {
    chk=0;
    for(int j=0; j<cnt; j++)
    {
      //query[i번째 문자열]과 list[j번째 구조체].이름이 같다면
      if(strcmp(query[i], list[j].str)==0) 
      {
        chk=list[j].sum;
      }
    }
    printf("%d\n", chk);
  }

  return 0;
}
