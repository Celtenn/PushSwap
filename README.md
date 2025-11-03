# Push_swap Projesi
### 42 Okulu Projesi - Verimli Yığın Sıralama Algoritması

![Dil](https://img.shields.io/badge/Dil-C-blue.svg)
![Okul](https://img.shields.io/badge/Okul-42-black.svg)
![Proje](https://img.shields.io/badge/Proje-push_swap-lightgrey.svg)
![Algoritma](https://img.shields.io/badge/Algoritma-Quicksort-orange.svg)

---

## 🎯 Proje Hakkında

**Push_swap**, 42 müfredatının bir parçası olan, algoritmik düşünme ve veri yapısı optimizasyonu odaklı bir projedir.

**Amaç:** `A` ve `B` adında iki yığın (stack) ve sınırlı sayıda [operasyon](#%EF%B8%8F-izin-verilen-operasyonlar) kullanarak, `A` yığınına rastgele sırada verilen tamsayıları **en az hamleyle** sıralamaktır.

Bu depo iki program içerir:
1.  **`push_swap`**: Sıralanacak sayıları argüman olarak alır ve yığını sıralamak için gerekli olan operasyon listesini standart çıktıya (stdout) basar.
2.  **`checker` (Bonus)**: Sıralanacak sayıları ve operasyon listesini (standart girdiden) alır. Operasyonlar bittiğinde yığının sıralı olup olmadığını kontrol ederek `OK` veya `KO` yazar.

## 🧠 Kullanılan Algoritma: Quicksort (Böl ve Yönet)

Bu `push_swap` implementasyonu, popüler **Radix Sort** yaklaşımını *kullanmaz*. Bunun yerine, klasik **Quicksort** algoritmasının "Böl ve Yönet" (Divide and Conquer) prensibine dayalı bir strateji izler.

1.  **Pivot (Mihenk Taşı) Seçimi:**
    Sıralanacak yığından (veya yığının mevcut parçasından) bir "pivot" değeri seçilir. Verimlilik için bu genellikle medyan (ortanca) değerdir. (`ft_find_pivot.c`)

2.  **Bölümleme (Partitioning):**
    Yığın `A`'daki tüm elemanlar pivot ile karşılaştırılır:
    * Eğer eleman pivottan **küçükse**, `pb` (push B) operasyonu ile `B` yığınına atılır.
    * Eğer eleman pivottan **büyük veya eşitse**, `ra` (rotate A) operasyonu ile `A` yığınının en altına gönderilir.

3.  **Özyineleme (Recursion):**
    Bölümleme işlemi bittiğinde, problem iki küçük parçaya ayrılmış olur: `A` yığınında pivottan büyük olanlar ve `B` yığınında pivottan küçük olanlar. Algoritma, bu iki parça için özyineli olarak kendini tekrar çağırır.

4.  **Temel Durum (Base Case):**
    Parçanın boyutu 3 veya 5 gibi çok küçük bir sayıya indiğinde (`sort_three.c`, `sort_five.c`), özyineleme durdurulur ve bu küçük yığınlar önceden tanımlanmış en verimli hamlelerle (hard-coded) sıralanır.

Bu yöntem, yığını sürekli olarak daha küçük ve yönetilebilir parçalara ayırarak sıralamayı tamamlar.

## ⚙️ Kurulum ve Kullanım

### 1. Depoyu Klonlama
```bash
git clone [https://github.com/Celtenn/PushSwap.git](https://github.com/Celtenn/PushSwap.git)
cd PushSwap/ula
