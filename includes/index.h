/*
	This file is used for to include libraries that will are used in the API
*/

/*
	Theses structs will are used for all the actions 
	of program
*/
#include <stdio.h>
#include <stdlib.h>

struct USER {
	char email[50];
	char password[16];
};
struct POST {
	int id;
	char email[50];
	char postContent[1000];
};
struct POST *posts;
struct USER *users;
    
int POSITION = 0;
int POSITION_POST = 0;
int SIZE_USER = 1;
int SIZE_POST = 10;

#include <string.h>
#include <stddef.h>
#include <locale.h>
#include <conio.h>
#include "constants.h"
#include "validation.h"
#include "post.h"
#include "user.h"