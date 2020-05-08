#include "types.h"
#include "stat.h"
#include "user.h"

char buffer[1000]; //Inisialisasi buffer 1
char buffer2[1000]; //Inisialisasi buffer 2

//Fungsi tail
void tail(int fd,char *name, int x){
    int i, n, m, l;
    int total_lines = 0;
    int start;
    while((n=read(fd, buffer, sizeof (buffer)))>0){
        for(i=0;i<=n;i++){
            if (buffer[i]=='\n')
            {
                total_lines++; // Loop untuk total line di dalam file
                
                if(strcmp(name,"")==0){
                    printf(1, "\n");
                }

                else {
                    if(strcmp(name,"")==0){
                        if (buffer[i]=='\0') exit(); // Cek file akhir
                        if (buffer[i]=='\n') printf(1, "%c", buffer[i]);
                        else printf (1,"\n");
                    }
                }
            }
        }
    }
    close(fd);

    start=total_lines-x;
    l=0;

    int fd2 = open(name,0); //Buat file deskriptor 2
    while((m=read(fd2, buffer2, sizeof (buffer2)))>0){
        for(i=0;i<=m;i++){
            if(buffer2[i]=='\n') l++;
            if (l>=start){
                if(buffer2[i] != '\n' && l>= start) printf (1,"%c", buffer2[i]);
                else {
                    printf (1, "\n");
                    l++;
                }
            }
        }
    }
    close(fd2);

    //Error cek
    if(n<0){
        printf(1, "Tail: Error while reading\n");
        exit();
    }
}

int main(int argc, char *argv[]){
    int fd, i;
    if (argc<=1){
        tail(0, "", 10);
        exit();
    }

    else if (argc==2){
        for(i=1; i<=argc; i++){
            if((fd=open(argv[i], 10))<0){
                printf(1, "Error in file reading\n");
                exit();
            }
            tail(fd, argv[i], 10);
            close(fd);
        }
    }

    else if(argc==3){
        char c[1000];
        strcpy(c,argv[1]);
        char *num_str = c;
        num_str=num_str+1;
        int x = atoi(num_str);

        for(i=2; i<argc; i++){
            if((fd=open(argv[i], 0)) < 0){
                printf(1, "Tail: Error opening the %s\n", argv[i]);
                exit();
            }
            tail(fd, argv[i], x);
            close(fd);
        }
    }
    else printf (1, "Tail: Syntax error\n");
    exit();
}
