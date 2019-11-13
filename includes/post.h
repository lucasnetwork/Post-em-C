int createPost(char* email){
	struct POST post;
	int continuar,a;
	a= 1;
	continuar = 0;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	while(continuar ==0){
		printf("Escreva seu post: ");
		while(a== 1){
			if(strlen(post.postContent)>10){
				printf("post muito grande\n");
				a= 1;
			}else{
				a=0;
			}
		}
		fwrite(&post,1,sizeof(post),postFile);	
		printf("post cadastra com sucesso");
		getch();
		system("cls");
		printf("Deseja continuar?\n");
		scanf("%i",&continuar);
	}
	fclose(postFile);
	return 0;
}


int getPostsUser(char* email){
	struct POST post;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	while(fread(&post,sizeof(post),1,postFile)!=0){
		printf("%i",strcmp(email,post.email));
            if(strcmp(email,post.email)== 0){
				printf("email:\n%s\n",post.email);
				printf("%s\n",post.postContent);
				getch();
            }
	}	
	fclose(postFile);
	return 0;
}
int getPosts(){
	struct POST post;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	while(fread(&post,sizeof(post),1,postFile)!=0){
		printf("email:%s\n",post.email);
		printf("%s\n\n",post.postContent);
	}	
	getch();
	fclose(postFile);
	return 0;
}

