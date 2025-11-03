# 🧩 PushSwap — Yığın Tabanlı Sıralama Algoritması (42 Projesi)

<p align="center">
  <img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=30&pause=1000&color=00C2FF&center=true&vCenter=true&width=700&lines=🧩+PushSwap;Yığın+(stack)+tabanlı+sıralama;C+ile+Algoritma+Optimizasyonu;42+Projesi" alt="Typing SVG" />
</p>

---

<p align="center">
  <img src="https://img.shields.io/badge/Dil-C-blue?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Okul-42-green?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Proje-PushSwap-lightgrey?style=for-the-badge" />
  <img src="https://img.shields.io/badge/Durum-Tamamlanm%C4%B1%C5%9F-success?style=for-the-badge" />
</p>

---

## 🌐 Hakkında

**PushSwap** projesi, 42 okul müfredatında yer alan bir algoritma optimizasyon projesidir. Amaç, iki yığın (stack A ve stack B) ve sınırlı komut seti kullanarak verilen tamsayı dizisini mümkün olan en az komutla sıralamaktır.

Bu proje, **QuickSort** benzeri bir böl-ve-fethet (divide and conquer) yaklaşımıyla sıralama işlemini optimize eder. Diziyi küçük alt dizilere bölerek her alt diziyi uygun pivot seçimleriyle sıralar ve minimum komut sayısına ulaşmayı hedefler.

---

## 🧠 Öğrenilen Temel Konular

| Konu                               | Açıklama                                                                              |
| ---------------------------------- | ------------------------------------------------------------------------------------- |
| 🔁 **Yığın (Stack) Operasyonları** | `push`, `swap`, `rotate`, `reverse rotate` komutlarının kullanımı ve kombinasyonları. |
| ⚡ **QuickSort Yaklaşımı**          | Pivot temelli bölme stratejisi ile verimli sıralama.                                  |
| 🧠 **Algoritma Optimizasyonu**     | Komut sayısını azaltmak için pivot seçimi ve pozisyonlama stratejileri.               |
| 🧮 **Kompleksite Analizi**         | Ortalama durumda (O(n \log n)) hedefli sıralama yapısı.                               |

---

## ⚙️ Gereksinimler

* macOS veya Linux
* `gcc` veya `clang` derleyicisi
* Make

---

## 📦 Kurulum ve Derleme

```bash
# Depoyu klonlayın
git clone https://github.com/Celtenn/PushSwap.git
cd PushSwap/PushSwap

# Derleme
make
```

> Makefile standart 42 kurallarına uygun olarak `all`, `clean`, `fclean`, `re` hedeflerini içerir.

---

## ▶️ Kullanım

Program, komut satırından tamsayı argümanları alır.

```bash
# Örnek
./push_swap 3 2 5 1 4
```

Çıktı, her satırda bir komut olacak şekilde sıralama adımlarını yazdırır. Bu çıktıyı `checker` programı ile doğrulayabilirsiniz (projede varsa).

---

## ⌨️ Desteklenen Komutlar (Standart)

* `sa` — stack A üzerinde swap
* `sb` — stack B üzerinde swap
* `ss` — `sa` ve `sb` aynı anda
* `pa` — stack B'den stack A'ya push
* `pb` — stack A'dan stack B'ye push
* `ra` — stack A rotate (üst elemanı alta gönder)
* `rb` — stack B rotate
* `rr` — `ra` ve `rb` aynı anda
* `rra` — stack A reverse rotate (alt elemanı üste getir)
* `rrb` — stack B reverse rotate
* `rrr` — `rra` ve `rrb` aynı anda

---

## 🧭 Kullanılan Strateji: QuickSort Tabanlı Yaklaşım

1. **Girdi Doğrulama:** Tekrar eden veya sayısal olmayan girişlerin kontrolü.
2. **Normalizasyon:** Büyük sayıları indekslere dönüştürme (sıralamayı daha küçük aralıklarda çalıştırmak için).
3. **Pivot Seçimi:** Dizinin ortasındaki veya medyan değeri pivot olarak belirleme.
4. **Bölme:** Pivot’tan küçük değerleri stack B’ye gönderme, büyükleri A’da tutma.
5. **Özyineleme (Recursion):** Her iki alt kümede sıralamayı tekrarlama.
6. **Birleştirme:** Stack B’deki elemanları doğru sırayla `pa` komutlarıyla geri alma.

---

## 📈 Örnek Kod: QuickSort Uygulaması

```c
/* 42 norm kurallarına uygun örnek quicksort tabanlı sıralama */
void quicksort_a(t_stack *a, t_stack *b, int size)
{
    int pivot;
    int pushed;

    if (size <= 3)
    {
        sort_small(a, size);
        return;
    }
    pivot = get_pivot(a, size);
    pushed = push_lower_than_pivot(a, b, pivot, size);
    quicksort_a(a, b, size - pushed);
    quicksort_b(a, b, pushed);
    while (pushed-- > 0)
        pa(a, b);
}
```

---

## 🗂️ Proje Dizini (Örnek)

```
PushSwap/
├── includes/
│   └── push_swap.h
├── srcs/
│   ├── main.c
│   ├── parse_args.c
│   ├── quicksort_a.c
│   ├── quicksort_b.c
│   ├── operations.c
│   ├── utils.c
│   └── stack.c
├── Makefile
└── README.md
```

> Gerçek dizin yapısı depodaki yapıya göre değişebilir; burada tipik bir düzen örneklenmiştir.

---

## 🧪 Test ve Doğrulama

* Projenin çıktısını `./checker` ile doğrulayın (varsa). `checker` çıktıyı alır ve sonucu `OK` veya `KO` olarak döner.
* Farklı giriş büyüklükleriyle (küçük, orta, büyük) komut sayısını karşılaştırarak stratejinizi değerlendirin.

---

## 🧑‍💻 Yazar

**Celtenn** — GitHub: `https://github.com/Celtenn`

---

## 🧾 Lisans

Bu proje eğitim amaçlıdır. Lisans bilgisi repo sahibine aittir.

<p align="center">
  <img src="https://capsule-render.vercel.app/api?type=waving&color=00C2FF&height=80&section=footer&text=⭐%20Destekleyin%20ve%20%2F%2F%20Fork%20verin!%20⭐&fontSize=16&fontColor=ffffff" />
</p>
