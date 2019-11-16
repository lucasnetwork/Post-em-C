int postUserExists(char* email,int id){
    struct POST post;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	system("cls");
	while(fread(&post,sizeof(post),1,postFile)){
		if(strcmp(email,post.email)==0 && id == post.id){
			fclose(postFile);
            return 0;
		}
	}
	fclose(postFile);
	return 1;
}
int isNumber(int number){
    while(getchar()!='\n'){
        return 0;
    }
    return 1;
}
int userExist(char* email, char* password){
    FILE *usersFile;
    usersFile = fopen("users.txt","a+");
    struct USER user;
    while(fread(&user,sizeof(user),1,usersFile)!=0){
        if(strcmp(password,"")==0){
            if(strcmp(email,user.email)== 0){
                fclose(usersFile);
                return 0;
            }
        }else{
            if(strcmp(email,user.email)== 0 && strcmp(password,user.password) == 0){
                fclose(usersFile);
                return 0;
            }
        }
    }
    fclose(usersFile);
    
    return 2;
}
int checkPostId(char* email){
	int id;
	id = 0;
	struct POST post;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	while(fread(&post,sizeof(post),1,postFile)!=0){
            if(strcmp(email,post.email)== 0 && id == post.id){
                id++;
            }
	}	
	fclose(postFile);
	return id;
}