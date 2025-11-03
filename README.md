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

Proje hem doğru çalışır olmayı hem de operasyon sayısını minimize etmeyi hedefler. Çözüm, diziyi küçük parçalara bölme, uygun rotasyonlar ve eleman aktarımları ile etkin bir şekilde sıralama stratejileri içerir.

---

## 🧠 Öğrenilen Temel Konular

| Konu                                  | Açıklama                                                                              |
| ------------------------------------- | ------------------------------------------------------------------------------------- |
| 🔁 **Yığın (Stack) Operasyonları**    | `push`, `swap`, `rotate`, `reverse rotate` komutlarının kullanımı ve kombinasyonları. |
| ✂️ **Parçalama & Bölme Stratejileri** | Diziyi kısmi alt dizilere bölme (chunking) ve her parçayı ayrı ayrı sıralama.         |
| 🧠 **Algoritma Optimizasyonu**        | Komut sayısını azaltmak için heuristikler ve durum bazlı kararlar.                    |
| 🧮 **Kompleksite Analizi**            | Operasyon sayısı ve performans değerlendirmesi.                                       |

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

## 🧭 Kullanılan Strateji (Özet)

1. **Girdi Doğrulama:** Tekrar eden veya sayısal olmayan girişlerin kontrolü.
2. **Normalizasyon:** Büyük sayıları indekslere dönüştürme (sıralamayı daha küçük aralıklarda çalıştırmak için).
3. **Böl ve Fethet (Chunking):** Listeyi uygun büyüklükte parçalara (chunk) bölme.
4. **Hedefe Taşıma:** Her chunk içindeki elemanları stack B'ye verimli rotasyonlarla gönderme.
5. **Geri Yerleştirme:** B'den A'ya en uygun sırayla `pa` komutları ile geri alma.
6. **Son Temizleme:** Küçük n için özel durumlar (3 veya 5 eleman için optimal kısa çözüm).

---

## 📈 Örnek Algoritma: 3 Eleman İçin Optimal Yaklaşım

```c
/* 42 "norm" kurallarına uygun, açıklayıcı ve kısa */
void sort_three(t_stack *a)
{
    if (is_sorted(a))
        return;
    if (a->top->value > a->top->next->value && a->top->value < a->bottom->value)
        sa(a);
    else if (a->top->value > a->top->next->value && a->top->next->value > a->bottom->value)
    {
        sa(a);
        rra(a);
    }
    else if (a->top->value > a->bottom->value && a->top->next->value < a->bottom->value)
        ra(a);
    else if (a->top->value < a->top->next->value && a->top->value > a->bottom->value)
        rra(a);
    else
    {
        sa(a);
        ra(a);
    }
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
│   ├── ops.c
│   ├── sort_small.c
│   ├── sort_chunks.c
│   └── utils.c
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
