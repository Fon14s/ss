### Deskripsi

Opang sedang terjabak dalam suatu Kotak Ajaib. Kotak ini merupakan kotak berdimensi - $n$, sebut saja Kotak Ajaib ini sebagai $Q_n$. Terdapat juga $2^{n - 1}$ tree yang identik di dekat opang dan masing-masing tree memiliki $n$ edges dan juga $n$ + 1 node yang dinomori 0, 1, ..., $n$. Supaya dapat keluar dari kotak ajaib tersebut, Opang harus meletakkan $n$ tree tersebut pada setiap titik sudut dari kotak ajaib tersebut. 

Secara formal, suatu Kotak Ajaib $Q_n$ dapat kita representasikan sebagai suatu graph dimana tiap node pada graph tersebut mewakili suatu titik sudut pada Kotak Ajaib tersebut dan nodenya dinomori 0, 1, 2, ...., $2^{n}$ - 1.  Dua node akan terhubung jika dan hanya jika bitwise $xor$ dari nomor mereka merupakan bilangan dua pangkat.

Suatu tree dapat diletakkan pada Kotak Ajaib selama memenuhi syarat berikut:

* Setiap node pada tree mewakili suatu node pada Kotak Ajaib
* Dua node berbeda pada tree yang sama tidak boleh mewakili satu node yang sama pada Kotak Ajaib
* Jika terdapat edge yang menghubungkan dua node pada tree, maka node pada Kotak Ajaib yang diwakili oleh kedua node tersebut juga harus terhubung pada Kotak Ajaib

Opang ingin meletakkan sebanyak mungkin tree sehingga setiap edge pada Kotak Ajaib hanya boleh digunakan oleh satu tree. Bantulah Opang keluar dari Kotak Ajaib.

### Batasan

* $1 \le n \le 16$
* $0 \le U_i, V_i \le n$
* $U_i \ne V_i$, untuk semua $1 \le i \le n$
* $(U_i, V_i) \ne (U_j, V_j)$, untuk semue $i \ne j$

### Format Masukan
Masukan diberikan dalam format berikut:
```
n
U_1 V_1
U_2 V_2
. .
. .
U_n V_n
```

### Keluaran
Pada baris pertama keluarkan bilangan $K$ yaitu banyaknya tree yang akan kamu letakkan pada Kotak Ajaib.

Setiap baris berikutnya dari baris 2 sampai baris $n$ + 1 mendeskripsikan bagaimana tree ke - $i$ diletakkan

Di baris ke - $i$ + 1 keluarkan $n$ + 1 bilangan $a_0, a_1, ..., a_n$. $a_j$ melambangkan bahwa node $j$ pada tree ke - $i$ mewakili node $a_j$ pada Kotak Ajaib.

### Contoh Masukan
```
3
0 1
0 2
0 3
```

### Contoh Keluaran
```
4
0 1 2 4
3 1 2 7
5 1 4 7
6 2 4 7
```

### Penilaiain

Tidak terdapat subsoal pada soal ini. Untuk suatu kasus uji, anda akan mendapatkan poin jika anda memenuhi semua syarat yang disebutkan pada soal. Poin akhir dari soal ini adalah poin minimum dari seluruh kasus uji, dibulatkan ke bilangan bulat terdekat.

Untuk suatu kasus uji, poin yang anda dapatkan akan berdasarkan K. Perhitungan poinnya akan sebagai berikut:

| Kondisi | Poin |
|---|---|
| $0 \le K < 2^{n - 1}$ | $70 \cdot \frac{K}{2^{n - 1}}$ |
| $K = 2^{n - 1}$ | 100 |
