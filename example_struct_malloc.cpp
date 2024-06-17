#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _hobby {
	char	name[20];
	double	spent;
} HOBBY;

typedef struct _person {
	char	name[20];
	int		age;
	HOBBY	*hobby;
} PERSON;

static PERSON	*individual = NULL;
PERSON *set_person();

PERSON	*set_person() {
    PERSON *tmp_person;
	if ((tmp_person = (PERSON *)malloc(sizeof(PERSON))) == NULL) {
		return(NULL);
	}
	memset(tmp_person, 0x00, sizeof(PERSON));
	if ((tmp_person->hobby = (HOBBY *)malloc(sizeof(HOBBY))) == NULL) {
		free(tmp_person);
		return(NULL);
	}
	memset(tmp_person->hobby, 0x00, sizeof(HOBBY));

	return(tmp_person);
}

int main(void) {
	if ((individual = set_person()) == NULL) {
		return (-1);
	}
	strcpy(individual->name, "kakehi");
	individual->age = 41;
	strcpy(individual->hobby->name, "kickboxing");
	individual->hobby->spent = 10000;

    printf("%s,%d,%s,%f\n",
			individual->name, individual->age,
			individual->hobby->name, individual->hobby->spent); 
	return 0;
}
