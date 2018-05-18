/**
Sistemas Operativos
Tarea Hilos C
Integrantes:
Jaime Cuartas Granada           1632664
Juan Camilo Perez Muñoz	        1630779
Emily Esmeralda Carvajal Camelo 1630436*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdint.h>
//Cantidad de hilos
#define NTHREADS 16


void *hola(void * n);

int main(int argc, char *argv[]) {
	int countarray[NTHREADS];
	pthread_t ptarray[NTHREADS];

	for (int j = 0; j < NTHREADS; j++) {
		countarray[j]=j;
		pthread_create(&ptarray[j], NULL,(void*)hola,(void*)(intptr_t)countarray[j]);	
	}

	for(int k=0;k<NTHREADS;k++){
		pthread_join(ptarray[k], NULL);
	}
	return 0;
}

void *hola(void * n) {
	int hiloNumero = (intptr_t)n;
	pthread_t id = pthread_self();
	printf("Mensaje desde el hilo %d con id: %ld \n", hiloNumero, id);
	pthread_exit(NULL);
	return NULL;
} 
