#include <stdio.h>

struct contact {
	char Name[50];
	char Phone[15];
	char Address[100];
	char Email[50];
};

int main(){
	FILE *fpr = NULL;
	FILE *fpw = NULL;
	int check=0;
	int i = 0, j = 0, k = 0;
	int c; //read 용 
	int menu_num;
	char YN;
	char serch_word[100];
	struct contact conList[100];
	
	fpr = fopen("sample.txt", "rt"); //read 모드로 file open
	if( fpr == NULL ) {
		printf("파일 읽기 실패\n");
	}
	
	do { 
		fscanf(fpr, "%s %s %s %s", 
		&conList[i].Name, 
		&conList[i].Phone,
		&conList[i].Address,
		&conList[i].Email
		);
		i++; //size
	}while((c = fgetc(fpr)) != EOF); //End Of File 까지 
	printf("파일 읽기 완료\n\n");
	
	do {
		system( "cls" ); //화면 지우기 
		//-------------main UI-------------
       printf("\t**** Welcome to Contact Management ****\n\n");
	   printf("\t\t\tMAIN MENU\n");
	   printf("\t\t========================\n");
	   printf("\t\t[1] Add a new Contact\n");
	   printf("\t\t[2] List All Contacts\n");
	   printf("\t\t[3] Search fot contact\n");
       printf("\t\t[4] Edit a Contact\n");
       printf("\t\t[5] Delete a Contact\n");
       printf("\t\t[0] Exit\n");
       printf("\t\t========================\n");
       printf("\t\tEnter the choice:");
		//-------------main UI-------------
	
		scanf_s("%d", &menu_num);
		system( "cls" ); //화면 지우기 
		switch (menu_num){
			//-------------[1]-------------
			case 1:
				printf("\t\t================================\n");
				printf("\t\t\t ADD CONTACT\n");
				printf("\t\t================================\n");
				printf("Name : ");
		        scanf_s("%s", &conList[i].Name);
		        printf("Phone : ");
		        scanf_s("%s", &conList[i].Phone);
		        printf("Address : ");
		        scanf_s("%s", &conList[i].Address);
		        printf("Email : ");
		        scanf_s("%s", &conList[i].Email);
		        
		        system( "cls" ); //화면 지우기 
		        printf("\n\n\n=============================================================\n");
				printf("Name   :%s\n", conList[i].Name );
		       	printf("Phone  :%s\n", conList[i].Phone);
		       	printf("Adress :%s\n", conList[i].Address);
		       	printf("Email  :%s\n", conList[i].Email);
		       	printf("==============================================================\n\n\n");
		       	i++;
		       	while (!kbhit()); //키 입력 대기 
				fflush(stdin);
			break;
			//-------------[2]-------------
			case 2:
				printf("\t\t================================\n");
		       	printf("\t\t\tLIST OF CONTACTS\n");
		       	printf("\t\t================================\n\n");
		       	printf("Name           Phone No           Address           E-mail ad\n");
		       	printf("=============================================================\n\n\n");
		       	for(j=0;j<i;j++) {
					printf("Name   :%s\n", conList[j].Name );
			       	printf("Phone  :%s\n", conList[j].Phone);
			       	printf("Adress :%s\n", conList[j].Address);
			       	printf("Email  :%s\n", conList[j].Email);
			       	printf("==============================================================\n\n\n");
		        }
		        while (!kbhit()); //키 입력 대기 
				fflush(stdin);
			break;
			//-------------[3]-------------
			case 3:
				printf("\t\t================================\n");
				printf("\t\t\tSearch a Contact\n");
				printf("\t\t================================\n");
				printf("enter name or phoneNumber\n");
				printf("Search : ");
				scanf_s("%s", &serch_word);
				
				for(j = 0; j < i; j++){
					if(strcmp(serch_word, conList[j].Name) == 0 ||
					strcmp(serch_word, conList[j].Phone) == 0 ) {
						break;
					}
				}
				
				if(j==i) {
					printf("일치 데이터 없음 \n");
					while (!kbhit()); //키 입력 대기 
					fflush(stdin);
				}
				else {
					system( "cls" ); 
					printf("\t\t================================\n");
					printf("\t\t\tSEARCH RESULT\n");
					printf("\t\t================================\n");
					printf("Name      Phone No       Address      E-mail ad.\n");
					printf("================================================\n");
					printf("Name : %s\nPhone : %s\nAddress : %s\nEmail : %s\n", 
					conList[j].Name, 
					conList[j].Phone,
					conList[j].Address,
					conList[j].Email);
					printf("================================================\n");
				} 
				while (!kbhit()); //키 입력 대기 
				fflush(stdin);
				break;
				//-------------[4]-------------
				case 4:
					printf("\t\t================================\n");
					printf("\t\t\tEdit a Contact\n");
					printf("\t\t================================\n");
					printf("Enter the name or phoneNumber to edit : ");
					scanf_s("%s", &serch_word);
					
					for(j = 0; j < i; j++){
						if(strcmp(serch_word, conList[j].Name) == 0 ||
						strcmp(serch_word, conList[j].Phone) == 0 ) {
							break;
						}
					}
					
					if(j==i) {
						printf("일치 데이터 없음 \n");
						while (!kbhit()); //키 입력 대기 
						fflush(stdin);
					}
					else {
						system( "cls" ); 
						printf("================================================\n");
						printf("Name : %s\nPhone : %s\nAddress : %s\nEmail : %s\n", 
						conList[j].Name, 
						conList[j].Phone,
						conList[j].Address,
						conList[j].Email);
						printf("================================================\n");
						printf("edit this contact\n");
						printf("1.yes / 2.no\n\n");
						scanf_s("%d", &check);
						
						if (check == 1){
							printf("Name : ");
					        scanf_s("%s", &conList[j].Name);
					        printf("Phone : ");
					        scanf_s("%s", &conList[j].Phone);
					        printf("Address : ");
					        scanf_s("%s", &conList[j].Address);
					        printf("Email : ");
					    	scanf_s("%s", &conList[j].Email);
					    	
					    	system( "cls" );
					    	printf("Edit complete\n");
					    	printf("================================================\n");
					    	printf("Name : %s \nPhone : %s \nAddress : %s \nEmail :%s \n", 
					        conList[j].Name, 
					        conList[j].Phone,
					        conList[j].Address,
					        conList[j].Email
					        );
					        printf("================================================\n");
					        while (!kbhit()); //키 입력 대기 
							fflush(stdin);
						} else if(check == 2) {
							system( "cls" ); 
							printf("Back to main menu");
							while (!kbhit()); //키 입력 대기 
							fflush(stdin);
						} else {
							system( "cls" ); 
							printf("please enter a valid value");
							while (!kbhit()); //키 입력 대기 
							fflush(stdin);
						}
					}
				break;
				//-------------[5]-------------
				case 5:
					printf("\t\t================================\n");
					printf("\t\t\tDelete a Contact\n");
					printf("\t\t================================\n");
					printf("enter name or phoneNumber to delete : ");
					scanf_s("%s", &serch_word);
					
					for(j = 0; j < i; j++){
						if(strcmp(serch_word, conList[j].Name) == 0 ||
						strcmp(serch_word, conList[j].Phone) == 0 ) {
							break;
						}
					}
					
					if(j==i) {
						printf("일치 데이터 없음 \n");
						while (!kbhit()); //키 입력 대기 
						fflush(stdin);
					}
					else {
						system( "cls" ); 
						printf("================================================\n");
						printf("Name : %s\nPhone : %s\nAddress : %s\nEmail%s\n", 
						conList[j].Name, 
						conList[j].Phone,
						conList[j].Address,
						conList[j].Email);
						printf("================================================\n");
						printf("delete this contact\n");
						printf("1.yes / 2.no\n\n");
						scanf_s("%d", &check);
						
						if (check == 1){
							for(k = j; k < i; k++){
								strcpy(conList[k].Name, conList[k+1].Name);
								strcpy(conList[k].Phone, conList[k+1].Phone);
								strcpy(conList[k].Address, conList[k+1].Address);
								strcpy(conList[k].Email, conList[k+1].Email);
							}
							i--;
						} else if(check == 2) {
							system( "cls" ); 
							printf("Back to main menu");
							while (!kbhit()); //키 입력 대기 
							fflush(stdin);
						} else {
							system( "cls" ); 
							printf("please enter a valid value");
							while (!kbhit()); //키 입력 대기 
							fflush(stdin);
						}
					}
					break;
		}
		
		if(menu_num == 0) { //나중에 swich문으로 바꾸셔도 됩니
			printf("Are you sure you want to exit?\n");
			printf("1.yes / 2.no\n\n");
			printf("Enter the choice:");
			
			scanf_s("%d", &check);
		              	
	      	if(check == 1) {
	      	    menu_num = -1;
			} else if(check == 2) {//메뉴화면으로 돌아가야 됨. 
				
			} else {
				system( "cls" ); 
				printf("please enter a valid value");
				while (!kbhit()); //키 입력 대기 
				fflush(stdin);
			}
		}
		
	} while (menu_num != -1);
	
	// 종료 전 파일 저장 
	fpw = fopen("sample.txt", "wt");
	for(j = 0; j < i; j++){
	fprintf(fpw, "%s %s %s %s", 
				conList[j].Name, 
				conList[j].Phone,
				conList[j].Address,
				conList[j].Email);
		if (j!=i-1){
			fprintf(fpw, "\n");
		}
	}
	printf("\n 파일 쓰기 성공. 종료\n");
	
	fclose(fpr);
	fclose(fpw);
	return 0;
}
