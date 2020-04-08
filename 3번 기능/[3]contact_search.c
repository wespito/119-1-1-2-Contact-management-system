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
	int i = 0, j = 0;
	int c; //read 용 
	int menu_num;
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
		printf("          **** Welcome to Contact Management ****\n\n");
		printf("                       MAIN MENU\n");
		printf("               ========================\n");
		printf("               [1] Add a new Contact\n");
		printf("               [2] List All Contacts\n");
		printf("               [3] Search fot contact\n");
		printf("               [4] Edit a Contact\n");
		printf("               [5] Delete a Contact\n");
		printf("               [0] Exit\n");
		printf("               ========================\n");
		printf("               Enter the choice:");
		//-------------main UI-------------
	
		scanf_s("%d", &menu_num);
		system( "cls" ); //화면 지우기 
		switch (menu_num){
			
			//-------------[3]-------------
			case 3:
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
				}
				else {
					system( "cls" ); 
					printf("               ========================\n");
					printf("                       SEARCH RESULT \n");
					printf("               ========================\n");
					printf("Name      Phone No       Address      E-mail ad.\n");
					printf("================================================\n");
					printf("Name : %s\nPhone : %s\nAddress : %s\nEmail%s\n", 
					conList[j].Name, 
					conList[j].Phone,
					conList[j].Address,
					conList[j].Email);
					printf("================================================\n");
				} 
				while (!kbhit()); //키 입력 대기 
				fflush(stdin);
				break;
		}
	} while (menu_num != 0);
	
	// 종료 전 파일 저장 
	fpw = fopen("sample.txt", "wt");
	for(j = 0; j < i; j++){
	fprintf(fpw, "%s %s %s %s\n", 
				conList[j].Name, 
				conList[j].Phone,
				conList[j].Address,
				conList[j].Email);
	}
	printf("\n 파일 쓰기 성공. 종료\n");
	
	fclose(fpr);
	fclose(fpw);
	return 0;
}
