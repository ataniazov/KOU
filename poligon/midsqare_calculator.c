#include <stdio.h>
#include <math.h>

int main(){
	unsigned int uid = 1;	
	while(uid != 0){
	
		printf("Please enter UID: ");
		scanf("%d", &uid);
		unsigned int key = 0;
		key = ((pow(uid,2))/10000000);
		key %= 1000;
		printf("%d : %d\n",uid, key);
	}
	return 0;
}
