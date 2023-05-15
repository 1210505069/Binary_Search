#include <stdio.h>
#include <stdlib.h>

int binarySearch(int dizi[], int sol, int sag, int aranan) {
    if (sag >= sol) {
        int orta = sol + (sag - sol) / 2;

        // Eger aranan eleman ortadaki elemana esitse, ortadaki elemanin indeksini dondurur.
        if (dizi[orta] == aranan)
            return orta;

        // Eðer aranan eleman ortadaki elemandan kucukse, sol yarida arama yapar.
        if (dizi[orta] > aranan)
            return binarySearch(dizi, sol, orta - 1, aranan);

        // Eðer aranan eleman ortadaki elemandan buyukse, sag yarida arama yapar.
        return binarySearch(dizi, orta + 1, sag, aranan);
    }

    // Aranan eleman dizide yok.
    return -1;
}

int main(int argc, char *argv[]) {
	int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
	//diziyi tanimliyoruz.
    int dizi_boyutu = sizeof(dizi) / sizeof(dizi[0]);
    //dizi ile alakali islemlerde kullanacagiz.
    int indeksler[dizi_boyutu];
	 // yeni dizi
    for (int i = 0; i < dizi_boyutu; i++) {
        indeksler[i] = i;
    }

    // bubble sort ile dizi siralama
    for (int i = 0; i < dizi_boyutu - 1; i++) {
        for (int j = 0; j < dizi_boyutu - i - 1; j++) {
            if (dizi[j] > dizi[j + 1]) {
                // swap islemini yapiyoruz
                int gecici = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = gecici;
                // index swap islemini yapiyoruz
                gecici = indeksler[j];
                indeksler[j] = indeksler[j + 1];
                indeksler[j + 1] = gecici;
            }
        }
    }

    int aranan_sayi;
    //tanimlama yapiyoruz.
    printf("Aramak istediginiz sayiyi giriniz: ");
    scanf("%d", &aranan_sayi);
    //kullanicidan eleman istiyoruz.
    int sonuc = binarySearch(dizi, 0, dizi_boyutu - 1, aranan_sayi);
    //fonksiyonu cagiriyoruz.
    if (sonuc == -1) {
        printf("Sayi dizide yok.\n");
    }
    else {
        printf("Sayi dizinin %d. elemani.\n", indeksler[sonuc]+1);
    }
    //sonuca gore cikti aliyoruz.
	return 0;
}
