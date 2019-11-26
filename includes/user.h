int getRegister(){
	int moreAddUsers,lenghtOverflow;
	char nullPassword[1] = ""; 
	moreAddUsers = 0;
	while(moreAddUsers == 0){
		system("cls");
		lenghtOverflow= 1;
		moreAddUsers = 0;
		FILE *usersFile;
		usersFile = fopen(USERS_FILE,"a+");
		struct USER userLog;
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
		
		if(userExist(userLog.email,nullPassword)==0){
			printf("%s",REGISTER_EMAIL_ERROR);
			system("pause");
		}else{
			fwrite(&userLog,sizeof(userLog),1,usersFile);
			printf("%s",REGISTER_USER_SUCCESS);
			system("pause");
		}
		
		fclose(usersFile);
		system("cls");
		printf("deseja criar outro contato?\nSim(0)\nNao(1)\n");
		scanf("%i",&moreAddUsers);
	}
	return 0;
}
int deleteUser(char* email){
	struct USER user;
	FILE *usersFile;
	FILE *usersFileAux;
	usersFile = fopen(USERS_FILE,"a+");
	usersFileAux = fopen("usersaux.txt","a+");
	while(fread(&user,sizeof(user),1,usersFile)!=0){
            if(strcmp(email,user.email)!= 0){
				fwrite(&user,sizeof(user),1,usersFileAux);
            }else if(strcmp(email,user.email)==0){
				deletePostsUser(email);
			}
			
	}	
	fclose(usersFile);
	fclose(usersFileAux);
	remove(USERS_FILE);
	rename("usersaux.txt",USERS_FILE);
	return 0;
}
int editUser(char* email){
	struct USER user;
	struct USER userAux;
	FILE *usersFile; 
	FILE *usersFileAux;
	usersFile = fopen(USERS_FILE,"a+");
	usersFileAux = fopen("usersaux.txt","a+");
	while(fread(&user,sizeof(user),1,usersFile)!=0){
		printf("%i",strcmp(email,user.email));
		getch();
		if(strcmp(email,user.email)==0){
			printf("Digite o novo email:");
			scanf("%s",&user.email);
			printf("Digite a nova senha:");
			scanf("%s",&user.password);
			system("cls");
			if(userExist(user.email,"")==0){
				printf("%S",REGISTER_EMAIL_ERROR);
				fwrite(&user,sizeof(user),1,usersFileAux);
				getch();
			}else{
				fwrite(&user,sizeof(user),1,usersFileAux);
			}
		}else{
			fwrite(&user,sizeof(user),1,usersFileAux);
		}
	}
	fclose(usersFile);
	fclose(usersFileAux);
	remove(USERS_FILE);
	rename("usersaux.txt",USERS_FILE);
}
