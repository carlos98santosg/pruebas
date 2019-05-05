#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int is_valid_arguments(int argc); 

int main(int argc, char* argv[]){

    int n_hijos = 0, i = 0;

    if (!is_valid_arguments(argc)){
        return -1;
    }
    
    n_hijos = atoi(argv[1]);
    printf("Creando %d hijos.\n\n", atoi(argv[1]));
    
    for (i=0; i<n_hijos; i++) {
        if (fork()==0){
            //Este es el codigo del hijo
            printf("Yo soy el hijo numero %d.\n", i);
            sleep(i);
            printf("Yo soy el hijo numero %d y ya he terminado.\n", i);
            exit(0);   
        }
    }

    for (i=0; i<n_hijos; i ++){
        printf("\nSoy el padre y espero al hijo %d.\n",i);
        wait(NULL);
    }

    printf("\nSoy el padre y ya he terminado\n");
    return 6;
}

//Mostramos el error al ejecutarlo.
int is_valid_arguments(int argc){

    if (argc != 2){
        printf("Ejecutar el programa haciendo ./codigoprueba [numero]\n");
        return -1;
    }
    return -1;

}
