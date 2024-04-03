#ifndef ARCHIVOSINSTRUMENTOS_H_INCLUDED
#define ARCHIVOSINSTRUMENTOS_H_INCLUDED
#include <cstring>
#include <iostream>
using namespace std;

class ArchivoInstrumentos:public Instrumentos{
   protected:
        char nombre[30];

    public:

     ArchivoInstrumentos(const char *n){
            strcpy(nombre, n);}
 bool bajaLogica();
int asignarId();
void agregarInstrumento();
void mostrarPorId();
Instrumentos leerInstrumento(int id);
bool modificarInstrumento(Instrumentos obj, int pos);
bool modificarNombre();
int buscarInstrumento(int id);
void mostrarRegistros();
};


bool ArchivoInstrumentos::modificarNombre(){///////////FALTA CORREGIR///////////

   Instrumentos obj;
    int ID;
    cout<<"INGRESE EL ID DEL INSTRUMENTO A MODIFICAR: ";
    cin>>ID;

    int pos = buscarInstrumento(ID);//BUSCO LA POSICION DEL OBJETO SI EXISTE O NO

    if(pos==-1){
        cout<<"NO EXISTE INSTRUMENTO CON ESE ID"<<endl;
        return false ;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerInstrumento(pos);
    if(obj.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    //MODIFICAMOS EL NOMBRE
    char nom[30];

    cout<<"INGRESE EL NUEVO NOMBRE: ";
      scanf("%s",nom);

    obj.setNombre(nom);

    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarInstrumento(obj, pos);

    return aux;
}


int ArchivoInstrumentos::buscarInstrumento(int id){
   Instrumentos obj;
    int pos=0;

    FILE *pInst;
    pInst=fopen(nombre, "rb");
    if(pInst==NULL){return -2;}

    while(fread(&obj, sizeof obj, 1, pInst)==1){
        if(obj.getId() == id){ ;
            fclose(pInst);
            return pos;
        }
      pos++;
    }
	fclose(pInst);

	return -1;
}
bool ArchivoInstrumentos::modificarInstrumento(Instrumentos obj, int pos){
    FILE *pInst;
    pInst = fopen(nombre, "rb+");
    fseek(pInst, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pInst);
    fclose(pInst);
    return aux;
}


void ArchivoInstrumentos::agregarInstrumento(){
    cout<<"*******AGREGAR REGISTROS*******"<<endl;
    Instrumentos obj;
    int id;
    FILE *pInst;

    pInst=fopen(nombre, "ab");
       if(pInst==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;    }

    id=asignarId();
    obj.Cargar(id);
	fwrite(&obj, sizeof (Instrumentos), 1, pInst);
	fclose(pInst);
}
void ArchivoInstrumentos::mostrarPorId(){
  Instrumentos obj;
    int id;
    cout<<"INGRESE EL ID A BUSCAR ";
    cin>>id;
    int pos=buscarInstrumento(id);

    obj=leerInstrumento(pos);

    if(obj.getId()==id){
        obj.Mostrar();
   }else{cout<<"EL ID NO EXISTE EN EL ARCHIVO"<<endl;}
}
Instrumentos ArchivoInstrumentos::leerInstrumento(int id){
   Instrumentos obj;

    FILE *pInst;
    pInst=fopen(nombre, "rb");
    if(pInst==NULL){
     cout<<"NO SE PUDO LEER POR GENERO"<<endl;
        return obj;}

    fseek(pInst, sizeof obj * id, 0);
    int aux=fread(&obj, sizeof obj, 1, pInst);

    fclose(pInst);
    if(aux==0){obj.setId(-1);}

    return obj;
}




int ArchivoInstrumentos::asignarId(){//busca el ultimo id y le suma 1
    Instrumentos obj;
    int idNuevo=1;
    FILE *pIns;
    pIns=fopen(nombre, "rb");
    if(pIns==NULL){
     cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
    }

    while(fread(&obj, sizeof obj, 1, pIns)==1){

     idNuevo=obj.getId()+1;}


   fclose(pIns);

    return idNuevo;
}
void ArchivoInstrumentos::mostrarRegistros(){
    cout<<"*******INSTRUMENTOS********"<<endl;
  Instrumentos obj;
    FILE *pInst;
    pInst=fopen(nombre, "rb");
    if(pInst==NULL){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return;
    }

	while(fread(&obj, sizeof obj, 1, pInst)==1){
        if(obj.getEstado()){
            obj.Mostrar();}
             cout<<endl;}

	fclose(pInst);
}
bool ArchivoInstrumentos::bajaLogica(){
   cout<<"*******ELIMINAR INSTRUMENTO*******"<<endl;
   Instrumentos obj;
    int id;
    cout<<"INGRESE EL ID A DAR DE BAJA: ";
    cin>>id;
    //BUSCAMOS EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarInstrumento(id);
    if(pos==-1){
        cout<<"NO EXISTE INSTRUMENTO CON ESE ID"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerInstrumento(pos);
   if(obj.getEstado()==false){
        cout<<"EL INSTRUMENTO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }
    //MODIFICAMOS EL CAMPO ESTADO (LO PONEMOS EN FALSE)
    obj.setEstado(false);
    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
   bool aux = modificarInstrumento(obj, pos);
    return aux;
}

#endif // ARCHIVOSINSTRUMENTOS_H_INCLUDED
