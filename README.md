# soal-shift-sisop-modul-3-IT06-2021
Penyelesaian Soal Shift 3 Sistem Operasi 2021\
Kelompok IT06
* Alessandro Tionardo (05311940000018)
* Heaven Happyna P F (0531940000026)
* Zuhairaja M T (05311940000033)

---
## Daftar Isi
* [Soal 1](#soal-1)
  * [Soal 1.a.](#soal-1a)
  * [Soal 1.b.](#soal-1b)
  * [Soal 1.c.](#soal-1c)
  * [Soal 1.d.](#soal-1d)
  * [Soal 1.e.](#soal-1e)
  * [Soal 1.f.](#soal-1f)
  * [Soal 1.g.](#soal-1g)
  * [Soal 1.h.](#soal-1h)
* [Soal 2](#soal-2)
  * [Soal 2.a.](#soal-2a)
  * [Soal 2.b.](#soal-2b)
  * [Soal 2.c.](#soal-2c)
* [Soal 3](#soal-3)
  * [Soal 3.a.](#soal-3a)
  * [Soal 3.b.](#soal-3b)
  * [Soal 3.c.](#soal-3c)
  * [Soal 3.d.](#soal-3d)
  * [Soal 3.e.](#soal-3e)
---

## Soal 1
Keverk adalah orang yang cukup ambisius dan terkenal di angkatannya. Sebelum dia menjadi ketua departemen di HMTC, dia pernah mengerjakan suatu proyek dimana keverk tersebut meminta untuk membuat server database buku. Proyek ini diminta agar dapat digunakan oleh pemilik aplikasi dan diharapkan bantuannya dari pengguna aplikasi ini.\
Di dalam proyek itu, Keverk diminta: 
### Soal 1.a
Pada saat client tersambung dengan server, terdapat dua pilihan pertama, yaitu register dan login. Jika memilih register, client akan diminta input id dan passwordnya untuk dikirimkan ke server. User juga dapat melakukan login. Login berhasil jika id dan password yang dikirim dari aplikasi client sesuai dengan list akun yang ada didalam aplikasi server. Sistem ini juga dapat menerima multi-connections. Koneksi terhitung ketika aplikasi client tersambung dengan server. Jika terdapat 2 koneksi atau lebih maka harus menunggu sampai client pertama keluar untuk bisa melakukan login dan mengakses aplikasinya. Keverk menginginkan lokasi penyimpanan id dan password pada file bernama akun.txt dengan format :

akun.txt\
id:password\
id2:password2\

**Penyelesaian**

### Soal 1.b
Sistem memiliki sebuah database yang bernama files.tsv. Isi dari files.tsv ini adalah path file saat berada di server, publisher, dan tahun publikasi. Setiap penambahan dan penghapusan file pada folder file yang bernama  FILES pada server akan memengaruhi isi dari files.tsv. Folder FILES otomatis dibuat saat server dijalankan.\

**Penyelesaian**

### Soal 1.c
Tidak hanya itu, Keverk juga diminta membuat fitur agar client dapat menambah file baru ke dalam server. Direktori FILES memiliki struktur direktori di bawah ini :\
Direktori FILES\
File1.ekstensi\
File2.ekstensi\
Pertama client mengirimkan input ke server dengan struktur sebagai berikut :\
Contoh Command Client :\
add\

Output Client Console:\
Publisher:\
Tahun Publikasi:\
Filepath:\
Kemudian, dari aplikasi client akan dimasukan data buku tersebut (perlu diingat bahwa Filepath ini merupakan path file yang akan dikirim ke server). Lalu client nanti akan melakukan pengiriman file ke aplikasi server dengan menggunakan socket. Ketika file diterima di server, maka row dari files.tsv akan bertambah sesuai dengan data terbaru yang ditambahkan.\

**Penyelesaian**

### Soal 1.d
Dan client dapat mendownload file yang telah ada dalam folder FILES di server, sehingga sistem harus dapat mengirim file ke client. Server harus melihat dari files.tsv untuk melakukan pengecekan apakah file tersebut valid. Jika tidak valid, maka mengirimkan pesan error balik ke client. Jika berhasil, file akan dikirim dan akan diterima ke client di folder client tersebut.\

Contoh Command client\
download TEMPfile.pdf\

**Penyelesaian**

### Soal 1.e
Setelah itu, client juga dapat menghapus file yang tersimpan di server. Akan tetapi, Keverk takut file yang dibuang adalah file yang penting, maka file hanya akan diganti namanya menjadi ‘old-NamaFile.ekstensi’. Ketika file telah diubah namanya, maka row dari file tersebut di file.tsv akan terhapus.\
Contoh Command Client:\
delete TEMPfile.pdf\

**Penyelesaian**

### Soal 1.f
Client dapat melihat semua isi files.tsv dengan memanggil suatu perintah yang bernama see. Output dari perintah tersebut keluar dengan format.\
Contoh Command Client :\
see\
Contoh Format Output pada Client:\
Nama:\
Publisher:\
Tahun publishing:\
Ekstensi File : \
Filepath : \

Nama:\
Publisher:\
Tahun publishing:\
Ekstensi File : \
Filepath : \

**Penyelesaian**

### Soal 1.g
Aplikasi client juga dapat melakukan pencarian dengan memberikan suatu string. Hasilnya adalah semua nama file yang mengandung string tersebut. Format output seperti format output f.\

Contoh Client Command:\

find TEMP\

**Penyelesaian**

### Soal 1.h
Dikarenakan Keverk waspada dengan pertambahan dan penghapusan file di server, maka Keverk membuat suatu log untuk server yang bernama running.log. Contoh isi dari log ini adalah\

running.log\
Tambah : File1.ektensi (id:pass)\
Hapus : File2.ektensi (id:pass)\

**Penyelesaian**

### Screenshot
**Hasil Running Code**\

### Kendala

## Soal 2
Crypto (kamu) adalah teman Loba. Suatu pagi, Crypto melihat Loba yang sedang kewalahan mengerjakan tugas dari bosnya. Karena Crypto adalah orang yang sangat menyukai tantangan, dia ingin membantu Loba mengerjakan tugasnya. Detil dari tugas tersebut adalah:
### Soal 2.a
Membuat program perkalian matrix (4x3 dengan 3x6) dan menampilkan hasilnya. Matriks nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).\
**Penyelesaian**\

### Soal 2.b
Membuat program dengan menggunakan matriks output dari program sebelumnya (program soal2a.c) (Catatan!: gunakan shared memory). Kemudian matriks tersebut akan dilakukan perhitungan dengan matrix baru (input user) sebagai berikut contoh perhitungan untuk matriks yang ada. Perhitungannya adalah setiap cel yang berasal dari matriks A menjadi angka untuk faktorial, lalu cel dari matriks B menjadi batas maksimal faktorialnya (dari paling besar ke paling kecil) (Catatan!: gunakan thread untuk perhitungan di setiap cel).\
**Penyelesaian**\

### Soal 2.c
Karena takut lag dalam pengerjaannya membantu Loba, Crypto juga membuat program (soal2c.c) untuk mengecek 5 proses teratas apa saja yang memakan resource komputernya dengan command “ps aux | sort -nrk 3,3 | head -5” (Catatan!: Harus menggunakan IPC Pipes)\
**Penyelesaian**\

### Screenshot
**Hasil Running Code**

### Kendala

## Soal 3
Seorang mahasiswa bernama Alex sedang mengalami masa gabut. Di saat masa gabutnya, ia memikirkan untuk merapikan sejumlah file yang ada di laptopnya. Karena jumlah filenya terlalu banyak, Alex meminta saran ke Ayub. Ayub menyarankan untuk membuat sebuah program C agar file-file dapat dikategorikan. Program ini akan memindahkan file sesuai ekstensinya ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working directory ketika program kategori tersebut dijalankan.
### Soal 3.a
Program menerima opsi -f seperti contoh di atas, jadi pengguna bisa menambahkan argumen file yang bisa dikategorikan sebanyak yang diinginkan oleh pengguna.\
**Penyelesaian**\

### Soal 3.b
Program juga dapat menerima opsi -d untuk melakukan pengkategorian pada suatu directory. Namun pada opsi -d ini, user hanya bisa memasukkan input 1 directory saja, tidak seperti file yang bebas menginput file sebanyak mungkin.\
**Penyelesaian**\

### Soal 3.c
Selain menerima opsi-opsi di atas, program ini menerima opsi yang akan mengkategorikan seluruh file yang ada di working directory ketika menjalankan program C tersebut.\
**Penyelesaian**\

### Soal 3.d
Semua file harus berada di dalam folder, jika terdapat file yang tidak memiliki ekstensi, file disimpan dalam folder “Unknown”. Jika file hidden, masuk folder “Hidden”.\
**Penyelesaian**\

### Soal 3.e
Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan secara paralel sehingga proses kategori bisa berjalan lebih cepat.\
**Penyelesaian**\

### Screenshot
**Hasil Running Code**

### Kendala

