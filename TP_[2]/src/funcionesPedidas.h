
#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#endif /* FUNCIONES_H_ */


typedef struct
	{

			int id;
			char name[51];
			char lastname[51];
			float price;
			char flycode[10];
			int typePassenger;
			int statusFlight;
			int isEmpty;

	}agendaPassengers;

typedef struct
	{

			char name[51];
			char lastname[51];
			float price;
			char flycode[10];
			int typePassenger;
			int statusFlight;

	}agendaPassengersAux;



//--------------------------------FUNCIONES PEDIDA-----------------------
int initPassangers(agendaPassengers pasajeros[],int tam);
int addPassenger(agendaPassengers pasajeros[],int tam, char name[], char lastname[], float price, char flycode[], int typePassenger, int statusFlight, int posisionArray);
int findPassangerById(agendaPassengers pasajeros[], int tam, int idSeleccionada);
int removePassanger(agendaPassengers pasajeros[], int tam, int idSeleccionada);
int sortPassangers(agendaPassengers pasajeros[], int tam, int orden);
int printPassangers1(agendaPassengers pasajeros[], int tam);
int printPassangers3(agendaPassengers pasajeros[], int tam);
int sortPassangersByCode(agendaPassengers pasajeros[], int tam, int orden);
int editPassanger(agendaPassengers pasajeros[],int tam,int idSeleccionada);

//----------------------------------FUNCIONES AUXILIARES------------------

void mostrarOpciones();
int takeDatosPassenger(agendaPassengersAux *pasajerosAux,int tam);
int findFree(agendaPassengers pasajeros[],int tam);
int promedioPasajes(agendaPassengers pasajeros[], int tam);











