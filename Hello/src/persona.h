/*
 * persona.h
 *
 *  Created on: 9 nov 2022
 *      Author: alumno
 */

#ifndef PERSONA_H_
#define PERSONA_H_

typedef struct{

	int id;
	char nombre[20];
	char apellido[20];
	char sexo;
	float altura;
}ePersona;



#endif /* PERSONA_H_ */


ePersona* new_persona();
ePersona* newPersonaParam(int id, char nombre[],char apellido[],char sexo, float altura);
ePersona* newPersonaParamString(char* id, char* nombre,char* apellido,char* sexo, char* altura);
int mostrarPersona(ePersona* p);
void daletePersona(ePersona* p);

//getters y setters

int personaSetId(ePersona* p, int id);
int personaSetNombre(ePersona* p, char nombre[]);
int personaSetApellido(ePersona* p, char apellido[]);
int personaSetSexo(ePersona* p, char sexo);
int personaSetAltura(ePersona* p, float altura);
//---------------------------------------------------------------------
int personaGetId(ePersona* p, int* pId);
int personaGetNombre(ePersona* p, char* pNombre);
int personaGetApellido(ePersona* p, char* pApellido);
int personaGetSexo(ePersona* p, char* pSexo);
int personaGetSexoString(ePersona* p, char pSexo[]);
int personaGetAltura(ePersona* p, float* pAltura);
int personaGetFullName(ePersona* p, char fullName[]);


int personaComperId(void* i, void* j);
int personaComperNombre(void* i, void* j);
int personaComperApellido(void* i, void* j);
int personaComperSexo(void* i, void* j);
int personaComperAltura(void* i, void* j);
