#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

#include <iostream>
using namespace std;

bool validarGenero(int g){
    Generos obj;
    bool encontro=false;
    FILE *pGen;
    pGen=fopen("Generos.dat", "rb");
    if(pGen==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return false;
    }

    while(fread(&obj, sizeof obj, 1, pGen)==1){
        if(obj.getId()==g){
            fclose(pGen);
       return true; }
	}

	if(encontro==false){
        cout<<"NO SE ENCONTRO GENERO CON ESE ID"<<endl;
       fclose(pGen);

        return false;}
}

bool validarInstrumentoPrincipal(int i){
  Instrumentos obj;
    bool encontro=false;
    FILE *pInst;
    pInst=fopen("Instrumentos.dat", "rb");
    if(pInst==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return false;
    }

    while(fread(&obj, sizeof obj, 1, pInst)==1){
        if(obj.getId()==i){
            fclose(pInst);
       return true; }
	}

	if(encontro==false){
        cout<<"NO SE ENCONTRO INSTRUMENTO CON ESE ID"<<endl;
       fclose(pInst);

        return false;}
}


#endif // FUNCIONESGLOBALES_H_INCLUDED
