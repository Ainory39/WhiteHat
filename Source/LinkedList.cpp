#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE{
	NODE *next;
	char name[10];
	char phoneNum[20];
}NODE;

void Append_Node(NODE *target)		// target 노드 뒤에 새로운 노드 생성 및 삽입
{
	//printf("\n\nHERE!!!!\n");
	NODE *newNode = (NODE*)malloc(sizeof(NODE*));
	newNode->next = target->next;		// 새 노드의 다음 노드는 타겟 노드의 다음 노드
	target->next = newNode;				// 타겟 노드의 다음은 새 노드 
	
	printf("\n--- 이름 입력 : ");
	scanf("%s", newNode->name);
	
	printf("\n--- 전화번호 입력 : ");
	scanf("%s", newNode->phoneNum);
	
	printf("\n저장되었습니다.\n");
}

void Delete_Node(NODE *head)
{
	NODE *PrevNode=head;
	NODE *curr = PrevNode->next;
	
	
	char search[10];
	
	printf("\n---삭제하고하는 전화번호의 이름 입력 : ");
	scanf("%s", search);
	
	while(curr != NULL)
	{
		if(strcmp(curr->name, search)==0)
		{
			PrevNode->next = curr->next;
			free(curr);
			printf("삭제되었습니다.\n");
			return;
		}
		PrevNode = curr;
		curr= curr->next;
	}
	printf("해당 이름이 없습니다.\n");
	
}

void Search_Node(NODE *head)
{
	NODE *curr;		// 노드 선택용 노드
	char search[10];
	int nodeCnt=1;		// 찾는 데이터가 들어있는 노드의 위치 
	char q=1;		// 반복 체크용 변수 q 
	
	while(1)
	{
		curr = head->next;		// 노드 선택용 노드
		nodeCnt=1;
		
		printf("\n--- 찾으려는 이름 입력 : ");
		scanf("%s", search);
			
		while(1) 
		{
			if(strcmp(curr->name, search) == 0)
			{
				printf("해당 데이터는 %d번째 노드에 위치해있습니다.\n", nodeCnt);
				break;
			}
			
			curr = curr->next;
			nodeCnt++;
			if(curr==NULL)
			{
				printf("해당 데이터를 가진 노드가 없습니다.\n");
				break;
			}
			
		}
		
		printf("종료하시겠습니까? (y/n) : ");
		scanf(" %c", &q);
		if(q=='y' || q=='Y') break;
	}
	
}

void Print_Node(NODE *head)
{
	int cnt=1;
	
	NODE *curr=head->next;
	
	printf("\n------------------------\n  이름  |  전화번호\n");
	
	while(curr!=NULL)
	{
		printf("%s | %s\n", curr->name, curr->phoneNum);
		curr=curr->next;
	}
	printf("\n---끝---\n");
}

int main()
{
	NODE *head = (NODE*)malloc(sizeof(NODE*));
	head->next=NULL;
	short select=0;
	char whileCh=1;		// 반복문 체크용 변수 
	
	while(whileCh)
	{
		printf("\n\n---- MENU ----\n");
		printf("1) 전화번호부 출력\n");
		printf("2) 전화번호 입력\n");
		printf("3) 전화번호 삭제\n");
		printf("4) 이름으로 전화번호 검색\n");
		printf("5) 시스템 종료\n");
		printf("입력 : ");
		scanf("%d%*c", &select);
		
		switch(select)
		{
			case 1:
				Print_Node(head);
				break;
			case 2:
				Append_Node(head);
				break;
			case 3:
				Delete_Node(head);
				break;
			case 4:
				Search_Node(head);
				break;
			case 5:
				whileCh=0;
		}
		
		select = 0;
	}

	
	return 0;
}

