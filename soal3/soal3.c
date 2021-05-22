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


char *getNamaFile(char *NamaFile, char Buffer[]){
  char *token = strtok(NamaFile, "/");
  while(token != NULL){
    sprintf(Buffer, "%s", token);
    token = strtok(NULL, "/");
  }
}

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

void CheckDir(char Buffer[]){
  DIR *dr = opendir(Buffer);
  if (ENOENT == errno){
    mkdir(Buffer, 0775);
    closedir(dr);
  }
}

struct args{
  char *Bufferer;
};

void *input(void* arg){
  char BufferExt[100];
  char BufferNamaFile[1500];
  char BufferFrom[1500];
  char BufferTo[1500];
  char cwd[1500];
  getcwd(cwd, sizeof(cwd));
  strcpy(BufferFrom, (char *) arg);

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


  getNamaFile(BufferFrom, BufferNamaFile);
  strcpy(BufferFrom, (char *) arg);

  getExtensionFile(BufferFrom, BufferExt);
  for(int i = 0; i < sizeof(BufferExt); i++){
    BufferExt[i] = tolower(BufferExt[i]);
  }
  strcpy(BufferFrom, (char *) arg);

  CheckDir(BufferExt);

  sprintf(BufferTo, "%s/%s/%s", cwd, BufferExt, BufferNamaFile);
  rename(BufferFrom, BufferTo);

  pthread_exit(0);
}

int main(int argc, char *argv[]) {
  if(argc == 1){
    printf("Input argument kurang\n");
    exit(1);
  }
  if(strcmp(argv[1], "-f") != 0 && strcmp(argv[1], "-d") && strcmp(argv[1], "*") != 0){
    printf("Input argument tidak ada(silahkan input [-f], [-d], atau [*]\n");
    exit(1);
  }

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

  if(strcmp(argv[1], "-d") == 0){
    if(argc != 3){
      printf("Input argument salah\n");
      exit(1);
    }
    DIR* dir = opendir(argv[2]);
    if(dir){
      direktori = argv[2];
      printf("Direktori sukses disimpan!\n");
    } else if(ENOENT == errno){
      printf("Yah, gagal disimpan :(\n");
      exit(1);
    }
    closedir(dir);
  }

  int jumlah_file = 0;
  DIR* dir = opendir(direktori);
  struct dirent *entri;
  while ((entri = readdir(dir)) != NULL){
    if(entri->d_type == DT_REG){
      jumlah_file++;
    }
  }
  closedir(dir);

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

  for(int i = 0; i < jumlah_file; i++){
    char  *test = (char*)Buffer[i];
    //printf("%s\n", test);
    pthread_create(&tid[i], NULL, &input, (void *)test);
  }

  for(int i = 0; i < jumlah_file; i++){
    pthread_join(tid[i], NULL);
  }

}
