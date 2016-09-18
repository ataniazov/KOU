#include <stdio.h>
#include <stdlib.h>

void time_format(unsigned int *ctry, unsigned int *yr, unsigned int *mth, unsigned int *wk, unsigned int *dy, unsigned int *hr, unsigned int *min, unsigned int *sec, unsigned int N) {

	unsigned int century,year,month,week,day,hour,minute,second;

	second = N%60;
	minute = (N/60)%60;
	hour = (N/3600)%24;
	day = (N/86400)%7;
	week = (N/604800)%4;
	month = (N/2592000)%12;
	year = (N/31536000)%100;
	century = (N/3153600000);

	*sec = second;
	*min = minute;
	*hr = hour;
	*dy = day;
	*wk = week;
	*mth = month;
	*yr = year;
	*ctry = century;

}

int main() {

	unsigned int N;
	unsigned int century,year,month,week,day,hour,minute,second;

	system("clear");

	printf("Sayi giriniz: ");

	scanf("%u",&N);	

	time_format(&century,&year,&month,&week,&day,&hour,&minute,&second,N);

	printf("%u century %u year %u month %u week %u day %u:%u:%u\n",century,year,month,week,day,hour,minute,second);

	return 0;
}
