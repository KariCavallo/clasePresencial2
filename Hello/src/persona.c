/*
 * persona.c
 *
 *  Created on: 9 nov 2022
 *      Author: alumno
 */

#include "persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


ePersona* new_persona(){


 ePersona* p =  (ePersona*) malloc(sizeof(ePersona));


	p->id = 0;
	strcpy(p->nombre, " "); // *(p->nombre) = '\0';
	strcpy(p->apellido, " ");
	p->sexo = ' ';
	p->altura = 0;


 return p;
}

int mostrarPersona(ePersona* p){

	int todoOk = 0;


	 int id;
	 char nombre[20];
	 char apellido[20];
	 char sexo;
	 float altura;

	 if(personaGetId(p,&id)==1 &&
			 personaGetNombre(p,nombre)==1 &&
			 personaGetApellido(p,apellido)==1 &&
			 personaGetSexo(p,&sexo)==1 &&
			 personaGetAltura(p,&altura)==1){

		 printf("id: %d  nombre: %s apellido: %s sexo: %c  altura: %.2f\n", id, nombre,apellido, sexo,altura);

		 todoOk = 1;
	 }



	return todoOk;
}

ePersona* newPersonaParam(int id, char nombre[],char apellido[],char sexo, float altura){

	ePersona* p = new_persona();

 if(!(personaSetId(p,id),personaSetNombre(p,nombre),personaSetApellido(p,apellido),personaSetSexo(p,sexo),personaSetAltura(p,altura)))
 {

      daletePersona(p);

 }
	return p;
}

void daletePersona(ePersona* p){

	free(p);
}

int personaSetId(ePersona* p, int id){
int todoOk = 0;

if(p != NULL && id >= 20000 && id <= 30000){

	p->id = id;
	todoOk = 1;
}

return todoOk;

}

int personaSetNombre(ePersona* p, char nombre[]){

	int todoOk = 0;

	if(p != NULL && strlen(nombre) < 20){


		strcpy(p->nombre,nombre);
		strlwr(p->nombre);
		p->nombre[0]= toupper(p->nombre[0]);
		todoOk = 1;
	}

	return todoOk;

}

int personaSetApellido(ePersona* p, char apellido[]){

	int todoOk = 0;

		if(p != NULL && strlen(apellido) < 20){


			strcpy(p->apellido,apellido);
			strlwr(p->apellido);
			p->apellido[0]= toupper(p->apellido[0]);
			todoOk = 1;
		}

		return todoOk;
}
int personaSetSexo(ePersona* p, char sexo){

	int todoOk = 0;

	sexo = tolower(sexo);

	if(p != NULL && (sexo == 'f' || sexo == 'm')){

		p->sexo = sexo;
		todoOk = 1;
	}

	return todoOk;

}

int personaSetAltura(ePersona* p, float altura) {

	int todoOk = 0;

	if(p != NULL && (altura > 0 && altura < 2.50)){

		p->altura = altura;
		todoOk = 1;
	}

	return todoOk;

}

int personaGetId(ePersona* p, int* pId){

	int todoOk = 0;

	if(p != NULL && pId != NULL){

		*pId = p->id;
		todoOk = 1;
	}

	return todoOk;


}

int personaGetNombre(ePersona* p, char* pNombre){

	int todoOk = 0;

		if(p != NULL && pNombre != NULL){


			strcpy(pNombre,p->nombre);

			todoOk = 1;
		}

		return todoOk;


}

int personaGetApellido(ePersona* p, char* pApellido){

	int todoOk = 0;

			if(p != NULL && pApellido != NULL){


				strcpy(pApellido,p->apellido);
				todoOk =1;

			}

			return todoOk;
}

int personaGetSexo(ePersona* p, char* pSexo){



	int todoOk = 0;


		if(p != NULL && pSexo != NULL){

			*pSexo = p->sexo;
			todoOk = 1;
		}

		return todoOk;

}

int personaGetSexoString(ePersona* p, char pSexo[]){


	int todoOk = 0;


		if(p != NULL && pSexo != NULL){

			if(p->sexo == 'f'){
			strcpy(pSexo,"Femenino");

			}else{

				strcpy(pSexo,"Masculino");
			}

			todoOk = 1;
		}

		return todoOk;


}

int personaGetAltura(ePersona* p, float* pAltura){


	int todoOk = 0;


		if(p != NULL && pAltura != NULL){

			*pAltura = p->altura;
			todoOk = 1;
		}

		return todoOk;

}


ePersona* newPersonaParamString(char* id, char* nombre,char* apellido,char* sexo, char* altura){

	ePersona* p = new_persona();

 if(!(personaSetId(p,atoi(id)),personaSetNombre(p,nombre),personaSetApellido(p,apellido),personaSetSexo(p,sexo[0]),personaSetAltura(p,atof(altura))))
 {

      daletePersona(p);
 }
	return p;
}

int personaComperId(void* p, void* q){

	int rta = 0;

	ePersona* p1 = NULL;
	ePersona* p2 = NULL;

	if(p != NULL && q != NULL){

		p1 = (ePersona*) p;
		p2 = (ePersona*) q;

		if(p1->id > p2->id){

			rta = 1;
		}

		else if(p1->id < p2->id){
			rta = -1;
		}
	}



	return rta;


}

int personaComperNombre(void* p, void* q){

	int rta = 0;

	ePersona* p1 = NULL;
	ePersona* p2 = NULL;

	if(p != NULL && q != NULL){

		p1 = (ePersona*) p;
		p2 = (ePersona*) q;

		rta = strcmp(p1->nombre , p2->nombre);
	}



	return rta;


}

int personaComperApellido(void* p, void* q){

	int rta = 0;

	ePersona* p1 = NULL;
	ePersona* p2 = NULL;

	if(p != NULL && q != NULL){

		p1 = (ePersona*) p;
		p2 = (ePersona*) q;

		rta = strcmp(p1->apellido , p2->apellido);
	}



	return rta;


}

int personaComperSexo(void* p, void* q){

	int rta = 0;

	ePersona* p1 = NULL;
	ePersona* p2 = NULL;

	if(p != NULL && q != NULL){

		p1 = (ePersona*) p;
		p2 = (ePersona*) q;

		if(p1->sexo > p2->sexo){

			rta = 1;
		}

		else if(p1->sexo < p2->sexo){
			rta = -1;
		}
	}



	return rta;


}


int personaComperAltura(void* p, void* q){

	int rta = 0;

	ePersona* p1 = NULL;
	ePersona* p2 = NULL;

	if(p != NULL && q != NULL){

		p1 = (ePersona*) p;
		p2 = (ePersona*) q;

		if(p1->altura > p2->altura){

			rta = 1;
		}

		else if(p1->altura < p2->altura){
			rta = -1;
		}
	}



	return rta;


}

int personaComperSexoNombre(void* p, void* q){

	int rta = 0;

	ePersona* p1 = NULL;
	ePersona* p2 = NULL;

	if(p != NULL && q != NULL){

		p1 = (ePersona*) p;
		p2 = (ePersona*) q;


		if(p1->sexo != p2->sexo){

		if(p1->sexo > p2->sexo){

					rta = 1;
				}

	   else if(p1->sexo < p2->sexo){
					rta = -1;
				}
	}else{

		rta = strcmp(p1->nombre , p2->nombre);


	}


	}


	return rta;


}
