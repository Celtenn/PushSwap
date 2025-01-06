Zorunlu Bölüm
Bellek sızıntıları
Hatırlatma: Savunma süresince, herhangi bir bölüm hatası veya programın beklenmedik, erken, kontrolsüz veya beklenmedik bir şekilde sonlandırılmasının olmaması gerektiğini unutmayın, aksi takdirde final notu 0 olur. Uygun bayrağı kullanın. Bu kural tüm savunma boyunca geçerlidir.

Savunma boyunca hafıza miktarına dikkat edin

push_swap tarafından kullanılır (örneğin top komutunu kullanarak)

herhangi bir anormalliği tespit etmek ve tahsis edilen belleğin doğru olduğundan emin olmak için

düzgün bir şekilde serbest bırakıldı. Bir bellek sızıntısı (veya daha fazlası) varsa, son

notu 0.



Evet

HAYIR
Hata yönetimi
Bu bölümde push_swap'ın hata yönetimini değerlendireceğiz. En az bir tanesi başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin.

Sayısal olmayan parametrelerle push_swap'ı çalıştırın. Program "Hata" görüntülemelidir.

push_swap'ı yinelenen bir sayısal parametreyle çalıştırın. Program "Hata" görüntülemelidir.

push_swap'ı yalnızca MAXINT'ten büyük bir parametre içeren sayısal parametrelerle çalıştırın. Program "Hata" görüntülemelidir.

push_swap'ı herhangi bir parametre olmadan çalıştırın. Program hiçbir şey görüntülememeli ve istemi geri vermelidir.



Evet

HAYIR
Push_swap - Kimlik testi
Bu bölümde, daha önceden sıralanmış bir liste verildiğinde push_swap'ın davranışını değerlendireceğiz. Aşağıdaki 3 testi yürütün. En az bir tanesi başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin.

Aşağıdaki komutu çalıştırın "$>./push_swap 42". Program hiçbir şey göstermemelidir (0 talimat).

Aşağıdaki komutu çalıştırın "$>./push_swap 2 3". Program hiçbir şey göstermemeli (0 talimat).

Aşağıdaki komutu çalıştırın "$>./push_swap 0 1 2 3". Program hiçbir şey göstermemelidir (0 talimat).

Aşağıdaki komutu çalıştırın "$>./push_swap 0 1 2 3 4 5 6 7 8 9". Program hiçbir şey görüntülememelidir (0 talimat).

Aşağıdaki komutu çalıştırın "$>./push_swap '0 ile 9 arasında rastgele sıralanmış değerler seçildi>'. Program hiçbir şey göstermemelidir (0 talimat).



Evet

HAYIR
Push_swap - Basit versiyon
Aşağıdaki testler başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin. Eklerde verilen denetleyici ikilisini kullanın.

"$>ARG="2 1 0"; ./push_swap $ARG | ./checker_OS $ARG" komutunu çalıştırın.

Kontrol programının "OK" gösterdiğini ve push_swap'tan gelen talimat listesinin boyutunun 2 VEYA 3 olduğunu kontrol edin. Aksi takdirde test başarısız olur.

"$>ARG="'0 ile 3 arasında rastgele değerler seçildi'"; ./push_swap $ARG | ./checker_OS $ARG" çalıştırın. Denetleme programının "OK" gösterdiğini ve push_swap'tan gelen talimat listesinin boyutunun 0 İLE 3 arasında olduğunu kontrol edin. Aksi takdirde test başarısız olur.



Evet

HAYIR
Başka bir basit versiyon
Aşağıdaki 2 testi gerçekleştirin. En az bir tanesi başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin. Eklerde verilen denetleyici ikilisini kullanın.

"$>ARG="1 5 2 4 3"; ./push_swap $ARG | ./checker_OS $ARG" komutunu çalıştırın.

Kontrol programının "OK" gösterdiğini ve push_swap'tan gelen talimat listesinin boyutunun 12'den fazla olmadığını kontrol edin. Talimat listesinin boyutu 8 ise tebrikler.

"$>ARG="<5 random values>"; ./push_swap $ARG | ./checker_OS $ARG" komutunu çalıştırın ve yer tutucuyu 5 geçerli rastgele değerle değiştirin.

Kontrol programının "OK" gösterdiğini ve push_swap'tan gelen talimat listesinin boyutunun 12'den fazla olmadığını kontrol edin. Aksi takdirde bu test başarısız olur. Programın yalnızca bu ölçeğe dahil edilen testte doğru cevap vermek için geliştirilmediğini özellikle kontrol etmeniz gerekir. Doğrulamadan önce bu testi birkaç değişiklikle birkaç kez tekrarlamalısınız.



Evet

HAYIR
Push_swap - Orta sürüm
Aşağıdaki test başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin. Bir sonrakine geçin. Eklerde verilen denetleyici ikilisini kullanın.

"$>ARG="<100 random values>"; ./push_swap $ARG | ./checker_OS $ARG" çalıştırın ve yer tutucuyu 100 random geçerli değerle değiştirin. Denetleme programının "OK" gösterdiğini ve talimat listesinin boyutunu kontrol edin. Aşağıdakilere göre puan verin:

700'den az: 5

900'den az: 4

1100'den az: 3

1300'den az: 2

1500'den az: 1

Programın yalnızca bu ölçeğe dahil edilen testte doğru cevap vermek için geliştirilmediğini özellikle kontrol etmeniz gerekecektir. Doğrulamadan önce bu testi birkaç değişiklikle birkaç kez tekrarlamalısınız.


0 (başarısız) ile 5 (mükemmel) arasında puan verin


0
1
2
3
4
5
Push_swap - Gelişmiş sürüm
Aşağıdaki test başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin. Bir sonrakine geçin. Eklerde verilen denetleyici ikilisini kullanın.

"$>ARG="<500 random values>"; ./push_swap $ARG | ./checker_OS $ARG" çalıştırın ve yer tutucuyu 500 rastgele geçerli değerle değiştirin (Biri boşuna John/Jane Script olarak adlandırılmaz). Denetleme programının "OK" gösterdiğini ve talimat listesinin boyutunun

5500'den az: 5

7000'den az: 4

8500'den az: 3

10000'den az: 2

11500'den az: 1

Programın yalnızca bu ölçeğe dahil edilen testte doğru cevap vermek için geliştirilmediğini özellikle kontrol etmeniz gerekecektir. Doğrulamadan önce bu testi birkaç değişiklikle birkaç kez tekrarlamalısınız.


0 (başarısız) ile 5 (mükemmel) arasında puan verin


0
1
2
3
4
5
Bonus Bölüm
Kontrol programı - Hata yönetimi
Bu bölümde, denetleyicinin hata yönetimini değerlendireceğiz. En az bir tanesi başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin.

Sayısal olmayan parametrelerle denetleyiciyi çalıştırın. Program "Hata" görüntülemelidir.

Denetleyiciyi yinelenen bir sayısal parametreyle çalıştırın. Program "Hata" görüntülemelidir.

Denetleyiciyi yalnızca MAXINT'ten büyük bir tane de dahil olmak üzere sayısal parametrelerle çalıştırın. Program "Hata" görüntülemelidir.

Denetleyiciyi herhangi bir parametre olmadan çalıştırın. Program hiçbir şey görüntülememeli ve istemi geri vermelidir.

Denetleyiciyi geçerli parametrelerle çalıştırın ve talimat aşamasında var olmayan bir eylem yazın. Program "Hata" görüntülemelidir.

Denetleyiciyi geçerli parametrelerle çalıştırın ve talimat aşaması sırasında eylemden önce ve/veya sonra bir veya birkaç boşlukla bir eylem yazın. Program "Hata" görüntülemelidir.



Evet

HAYIR
Kontrol programı - Yanlış testler
Bu bölümde, denetleyicinin listeyi sıralamayan bir talimat listesini yönetme yeteneğini değerlendireceğiz. Aşağıdaki 2 testi yürütün. En az bir tanesi başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin. Talimat aşaması sırasında okumayı durdurmak için CTRL+D tuşlarına basmayı unutmayın.

Aşağıdaki komutla denetleyiciyi çalıştırın "$>./checker 0 9 1 8 2 7 3 6 4 5" ve ardından geçerli eylem listesini yazın "[sa, pb, rrr]". Denetleyici "KO" görüntülemelidir.

Kontrolcüyü istediğiniz parametre olarak geçerli bir listeyle çalıştırın ve ardından tam sayıları sıralamayan geçerli bir talimat listesi yazın. Kontrolcü "KO" görüntülemelidir. Programın yalnızca bu ölçeğe dahil edilen testte doğru cevap vermek için geliştirilmediğini özellikle kontrol etmeniz gerekecektir. Doğrulamadan önce bu testi birkaç permütasyonla birkaç kez tekrarlamalısınız.



Evet

HAYIR
Kontrol programı - Doğru testler
Bu bölümde, denetleyicinin listeyi sıralayan bir talimat listesini yönetme yeteneğini değerlendireceğiz. Aşağıdaki 2 testi yürütün. En az bir tanesi başarısız olursa, bu bölüm için puan verilmeyecektir. Bir sonrakine geçin. Talimat aşaması sırasında okumayı durdurmak için CTRL+D'ye basmayı unutmayın.

Aşağıdaki komutla denetleyiciyi çalıştırın "$>./checker 0 1 2" sonra herhangi bir talimat yazmadan CTRL+D'ye basın. Program "OK" göstermelidir.

Aşağıdaki komutla denetleyiciyi çalıştırın "$>./checker 0 9 1 8 2" sonra aşağıdaki geçerli eylem listesini yazın "[pb, ra, pb, ra, sa, ra, pa, pa]". Program "OK" görüntülemelidir.

Kontrol cihazını istediğiniz parametre olarak geçerli bir listeyle çalıştırın, ardından tam sayıları sıralayan geçerli bir talimat listesi yazın. Kontrol cihazı "OK" göstermelidir. Programın yalnızca bu ölçeğe dahil edilen testte doğru cevap vermek için geliştirilmediğini özellikle kontrol etmeniz gerekecektir. Doğrulamadan önce bu testi birkaç permütasyonla birkaç kez tekrarlamalısınız.



Evet

HAYIR
