
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "funcionesPedidas.h"


# define TAM 2000

int main(void)
{
	setbuf(stdout,NULL);

	agendaPassengers pasajeros[TAM];
	agendaPassengersAux pasajerosAux;
	int retorno;
	int opciones;
	int idSeleccionada;
	int orden;
	int opcionesInfomar;
	int flag = 0;

	retorno = initPassangers(pasajeros,TAM);

	if(retorno!=0)
	{
		printf("No se inicalizo correctamente los espacios de memoria\n");
	}
	else
	{
		printf("Los espacios de memoria estan listos\n");
	}

	do
	{
		mostrarOpciones();
		retorno = utn_getInt(&opciones, "Ingrese su opcion\n", "Error ingrese su opcion de nuevo\n", 5, 1, 2);

		if(retorno == 0)
		{
			switch(opciones)
			{
				case 1:

						retorno = findFree(pasajeros,TAM);
						if(retorno != -1)
						{
							takeDatosPassenger(&pasajerosAux,TAM);
							addPassenger(pasajeros,TAM,pasajerosAux.name,pasajerosAux.lastname,pasajerosAux.price,pasajerosAux.flycode,pasajerosAux.typePassenger,pasajerosAux.statusFlight,retorno);
							flag = flag + 1;
						}
						else
						{
							printf("No se encontro libre\n");
						}
					break;

				case 2:

					if(flag != 0)
					{
						retorno = utn_getInt(&idSeleccionada, "Ingrese la id que quiere modificar\n", "Error ingrese la id de nuevo\n", TAM, 1, 2);
						if(retorno == 0)
						{
							editPassanger(pasajeros,TAM,idSeleccionada);
						}
						else
						{
							printf("Hubo un error al editar el pasajero\n");
						}
					}
					else
					{
						printf("Primero debe cargar algun dato\n");
					}

						break;

				case 3:

					if(flag != 0)
					{
						retorno = utn_getInt(&idSeleccionada, "Ingrese la id que quiere eliminar\n", "Error ingrese la id de nuevo\n", TAM, 1, 2);
						if(retorno == 0)
						{
							removePassanger(pasajeros,TAM,idSeleccionada);
							flag = flag - 1;
						}
						else
						{
							printf("Hubo un error al remover el pasajero\n");
						}
					}
					else
					{
						printf("Primero debe cargar algun dato\n");
					}
					break;

				case 4:

					if(flag != 0)
					{
						retorno = utn_getInt(&opcionesInfomar, "Que quiere ver: \n1. Listado de los pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero\n2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio\n3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’\n", "Error ingrese el orden de nuevo\n", 3, 1, 2);

						if(retorno == 0)
						{
							switch(opcionesInfomar)
							{
								case 1:
									retorno = utn_getInt(&orden, "que orden quiere, 1. Ascendente, 0. Descendente\n", "Error ingrese el orden de nuevo\n", 1, 0, 2);

									if(retorno == 0)
									{
										retorno = sortPassangers(pasajeros,TAM, orden);

										if(retorno == 0)
										{
											printf("se ordeno correctamente\n");
										}
										else
										{
											printf("hubo un error al ordenar\n");
										}

										printPassangers1(pasajeros,TAM);
									}

									break;
								case 2:
									promedioPasajes(pasajeros,TAM);
									break;
								case 3:
									retorno = utn_getInt(&orden, "que orden quiere, 1. Ascendente, 0. Descendente\n", "Error ingrese el orden de nuevo\n", 1, 0, 2);

									if(retorno == 0)
									{
										retorno = sortPassangersByCode(pasajeros,TAM, orden);

										if(retorno == 0)
										{
											printf("se ordeno correctamente\n");
										}
										else
										{
											printf("hubo un error al ordenar\n");
										}

											printPassangers3(pasajeros,TAM);
									}

									break;
							}
						}
						else
						{
							printf("error al ingresar la opcion\n");
						}
					}
					else
					{
						printf("Primero debe cargar algun dato\n");
					}
					break;
			}
		}
	}
	while(opciones != 5);


	return EXIT_SUCCESS;
}
