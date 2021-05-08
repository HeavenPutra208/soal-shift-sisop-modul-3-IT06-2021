#include <stdio.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>

//inisialisasi matriks 1 2 hasil dan size array nya
int matriks1[4][3];
int matriks2[3][6];
int hasil[4][6];

//inisialisasi array thread
pthread_t tid[4][6];

//inisialisasi struct i dan j
struct args {
  int i;
  int j;
};

//fungsi perkalian matriks A dan B
void *kaliMatriks(void* arg) {
    //untuk dijadikan thread
    int i = ((struct args*)arg)->i;
    int j = ((struct args*)arg)->j;

    for (int n = 0; n < 3; n++) { //looping
        hasil[i][j] = hasil[i][j] + matriks1[i][n] * matriks2[n][j]; //perkalian matriks sd. n=2
  }
}

//fungsi main
int main() {

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

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
          struct args *index = (struct args *)malloc(sizeof(struct args)); //menyesuaikan ukuran index
          index->i = i;
          index->j = j;
          pthread_create(&tid[i][j], NULL, &kaliMatriks, (void *)index); //pthread_create
          pthread_join(tid[i][j], NULL);                                 //kemudian sekaligus join
        }
    }

    printf("Matriks :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
          printf("%3d", hasil[i][j]);
        }
        printf("\n");
    }

    //shared memory
    key_t key = 1230;
    int *value;

    int shmid = shmget(key, 96, IPC_CREAT | 0666);
    value = shmat(shmid, NULL, 0);

    int* z = (int*) value;

    memcpy(z, hasil, 96); //memcpy

    shmdt(value);
}
