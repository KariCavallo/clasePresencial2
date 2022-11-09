/*
 ============================================================================
 Name        : Hello.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "persona.h"



int main(void) {

	setbuf(stdout,NULL);


	ePersona* p = new_persona();
	if(p == NULL){
		printf("No se consiguio mnemoria\n");
		exit(1);
	}else{
		printf("Se cargo una persona con exito!!!\n");
	}



	p = newPersonaParam(20000,"juan","Perez",'m',2.00);
	if(p != NULL){


		mostrarPersona(p);
	}


 personaSetNombre(p,"mario");

 mostrarPersona(p);




	return EXIT_SUCCESS;
}

