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

static void
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

int main(int argc, char *argv[])
{
	char *ps[] = {"ps", "aux", NULL}; //pipe s1
	char *sort[] = {"sort", "-nrk", "3,3", NULL}; //pipe s2
	char *head[] = {"head", "-5", NULL}; //pipe s3
	char **cmd[] = {ps, sort, head, NULL}; //binding cmd pipes

	multiPipes(cmd);//run cmd pakai fungsi multiPipes
	return (0);
}
