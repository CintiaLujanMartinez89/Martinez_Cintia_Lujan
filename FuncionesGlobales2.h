#ifndef FUNCIONESGLOBALES2_H_INCLUDED
#define FUNCIONESGLOBALES2_H_INCLUDED

#include <iostream>
using namespace std;

bool validarPais(int p){
  Paises obj;
 bool encontro=false;
    FILE *pPais;
    pPais=fopen("Paises.dat", "rb");
    if(pPais==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return false;
    }

    while(fread(&obj, sizeof obj, 1, pPais)==1){
        if(obj.getId()==p){
            fclose(pPais);
       return true; }
	}

if(encontro==false){
        cout<<"NO SE ENCONTRO PAIS CON ESE ID"<<endl;
       fclose(pPais);

        return false;}
}



#endif // FUNCIONESGLOBALES2_H_INCLUDED
