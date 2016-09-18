int mutlak_deger( int x ) {
	int y;
	if (x >= 0)
		y = x;
	else
		y = -1 * x;
	return y;
}
int main( ) {
	int sayi, sonuc;
	printf("sayi girin:");
	scanf("%d", &sayi);
	sonuc = mutlak_deger(sayi);
	printf("mutlak deger: %d\n", sonuc);
	return 0;
}
