
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "funcionesPedidas.h"


//-------------------------------------FUNCIONES PEDIDAS-------------------------------------------------//

int initPassangers(agendaPassengers pasajeros[],int tam)
{
	int retorno = -1;
	int i;

	for(i=0;i<tam;i++)
	{
		pasajeros[i].isEmpty=1;
		pasajeros[i].id=i+1;
		retorno = 0;
	}
	return retorno;
}

int addPassenger(agendaPassengers pasajeros[],int tam, char name[], char lastname[], float price, char flycode[], int typePassenger, int statusFlight, int posisionArray)
{
	int retorno = -1;


		if(pasajeros!=NULL && tam>0)
		{
			strcpy(pasajeros[posisionArray].name,name);
			strcpy(pasajeros[posisionArray].lastname,lastname);
			pasajeros[posisionArray].price=price;
			strcpy(pasajeros[posisionArray].flycode,flycode);
			pasajeros[posisionArray].typePassenger=typePassenger;
			pasajeros[posisionArray].statusFlight=statusFlight;
			pasajeros[posisionArray].isEmpty=0;

			retorno = 0;
		}

	return retorno;
}

int findPassangerById(agendaPassengers pasajeros[], int tam, int idSeleccionada)
{
	int retorno = -1;
	int i;

	if(pasajeros != NULL && tam > 0 && idSeleccionada > 0)
	{
		for(i=0;i<tam;i++)
		{
			if(idSeleccionada == pasajeros[i].id && pasajeros[i].isEmpty == 0)
			{
				retorno = i;
				break;
			}
		}
	}
		return retorno;
}

int removePassanger(agendaPassengers pasajeros[], int tam, int idSeleccionada)
{
	int retorno = -1;
	int posicionArray;

	if(pasajeros != NULL && tam > 0 && idSeleccionada > 0)
	{

		posicionArray = findPassangerById(pasajeros,tam,idSeleccionada);

		if(posicionArray == -1)
		{
			printf("No se encontro la id\n");
		}
		else
		{
			pasajeros[posicionArray].isEmpty = 1;
			retorno = 0;
		}

	}

	return retorno;
}

int sortPassangers(agendaPassengers pasajeros[], int tam, int orden)
{
	int retorno = -1;
	int i;
	int j;
	agendaPassengers auxPasajeros;


	if(orden == 0)
	{
		for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(strcmp(pasajeros[i].lastname,pasajeros[j].lastname)>0)
					{

							auxPasajeros = pasajeros[i];
							pasajeros[i] = pasajeros[j];	//up
							pasajeros[j] = auxPasajeros;

					}
				}
			}
			retorno = 0;
	}
	else
	{
		for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(strcmp(pasajeros[i].lastname,pasajeros[j].lastname)<0)
					{
						auxPasajeros = pasajeros[i];
						pasajeros[i] = pasajeros[j];  //down
						pasajeros[j] = auxPasajeros;
					}
				}
			}
			retorno = 0;
	}

	return retorno;
}

int printPassangers1(agendaPassengers pasajeros[], int tam)
{
	int retorno = -1;
	int i;
	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0 && pasajeros[i].typePassenger == 1)
		{

			printf("ID: %d\n", pasajeros[i].id);
			printf("Nombre: %s\n", pasajeros[i].name);
			printf("Apellido: %s\n", pasajeros[i].lastname);
			printf("Precio: %f\n", pasajeros[i].price);
			printf("Codigo de vuelo: %s\n", pasajeros[i].flycode);
			printf("Tipo de pasajero: %d (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)\n", pasajeros[i].typePassenger);
			printf("Estado del vuelo: %d (1. Cancelado, 2. Demorado, 3. Activo)\n", pasajeros[i].statusFlight);

		}
	}
	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0 && pasajeros[i].typePassenger == 2)
		{

			printf("ID: %d\n", pasajeros[i].id);
			printf("Nombre: %s\n", pasajeros[i].name);
			printf("Apellido: %s\n", pasajeros[i].lastname);
			printf("Precio: %f\n", pasajeros[i].price);
			printf("Codigo de vuelo: %s\n", pasajeros[i].flycode);
			printf("Tipo de pasajero: %d (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)\n", pasajeros[i].typePassenger);
			printf("Estado del vuelo: %d (1. Cancelado, 2. Demorado, 3. Activo)\n", pasajeros[i].statusFlight);

		}
	}
	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0 && pasajeros[i].typePassenger == 3)
		{

			printf("ID: %d\n", pasajeros[i].id);
			printf("Nombre: %s\n", pasajeros[i].name);
			printf("Apellido: %s\n", pasajeros[i].lastname);
			printf("Precio: %f\n", pasajeros[i].price);
			printf("Codigo de vuelo: %s\n", pasajeros[i].flycode);
			printf("Tipo de pasajero: %d (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)\n", pasajeros[i].typePassenger);
			printf("Estado del vuelo: %d (1. Cancelado, 2. Demorado, 3. Activo)\n", pasajeros[i].statusFlight);

		}
	}
	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0 && pasajeros[i].typePassenger == 4)
		{

			printf("ID: %d\n", pasajeros[i].id);
			printf("Nombre: %s\n", pasajeros[i].name);
			printf("Apellido: %s\n", pasajeros[i].lastname);
			printf("Precio: %f\n", pasajeros[i].price);
			printf("Codigo de vuelo: %s\n", pasajeros[i].flycode);
			printf("Tipo de pasajero: %d (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)\n", pasajeros[i].typePassenger);
			printf("Estado del vuelo: %d (1. Cancelado, 2. Demorado, 3. Activo)\n", pasajeros[i].statusFlight);
			retorno = 0;
		}
	}

	return retorno;

}

int sortPassangersByCode(agendaPassengers pasajeros[], int tam, int orden)
{
	int retorno = -1;
	int i;
	int j;
	agendaPassengers auxPasajeros;


	if(orden == 0)
	{
		for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(strcmp(pasajeros[i].flycode,pasajeros[j].flycode)>0)
					{

							auxPasajeros = pasajeros[i];
							pasajeros[i] = pasajeros[j];
							pasajeros[j] = auxPasajeros;

					}
				}
			}
			retorno = 0;
	}
	else
	{
		for(i=0;i<tam-1;i++)
			{
				for(j=i+1;j<tam;j++)
				{
					if(strcmp(pasajeros[i].flycode,pasajeros[j].flycode)<0)
					{
						auxPasajeros = pasajeros[i];
						pasajeros[i] = pasajeros[j];
						pasajeros[j] = auxPasajeros;
					}
				}
			}
			retorno = 0;
	}
	return retorno;
}

int printPassangers3(agendaPassengers pasajeros[], int tam)
{
	int retorno = -1;
	int i;
	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0 && pasajeros[i].statusFlight == 1)
		{

			printf("ID: %d\n", pasajeros[i].id);
			printf("Nombre: %s\n", pasajeros[i].name);
			printf("Apellido: %s\n", pasajeros[i].lastname);
			printf("Precio: %f\n", pasajeros[i].price);
			printf("Codigo de vuelo: %s\n", pasajeros[i].flycode);
			printf("Tipo de pasajero: %d (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)\n", pasajeros[i].typePassenger);
			printf("Estado del vuelo: %d (1. Cancelado, 2. Demorado, 3. Activo)\n", pasajeros[i].statusFlight);
			retorno = 0;
		}

	}
	return retorno;
}

int editPassanger(agendaPassengers pasajeros[],int tam,int idSeleccionada)
{
	int retorno=-1;
	int posicionArray;
	int decicion;
	int opciones;
	int validacion;
	char auxString[51];
	char auxFlicode[10];


	if(pasajeros != NULL && tam > 0 && idSeleccionada > 0)
		{

			posicionArray = findPassangerById(pasajeros,tam,idSeleccionada);

			if(posicionArray == -1)
			{
				printf("No se encontro la id\n");
			}
			else
			{

				validacion = utn_getInt(&decicion, "Que desea modificar?\n1. Nombre\n 2. Apellido\n 3. precio\n 4. codigo de vuelo\n 5. tipo de pasajero\n 6. estado del vuelo\n", "error ingrese de nuevo",6,1,2);
				switch(decicion)
				{
					case 1:
						do
						{
							printf("Ingrese el nuevo nombre\n");
							fflush(stdin);
							scanf("%s",auxString);

							validacion = validarString(auxString);

						}while(validacion != 0);

						strcpy(pasajeros[posicionArray].name,auxString);
						validacion = -1;

						break;

					case 2:
						do
						{
							printf("Ingrese el nuevo apellido\n");
							fflush(stdin);
							scanf("%s",auxString);

							validacion = validarString(auxString);

						}while(validacion != 0);

						strcpy(pasajeros[posicionArray].lastname,auxString);
						validacion = -1;

						break;

					case 3:

						printf("Ingrese el nuevo precio\n");
						scanf("%f",&pasajeros[posicionArray].price);

						break;

					case 4:

						do
						{
							printf("Ingrese el codigo de vuelo\n");
							fflush(stdin);
							scanf("%s",auxFlicode);

							validacion = validarFlycode(auxFlicode);

						}while(validacion != 0);

						strcpy(pasajeros[posicionArray].flycode,auxFlicode);
						validacion = -1;

						break;

					case 5:

						validacion = utn_getInt(&opciones,"elija el nuevo tipo de pasajero (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)" , "Error ingrese de nuevo\n", 4, 1, 2);\

						if(validacion == 0)
						{
							pasajeros[posicionArray].typePassenger = opciones;
						}

						break;

					case 6:

						validacion = utn_getInt(&opciones,"elija el nuevo estado de vuelo (1. Activo, 2. Cancelado, 3. Demorado)" , "Error ingrese de nuevo\n", 3, 1, 2);\

						if(validacion == 0)
						{
							pasajeros[posicionArray].statusFlight = opciones;
						}

						break;
				}

				retorno = 0;
			}

		}

	return retorno;
}

//--------------------------------FUNCIONES AUXILIARES-----------------------------------------------------------//

void mostrarOpciones()
{
	printf("1) Altas\n2) Modificar\n3) Baja\n4) Informar\n5) Salir\n");
}

int takeDatosPassenger(agendaPassengersAux *pasajerosAux,int tam)
{
	int retorno = -1;
	int validacion;
	char nameAux[51];
	char lastnameAux[51];
	char flycodeAux[10];
	int opciones;

		do
		{
			printf("Ingrese el nombre\n");
			fflush(stdin);
			scanf("%s",nameAux);

			validacion = validarString(nameAux);

		}while(validacion != 0);

		strcpy(pasajerosAux->name,nameAux);
		validacion = -1;

		do
		{
			printf("Ingrese el apellido\n");
			fflush(stdin);
			scanf("%s",lastnameAux);

			validacion = validarString(lastnameAux);

		}while(validacion != 0);

		strcpy(pasajerosAux->lastname,lastnameAux);
		validacion = -1;

		printf("Ingrese el precio\n");
		scanf("%f",&pasajerosAux->price);

		do
		{
			printf("Ingrese el codigo de vuelo\n");
			fflush(stdin);
			scanf("%s",flycodeAux);

			validacion = validarFlycode(flycodeAux);

		}while(validacion != 0);

		strcpy(pasajerosAux->flycode,flycodeAux);
		validacion = -1;

		validacion = utn_getInt(&opciones,"elija el tipo de pasajero (1. Infante, 2. Adolescente, 3. Adulto, 4. Anciano)" , "Error ingrese de nuevo\n", 4, 1, 2);\

		if(validacion == 0)
		{
			pasajerosAux->typePassenger = opciones;
		}

		validacion = utn_getInt(&opciones,"elija el estado de vuelo (1. Activo, 2. Cancelado, 3. Demorado)" , "Error ingrese de nuevo\n", 3, 1, 2);\

		if(validacion == 0)
		{
			pasajerosAux->statusFlight = opciones;
		}

		retorno = 0;


	return retorno;
}

int findFree(agendaPassengers pasajeros[],int tam)
{

	int retorno=-1;
	int i;

	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty == 1)
		{
			pasajeros[i].isEmpty = 0;
			retorno = i;
			break;
		}

	}

	return retorno;

}

int promedioPasajes(agendaPassengers pasajeros[], int tam)
{
	int retorno = -1;
	int i;
	int acumPrecio = 0;
	float contadorPrecio = 0;
	float resultadoFinal;
	int contadorMasPromedio = 0;


	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0)
		{
			acumPrecio = acumPrecio + pasajeros[i].price;
			contadorPrecio = contadorPrecio + 1;
		}
	}

	resultadoFinal = acumPrecio/contadorPrecio;

	for(i=0;i<tam;i++)
	{
		if(pasajeros[i].isEmpty==0 && pasajeros[i].price > resultadoFinal)
		{
			contadorMasPromedio = contadorMasPromedio + 1;
		}
	}

	printf("El Promedio de precio es de: %.2f\nY la cantidad de pasajeros que supera el promedio es de %d\n", resultadoFinal,contadorMasPromedio);
	return retorno;
}





