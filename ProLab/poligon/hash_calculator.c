#include <stdio.h>

int main(){
	unsigned int uid = 1;	
	while(uid != 0){
	
		printf("Please enter UID: ");
		scanf("%d", &uid);
		printf("%d : %d\n",uid, uid%709);
	}
	return 0;
}
