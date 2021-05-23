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
id2:password2

**Penyelesaian**

### Soal 1.b
Sistem memiliki sebuah database yang bernama files.tsv. Isi dari files.tsv ini adalah path file saat berada di server, publisher, dan tahun publikasi. Setiap penambahan dan penghapusan file pada folder file yang bernama  FILES pada server akan memengaruhi isi dari files.tsv. Folder FILES otomatis dibuat saat server dijalankan.

**Penyelesaian**

### Soal 1.c
Tidak hanya itu, Keverk juga diminta membuat fitur agar client dapat menambah file baru ke dalam server. Direktori FILES memiliki struktur direktori di bawah ini :\
Direktori FILES\
File1.ekstensi\
File2.ekstensi\
Pertama client mengirimkan input ke server dengan struktur sebagai berikut :\
Contoh Command Client :\
add

Output Client Console:\
Publisher:\
Tahun Publikasi:\
Filepath:\
Kemudian, dari aplikasi client akan dimasukan data buku tersebut (perlu diingat bahwa Filepath ini merupakan path file yang akan dikirim ke server). Lalu client nanti akan melakukan pengiriman file ke aplikasi server dengan menggunakan socket. Ketika file diterima di server, maka row dari files.tsv akan bertambah sesuai dengan data terbaru yang ditambahkan.

**Penyelesaian**

### Soal 1.d
Dan client dapat mendownload file yang telah ada dalam folder FILES di server, sehingga sistem harus dapat mengirim file ke client. Server harus melihat dari files.tsv untuk melakukan pengecekan apakah file tersebut valid. Jika tidak valid, maka mengirimkan pesan error balik ke client. Jika berhasil, file akan dikirim dan akan diterima ke client di folder client tersebut.

Contoh Command client\
download TEMPfile.pdf

**Penyelesaian**

### Soal 1.e
Setelah itu, client juga dapat menghapus file yang tersimpan di server. Akan tetapi, Keverk takut file yang dibuang adalah file yang penting, maka file hanya akan diganti namanya menjadi ‘old-NamaFile.ekstensi’. Ketika file telah diubah namanya, maka row dari file tersebut di file.tsv akan terhapus.\
Contoh Command Client:\
delete TEMPfile.pdf

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
Filepath : 

Nama:\
Publisher:\
Tahun publishing:\
Ekstensi File : \
Filepath :

**Penyelesaian**

### Soal 1.g
Aplikasi client juga dapat melakukan pencarian dengan memberikan suatu string. Hasilnya adalah semua nama file yang mengandung string tersebut. Format output seperti format output f.

Contoh Client Command:

find TEMP

**Penyelesaian**

### Soal 1.h
Dikarenakan Keverk waspada dengan pertambahan dan penghapusan file di server, maka Keverk membuat suatu log untuk server yang bernama running.log. Contoh isi dari log ini adalah

running.log\
Tambah : File1.ektensi (id:pass)\
Hapus : File2.ektensi (id:pass)

**Penyelesaian**

### Screenshot
**Hasil Running Code**\

### Kendala

## Soal 2
Crypto (kamu) adalah teman Loba. Suatu pagi, Crypto melihat Loba yang sedang kewalahan mengerjakan tugas dari bosnya. Karena Crypto adalah orang yang sangat menyukai tantangan, dia ingin membantu Loba mengerjakan tugasnya. Detil dari tugas tersebut adalah:
### Soal 2.a
Membuat program perkalian matrix (4x3 dengan 3x6) dan menampilkan hasilnya. Matriks nantinya akan berisi angka 1-20 (tidak perlu dibuat filter angka).

**Penyelesaian**\
Pertama, kami menuliskan library yang diperlukan:
```c
#include <stdio.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
```
Kemudian, diinisialisasikan `matriks1` dan `matriks2` yang nantinya akan dikalikan kemudian dimasukkan dalam array 2 dimensil bernama `hasil`. Tidak lupa dideklarasikan sebuah pthread berbentuk array 2 dimensi bernama `tid[4][6]`, juga sebuah struct bernama `args` yang menyimpan variabel `i` dan `j`:
```c
int matriks1[4][3];
int matriks2[3][6];
int hasil[4][6];

pthread_t tid[4][6];

struct args {
  int i;
  int j;
};
```
Lalu, dibuat sebuah fungsi bernama `kaliMatriks` yang melakukan operasi perkalian matriks 1 dan matriks 2, yang sebelumnya variabel `i` dan `j` berada pada struct `args` kemudian dipointerkan:
```c
void * kaliMatriks(void* arg) {
    //untuk dijadikan thread
    int i = ((struct args*)arg)->i;
    int j = ((struct args*)arg)->j;

    for (int n = 0; n < 3; n++) { //looping
        hasil[i][j] = hasil[i][j] + matriks1[i][n] * matriks2[n][j]; //perkalian matriks sd. n=2
  }
}
```
Setelah itu, kita masuk pada fungsi `main`. Mula-mula, kita melakukan `scanf` input yang akan dimasukkan user untuk matriks 1 dan matriks 2:
```c
printf("masukkan matriks 4x3:\n");
       
    int i, j;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 3; j++) {
        scanf("%d", &matriks1[i][j]); //scan matriks1
      }
    }

    printf("masukkan matriks 3x6:\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
          scanf("%d", &matriks2[i][j]); //scan matriks2
        }
    }
```
Kemudian, hasil dari input fungsi matriks `kaliMatriks` dibuat thread sekaligus dilakukan join pada setiap indeks matriks:
```c
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
          struct args *index = (struct args *)malloc(sizeof(struct args)); //menyesuaikan ukuran index
          index->i = i;
          index->j = j;
          pthread_create(&tid[i][j], NULL, &kaliMatriks, (void *)index); //pthread_create
          pthread_join(tid[i][j], NULL);                                 //kemudian sekaligus join
        }
    }
```

Hasil output akan ditampilkan sebagai hasil menggunakan double looping dimentions:
```c
    printf("Matriks :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
          printf("%3d", hasil[i][j]);
        }
        printf("\n");
    }
```

Setelah itu, kami juga akan menggunakan matriks `hasil` untuk diletakkan pada shared memory yang nantinya digunakan untuk soal 2.b. Untuk ukuran matriks yang digunakan adalah ukuran matriks (4x6) dikali 4 bytes (int), menjadi 96. Setelah itu, dilakukan juga `memcpy` untuk menyalin ukuran memori dari area memori source ke tujuan area memori. nilai dari variabel `value` kemudian dilepaskan menggunakan `shmdt`.

```c
    //shared memory
    key_t key = 1230;
    int *value;

    int shmid = shmget(key, 96, IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

    int* z = (int*) value;

    memcpy(z, hasil, 96); //memcpy

    shmdt(value);
```
### Soal 2.b
Membuat program dengan menggunakan matriks output dari program sebelumnya (program soal2a.c) (Catatan!: gunakan shared memory). Kemudian matriks tersebut akan dilakukan perhitungan dengan matrix baru (input user) sebagai berikut contoh perhitungan untuk matriks yang ada. Perhitungannya adalah setiap cel yang berasal dari matriks A menjadi angka untuk faktorial, lalu cel dari matriks B menjadi batas maksimal faktorialnya (dari paling besar ke paling kecil) (Catatan!: gunakan thread untuk perhitungan di setiap cel).

**Penyelesaian**\
Pertama, kita menginputkan library yang diperlukan:
```c
#include <stdio.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
```
Kemudian, kita menginisialisasi matriks A dan matriks B yang akan dilakukan operasi faktorial sesuai ketentuan soal, yang nanti hasilnya masuk ke dalam array 2 dimensi `matriksHasil[4][6]`.
```c
//inisialiasi matriks
int matriksA[4][6]; //matriks A
int matriksB[4][6]; //matriks B
int matriksHasil[4][6]; //matriks hasilnya
```

Sama seperti pada soal 2.a, kami menginisialisasi sebuah struct yang berisi variabel `i` dan `j`:
```c
//inisialisasi struct i dan j
struct args {
  int i;
  int j;
};
```

Kemudian, kami membuat fungsi `faktorial` untuk memfaktorialkan sebuah nilai dari variabel yang ditransfer nantinya dari setiap indeks matriks A dan B.
```c
int faktorial(int n) { //fungsi untuk nge faktorial
    if (n>=1)
        return n*faktorial(n-1);
    else
        return 1;
}
```
Fungsi `faktorial` sebelumnya digunakan pada fungsi `func` di bawah ini, di mana setiap indeks dari matriks a dan b diperiksa menggunakan looping `for` untuk dilakukan  operasi faktorial, sesuai rumus yang diberikan pada soal:
```c
void *func() { //fungsi input fungsi faktorial
    for(int i=0; i < 4; i++) {
        for(int j=0; j < 6; j++) {
            int value = 0;

            if (matriksA[i][j] >= matriksB[i][j])
            {
                int a = matriksA[i][j];
                int b = matriksB[i][j];
                value = faktorial(a)/faktorial(a-b);
            }

            else if (matriksB[i][j] > matriksA[i][j]) {
                int a = matriksA[i][j];
                value = faktorial(a);
            }

            else if (matriksA[i][j] == 0 || matriksB[i][j] == 0) {
                value = 0;
            }
        
        matriksHasil[i][j] = value;
        }
    //pthread_exit(0);
    }
}
```
Setelah itu, masuk ke fungsi `main`, digunakan shared memory yang sebelumnya telah dimasukkan nilai sebuah matriks dan sekarang digunakan menjadi value dari matriks A:
```c

key_t key = 1230;
    int *value;
    int shmid = shmget(key, 96, IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

    int* z = (int *)value;
    memcpy(matriksA, z, 96); //membuat size z jadi array 2 dimensi

    shmdt(value);
    shmctl(shmid, IPC_RMID, NULL);

    printf("masukkan matriks B:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &matriksB[i][j]); 
        }
    }

```

Setelah itu, kita menginisalisasikan sebuah pthread `tid` untuk nantinya memproses fungsi `func`.
```c
    pthread_t tid[4][6];
```

Lalu, dengan looping, dibuat sebuah pthread (`pthread_create`) sekaligus dilakukan perintah `pthread_join` untuk menjalankan fungsi `func`:
```c    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
        //struct args* index = (struct args *)malloc(sizeof(struct args));
        struct args* index = (struct args *)malloc(sizeof(struct args));
        index->i = i;
        index->j = j;
        pthread_create(&tid[i][j], NULL, &func, (void *)index);
        }
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
        pthread_join(tid[i][j], NULL);
        }
    }
```

Sehingga, dilakukan printf untuk mencetak hasil output dari variabel `matriksHasil[i][j]`
```c
    printf("Matriks :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d\t", matriksHasil[i][j]);
        }
        printf("\n");
    }
}
```

### Soal 2.c
Karena takut lag dalam pengerjaannya membantu Loba, Crypto juga membuat program (soal2c.c) untuk mengecek 5 proses teratas apa saja yang memakan resource komputernya dengan command “ps aux | sort -nrk 3,3 | head -5” (Catatan!: Harus menggunakan IPC Pipes)

**Penyelesaian**\
Mula-mula, kami menginputkan library yang diperlukan:
```c
#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>
```

Kemudian, dideklarasikan array 'p[2]' dan 'p2[2]' yang akan digunakan nantinya sebagai pipes. Lalu dideklarasikan juga sebuah 'die(x)' yang melakukan 'fprintf' saat dipanggil dan ketika pipes error nantinya.

```c
int p[2];
int p2[2];

#define die(x) do {fprintf(stderr, "%s\n", x); exit(EXIT_FAILURE);} while (0);
```

Kemudian, masuk pada fungsi 'main()', yang akan dideklarasikan 'pipe(p)', kemudian jika pipe tersebut salah/error, maka akan dijalankan operasi 'die(" pipe ")'. Kemudian, dijalankan pipes nya sehingga melakukan command 'execlp("ps", "ps", "aux", NULL);':

```c
	pipe(p); // inisialisasi pipe p

	if(pipe(p) == -1) { // jika p salah
		die("pipe");
	}
	
	if (fork() == 0) // fork1
    {
        close(p[0]);
        dup2(p[1], 1);
        close(p[1]);
        execlp("ps", "ps", "aux", NULL); // cmd 1
    }
```

Sama seperti 'pipe(p)', dideklarasikan 'pipe(p2)', kemudian jika pipe tersebut salah/error, maka akan dijalankan operasi 'die(" pipe ")'. Kemudian, dijalankan pipes nya sehingga melakukan command 'execlp("sort", "sort", "-nrk", "3,3", NULL);':

```c
    pipe(p2); // inisialisasi pipe p2

	if(pipe(p2) == -1) { // jika p2 salah
		die("pipe");
	}

    if (fork() == 0) // fork2
    {
        close(p[1]);
        dup2(p[0], 0);
        close(p[0]);

        close(p2[0]);
        dup2(p2[1], 1);
        close(p2[1]);
        execlp("sort", "sort", "-nrk", "3,3", NULL); // cmd 2
    }
```

Setelah itu, 'p[0]' dan 'p[1]' akan diclose:
```c
    close(p[0]); // close pipe p[0]
    close(p[1]); // close pipe p[1]
```

Kemudian, dijalankan fork ketiga, yang akan menjalankan sebuah command line menggunakan 'execlp("head", "head", "-5", NULL);'
```c
    if (fork() == 0)
    {
        close(p2[1]);
        dup2(p2[0], 0);
        close(p2[0]);
        execlp("head", "head", "-5", NULL); // cmd 3
    }
```

Terakhir, 'p2[0]' dan 'p2[1]' diclose, dan akhirnya return:

```c
    close(p2[0]); // close pipe p2[0]
    close(p2[1]); // clode pipe p2[1]

	return(0);
```
### Screenshot
**Hasil Running Code**\
**Soal 2.a**
<br>
<img height="500" src="https://github.com/HeavenPutra208/soal-shift-sisop-modul-3-IT06-2021/blob/main/img/Soal2a.jpg" />
<br>
**Soal 2.b**
<br>
<img height="500" src="https://github.com/HeavenPutra208/soal-shift-sisop-modul-3-IT06-2021/blob/main/img/Soal2b.jpg" />
<br>
**Soal 2.c**
<br>
<img height="500" src="https://github.com/HeavenPutra208/soal-shift-sisop-modul-3-IT06-2021/blob/main/img/Soal2c.jpg" />
<br>
### Kendala
* Tidak ada

## Soal 3
Seorang mahasiswa bernama Alex sedang mengalami masa gabut. Di saat masa gabutnya, ia memikirkan untuk merapikan sejumlah file yang ada di laptopnya. Karena jumlah filenya terlalu banyak, Alex meminta saran ke Ayub. Ayub menyarankan untuk membuat sebuah program C agar file-file dapat dikategorikan. Program ini akan memindahkan file sesuai ekstensinya ke dalam folder sesuai ekstensinya yang folder hasilnya terdapat di working directory ketika program kategori tersebut dijalankan.
### Soal 3.a
Program menerima opsi -f seperti contoh di atas, jadi pengguna bisa menambahkan argumen file yang bisa dikategorikan sebanyak yang diinginkan oleh pengguna.

**Penyelesaian**\
Pertama, kami menuliskan library yang diperlukan:
```c
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<dirent.h>
#include<pthread.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
```
Selanjutnya kami membuat 3 fungsi yaitu `getNamaFile`, `getExtensionFile`, dan `CheckDir`.

**Fungsi *getNamaFile***\
Fungsi ini digunakan untuk mereturn nama file yang masih bersama dengan ekstensinya. Fungsi ini menggunakan dua parameter yaitu `NamaFile` sebagai pointer dan `Buffer` untuk menyimpan hasil dari fungsi ini. Fungsi ini menggunakan **strtok()** untuk memecah string dengan delimiter `/` dan akan disimpan di dalam `*token`. Dengan **while** loop, fungsi akan berjalan selama token belum habis dan nama file yang sudah diambil akan diprint ke dalam `buffer`. Fungsi **strtok()** akan dijalankan hingga akhir dari input.
```c
char *getNamaFile(char *NamaFile, char Buffer[]){
  char *token = strtok(NamaFile, "/");
  while(token != NULL){
    sprintf(Buffer, "%s", token);
    token = strtok(NULL, "/");
  }
}
```
**Fungsi *getExtensionFile***\
Fungsi ini digunakan untuk mendapatkan ekstensi dari sebuah file. Fungsi ini menggunakan dua parameter yaitu `NamaFile` sebagai pointer dan `Buffer` untuk menyimpan hasil dari fungsi ini. Selanjutnya fungsi ini akan melakukan hal yang sama dengan fungsi getNamaFile, yang nantinya akan menghasilkan nama file beserta dengan ekstensinya. Setelah mendapatkan nama file beserta dengan ekstensinya, fungsi ini akan menggunakan fungsi **strtok()** dengan delimiter `.`.
```c
char *getExtensionFile(char *NamaFile, char Buffer[]){
  char BufferNamaFile[1500];
  char *token = strtok(NamaFile, "/");
  while (token != NULL){
    sprintf(BufferNamaFile, "%s", token);
    token = strtok(NULL, "/");
  }
  int count = 0;
  if(BufferNamaFile[0]== '.'){
    strcpy(Buffer, "Hidden");
  }else{
    token = strtok(BufferNamaFile, ".");
    while(token != NULL){
        count++;
        sprintf(Buffer, "%s", token);
        token = strtok(NULL, ".");
    }
    if (count <= 1){
        strcpy(Buffer, "unknown");
    }
  }
  return Buffer;
}
```
**Fungsi *CheckDir***\
Fungsi ini digunakan untuk membuat direktori baru untuk masing-masing ekstensi yang didapatkan melalui fungsi getExtensionFile. Fungsi ini menggunakan satu parameter yaitu `Buffer`. Disini pembuatan direktori baru akan dilakukan jika ada sebuah error yang dihasilkan dari fungsi **opendir**, dengan **if** melakukan error handling. Fungsi ini akan membuat direktori baru dengan menggunakan fungsi **mkdir()** dengan nama pada parameter `Buffer` lalu akan ditutup direktorinya.

```c
void CheckDir(char Buffer[]){
  DIR *dr = opendir(Buffer);
  if (ENOENT == errno){
    mkdir(Buffer, 0775);
    closedir(dr);
  }
}
```
***Input***\
Selanjutnya, kami ada membuat sebuah fungsi `input` yang digunakan untuk setiap argumen. Pada `input` kami mendefiniskan lima buffer untuk menghandle ekstensi file, nama file, path input, tujuan path dan current working directory. Dimana buffer `cwd` akan langsung diisi dengan fungsi **getcwd()** yang mereturn current working directory beserta sizenya, dan juga buffer `BufferFrom` akan diisi dengan `(char *) arg`.
```c
void *input(void* arg){
  char BufferExt[100];
  char BufferNamaFile[1500];
  char BufferFrom[1500];
  char BufferTo[1500];
  char cwd[1500];
  getcwd(cwd, sizeof(cwd));
  strcpy(BufferFrom, (char *) arg);
```
Selanjutnya, fungsi `input` akan mengecek ekstensi dan bentuk dari file yang diinputkan oleh user pada argumen yang telah diinputkan user dengan menggunakan fungsi **access()** dengan source `BufferFrom` dan `F_OK`. Jika argumen yang diinputkan tidak sesuai, maka akan diprint error message dan akan dilakukan `pthread_exit(0)`. Dicek juga apakah file yang diinputkan merupakan sebuah direktori dengan menggunakan `if(dir)`, maka akan diprint error message dan dilakukan `pthread_exit(0)`. Jike berhasil, akan ditampilkan message bahwa file berhasil dikategorikan.
```c
 if (access(BufferFrom, F_OK) == -1){
    printf("File %s : Sad, gagal :(\n", BufferFrom);
    pthread_exit(0);
  }else{ 
    DIR* dir = opendir(BufferFrom);
    if(dir){
    printf("file %s : Sad, gagal\n", BufferFrom);
    pthread_exit(0);
  }else{
    printf("File %s : Berhasil Dikategorikan\n", BufferFrom);
  }
  closedir(dir);
  }
```
Selanjutnya akan digunakan fungsi **getNamaFile** yang dimana hasil dari fungsinya akan dimasukan pada buffer `BufferNameFile`. Setelah itu akan dilakukan juga fungsi **getExtensionFile** yang dimana akan menyimpan hasilnya pada buffer `BufferExt`, disini hasil dari fungsi getExtensionFile akan diubah menjadi lowercase dengan **for loop** yang memiliki fungsi **tolower**.
```c
  getNamaFile(BufferFrom, BufferNamaFile);
  strcpy(BufferFrom, (char *) arg);

  getExtensionFile(BufferFrom, BufferExt);
  for(int i = 0; i < sizeof(BufferExt); i++){
    BufferExt[i] = tolower(BufferExt[i]);
  }
  strcpy(BufferFrom, (char *) arg);
```
Selanjutnya akan digunakan fungsi `CheckDir` untuk membuat direktori baru pada setiap ekstensi didalam `BufferExt` yang belum memiliki direktori. Lalu buffer `BufferTo` akan diisi dengan value setiap buffer yang sudah ditetapkan sebelumnya dengan urutan `cwd`, `BufferExt`, dan `BufferNamaFile` dengan menggunakan fungsi **sprintf**. Kemudian file yang ada pada di `BufferFrom` akan di**rename()** dengan `BufferTo` untuk kita pindahkan filenya ke direktori yang sudah dibuat.
```c
 CheckDir(BufferExt);

  sprintf(BufferTo, "%s/%s/%s", cwd, BufferExt, BufferNamaFile);
  rename(BufferFrom, BufferTo);

  pthread_exit(0);
}
```

***main()***\
Disini main akan menggunakan dua parameter yaitu `argc` dan `*argv[]` untuk jumlah argumen dan pointer ke masing-masing argumen tersebut dikarenakan akan dibutuhkan beberapa pengecekan untuk argumen yang diinputkan. Pertama program akan melakukan pengecekan jumlah pada **if()** pertama, jika jumlah argumen hanya 1 maka akan diberikan error message. Lalu pada **if()** kedua, akan melakukan pengecekan karakter argumen yang diinputkan dengan fungsi **strcmp()** ke masing-masing argumen menggunakan `argv[1]` sebagai parameter pertama dan `-f`, `-d`, atau `\*` sebagai parameter kedua. Jika tidak sesuai, maka akan diprint error message.

```c
int main(int argc, char *argv[]) {
  if(argc == 1){
    printf("Input argument kurang\n");
    exit(1);
  }
  if(strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-d") && strcmp(argv[1], "*") != 0){
    printf("Input argument tidak ada(silahkan input [-f], [-d], atau [*]\n");
    exit(1);
  }
```
Selanjutnya ada fungsi **if()** untuk mengecek argumen `-f` dan nama-nama file yang akan dikategorikan. Jika argumen yang diinputkan kurang, maka akan diberikan error messsage. Jika argumen yang diberikan memenuhi syarat, maka akan dibuat array `tid` sebesar dengan jumlah argumen dikurang 2, lalu akan dilakukan **for loop** untuk membuat thread untuk masing-masing file yang telah diinputkan dengan tid masing-masing. Lalu thread akan dijalankan dengan `input` pada `(void*)argv[i]`, program juga akan men-join setiap `thread` yang sudah dibuat dengan **pthread_join**.
```c
  if(strcmp(argv[1], "-f") == 0){
    if(argc <= 2) {
      printf("Input argument salah\n");
      exit(1);
    }

    pthread_t tid[argc-2];
    for(int i = 2; i < argc; i++){
      pthread_create(&tid[i-2], NULL, &input, (void *)argv[i]);
    }
    for(int i = 2; i < argc; i++){
      pthread_join(tid[i-2], NULL);
    }
    exit(0);
  }
```

### Soal 3.b
Program juga dapat menerima opsi -d untuk melakukan pengkategorian pada suatu directory. Namun pada opsi -d ini, user hanya bisa memasukkan input 1 directory saja, tidak seperti file yang bebas menginput file sebanyak mungkin.

**Penyelesaian**\
Disini program akan mengecek banyak argumen jika yang diinputkan adalah `-d`. Apabila jumlah argumen kurang dari tiga, maka akan diberikan error message dan program akan ditutup. Jika berhasil, maka program akan membuka direktori sesuai dengan argumen kedua menggunakan fungsi **opendir()** dan memasukan nama direktori kedalam variabel dir. Tetapi jika direktori tidak bisa dibuka, maka akan diberikan error message.
```c
  if(strcmp(argv[1], "-d") == 0){
    if(argc != 3){
      printf("Input argument salah\n");
      exit(1);
    }
    DIR* dir = opendir(argv[2]);
    if(dir){
      direktori = argv[2];
    } else if(ENOENT == errno){
      printf("direktori tidak ada\n");
      exit(1);
    }
    closedir(dir);
  }
```
Selanjutnya, kami melakukan penjumlahan file untuk setiap file yang ada di dalam direktori. Pertama-tama direktori akan dibukan dengan fungsi **opendir()** dan di set ke variable `dir`, lalu dibuat sebuah struct `dirent` untuk menggunakan fungsi `readdir()`. Terdapat **while** untuk melakukan pengecekan setiap file di dalam `dir` yang dibuka dengan menggunakan `entry->d_type` dan `DT_REG`. Untuk setiap file reguler yang ditemukan maka nilai `jumlah_file` akan di increment sampai tiap file yang ada di direktori habis.
```c
  int jumlah_file = 0;
  DIR* dir = opendir(direktori);
  struct dirent *entri;
  while ((entri = readdir(dir)) != NULL){
    if(entri->d_type == DT_REG){
      jumlah_file++;
    }
  }
  closedir(dir);
```
Selanjutnya, kami mendefiniskan sebuah `Buffer` untuk menyimpan absolut path dan sebuah variabel untuk iterasi. Direktori akan dibuka dengan **opendir()** untuk pengecekan tiap file didalamnya. Disini `tid` kami tetapkan sebesar dengan jumlah file yang ada pada setiap direktori untuk thread yang akan dibuat. Lalu dengan `sprintf(Buffer[iter], "%s/%s", direktori, entri->d_name);` akan memasukan absolut path dari setiap file reguler itu sendiri. Kondisi ini akan berjalan terus sampai telah dilakukan pada semua file regular yang ada. Size dari variable `iter` akan di inkrement terus untuk setiap absolut path yang masuk kedalam buffer `Buffer[iter]`.
```c
  pthread_t tid[jumlah_file];
  char Buffer[jumlah_file][1500];
  int iter = 0;

  dir = opendir(direktori);
  while((entri = readdir(dir)) != NULL){
    if(entri->d_type == DT_REG){
      sprintf(Buffer[iter], "%s/%s", direktori, entri->d_name);
      iter++;
    }
  }
  closedir(dir);
```
Selanjutnya, pada **for()** loop akan berjalan sebanyak dengan jumlah file reguler yang telah dihitung. `*test` disini berfungsi untuk menyimpan absolut path dari setiap file sebelum thread dijalankan agar thread tidak langsung mengambil argumen keempatnya dari `Buffer`. Selanjutnya akan dibuat thread dengan `pthread()` dan **for()** loop kedua digunakan untuk men-join setiap thread yang sudah dibuat.
```c
  for(int i = 0; i < jumlah_file; i++){
    char  *test = (char*)Buffer[i];
    pthread_create(&tid[i], NULL, &input, (void *)test);
  }

  for(int i = 0; i < jumlah_file; i++){
    pthread_join(tid[i], NULL);
  }

```


### Soal 3.c
Selain menerima opsi-opsi di atas, program ini menerima opsi yang akan mengkategorikan seluruh file yang ada di working directory ketika menjalankan program C tersebut.

**Penyelesaian**\
Sama seperti di soal 3.b, tetapi bedanya pada input argumen `*` akan langsung menggunakan fungsi `getcwd` untuk mendapatkan current working direktori sebagai direktori yang akan digunakan pada fungsi 3.b.
```c
  char *direktori;
  if(strcmp(argv[1], "*") == 0){
    if(argc != 2){
      printf("Input argument salah\n");
      exit(1);
    }
    char Buffer[1500];
    getcwd(Buffer, sizeof(Buffer));
    direktori = Buffer;
  }
```

### Soal 3.d
Semua file harus berada di dalam folder, jika terdapat file yang tidak memiliki ekstensi, file disimpan dalam folder “Unknown”. Jika file hidden, masuk folder “Hidden”.

**Penyelesaian**\

Untuk soal 3.d, kami menambah beberapa fungsi **if()** pada fungsi `getExtensionFile`, dimana jika pada char `BufferNamaFile[0]` merupakan `.` maka akan langsung mereturn `Buffer` yang bernilai `Hidden`. Jika `count` saat perulangan **while()** kurang atau sama dengan 1 dikarenakan posisi `.` itu tidak ada atau ada tetapi pada awal maupun akhir kata maka akan mereturn `Buffer` yang bernilai `unknown`.

```c
  int count = 0;
  if(BufferNamaFile[0]== '.'){
    strcpy(Buffer, "Hidden");
  }else{
    token = strtok(BufferNamaFile, ".");
    while(token != NULL){
        count++;
        sprintf(Buffer, "%s", token);
        token = strtok(NULL, ".");
    }
    if (count <= 1){
        strcpy(Buffer, "unknown");
    }
  }
  return Buffer;
}
```

### Soal 3.e
Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan secara paralel sehingga proses kategori bisa berjalan lebih cepat.

**Penyelesaian**\
Sudah dijelaskan pada soal 3.a, 3.b, 3.c bahwa masing-masing file yang diproses akan menggunakan 1 thread. Pada perulangan **for()** pasti akan terdapat fungsi `pthread_create` untuk setiap file yang akan diproses.

### Screenshot
**Hasil Running Code**\
**Mode -f**
<br>
<img height="500" src="https://github.com/HeavenPutra208/soal-shift-sisop-modul-3-IT06-2021/blob/main/img/Screenshot (294).png" />
<br>

**Mode -d**
<br>
<img height="500" src="https://github.com/HeavenPutra208/soal-shift-sisop-modul-3-IT06-2021/blob/main/img/Screenshot (295).png" />
<br>

**Mode \***
<br>
<img height="500" src="https://github.com/HeavenPutra208/soal-shift-sisop-modul-3-IT06-2021/blob/main/img/Screenshot (296).png" />
<br>

### Kendala
* tidak ada
