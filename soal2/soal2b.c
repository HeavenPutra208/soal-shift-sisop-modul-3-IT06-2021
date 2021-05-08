#include <stdio.h>
#include <pthread.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>

//inisialiasi matriks
int matriksA[4][6]; //matriks A
int matriksB[4][6]; //matriks B
int matriksHasil[4][6]; //matriks hasilnya

//inisialisasi struct i dan j
struct args {
  int i;
  int j;
};

int faktorial(int n) { //fungsi untuk nge faktorial
    if (n>=1)
        return n*faktorial(n-1);
    else
        return 1;
}

//    int i = ((struct args*)arg)->i;
//    int j = ((struct args*)arg)->j;

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

int main() {
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

    pthread_t tid[4][6];

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
        //struct args *index = (struct args *)malloc(sizeof(struct args));
        struct args *index = (struct args *)malloc(sizeof(struct args));
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

    printf("Matriks :\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%d\t", matriksHasil[i][j]);
        }
        printf("\n");
    }
}
