//CINTIA LUJAN MARTINEZ
#include <iostream>
#include <cstring>
#include <time.h>
#include <wchar.h>
#include <locale>
#include <string.h>
#include <stdio.h>

using namespace std;

const char *ARCHIVO_MUSICOS="Musicos.dat";
const char *ARCHIVO_GENEROS="Generos.dat";
const char *ARCHIVO_CONFIGURACIONES_MUSICOS="Musicos.bkp";
const char *ARCHIVO_CONFIGURACIONES_GENEROS="Generos.bkp";
const char *ARCHIVO_INSTRUMENTOS="instrumentos.dat";
const char *ARCHIVO_PAISES= "paises.dat";
const char *ARCHIVO_CONFIGURACIONES_INSTRUMENTOS="intrumentos.bkp";
const char *ARCHIVO_CONFIGURACIONES_PAISES  ="paises.bkp";


void cargarCadena(char *pal,int tam){
    int i;
    fflush(stdin);
    for(i=0;i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n') break;
    }
    pal[i]='\0';
    fflush(stdin);
}
#include "Fecha.h"
#include "Instrumentos.h"
#include "Paises.h"
#include "FuncionesGlobales2.h"
#include "Generos.h"
#include "FuncionesGlobales.h"
#include "Persona.h"
#include "Musicos.h"
#include "ArchivoMusicos.h"
#include "ArchivoGeneros.h"
#include "ArchivosPaises.h"
#include "ArchivosInstrumentos.h"
#include "Archivos.h"
#include "Reportes.h"

void MenuMusicos();
void MenuGeneros();
void MenuInstrumentos();

void MenuPaises();
void MenuConfiguraciones();


int main()
{    setlocale(LC_ALL, "");


   int opc;
   while(true){
          system("cls");
   cout<<"  MENU PRINCIPAL"<<endl;
 cout<<"------------------"<<endl;
 cout<<"1) MENU MUSICOS"<<endl;
 cout<<"2) MENU GENEROS"<<endl;
 cout<<"3) MENU INTRUMENTOS"<<endl;
 cout<<"4) MENU PAISES"<<endl;
 cout<<"5) REPORTES"<<endl;
 cout<<"6)CONFIGURACIONES"<<endl;
 cout<<"--------------------------------"<<endl;
 cout<<"0) FIN DEL PROGRAMA"<<endl;
 cout<<"SELECCIONE UNA DE LAS OPCIONES:"<<endl;

     cin>>opc;
        system("cls");
        switch(opc){
            case 1: MenuMusicos();
                    break;
            case 2: MenuGeneros();
                    break;
            case 3:MenuInstrumentos();
                    break;
            case 4:MenuPaises();
                    break;
            case 5:menu();

                    break;
            case 6:MenuConfiguraciones();
                    break;
            case 0:
                return 0;
                break;
            }
    }
}

   void MenuMusicos(){
       ArchivoMusicos obj(ARCHIVO_MUSICOS);
    int opc;
    while(true){
            system("cls");

  cout<<"  MENU MUSICOS"<<endl;
  cout<<" ------------------"<<endl;
cout<<"1) AGREGAR MUSICOS"<<endl;
cout<<"2) LISTAR MUSICO POR DNI"<<endl;
cout<<"3) LISTAR TODOS LOS MUSICOS"<<endl;
cout<<"4) MODIFICAR FECHA DE INSCRIPCION"<<endl;
cout<<"5) ELIMINAR REGISTRO DE MUSICO"<<endl;
cout<<"--------------------------------"<<endl;
cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
cout<<"--------------------------------"<<endl;
 cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:// AGREGAR MUSICOS permitir ingresar de a un registro por vez
                obj.agregarRegistro();

                    break;
            case 2: //LISTAR MUSICO POR DNI  deberá solicitar el DNI y listar todos los campos del registro si
                    //éste existe, o informar si no existe.
                 obj.buscarPorDNI();
                    break;
            case 3: //LISTAR TODOS LOS MUSICOS deberá listar todos los registros
                obj.mostrarRegistros();
                    break;
            case 4:// MODIFICAR FECHA DE INSCRIPCION deberá pedir un DNI de músico y una fecha y cambiar la
                    //fecha de inscripción del músico con ese DNI.
                    obj.modificarFecha();
                    break;
            case 5:// ELIMINAR REGISTRO DE MUSICO  deberá solicitar el DNI y realizar la baja lógica.
                if(obj.bajaLogica()){
                        cout<<"MUSICO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;
                    }
                    break;

            case 0:
                return ;

        }
          cout<<endl;
        system("pause");
      }

  }

void MenuGeneros(){
 ArchivoGeneros obj(ARCHIVO_GENEROS);
    int opc;
    while(true){
            system("cls");
   cout<<"MENU GÉNEROS"<<endl;
   cout<<"------------------"<<endl;
   cout<<"1) AGREGAR GÉNERO"<<endl;
   cout<<"2) LISTAR GÉNERO POR ID"<<endl;
   cout<<"3) LISTAR TODO"<<endl;
   cout<<"4) MODIFICAR AÑO DE ORIGEN"<<endl;
   cout<<"5) ELIMINAR REGISTRO"<<endl;
   cout<<"--------------------------------"<<endl;
   cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"-------------------------------"<<endl;
        cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: obj.agregarRegistro();
                    break;
            case 2:obj.buscarPorId();
                    break;
            case 3:
                 obj.mostrarRegistros();
                    break;
            case 4: obj.modificarAnioOrigen();
                    break;
            case 5:if(obj.bajaLogica()){
                        cout<<"REGISTRO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;}

                    break;

            case 0:
               return ;



 }
  cout<<endl;
        system("pause");


 }}
void MenuInstrumentos(){
    ArchivoInstrumentos obj(ARCHIVO_INSTRUMENTOS);
     int opc;
    while(true){
            system("cls");
    cout<<"MENU INSTRUMENTOS"<<endl;
    cout<<"------------------"<<endl;
    cout<<"1) AGREGAR INSTRUMENTO"<<endl;
    cout<<"2) LISTAR INSTRUMENTO POR ID"<<endl;
    cout<<"3) LISTAR TODO"<<endl;
    cout<<"4) MODIFICAR NOMBRE"<<endl;
    cout<<"5) ELIMINAR REGISTRO"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:obj.agregarInstrumento();
                break;
            case 2:obj.mostrarPorId();
                    break;
            case 3:obj.mostrarRegistros();
                    break;
            case 4: obj.modificarNombre();
                    break;
            case 5:if(obj.bajaLogica()){
                        cout<<"REGISTRO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;};

                    break;

            case 0:
               return ;
 }
  cout<<endl;
        system("pause");

 }}

 void MenuPaises(){
    ArchivoPaises obj(ARCHIVO_PAISES);
     int opc;
    while(true){
            system("cls");
    cout<<"MENU PAISES"<<endl;
    cout<<"------------------"<<endl;
    cout<<"1) AGREGAR PAIS"<<endl;
    cout<<"2) LISTAR PAIS POR ID"<<endl;
    cout<<"3) LISTAR TODO"<<endl;
    cout<<"4) MODIFICAR NOMBRE"<<endl;
    cout<<"5) ELIMINAR REGISTRO"<<endl;
    cout<<"--------------------------------"<<endl;
    cout<<"0) VOLVER AL MENU PRINCIPAL"<<endl;
    cout<<"INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:obj.agregarPaises();
                break;
            case 2:obj.mostrarPorId();
                    break;
            case 3:obj.mostrarRegistros();
                    break;
            case 4: obj.modificarNombre();
                    break;
            case 5:if(obj.bajaLogica()){
                        cout<<"REGISTRO DADO DE BAJA CORRECTAMENTE"<<endl;
                    }else{
                        cout<<"NO SE PUDO REALIZAR LA BAJA"<<endl;}

                    break;

            case 0:
               return ;
 }
  cout<<endl;
        system("pause");

 }}



void MenuConfiguraciones(){
   Archivos objGeneros(ARCHIVO_CONFIGURACIONES_GENEROS);
   Archivos objMusicos(ARCHIVO_CONFIGURACIONES_MUSICOS);
 Archivos objInstrumentos(ARCHIVO_CONFIGURACIONES_INSTRUMENTOS);
  Archivos objPaises(ARCHIVO_CONFIGURACIONES_PAISES);
    int opc;
    while(true){
            system("cls");

  cout<<"MENÚ CONFIGURACIÓN"<<endl;
   cout<<"------------------"<<endl;
   cout<<"1) COPIA DE SEGURIDAD DEL ARCHIVO DE MUSICOS"<<endl;
  cout<<"2) COPIA DE SEGURIDAD DEL ARCHIVO DE GENEROS"<<endl;
   cout<<"3) COPIA DE SEGURIDAD DEL ARCHIVO DE INSTRUMENTOS"<<endl;
    cout<<"4) COPIA DE SEGURIDAD DEL ARCHIVO DE PAISES"<<endl;
   cout<<"5) RESTAURAR EL ARCHIVO DE MUSICOS"<<endl;
   cout<<"6) RESTAURAR EL ARCHIVO DE GENEROS"<<endl;
   cout<<"7) RESTAURAR EL ARCHIVO DE INSTRUMENTOS"<<endl;
   cout<<"8) RESTAURAR EL ARCHIVO DE PAISES"<<endl;
 cout<<"9) ESTABLECER DATOS DE INICIO"<<endl;
 cout<<"--------------------------------"<<endl;
  cout<<"0) VOLVER AL MENÚ PRINCIPAL"<<endl;
   cout<<"INGRESE UNA OPCION: ";
    cin>>opc;
        system("cls");
        switch(opc){
            case 1:{
               bool rta= objMusicos.copiaSeguridadMusicos();
               if(rta){cout<<"COPIA DE SEGURIDAD DE MUSICOS.DAT A SIDO REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA COPIA DE SEGURIDAD DE MUSICOS.DAT NO SE HA PODIDO REALIZAR";};}
                    break;
            case 2:{
               bool rta= objGeneros.copiaSeguridadGeneros();
               if(rta){cout<<"COPIA DE SEGURIDAD DE GENEROS.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA COPIA DE SEGURIDAD DE GENEROS.DAT NO SE HA PODIDO REALIZAR";};}
                    break;
             case 3:{
               bool rta= objInstrumentos.copiaSeguridadInstrumentos();
               if(rta){cout<<"COPIA DE SEGURIDAD DE INSTRUMENTOS.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA COPIA DE SEGURIDAD DE INSTRUMENTOS.DAT NO SE HA PODIDO REALIZAR";};}
                    break;
                case 4:{
               bool rta= objPaises.copiaSeguridadPaises();
               if(rta){cout<<"COPIA DE SEGURIDAD DE PAISES.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA COPIA DE SEGURIDAD DE PAISES.DAT NO SE HA PODIDO REALIZAR";};}
                    break;

            case 5:{bool rta=objMusicos.restaurarMusicos();
                      if(rta){cout<<"LA RESTAURACION DE MUSICOS.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA RESTAURACION MUSICOS.DAT NO SE HA PODIDO REALIZAR";};}
                    break;

             case 6:{bool rta=objGeneros.restaurarGeneros();
                      if(rta){cout<<"LA RESTAURACION DE GENEROS.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA RESTAURACION GENEROS.DAT NO SE HA PODIDO REALIZAR";};}
                    break;
              case 7:{bool rta=objInstrumentos.restaurarInstrumentos();
                      if(rta){cout<<"LA RESTAURACION DE INSTRUMENTOS.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA RESTAURACION INSTRUMENTOS.DAT NO SE HA PODIDO REALIZAR";};}
                    break;
               case 8:{bool rta=objPaises.restaurarPaises();
                      if(rta){cout<<"LA RESTAURACION DE PAISES.DAT REALIZADA CORRECTAMENTE";}
                   else{cout<<"LA RESTAURACION PAISES.DAT NO SE HA PODIDO REALIZAR";};}
                    break;

            case 9:{  bool datosInicioI= objInstrumentos.establecerDatosInicioI();
             if(datosInicioI){cout<<"LA CARGA DE DATOS DE INICIO INSTRUMENTOS FUE EXITOSA"<<endl;}
                   else{cout<<"LA CARGA DE DATOS DE INICIO INSTRUMENTOS NO SE HA PODIDO REALIZAR";};

                    bool datosInicioP= objPaises.establecerDatosInicioP();
             if(datosInicioP){cout<<"LA CARGA DE DATOS DE INICIO PAISES FUE EXITOSA"<<endl;}
                   else{cout<<"LA CARGA DE DATOS DE INICIO PAISES NO SE HA PODIDO REALIZAR";};


                bool datosInicioM= objMusicos.establecerDatosInicioM();
             if(datosInicioM){cout<<"LA CARGA DE DATOS DE INICIO MUSICOS FUE EXITOSA"<<endl;}
                   else{cout<<"LA CARGA DE DATOS DE INICIO MUSICOS NO SE HA PODIDO REALIZAR";};

                   bool datosInicioG= objGeneros.establecerDatosInicioG();
             if(datosInicioM){cout<<"LA CARGA DE DATOS DE INICIO GENEROS FUE EXITOSA"<<endl;}
                   else{cout<<"LA CARGA DE DATOS DE INICIO GENEROS NO SE HA PODIDO REALIZAR";};


                   }
                    break;

            case 0:
               return ;

            }
        cout<<endl;
        system("pause");
    }
}



