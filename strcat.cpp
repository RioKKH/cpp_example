#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define	PRMS "/home/kakehi/work/git/c_example/prms.dat"

typedef struct _test {
	double x;
	double y;
} TEST_s;

int main(int argc, char const* argv[])
{
	FILE *fp;
	char buff[512];
	char buff2[512];
	char val[512];

	TEST_s *testfp;
	testfp = (TEST_s *)malloc(sizeof(TEST_s));
	if (testfp == NULL) {
		printf("Erro in malloc\n");
		free(testfp);
		return 1;
	}

	if ((fp = fopen(PRMS, "r")) == NULL) {
		printf("Error in fopen\n");
		free(testfp);
		fclose(fp);
		return 1;
	}

	printf("%ld\n", sizeof(buff2)); 
	fgets(buff2, sizeof(buff2), fp);
	sscanf(buff, "%lf %lf", &testfp->x, &testfp->y);
	fclose(fp);
	strcpy(buff, "stpmoveX ");
	sprintf(val, "%lf", testfp->x); 
	strcat(buff, val);
	strcat(buff, " ");
	sprintf(val, "%lf", testfp->y); 
	strcat(buff, val);
	printf("%s\n", buff);

	// To use snprintf() is easier way to make string from variables.
	snprintf(buff2, sizeof(buff2), "%s %lf", "stpmoveX ", testfp->x);
	printf("%s\n", buff2);
	snprintf(buff2, sizeof(buff2), "%s %lf", "stpmoveY ", testfp->y);
	printf("%s\n", buff2);
	
	free(testfp);
	return 0;
}
