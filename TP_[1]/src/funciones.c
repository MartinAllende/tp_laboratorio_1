
#include <stdio.h>
#include <stdlib.h>

int mostrarOpciones(void)
{

	int retorno = -1;

	printf("\n1) Ingresar kilometros");
	printf("\n2) Ingresar precio de los vuelos");
	printf("\n3) Cacular todos los costos");
	printf("\n4) Informar resultado");
	printf("\n5) Carga forzada de datos");
	printf("\n6) Salir\n");

	retorno = 0;

	return retorno;

}

int calcularCostos(int precioAerolineas, int precioLatam, int km, float *precioCreditoLatam, float *precioDebitoLatam, float *precioBitcoinLatam, float *precioUnitarioLatam, float *precioCreditoAero, float *precioDebitoAero, float *precioBitcoinAero, float *precioUnitarioAero, float *diferenciaDePrecio)
{

	int retorno = -1;

	*precioDebitoLatam = precioLatam * 0.9;
	*precioCreditoLatam = precioLatam * 1.2;
	*precioBitcoinLatam = precioLatam / 4606954.55;
	*precioUnitarioLatam = precioLatam / km;
	*precioDebitoAero = precioAerolineas * 0.9;
	*precioCreditoAero = precioAerolineas * 1.2;
	*precioBitcoinAero = precioAerolineas / 4606954.55;
	*precioUnitarioAero = precioAerolineas / km;

	if(precioAerolineas > precioLatam)
	{

		*diferenciaDePrecio = precioAerolineas - precioLatam;

	}
	else if(precioAerolineas < precioLatam)
	{

		*diferenciaDePrecio = precioLatam - precioAerolineas;

	}
	else
	{

		*diferenciaDePrecio = 0;

	}

	printf("\nCalculos realizados con exito\n");

	retorno = 0;

	return retorno;
}

int mostrarCostos(int precioAerolineas, int precioLatam, int km, float precioCreditoLatam, float precioDebitoLatam, float precioBitcoinLatam, float precioUnitarioLatam, float precioCreditoAero, float precioDebitoAero, float precioBitcoinAero, float precioUnitarioAero, float diferenciaDePrecio)
{

	int retorno = -1;

	printf("\nKMs Ingresados: %d", km);
	printf("\n\nPrecio Aerolineas: %d", precioAerolineas);
	printf("\na) Precio con tarjeta de debito: $ %.2f ", precioDebitoAero);
	printf("\nb) Precio con tarjeta de credito: $ %.2f ", precioCreditoAero);
	printf("\nc) Precio pagando con bitcoin: $ %.2f ", precioBitcoinAero);
	printf("\nd) Mostrar precio unitario: $ %.2f" , precioUnitarioAero);
	printf("\n\nPrecio Latam: %d", precioLatam);
	printf("\na) Precio con tarjeta de debito: $ %.2f ", precioDebitoLatam);
	printf("\nb) Precio con tarjeta de credito: $ %.2f ", precioCreditoLatam);
	printf("\nc) Precio pagando con bitcoin: $ %.2f ", precioBitcoinLatam);
	printf("\nd) Mostrar precio unitario: $ %.2f" , precioUnitarioLatam);
	printf("\n\nLa diferencia de precio es: $ %.2f\n" , diferenciaDePrecio);

	retorno = 0;

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


