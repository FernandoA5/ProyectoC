//INTERPRETE HARD-LEVEL LANGUAGE

//LIBRERIAS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

//Estructuras
struct palabras{
	char *palabra;
};

//DEFINICIONES 
#define EXIT "exit"
//VARIABLES Y DECLARACION DE lAS FUNCIONES CREADAS POR EL USUARIO
FILE *f;
char *Linea;
palabras *p;
void vMenu();
void vSeparar(int);
int iContarPalabras(int);
void vSepararInstrucciones(int, int);
void vVaciarCadena(char []);

//DEFINICION DE LA FUNCION MAIN
main()
{
	setlocale(LC_ALL, "");
	vMenu();
}	//FIN DE LA FUNCION MAIN
//-----------------------------------------------
//DEFINICION DE FUNCIONES CREADAS POR EL USUARIO
void vMenu()
{
	char cOpcion[2], cLinea[20]; int iOpcion, n;
	do
	{
		vVaciarCadena(cLinea);
		printf(">>");
		//ENTRADA DE COMANDOS
		scanf("%[^\n]", cLinea);
		n=strlen(cLinea);
		if(cLinea[0]!='\0')
		{
			Linea=(char*)malloc(n*sizeof(cLinea)+1);
			strcpy(Linea, cLinea);
			Linea[n]=' '; n++;
			vSeparar(n);
			printf("\n");
		}
		fflush(stdin);
	}while(!strcmp(cLinea, EXIT)==0);
	system("EXIT");
}	//FIN DE LA FUNCIÓN vMenu
//-----------------------------------------------
void vSeparar(int n)
{
	int NumPalabras=iContarPalabras(n);
	p=(palabras*)malloc(NumPalabras*(sizeof(palabras)));
	vSepararInstrucciones(NumPalabras, n);
}	//FIN DE LA FUNCIÓN vSeparar
//-----------------------------------------------
void vSepararInstrucciones(int NumPalabras, int n){
	char palabra[20], temp; int indice=0, i=0;
	vVaciarCadena(palabra);
	for(auto int j=0; j<n; j++)
	{
		temp=Linea[j];
		if(temp==' ')
		{
			p[indice].palabra=(char*)malloc((i+1)*sizeof(char));
			strcpy(p[indice].palabra, palabra);
			indice++;
			vVaciarCadena(palabra);
			i=0;
		}	//FIN DEL IF
		else{
			palabra[i]=temp;
			i++;
		}
	}//FIN DEL FOR
	for(auto int i=0; i<NumPalabras; i++)
	{
		printf("PALABRA: %s\n", p[i].palabra);
	}
}	//Fin de la Funcion vSepararInstrucciones
//-----------------------------------------------
int iContarPalabras(int n)
{
	int palabras=0;
	for(int i=0; i<n;i++)
	{
		if(Linea[i]==' '){
			palabras++;
		}
	}
	return palabras;
}	//FIN DE LA FUNCIÓN iContarPalabras
//-----------------------------------------------
void vVaciarCadena(char aux[])
{
	for(auto int i=0; i<20; i++)
	{
		aux[i]='\0';
	}
}
