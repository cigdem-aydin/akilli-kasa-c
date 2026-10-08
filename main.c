#include <stdio.h>

int main() {
    float uruntutari, odenenpara, paraustu;
    int yuvarlamasiz_kurus, toplamkurus, kalan;

    int kagit200, kagit100, kagit50, kagit20, kagit10, kagit5;
    int tl1, madeni50, madeni25, madeni10, madeni5, madeni1;
    int toplamkupursayisi;

    // Kullanıcıdan ürün tutarı ve ödenen parayı alma
    printf("Urun tutarini giriniz (TL): ");
    scanf("%f", &uruntutari);

    printf("Odenen parayi giriniz (TL): ");
    scanf("%f", &odenenpara);

    // Para üstünü hesaplama
    paraustu = odenenpara - uruntutari;

    // Yuvarlama yapmadan kuruşa çevirme
    yuvarlamasiz_kurus = (int)(paraustu * 100.0f);

    // Doğru yuvarlama
    toplamkurus = (int)(paraustu * 100.0f + 0.5f);

    // Sonuçları gösterme
    printf("\n************************************\n");
    printf("Para Ustu: %.2f TL\n", paraustu);
    printf("Yuvarlamasiz Kurus: %d Kr\n", yuvarlamasiz_kurus);
    printf("Dogru Yuvarlanmis Kurus: %d Kr\n", toplamkurus);
    printf("************************************\n\n");

    // Küpür hesaplama
    kalan = toplamkurus;

    kagit200 = kalan / 20000;
    kalan = kalan % 20000;

    kagit100 = kalan / 10000;
    kalan = kalan % 10000;

    kagit50 = kalan / 5000;
    kalan = kalan % 5000;

    kagit20 = kalan / 2000;
    kalan = kalan % 2000;

    kagit10 = kalan / 1000;
    kalan = kalan % 1000;

    kagit5 = kalan / 500;
    kalan = kalan % 500;

    tl1 = kalan / 100;
    kalan = kalan % 100;

    madeni50 = kalan / 50;
    kalan = kalan % 50;

    madeni25 = kalan / 25;
    kalan = kalan % 25;

    madeni10 = kalan / 10;
    kalan = kalan % 10;

    madeni5 = kalan / 5;
    kalan = kalan % 5;

    madeni1 = kalan;

    // Toplam küpür sayısını hesaplama
    toplamkupursayisi = kagit200 + kagit100 + kagit50 + kagit20 + kagit10 + kagit5 + tl1 + madeni50 + madeni25 + madeni10 + madeni5 + madeni1;

    // Sonuçları ekrana yazdırma
    printf("VERILECEK BANKNOT VE MADENI PARALAR:\n");

    printf("200 TL : %d adet\n", kagit200);
    printf("100 TL : %d adet\n", kagit100);
    printf("50 TL  : %d adet\n", kagit50);
    printf("20 TL  : %d adet\n", kagit20);
    printf("10 TL  : %d adet\n", kagit10);
    printf("5 TL   : %d adet\n", kagit5);
    printf("1 TL   : %d adet\n", tl1);
    printf("50 Kr  : %d adet\n", madeni50);
    printf("25 Kr  : %d adet\n", madeni25);
    printf("10 Kr  : %d adet\n", madeni10);
    printf("5 Kr   : %d adet\n", madeni5);
    printf("1 Kr   : %d adet\n", madeni1);

    printf("************************************\n");
    printf("TOPLAM KUPUR SAYISI: %d adet\n", toplamkupursayisi);
 
    return 0;
}
