# akilli-kasa-c (Smart Cash Register)

Bu proje, bir mağazadaki kasiyerin girdiği **ürün tutarı** ve **alınan ödemeye** göre verilecek para üstünü hesaplayan ve bu para üstünü **en az sayıda banknot ve madeni para** ile veren bir C programıdır.

Proje; kontrol ve döngü yapıları (`if`, `else`, `for`, `while`) kullanılmadan, yalnızca temel veri tipleri, aritmetik işlemler ve mod (`%`) operatörü kullanılarak geliştirilmiştir.

---

## 📌 Proje Şartları ve Kuralları

1. **Ondalıklı Sayı Kullanımı:** Ürün tutarı ve ödenen para `float` değişkenler üzerinde tutulur.
2. **Tam Sayı Küpür Hesabı:** Küpür hesaplamaları veri kaybı ve sapmaları önlemek adına kuruş cinsinden `int` veri tipiyle yapılır.
3. **Kısıtlamalar:** Kod içerisinde hiçbir koşul (`if/else`) veya döngü (`for/while`) yapısı kullanılmamıştır.
4. **Çıktı:** Verilecek banknot ve madeni para adetlerinin yanı sıra **toplam küpür sayısı** da hesaplanıp ekrana yazdırılır.

---

## 🔬 Floating-Point (Ondalıklı Sayı) Hassasiyeti Raporu

### Problem Analizi (18.70 TL Tutar - 20.00 TL Ödeme)
Örnek olarak ürün tutarı `18.70 TL`, ödenen para `20.00 TL` girildiğinde doğru para üstü **`1.30 TL` (130 Kuruş)** olmalıdır. 

Ancak programda `paraustu = 20.00f - 18.70f;` işlemi yapıldığında:
* Bilgisayar hafızasında `float` türündeki sayılar ikili (binary) kayan noktalı sayı sisteminde saklandığından `18.70` sayısı ikili tabanda tam ifade edilemez ve küçük bir hassasiyet kaybı oluşur.
* `paraustu` değeri hafızada tam olarak `1.30` değil, yaklaşık **`1.299999`** olarak tutulur.
* **Yuvarlamasız Dönüşüm:** `(int)(paraustu * 100.0f)` işlemi yapıldığında ondalık kısım doğrudan atılır (`truncation`) ve sonuç **129 Kr** çıkar (1 kuruş eksik hesaplanır).

### Çözüm (Doğru Yuvarlama Yöntemi)
Ondalıklı sayı sapmasını engellemek için **Round Half Up** (`+ 0.5f`) yuvarlama yöntemi uygulanmıştır:
```c
toplamkurus = (int)(paraustu * 100.0f + 0.5f);
