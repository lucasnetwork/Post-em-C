int getRegister(){
	int moreAddUsers;
	char nullPassword[1] = ""; 
	moreAddUsers = 0;
	struct USER userLog;
	while(moreAddUsers == 0){
		system("cls");
		moreAddUsers = 0;
		memmove(userLog.email,addValues(USER_EMAIL_LENGHT_ERROR,"","Digite o seu email:",50,0),sizeof(userLog.email));
		memmove(userLog.password,addValues(USER_PASSWORD_LENGHT_ERROR,USER_PASSWORD_LENGHT_SMALL_ERROR,"Digite a sua senha:",16,8),sizeof(userLog.password));
			if(POSITION >= SIZE_USER-1){
				SIZE_USER = SIZE_USER*2;
				users = (struct USER *)realloc(users,SIZE_USER*sizeof(struct USER));
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
				memmove(newUsers[i].email,addValues(USER_EMAIL_LENGHT_ERROR,"","Digite o seu novo email:",50,0),sizeof(newUsers[i].email));
				memmove(newUsers[i].password,addValues(USER_PASSWORD_LENGHT_ERROR,USER_PASSWORD_LENGHT_SMALL_ERROR,"Digite a sua nova senha:",16,8),sizeof(newUsers[i].password));
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