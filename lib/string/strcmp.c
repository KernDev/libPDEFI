#include <string.h>

int strcmp(const char *str1, const char *str2) {
	size_t size = strlen(str1);
	if (size > strlen(str2)) size = strlen(str2); 
	for (size_t i = 0; i <= size; i++)
		if (((unsigned char*) a)[i] < ((unsigned char*) b)[i])
			return -1;
		else if (((unsigned char*) b)[i] < ((unsigned char*) a)[i])
			return 1;

	return 0;
}
