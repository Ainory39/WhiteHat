#include <stdio.h>


int Check(int x)    // 인수가 소수인지 검사
{
  char flag=0;
  for(int i=2; i<x; i++)
  {
    if(x%i==0) flag=1;    //소수라면 1과 자신외에는 나누어지지 않음을 검사
  }
  
  return !flag;
}

int main(void) {
  int n, cntLmt=0;    // cntLmt : 가장 작은 소수를 2개까지만 출력 제한
  int ans[2]={0};
  scanf("%d", &n);

  for(int i=2; i<n; i++) // cntLmt : 가장 작은 소수를 2개까지만 출력 제한
  {
    
    if(n%i==0 && Check(i)) // n이 i로 나누어 떨어지고, i가 소수라면
    {
      ans[cntLmt] = i;
      cntLmt++;
    }
    if(cntLmt==2) break;
  }

    if(ans[0]!=0 && ans[1]!=0 && n==(ans[0]*ans[1])) printf("%d %d", ans[0], ans[1]); // 두 값이 모두 0이 아니고 두 값의 곱으로 n을 만들 수 있다면 출력
    else printf("wrong number");

  return 0;
}
