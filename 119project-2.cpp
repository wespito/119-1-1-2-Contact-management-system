#include <stdio.h>

int main()

       {
       	int menu_num;
       	int check=0;
       	
       	scanf("%d", &menu_num);
       	
       			if(menu_num == 0) //���߿� swich������ �ٲټŵ� �˴�
			{
					printf("Are you sure you want to exit?\n");
					printf("1.yes / 2.no\n\n");
					printf("Enter the choice:");
					scanf("%d\n", &check);
	              	
	              	if(check == 1)
	              	{
	              	    return 0;
					}
					else if(check == 2) //�޴�ȭ������ ���ư��� ��. 
					{
						 
					}
					else
					{
						printf("please enter a valid value");
						return 0;
					}
					
		
			}
		}
	   
	   
