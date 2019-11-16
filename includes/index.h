#define SIZE 50
struct USER {
	char email[SIZE];
	char password[SIZE];
};

struct POST {
	int id;
	char email[SIZE];
	char postContent[1000];
};
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <locale.h>
#include <conio.h>
#include "validation.h"
#include "post.h"
#include "user.h"
