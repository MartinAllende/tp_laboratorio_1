
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main(void)
{

	setbuf(stdout, NULL);

	int respuesta;
	int decicion = 1;
	int precioLatam;
	int precioAerolineas;
	int km;
	float precioCreditoLatam;
	float precioDebitoLatam;
	float precioBitcoinLatam;
	float precioUnitarioLatam;
	float precioCreditoAero;
	float precioDebitoAero;
	float precioBitcoinAero;
	float precioUnitarioAero;
	float diferenciaDePrecio;
	int banderaCase1 = 1;
	int banderaCase2 = 1;
	int banderaCase3 = 1;
	int validacionPrecioAerolineas;
	int validacionPrecioLatam;
	int validacionKm;
	int validacionCalcularCostos;

	do
	{

		do
		{
			mostrarOpciones();
			utn_getInt(&respuesta,"\nIngrese su opcion\n" ,"\nError ingrese de nuevo su respuesta\n", 6, 1, 2);

			switch(respuesta)
			{

				case 1:
					validacionKm = utn_getInt(&km, "\nIngrese la cantidad de km\n","\nerror ingrese de nuevo los km\n", 999999999, 1, 2);
						if(validacionKm == 0)
						{
							banderaCase1 = 0;
						}

					break;

				case 2:
					if(banderaCase1 == 0)
					{
						validacionPrecioLatam = utn_getInt(&precioLatam,"\nIngrese el precio de Latam\n" ,"\nerror ingrese de nuevo precio de latam\n", 999999999, 1, 2);
						validacionPrecioAerolineas = utn_getInt(&precioAerolineas,"\nIngrese el precio de Aerlonieas\n" ,"\nerror ingrese de nuevo precio de aerlonieas\n", 999999999, 1, 2);

							if(validacionPrecioLatam == 0 && validacionPrecioAerolineas == 0)
							{

								banderaCase2 = 0;

							}
					}
					else
					{
						printf("\nPrimero debe ingresar los km\n");
					}

					break;

				case 3:

					if(banderaCase2 == 0)
					{
						validacionCalcularCostos = calcularCostos(precioAerolineas, precioLatam, km, &precioCreditoLatam, &precioDebitoLatam, &precioBitcoinLatam, &precioUnitarioLatam, &precioCreditoAero, &precioDebitoAero, &precioBitcoinAero, &precioUnitarioAero, &diferenciaDePrecio);
							if(validacionCalcularCostos == 0)
							{
								banderaCase3 = 0;
							}
					}
					else
					{
						printf("\nPrimero debe ingresar los precios\n");
					}

					break;

				case 4:

					if(banderaCase3 == 0)
					{
						mostrarCostos(precioAerolineas, precioLatam, km, precioCreditoLatam, precioDebitoLatam, precioBitcoinLatam, precioUnitarioLatam, precioCreditoAero, precioDebitoAero, precioBitcoinAero, precioUnitarioAero, diferenciaDePrecio);
					}
					else
					{
						printf("\nPrimero debe calcular los costos\n");
					}

					break;

				case 5:

					calcularCostos(162965,159339,7090, &precioCreditoLatam, &precioDebitoLatam, &precioBitcoinLatam, &precioUnitarioLatam, &precioCreditoAero, &precioDebitoAero, &precioBitcoinAero, &precioUnitarioAero, &diferenciaDePrecio);
					mostrarCostos(162965,159339,7090, precioCreditoLatam, precioDebitoLatam, precioBitcoinLatam, precioUnitarioLatam, precioCreditoAero, precioDebitoAero, precioBitcoinAero, precioUnitarioAero, diferenciaDePrecio);

					break;

			}

		}while(respuesta != 6 );

			printf("\n¿Quiere ingresar otro vuelo?(si = 1, no = 0)\n");
			scanf("%d", &decicion);

	}while(decicion == 1);

	printf("\nGracias por su participacion\n");

	return 0;

}

