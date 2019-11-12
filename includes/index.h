#define SIZE 50
struct USER {
	char email[SIZE];
	char password[SIZE];
};

struct POST {
	char email[SIZE];
	char password[SIZE];
	char postContent[1000];
};
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <locale.h>
#include "post.h"
#include "validation.h"
#include "user.h"
