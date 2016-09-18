int us_al(int sayi, unsigned int us) {
    int i;    
    int sonuc = 1;

    if (us == 0) {
        return 1;
    } else {
        for (i = 1 ; i <= us ; i++) {
	     sonuc = sonuc * sayi;
        }
    }
    return sonuc;
}
