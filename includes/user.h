int getRegister(){
	int moreAddUsers,lenghtOverflow;
	char nullPassword[1] = ""; 
	moreAddUsers = 0;
	struct USER userLog;
	while(moreAddUsers == 0){
		system("cls");
		lenghtOverflow= 1;
		moreAddUsers = 0;
		printf("digite seu email:");
		while(lenghtOverflow== 1){
			scanf("%s",userLog.email);
			if(strlen(userLog.email)>50){
				printf("%s",USER_EMAIL_LENGHT_ERROR);
				lenghtOverflow= 1;
			}else{
				lenghtOverflow=0;
			}
		}
		lenghtOverflow = 1;
		while(lenghtOverflow== 1){
			system("cls");
			printf("digite sua senha:");
			scanf("%s",userLog.password);
			if(strlen(userLog.password)>16){
				printf("%s",USER_PASSWORD_LENGHT_ERROR);
				lenghtOverflow= 1;
			}else if(strlen(userLog.password) < 8){
				printf("%s",USER_PASSWORD_LENGHT_SMALL_ERROR);
			}
			else{
				lenghtOverflow=0;
			}
		}
			if(POSITION >= sizeUser-1){
				sizeUser = sizeUser*2;
				users = (struct USER *)realloc(users,sizeUser*sizeof(struct USER));
			}
			if(userExist(userLog.email,nullPassword,users)==0){
					printf("%s",REGISTER_EMAIL_ERROR);
					system("pause");
			}else{
					printf("indice:%i\n",POSITION);
					printf("valor:%s",users[POSITION].email);
					users[POSITION] = userLog;
					printf("%s",REGISTER_USER_SUCCESS);
					system("pause");
				}	
			POSITION++;
			
		system("cls");
		printf("deseja criar outro contato?\nSim(0)\nNao(1)\n");
		scanf("%i",&moreAddUsers);
		}
		
	return 0;
}
int deleteUser(char* email){
	struct USER *newUsers;
	newUsers = (struct USER *)malloc(POSITION*sizeof(struct USER));
	int i,j;
	j=0;
	for(i=0;i<=POSITION;i++){
            if(strcmp(email,users[i].email)!= 0){
				newUsers[j] = users[i];
				j++;
            }
			else if(strcmp(email,users[i].email)==0){
				deletePostsUser(email);
			}
	}
	users = newUsers;
	return 0;
}
int editUser(char* email){
	int i,j;
	j=0;
	struct USER *newUsers;
	newUsers = (struct USER *)malloc((POSITION+1) * sizeof(struct USER));
	/*
		O for abaixo verificara se o email existe. se existe ele vai pedir o novo email e a nova senha,
		se o email verificado não for igual ao pedido, ele será escrito na nova struct;
	*/
	for(i=0;i<=POSITION;i++){
		if(strcmp(email,users[i].email)==0){
			while(j==0){
				printf("Digite o novo email:");
				scanf("%s",&newUsers[i].email);
				printf("Digite a nova senha:");
				scanf("%s",&newUsers[i].password);
				system("cls");
				if(userExist(newUsers[i].email,"",users)==0){
					printf("%s",REGISTER_EMAIL_ERROR);
					getch();
				}else{
					j=1;
				}
			}
		}else{
			newUsers[i]=users[i];
		}
	}
	users = newUsers;
	return 0;
}