int getRegister(){
	int continuar;
	char a[1] = ""; 
	continuar = 0;
	while(continuar == 0){
		continuar = 0;
		FILE *usersFile;
		usersFile = fopen("users.txt","a+");
		struct USER userLog;
		printf("digite seu email:");
		scanf("%s",userLog.email);
		printf("digite sua senha:");
		scanf("%s",userLog.password);
		if(userExist(userLog.email,a)==1){
			printf("email já existe\n");
			system("pause");
		}else{
			fwrite(&userLog,sizeof(userLog),1,usersFile);
			printf("Cadastro feito com sucesso\n");
			system("pause");
		}
		fclose(usersFile);
		system("cls");
		printf("deseja criar outro contato?\nSim(0)\nNao(1)\n");
		scanf("%i",&continuar);
	}
	return 0;
}
int getLogin(char* emailLog, char* passwordLog){
	if(userExist(emailLog,passwordLog)==0){
		return 0;
	}
	system("cls");
	return 1;
}