
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "funcionesPedidas.h"

int validarString(char string[])
{
	int retorno = 0;
	int i;

	for(i=0;i<strlen(string);i++)
	{

		if(!((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122)))
		{
			printf("Solo ingresa letras\n\n");
			retorno = -1;
			break;
		}

	}
	return retorno;
}

int validarFlycode(char string[])
{
	int retorno = 0;
	int i;

	if(strlen(string)!=10)
	{
		printf("El flycode debe tener 10 caracteres\n");
		retorno = -1;
	}
	else
	{
		for(i=0;i<strlen(string);i++)
		{
			if(!((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122)||(string[i] >= 47 && string[i] <= 57)))
					{
						printf("Solo ingresa letras o numeros\n");
						retorno = -1;
						break;
					}
		}
	}
		return retorno;
}

int utn_getInt(int *pResultado, char *mensaje, char *mensajeError, int maximo, int minimo, int reintentos)
{

	int retorno = -1;
	int buffer;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && maximo >= minimo && reintentos >= 0)
	{
		do{
				printf("%s", mensaje);
				scanf("%d", &buffer);

				if(buffer >= minimo && buffer <= maximo)
				{
					*pResultado = buffer;
					retorno = 0;
					break;
				}
				else
				{
					printf(mensajeError);
					reintentos--;
				}

			}while(reintentos >=0);
	}

	return retorno;
}
