#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

#include <iostream>



void menu ();
int puntoA ();

void puntoC ();

void puntoB();




void menu (){
 int opc;
    while(true){
            system("cls");
   cout<<"MENU REPORTES"<<endl;
   cout<<"------------------"<<endl;
   cout<<"1) PUNTO A"<<endl;
   cout<<"2) PUNTO B"<<endl;
   cout<<"3) PUNTO C"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"-------------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: puntoA();
                    break;
            case 2:puntoB();
                    break;
            case 3:puntoC();
                    break;
            case 0:
               return ;

            }
        cout<<endl;
        system("pause");
    }
}
///////////////////////////////////////////PUNTO A//////////////////////////////////////////////////

/*A partir de un nombre de país que se ingresa por teclado, generar un archivo con todos los géneros
 que tengan ese país como país de origen. Listar el archivo nuevo.*/
int buscarPais(char *);

 int buscarPais(char *nombre){
    int pos=0;
Paises obj;
    FILE *pI;
    pI=fopen("Paises.dat", "rb");
    if(pI==NULL){return -2;}

    while(fread(&obj, sizeof obj, 1, pI)==1){
        if( strcmp(obj.getNombre(), nombre)==0){

            pos=obj.getId();

            fclose(pI);
            return pos;
        }
      pos++;
    }
	fclose(pI);
	return -1;
 }
int puntoA (){
 // Instrumentos obj;
  Generos obj1;
   char nombre[30];
    cout<<"INGRESE EL NOMBRE DEL PAIS: ";
    cargarCadena(nombre,30);

 int id= buscarPais(nombre);//MANDO EL NOMBRE PARA QUE BUSQUE EL ID DEL INSTRUMENTO

  //abro el archivo musicos
  FILE *pGen,*m; ;
    pGen=fopen("Generos.dat", "rb");
    if(pGen==NULL){
        return 0;
    }
    //CREO EL ARCHIVO PARA LOS DATOS NUEVOS
      m=fopen("generosXPaises.dat", "wb+");
    if(m==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return 0;}

    while(fread(&obj1, sizeof obj1, 1, pGen)==1){

        if(obj1.getPais()==id){

                  fwrite(&obj1,sizeof obj1,1,m);
                   }
                    }
	fclose(pGen);
    fclose(m);

 m=fopen("generosXPaises.dat", "rb");
    if(m==NULL){
        cout<<"NO SE PUDO ABBRIR EL ARCHIVO"<<endl;
        return 0;}
cout<<"LOS GENEROS CON EL PAIS DE ORIGEN "<<nombre<<" :"<<endl;

 while(fread(&obj1, sizeof obj1, 1, m)==1){
    obj1.Mostrar();
    cout<<endl;}
     fclose(m);

    }
//}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////PUNTO C//////////////////////////////////////////////////////////////
/*HACER UN LISTADO DE LOS GENEROS MUSICALES CON AÑO DE ORIGEN POSTERIOR A 2000 USANDO ASIGNACION DIN DE MEM*/

int contarRegistro();

int contarRegistros(){
    Generos obj;
FILE *p;
p=fopen("Generos.dat","rb");
if(p==NULL){ return 0;}

int contador=0;
while(fread(&obj, sizeof obj, 1, p)==1){
 if(obj.getAnioOrigen()>2000){contador=contador+1;}
}
fclose(p);
return contador; //devuelve la cantidad de registro
}


void puntoC (){
FILE *p;
Generos obj;

Generos  (*genPos2000);
int cantObj;
cantObj=contarRegistros();

genPos2000=new Generos [cantObj];

if(genPos2000==NULL){
 cout<<"Error de asignación de memoria"<<endl;
 system("pause");
 return;
}


{
int f;
for(f=0;f<cantObj;f++)

		genPos2000[f]={};

}


p=fopen("Generos.dat", "rb");
if(p==NULL){
 cout<<"ERROR DE ARCHIVO"<<endl;
return;
 }

 int i=0;
while(fread(&obj, sizeof obj, 1, p)==1){
 if(obj.getAnioOrigen()>2000){

      genPos2000[i]=obj;
     i++;

            } }



cout<<"LOS GENEROS MUSICALES CON AÑO DE ORIGEN POSTERIOR A 2000 SON: "<<endl;

for(int x=0;x<cantObj;x++){

            genPos2000[x].Mostrar();
	}
fclose(p);
delete genPos2000;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////PUNTO B///////////////////////////////////////////////////////////

/*Informar, por cada país, la cantidad de géneros musicales que no son originarios
de Europa (los países de Europavan desde el 20 hasta el 40 inclusive).*/

int contarRegistrosB();

int contarRegistrosB(){
FILE *p;
p=fopen("paises.dat","rb");
if(p==NULL){ return 0;}
fseek(p,0,2);
int tam=ftell(p); //ftell devuelve la cantidad de bytes q hay entre el principio del archivo y la posicion del puntero

fclose(p);
return tam/sizeof(Paises); //devuelve la cantidad de registro
}






void puntoB(){
FILE *p;
Generos obj;
Paises obj1;
int *generosSinEuropa;
int cantObj;
cantObj=contarRegistrosB();

generosSinEuropa=new int[cantObj];


if(generosSinEuropa==NULL){
 cout<<"Error de asignación de memoria"<<endl;
 system("pause");
 return ;
}



for(int f=0;f< cantObj;f++){////PONGO EN CERO EL VECTOR

		generosSinEuropa[f]=0;}

FILE *pPais;

pPais=fopen("paises.dat", "rb");
if(p==NULL){
 cout<<"ERROR DE ARCHIVO"<<endl;
return ;}


p=fopen("Generos.dat", "rb");
if(p==NULL){
 cout<<"ERROR DE ARCHIVO"<<endl;
return;
 }
 int i=0;
while(fread(&obj, sizeof obj, 1, p)==1){
 if(obj.getPais()!=3){
         if(obj.getPais()!=4){

  generosSinEuropa[obj.getPais()-1]++;
}
        }}



cout<<"POR CADA PAíS, LA CANTIDAD DE GéNEROS MUSICALES QUE NO SON ORIGINARIOS DE EUROPA: "<<endl;
int x;
for(x=0;x<cantObj;x++){

          cout<<"PAIS "<<x+1<<": ";

            cout<<generosSinEuropa[x]<<" GENEROS"<<endl;
        }

fclose(pPais);
fclose(p);
delete generosSinEuropa;

}


#endif // REPORTES_H_INCLUDED
