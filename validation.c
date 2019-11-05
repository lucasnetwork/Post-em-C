#include <string.h>

int login(int password,char* email){
    int user;
    for(user=0; user <= 10;user++){
        if(password == 123456 && strcmp(email,"lucas")==0){
            return 0;
        }else{
            return 1;
        }
    }
}
int postUserExists(char* email){
    if(strcmp(email,"lucas")==0){
        return "existe";
    }else{
        return "nao existe";
    }
}


int userExist(char* email){

}

int signUp(int password,char* email){
    userExist(email);
}
