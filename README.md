# Celtenn'in 42 Proje Portföyü

### 👤 Enes Kahraman (Celtenn) | 42 Kocaeli

[![Dil](https://img.shields.io/badge/Dil-C-blue.svg)](https://c-for-dummies.com/)
[![Okul](https://img.shields.io/badge/Okul-42_Kocaeli-black.svg)](https://www.42kocaeli.com.tr)
[![GitHub](https://img.shields.io/badge/GitHub-Celtenn-lightgrey.svg)](https://github.com/Celtenn)

Merhaba! Ben Enes, 42 Kocaeli'de bir yazılım öğrencisiyim. Bu depo, 42 müfredatı boyunca C ve UNIX temelleri üzerine inşa ettiğim projelerin bir koleksiyonudur. Her bir proje, sistem programlamadan algoritmalara, eşzamanlılıktan grafik programlamaya kadar farklı bir konsepti derinlemesine öğretmeyi amaçlamaktadır.

---

## 🚀 Projelere Hızlı Bakış

Aşağıdaki tablo, bu portföyde yer alan projeleri ve odaklandıkları ana konuları özetlemektedir.

| Kategori | Proje | Kısa Açıklama |
| :--- | :--- | :--- |
| **Temeller** | [42-Havuz (Piscine)](#-42-havuz-piscine) | C ve UNIX temellerini öğreten Havuz egzersizleri (C00-C06). |
| **Temeller** | [libft](#-libft-kütüphanesi) | Standart C kütüphanesinin (libc) temel fonksiyonlarının yeniden yazımı. |
| **Algoritmalar** | [get_next_line](#-get_next_line) | Bir dosya tanımlayıcısından `static` değişken kullanarak satır satır okuma. |
| **Algoritmalar** | [push_swap](#-push_swap) | Yığınları en az hamleyle (Quicksort ile) sıralayan algoritma projesi. |
| **Sistem** | [Born2beroot](#-born2beroot) | Sanal makine üzerine güvenli bir Debian sunucusu kurma (SysAdmin). |
| **Sistem** | [Minitalk](#-minitalk) | İki süreç arasında UNIX sinyalleriyle (bit-bit) iletişim kurma. |
| **Sistem** | [Minishell](#-minishell) | `bash` benzeri bir UNIX kabuğunun sıfırdan yazılması. |
| **Eşzamanlılık** | [Philosophers](#-philosophers) | Thread/Mutex kullanarak "Yemek Yiyen Filozoflar" problemini çözme. |
| **Grafik** | [FDF (Fil de Fer)](#-fdf-fil-de-fer) | 3D arazi haritasını 2D'de (MiniLibX ile) tel kafes olarak çizme. |
| **Yardımcı** | [ft_printf](#-ft_printf) | C dilinin `printf` fonksiyonunun `stdarg.h` ile yeniden yazılması. |

---

## 📁 Proje Detayları

### 🌊 42-Havuz (Piscine)
* **Depo Linki:** [`Celtenn/42-Havuz/tree/main/42havuz`](https://github.com/Celtenn/42-Havuz/tree/main/42havuz)
* **Açıklama:** 4 haftalık yoğun "Havuz" (Piscine) eğitiminin ilk bölümünü oluşturan egzersiz koleksiyonudur. C dilinin temellerini (`C00`-`C06`), UNIX kabuk komutlarını (`Shell00`, `Shell01`) ve ilk grup projesini (`Rush00`) içerir.
* **Temel Konular:** Döngüler, pointer'lar, string manipülasyonu, özyineleme (recursion), program argümanları, `git` temelleri, `find`, `grep`.

### 📚 libft (Kütüphanesi)
* **Depo Linki:** [`Celtenn/libft`](https://github.com/Celtenn/libft)
* **Açıklama:** Standart C kütüphanesinin (libc) temel fonksiyonlarının (<code>ft_strlen</code>, <code>ft_split</code>, <code>ft_atoi</code> vb.) sıfırdan yeniden yazıldığı kişisel C kütüphanesi. 42'deki tüm C projelerinin temel taşıdır.
* **Temel Konular:** Pointer aritmetiği, bellek yönetimi (<code>malloc</code>), string manipülasyonu, bağlı listeler (<code>ft_lstnew</code>), `Makefile` oluşturma.

### 📜 get_next_line
* **Depo Linki:** [`Celtenn/get_next_line`](https://github.com/Celtenn/get_next_line)
* **Açıklama:** Bir dosya tanımlayıcısından (file descriptor) çağrıldığında bir sonraki satırı döndüren bir fonksiyon. Kilit noktası, bir sonraki çağrı için dosyanın nerede kaldığını hatırlamak amacıyla <code>static</code> bir değişken kullanmasıdır.
* **Temel Konular:** Statik değişkenler, dosya okuma (<code>read</code>), `BUFFER_SIZE` yönetimi, bellek yönetimi.

### 🖨️ ft_printf
* **Depo Linki:** [`Celtenn/Printf`](https://github.com/Celtenn/Printf)
* **Açıklama:** C dilinin standart <code>printf</code> fonksiyonunun yeniden implementasyonudur. Değişken sayıda argüman almayı (`...`) ve format belirteçlerini (<code>%c, %s, %p, %d, %i, %u, %x, %X, %%</code>) işlemeyi içerir.
* **Temel Konular:** Variadic fonksiyonlar (<code>stdarg.h</code>), <code>va_list</code>, <code>va_start</code>, <code>va_arg</code>, <code>va_end</code>, format ayrıştırma (parsing).

### 🖥️ Born2beroot
* **Depo Linki:** [`Celtenn/Born2beroot`](https://github.com/Celtenn/Born2beroot)
* **Açıklama:** Bir sanal makine (VirtualBox) üzerine sıfırdan, grafik arayüzü olmayan, güvenli bir Debian sunucusu kurma ve yapılandırma projesidir.
* **Temel Konular:** Sistem yönetimi (SysAdmin), <code>SSH</code> (port 4242), <code>UFW</code> (güvenlik duvarı), <code>sudo</code> yetkileri, güçlü parola politikaları, <code>cron</code> ile script otomasyonu.

### 🔄 push_swap
* **Depo Linki:** [`Celtenn/PushSwap/tree/main/ula`](https://github.com/Celtenn/PushSwap/tree/main/ula)
* **Açıklama:** A ve B adında iki yığını kullanarak A'daki sayıları en az hamleyle sıralamayı amaçlayan bir algoritma projesi. Bu implementasyon, "Böl ve Yönet" prensibine dayalı bir **Quicksort** algoritması kullanır.
* **Temel Konular:** Algoritma verimliliği, Quicksort, pivot seçimi (`ft_find_pivot.c`), yığın (stack) veri yapısı, bağlı listeler, <code>checker</code> programı.

### 📡 Minitalk
* **Depo Linki:** [`Celtenn/Minitalk`](https://github.com/Celtenn/Minitalk)
* **Açıklama:** İki program (istemci ve sunucu) arasında **sadece** UNIX sinyallerini (<code>SIGUSR1</code> ve <code>SIGUSR2</code>) kullanarak iletişim kurmayı amaçlayan bir projedir. İstemci, bir metni bit'lerine ayırır ve her bit'i bir sinyal olarak gönderir.
* **Temel Konular:** Süreçler arası iletişim (IPC), UNIX sinyalleri, <code>sigaction</code>, <code>kill</code>, <code>getpid</code>, bitwise operasyonlar, sinyal yönetimi.

### 📈 FDF (Fil de Fer)
* **Depo Linki:** [`Celtenn/FDF`](https://github.com/Celtenn/FDF)
* **Açıklama:** 42'nin ilk grafik projesi. <code>.fdf</code> uzantılı bir 3D arazi haritasını okur ve 42'nin kendi grafik kütüphanesi olan <code>MiniLibX</code>'i kullanarak bunu 2D ekranda "tel kafes" (wireframe) olarak çizer.
* **Temel Konular:** Grafik programlama, <code>MiniLibX</code>, 3D'den 2D'ye projeksiyon (İzometrik), Bresenham çizgi algoritması, optimize edilmiş görüntü arabelleği (<code>mlx_new_image</code>), klavye olayları (hooks).

### 🍽️ Philosophers
* **Depo Linki:** [`Celtenn/Philosophers`](https://github.com/Celtenn/Philosophers)
* **Açıklama:** Klasik "Yemek Yiyen Filozoflar" problemini simüle eden bir eşzamanlılık (concurrency) projesidir. Amaç, filozofların (thread'ler) çatalları (mutex'ler) kullanarak <code>deadlock</code> (kilitlenme) veya <code>starvation</code> (açlık) yaşamadan yemek yemesini sağlamaktır.
* **Temel Konular:** Eşzamanlılık, Thread'ler (<code>pthread</code>), Mutex'ler (<code>pthread_mutex_t</code>), Deadlock, Race Condition, zamanlama (<code>gettimeofday</code>).

### 🐚 Minishell
* **Depo Linki:** [`Celtenn/Minishell-`](https://github.com/Celtenn/Minishell-)
* **Açıklama:** <code>bash</code> benzeri bir UNIX kabuğunun sıfırdan C dilinde yazılması. Müfredatın en kapsamlı projelerinden biridir.
* **Temel Konular:** Süreç yönetimi (<code>fork</code>, <code>execve</code>, <code>waitpid</code>), `pipe` (boru hattı), I/O yönlendirmeleri (<code><</code>, <code>></code>, <code><<</code>, <code>>></code>), sinyal yönetimi (<code>Ctrl+C</code>), dahili komutlar (<code>cd</code>, <code>export</code>, <code>exit</code>), Lexer (Tokenization), Parser (Sözdizimi) ve Expander (<code>$VAR</code>).
