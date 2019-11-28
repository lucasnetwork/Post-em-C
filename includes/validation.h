int postUserExists(char* email,int id){
	system("cls");
    int i;
	for(i=0;i<POSITION_POST;i++){
		if(strcmp(email,posts[i].email)==0 && id == posts[i].id){
            return 0;
		}
	}
	return 1;
}
int userExist(char* email, char* password,struct USER *user){
    int i;
    for(i=0;i< sizeUser;i++){
        if(strcmp(password,"")==0){
            if(strcmp(email,user[i].email)== 0){
                return 0;
            }
        }else{
            if(strcmp(email,user[i].email)== 0 && strcmp(password,user[i].password) == 0){
                return 0;
            }
        }
    }
   
    return 2;
}
int checkPostId(char* email){
	int id,i;
	id = 0;
	struct POST post;
	for(i=0;i<=POSITION_POST;i++){
            if(strcmp(email,posts[i].email)== 0 && id == posts[i].id){
                id++;
            }
	}	
	return id;
}