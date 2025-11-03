<h1 align="center">🔄 Push Swap — Yığın Sıralama Algoritması</h1><p align="center"><img src="https://readme-typing-svg.herokuapp.com?font=Fira+Code&size=30&pause=1000&color=F78C6C&center=true&vCenter=true&width=600&lines=🔄+Push+Swap;Yığın+Sıralama+Algoritması;C+ile+Algoritmik+Çözüm;42+Kocaeli+Projesi" alt="Typing SVG" /></p><p align="center"><img src="https://img.shields.io/badge/Dil-C-blue?style=for-the-badge" /><img src="https://img.shields.io/badge/Okul-42_Kocaeli-green?style=for-the-badge" /><img src="https://img.shields.io/badge/Proje-PushSwap-lightgrey?style=for-the-badge" /><img src="https://img.shields.io/badge/Durum-Tamamlandı-success?style=for-the-badge" /></p>🌐 HakkındaPush Swap, 42 okulu müfredatının en zorlu algoritma projelerinden biridir.Projenin temel amacı, A adında bir yığında (stack) bulunan rastgele sıralanmış tamsayıları, B adında ikinci bir yardımcı yığın kullanarak ve izin verilen sınırlı komutlarla en az hamlede sıralamaktır.🧩 Temel hedef:İki yığın üzerinde en verimli sıralama stratejisini geliştirmek ve en optimize komut dizisini üretmektir.<p align="center"><img src="assets/push_swap.gif" width="600" alt="Push Swap Demo GIF"></p>🧠 Öğrenilen TemellerKonuAçıklama🥞 Yığın (Stack) Yönetimiİki yığın arasında (A ve B) veri aktarımı ve manipülasyonu.📊 Sıralama AlgoritmalarıBasit (3-5 eleman) ve karmaşık (Radix, Chunking) sıralama teknikleri.💡 Algoritma OptimizasyonuEn az hamle sayısına (instruction count) ulaşmak için strateji geliştirme.🔗 Bağlı Listeler (Linked Lists)Yığın yapısını verimli bir şekilde uygulamak için bağlı listelerin kullanılması.⚙️ Kurulum ve Çalıştırma🔧 GereşimlermacOS veya Linuxgcc veya clang derleyicisimake aracı📦 KurulumBashgit clone https://github.com/Celtenn/PushSwap.git
cd PushSwap/PushSwap
make
(Bonus checker programını da derlemek için make bonus komutunu kullanabilirsiniz.)▶️ Başlatmapush_swap programı, sıralanacak sayıları argüman olarak alır ve sıralama komutlarını standart çıktıya basar.Bash# Program komutları üretecektir:
./push_swap 4 1 3 2
sa
pb
...
✅ checker ile Doğrulama (Bonus)checker programı, push_swap tarafından üretilen komutların doğruluğunu test eder.Bash# Komutlar doğruysa "OK", yanlışsa "KO" çıktısı verir.
./push_swap 4 6 1 2 9 0 | ./checker 4 6 1 2 9 0
Çıktı: OK📜 Temel OperasyonlarAlgoritma, yığınları sıralamak için yalnızca bu 11 komutu kullanabilir:KomutAçıklamasaA yığınının en üstündeki iki elemanı değiştirir (swap a).sbB yığınının en üstündeki iki elemanı değiştirir (swap b).sssa ve sb komutlarını aynı anda yapar.paB yığınının en üstündeki elemanı A yığınının en üstüne iter (push a).pbA yığınının en üstündeki elemanı B yığınının en üstüne iter (push b).raA yığınının tüm elemanlarını 1 yukarı kaydırır (rotate a).rbB yığınının tüm elemanlarını 1 yukarı kaydırır (rotate b).rrra ve rb komutlarını aynı anda yapar.rraA yığınının tüm elemanlarını 1 aşağı kaydırır (reverse rotate a).rrbB yığınının tüm elemanlarını 1 aşağı kaydırır (reverse rotate b).rrrrra ve rrb komutlarını aynı anda yapar.🗂️ Proje DiziniPushSwap/
├── includes/
│   └── PushSwap.h
├── mandatory/
│   ├── ft_alg.c
│   ├── ft_atoi.c
│   ├── ft_free.c
│   ├── ft_stack.c
│   ├── main.c
│   └── ... (diğer kaynak dosyaları)
├── bonus/
│   ├── checker.c
│   ├── checker_utils.c
│   ├── get_next_line.c
│   └── ... (diğer bonus kaynak dosyaları)
├── Makefile
└── README.md
📈 Algoritmik YaklaşımBu projede verimli bir sıralama için "Chunking" (Parçalara Ayırma) yöntemi kullanılmıştır.Ön Sıralama: Gelen sayılar bir diziye kopyalanır ve sıralanır. Bu dizi, sayıların "olması gereken" indekslerini belirlemek için kullanılır.Basit Sıralama: Eğer 3 veya 5 gibi az sayıda eleman varsa, en az hamleyi gerektiren özel, hard-coded fonksiyonlar çalıştırılır.Parçalara Ayırma (Chunking):A yığınındaki sayılar, hedef indekslerine göre parçalara (chunk) ayrılır.İlk parça (en küçük sayılar) B yığınına en verimli şekilde (ra veya rra kullanarak) itilir.Bu işlem tüm parçalar için tekrarlanır.Geri İtme (Push Back):Tüm sayılar B yığınına aktarıldıktan sonra, B'deki en büyük sayı bulunur.En büyük sayı en üste gelene kadar B yığını rb veya rrb ile döndürülür.Sayı pa ile A yığınına itilir.Bu işlem B yığını boşalana kadar tekrarlanır ve A yığını sıralanmış olur.🧰 Makefile KomutlarıKomutAçıklamamakepush_swap programını derler (zorunlu kısım).make bonuschecker programını derler (bonus kısım).make cleanAra dosyaları (.o) temizler.make fcleanTüm derleme çıktılarını siler (push_swap ve checker dahil).make refclean yapar ve projeyi baştan derler.🧑‍💻 YazarEnes Kahraman📍 42 Kocaeli🔗 GitHub: Celtenn
