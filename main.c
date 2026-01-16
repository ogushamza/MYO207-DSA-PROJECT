#include <stdio.h>
// AD SOYAD:HAMZA OĞUS
// ÖĞRENCİ NO:2420171030
// SERTİFİKA LİNKİ:https://www.btkakademi.gov.tr/portal/certificate/validate?certificateId=kK1hb7mL81
//Sertifika No:kK1hb7mL81

void sirala(int dizi[], int n) {
    int i, j, enKucukIndis, gecici;
    for (i = 0; i < n - 1; i++) {
        enKucukIndis = i;
        for (j = i + 1; j < n; j++) {
            if (dizi[j] < dizi[enKucukIndis]) {
                enKucukIndis = j;
            }
        }
     
        gecici = dizi[enKucukIndis];
        dizi[enKucukIndis] = dizi[i];
        dizi[i] = gecici;
    }
}


int ikiliArama(int dizi[], int sol, int sag, int aranan) {
    while (sol <= sag) {
        int orta = sol + (sag - sol) / 2;

        if (dizi[orta] == aranan)
            return orta; 

        if (dizi[orta] < aranan)
            sol = orta + 1;
        else
            sag = orta - 1;
    }
    return -1; 
}

int main() {
    int dizi[] = {42, 17, 89, 5, 23, 11, 67}; 
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int aranan, sonuc;

    
    sirala(dizi, n);

    printf("Dizi basariyla siralandi.\n");
    printf("Aranacak sayiyi giriniz: ");
    scanf("%d", &aranan);

    sonuc = ikiliArama(dizi, 0, n - 1, aranan);

    if (sonuc != -1) {
        printf("Sayı bulundu! Dizinin %d. indisinde yer aliyor.\n", sonuc);
    } else {
        printf("Aranan sayi listede bulunamadi.\n");
    }

    return 0;

}

