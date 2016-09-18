#include <stdio.h>

int access(const char pass[]);

int main() {

	int x=0;
	int i;
	char pass[9];

	for(i=0; i<3; i++) {

		printf("PLEASE ENTER PASSWORD: ");

		gets(pass);

		x = access(pass);

		if(x) {
			printf("\nACCESS ACCEPT\n");
			break;
		} else {
			printf("\nACCESS DENIED\n\n");
		}
	}

	return 0;

}

int access(const char pass[]) {

	int i;
	char mypass[9] = {'1','2','3','4','5','6','7','8','\0'};

	for(i=0; pass[i] != '\0'; i++) {
		if(pass[i] != mypass[i]) {
			return 0;
		}
		if(i == 7 &&  pass[i]==mypass[i]) {
			return 1;
		}
	}

	return 0;
}
