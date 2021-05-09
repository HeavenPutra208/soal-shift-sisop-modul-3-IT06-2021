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
```
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
#include <stdio.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>
```

Kemudian, dideklarasikan juga sebuah keyword `static void` yang di sini digunakan untuk menghindari konflik nama di sebuah OS linux yang tidak terkait.
```c
static void
```
Setelah itu, dibuat sebuah fungsi bernama `multiPipes` yang akan dapat menjalankan beberapa pipes sekaligus. Di sini, kami menyesuaikan jumlah pipes sejumlah `fd[2]`. Apabila command tidak sama dengan NULL, lalu pid sama dengan 0, juga command+1 tidak sama dengan NULL, maka akan diduplikasi menggunakan system call `dup2(fd[1], 1);`. Kemudian, `fd[0]` akan diclose dan dilakuakn execv pada parent menggunakan `execvp` sehingga child process tidak perlu merunning program yang sama seperti parentnya, kemudian exit dengan value 1. Jika pipes salah, maka dijalankan system call `perror` untuk fork dan exit 1. Selain keduanya, maka command line akan ditambahkan sebagai `fe` dengan mengambil value jadi `fd[0]`. 

```c
multiPipes(char ***command) //loop membuat pipes
{
	int fd[2];
    int fe = 0;				//backup
	pid_t pid;

	while (*command != NULL) {
		pipe(fd);				//membagi source pipes
		if (pid == 0) {    //jika pid 0
			dup2(fe, 0);
			if (*(command+1) != NULL) {

				dup2(fd[1], 1);

			}
			close(fd[0]);
			execvp((*command)[0], *command); //memasukkan
			exit(1);
		}
        
        if ((pid = fork()) == -1) { //jika pipes salah
			perror("fork");         //atau eror
			exit(1);                //exit status 1
		}

		else { //menambah cmd line
			wait(NULL); 		//mengambil child
			close(fd[1]);
			fe = fd[0];
			command++; //increment jumlah cmd line
		}
	}
}
```

Setelah itu, masuk ke dalam fungsi `main`, di sini dideklarasikan beberapa char pointer yang berisikan pipe/command yang akan dijalankan, yaitu `ps`, `sort`, dan `head`. Kemudian, ketiganya akan diproses dengan dimasukkan ke dalam double pointer char `cmd` yang selanjutnya akan dijadikan variabel pada fungsi `multiPipes` yang telah dibuat sebelumnya.

```c
int main(int argc, char *argv[])
{
	char *ps[] = {"ps", "aux", NULL}; //pipe s1
	char *sort[] = {"sort", "-nrk", "3,3", NULL}; //pipe s2
	char *head[] = {"head", "-5", NULL}; //pipe s3
	char **cmd[] = {ps, sort, head, NULL}; //binding cmd pipes

	multiPipes(cmd);//run cmd pakai fungsi multiPipes
	return (0);
}
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

### Soal 3.b
Program juga dapat menerima opsi -d untuk melakukan pengkategorian pada suatu directory. Namun pada opsi -d ini, user hanya bisa memasukkan input 1 directory saja, tidak seperti file yang bebas menginput file sebanyak mungkin.

**Penyelesaian**\

### Soal 3.c
Selain menerima opsi-opsi di atas, program ini menerima opsi yang akan mengkategorikan seluruh file yang ada di working directory ketika menjalankan program C tersebut.

**Penyelesaian**\

### Soal 3.d
Semua file harus berada di dalam folder, jika terdapat file yang tidak memiliki ekstensi, file disimpan dalam folder “Unknown”. Jika file hidden, masuk folder “Hidden”.

**Penyelesaian**\

### Soal 3.e
Setiap 1 file yang dikategorikan dioperasikan oleh 1 thread agar bisa berjalan secara paralel sehingga proses kategori bisa berjalan lebih cepat.

**Penyelesaian**\

### Screenshot
**Hasil Running Code**

### Kendala

