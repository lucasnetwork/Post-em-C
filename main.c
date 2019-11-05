#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char email[6];
    int password,Login;
    printf("Ja possui login?\nSim(0)\nNao(1)");
    scanf("%i",&Login);
    switch (Login){
        case 0:
            printf("Digite o email:\n");
            scanf("%s",&email);
            printf("Digite a senha:\n");
            scanf("%i",&password);
            system("cls");
            if(login(password,email)==0){
                printf("passou");
            }else{
                printf("Email ou senha incorretos");
            }
            break;
        case 1:
            printf("Digite o email");
    }
    return 0;
}
