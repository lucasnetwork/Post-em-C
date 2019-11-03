#include <stdio.h>
#include <string.h>

int getPost(char* email){
    int a = strcmp(email,"lucas");
    char* existe = postUserExists(email);
    printf("%s",existe);
}
