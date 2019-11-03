#include <string.h>

int postUserExists(char* email){
    if(strcmp(email,"lucas")==0){
        return "existe";
    }else{
        return "nao existe";
    }
}
