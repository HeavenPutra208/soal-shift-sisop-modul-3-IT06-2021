#include <string.h>
#include <stdio.h>
#include <wait.h>
#include <stdlib.h>
#include <unistd.h>

// var. global
int p[2];
int p2[2];

#define die(x) do {fprintf(stderr, "%s\n", x); exit(EXIT_FAILURE);} while (0);

int main()
{
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

	close(p[0]); // close pipe p[0]
    close(p[1]); // close pipe p[1]

    if (fork() == 0)
    {
        close(p2[1]);
        dup2(p2[0], 0);
        close(p2[0]);
        execlp("head", "head", "-5", NULL); // cmd 3
    }

    close(p2[0]); // close pipe p2[0]
    close(p2[1]); // clode pipe p2[1]

	return(0);
}
