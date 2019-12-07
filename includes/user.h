int getRegister(){
	int moreAddUsers;
	char nullPassword[1] = ""; 
	moreAddUsers = 0;
	struct USER userLog;
	while(moreAddUsers == 0){
		system("cls");
		moreAddUsers = 0;
		memmove(userLog.email,addValues(USER_EMAIL_LENGHT_ERROR,"",
		"Digite o seu email:",50,0),sizeof(userLog.email));

		memmove(userLog.password,addValues(USER_PASSWORD_LENGHT_ERROR,USER_PASSWORD_LENGHT_SMALL_ERROR,
		"Digite a sua senha:",16,8),sizeof(userLog.password));
		
			if(POSITION >= SIZE_USER-1){
				SIZE_USER = SIZE_USER*2;
				users = (struct USER *)realloc(users,SIZE_USER*sizeof(struct USER));
			}
			if(userExist(userLog.email,nullPassword,users)==0){
				printf("%s",REGISTER_EMAIL_ERROR);
				system("pause");
			}else{
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
	int data,newData;
	newData=0;
	for(data=0;data<=POSITION;data++){
            if(strcmp(email,users[data].email)!= 0){
				newUsers[newData] = users[data];
				newData++;
            }
			else if(strcmp(email,users[data].email)==0){
				deletePostsUser(email);
			}
	}
	free(users);
	users = newUsers;
	return 0;
}
int editUser(char* email){
	int data,emailExist;
	emailExist=0;
	struct USER *newUsers;
	newUsers = (struct USER *)malloc((POSITION+1) * sizeof(struct USER));
	/*
		O for abaixo verificara se o email existe. se existe ele vai pedir o novo email e a nova senha,
		se o email verificado não for igual ao pedido, ele será escrito na nova struct;
	*/
	for(data=0;data<=POSITION;data++){
		if(strcmp(email,users[data].email)==0){
			while(emailExist==0){
				memmove(newUsers[data].email,addValues(USER_EMAIL_LENGHT_ERROR,"",
				"Digite o seu novo email:",50,0),sizeof(newUsers[data].email));
				
				memmove(newUsers[data].password,addValues(USER_PASSWORD_LENGHT_ERROR,USER_PASSWORD_LENGHT_SMALL_ERROR,
				"Digite a sua nova senha:",16,8),sizeof(newUsers[data].password));

				system("cls");
				if(userExist(newUsers[data].email,"",users)==0){
					printf("%s",REGISTER_EMAIL_ERROR);
					getch();
				}else{
					emailExist=1;
				}
				renamePostsUser(users[data].email,newUsers[data].email);
			}
		}else{
			newUsers[data]=users[data];
		}
	}
	free(users);
	users = newUsers;
	return 0;
}