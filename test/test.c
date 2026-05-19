#include <stdio.h>

typedef enum {
	FEMALE,
	MALE
} GENDER;

int gMaleCount = 0;
int gFemaleCount = 0;

char *  WelcomeMessageForMale()
{
	return "Welcome Message For Male\n";
}

char *  WelcomeMessageForFemale()
{
	return "Welcome Message For Female\n";
}

char * WelcomeMessage( GENDER s) {
	char * mesg;

	// GENDER is an enum of MALE and FEMALE
	if  ( s == MALE ) {
		mesg = WelcomeMessageForMale();
	} else {
		mesg = WelcomeMessageForFemale();
	}

	return mesg;
}

void CountLogin( GENDER s ) {
	if ( s == MALE ) {
		gMaleCount ++;
	} else {
		gFemaleCount ++;
	}
}

int main()
{
	GENDER g = FEMALE;

	printf("%s",WelcomeMessage(g));

	return 0;
}
