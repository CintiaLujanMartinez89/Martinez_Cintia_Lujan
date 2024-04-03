#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include <iostream>

using namespace std;

class Archivos{
protected:
  char nombre[30];

    public:

     Archivos(const char *n){
            strcpy(nombre, n);}
//////////////////DECLARACION DE FUNCIONES/////////////////
            bool copiaSeguridadMusicos();
            bool copiaSeguridadGeneros();
             bool copiaSeguridadInstrumentos();

              bool copiaSeguridadPaises();
            bool restaurarMusicos();
            bool restaurarGeneros();
            bool restaurarInstrumentos();
            bool restaurarPaises();
            bool establecerDatosInicioM();
              bool establecerDatosInicioG();
              bool establecerDatosInicioI();
              bool establecerDatosInicioP();
};

 bool Archivos::copiaSeguridadPaises(){
    Paises obj;
     FILE *cPais,*cBkp;
     cPais=fopen(ARCHIVO_PAISES,"rb");
     if(cPais==NULL){
        cout<<"NO DE PUDO LEER EL ARCHIVO"<<endl;
        return false;
     }
    cBkp=fopen(ARCHIVO_CONFIGURACIONES_PAISES,"wb");
     if(cBkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(cPais);
        return false;}
      while(fread(&obj,sizeof obj,1,cPais)==1){
        fwrite(&obj,sizeof obj,1,cBkp);
    }
    fclose(cPais);
    fclose(cBkp);
    return true;
 }


 bool Archivos::copiaSeguridadInstrumentos(){
     Instrumentos obj;
     FILE *cInst,*cBkp;
     cInst=fopen(ARCHIVO_INSTRUMENTOS,"rb");
     if(cInst==NULL){
        cout<<"NO DE PUDO LEER EL ARCHIVO"<<endl;
        return false;
     }
    cBkp=fopen(ARCHIVO_CONFIGURACIONES_INSTRUMENTOS,"wb");
     if(cBkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(cInst);
        return false;}
      while(fread(&obj,sizeof obj,1,cInst)==1){
        fwrite(&obj,sizeof obj,1,cBkp);
    }
    fclose(cInst);
    fclose(cBkp);
    return true;
 }

bool Archivos::copiaSeguridadMusicos(){
   Musicos obj;
    FILE *cMus,*cBkp;
    cMus=fopen(ARCHIVO_MUSICOS,"rb");
    if(cMus==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return false;
    }
    cBkp=fopen(ARCHIVO_CONFIGURACIONES_MUSICOS,"wb");
    if(cBkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(cMus);
        return false;}

    while(fread(&obj,sizeof obj,1,cMus)==1){
        fwrite(&obj,sizeof obj,1,cBkp);
    }
    fclose(cMus);
    fclose(cBkp);
    return true;
}

  bool Archivos::copiaSeguridadGeneros(){
   Generos obj;
    FILE *cGen,*cBkp;
    cGen=fopen(ARCHIVO_GENEROS,"rb");
    if(cGen==NULL){
        cout<<"NO SE PUDO LEER EL ARCHIVO"<<endl;
        return false;
    }
    cBkp=fopen(ARCHIVO_CONFIGURACIONES_GENEROS,"wb");
    if(cBkp==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        fclose(cGen);
        return false;}

    while(fread(&obj,sizeof obj,1,cGen)==1){
        fwrite(&obj,sizeof obj,1,cBkp);
    }
    fclose(cGen);
    fclose(cBkp);
    return true;
  }

   bool Archivos::restaurarInstrumentos(){
   Instrumentos obj;
    FILE *cInst,*cBkp;
    cInst=fopen(ARCHIVO_INSTRUMENTOS,"wb");
    if(cInst==NULL){
        cout<<"NO SE PUDO RESTURAR EL ARCHIVO INSTRUMENTOS.DAT"<<endl;
        return false;
    }
     cBkp=fopen(ARCHIVO_CONFIGURACIONES_INSTRUMENTOS,"rb");
    if(cBkp==NULL){
        cout<<"NO SE PUDO RESTAURAR ARCHIVO"<<endl;
        fclose(cInst);
        return false;}

          while(fread(&obj,sizeof obj,1,cBkp)==1){
                if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,cInst);}
    }
    fclose(cInst);
    fclose(cBkp);
    return true;
   }




    bool Archivos:: restaurarPaises(){
     Paises obj;
    FILE *cPais,*cBkp;
    cPais=fopen(ARCHIVO_PAISES,"wb");
    if(cPais==NULL){
        cout<<"NO SE PUDO RESTAURAR EL ARCHIVO PAISES.DAT"<<endl;
        return false;
    }
     cBkp=fopen(ARCHIVO_CONFIGURACIONES_PAISES,"rb");
    if(cBkp==NULL){
        cout<<"NO SE PUDO RESTAURAR ARCHIVO"<<endl;
        fclose(cPais);
        return false;}

          while(fread(&obj,sizeof obj,1,cBkp)==1){
                if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,cPais);}
    }
    fclose(cPais);
    fclose(cBkp);
    return true;
    }


   bool Archivos::restaurarMusicos(){
   Musicos obj;
    FILE *cMus,*cBkp;
    cMus=fopen(ARCHIVO_MUSICOS,"wb");
    if(cMus==NULL){
        cout<<"NO SE PUDO RESTURAR EL ARCHIVO MUSICOS.DAT"<<endl;
        return false;
    }
     cBkp=fopen(ARCHIVO_CONFIGURACIONES_MUSICOS,"rb");
    if(cBkp==NULL){
        cout<<"NO SE PUDO RESTAURAR ARCHIVO"<<endl;
        fclose(cMus);
        return false;}

          while(fread(&obj,sizeof obj,1,cBkp)==1){
                if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,cMus);}
    }
    fclose(cMus);
    fclose(cBkp);
    return true;
   }

     bool Archivos::restaurarGeneros(){
   Generos obj;
    FILE *cGen,*cBkp;
    cGen=fopen(ARCHIVO_GENEROS,"wb");
    if(cGen==NULL){
        cout<<"NO SE PUDO VACIAR EL ARCHIVO GENEROS.DAT"<<endl;
        return false;
    }
     cBkp=fopen(ARCHIVO_CONFIGURACIONES_GENEROS,"rb");
    if(cBkp==NULL){
        cout<<"NO SE PUDO RESTAURAR EL ARCHIVO"<<endl;
        fclose(cGen);
        return false;}

          while(fread(&obj,sizeof obj,1,cBkp)==1){
                if(obj.getEstado()==true){
        fwrite(&obj,sizeof obj,1,cGen);}
    }
    fclose(cGen);
    fclose(cBkp);
    return true;
   }

bool Archivos::establecerDatosInicioM(){
Musicos obj1;


  FILE *cMus,*datInicioMus;

     cMus=fopen(ARCHIVO_MUSICOS,"wb");
    if(cMus==NULL){cout<<"NO SE PUDO VACIAR EL ARCHIVO MUSICOS.DAT"<<endl;
                    return false;
    }

 datInicioMus=fopen("DatosInicioMusicos.dat","rb");
    if(datInicioMus==NULL){cout<<"NO SE PUDO CARGAR EL ARCHIVO"<<endl;
                            fclose(datInicioMus);
                            return false;}

    while(fread(&obj1,sizeof obj1,1,datInicioMus)==1){
          if(obj1.getEstado()==true){
                fwrite(&obj1,sizeof obj1,1,cMus);} }

    fclose(cMus);
    fclose(datInicioMus);
    return true;
}


 bool Archivos:: establecerDatosInicioI(){
    Instrumentos obj;
    FILE *cInst,*datInicioInst;
    cInst=fopen(ARCHIVO_INSTRUMENTOS,"wb");
    if(cInst==NULL){
        cout<<"NO SE PUEDO VACIAR EL ARCHIVO INSTRUMENTOS.DAT"<<endl;
            return false; }

        datInicioInst=fopen("DatosInicioInstrumentos.dat","rb");
        if(datInicioInst==NULL){cout<<"NO SE PUDO CARGAR EL ARCHIVO"<<endl;
                            fclose(datInicioInst);
                            return false;}
     while(fread(&obj,sizeof obj,1,datInicioInst)==1){

                fwrite(&obj,sizeof obj,1,cInst); }

    fclose(cInst);
    fclose(datInicioInst);
    return true;
 }

 bool Archivos::establecerDatosInicioP(){
   Paises obj;
    FILE *cPais,*datInicioPais;
    cPais=fopen(ARCHIVO_PAISES,"wb");
    if(cPais==NULL){
        cout<<"NO SE PUEDO VACIAR EL ARCHIVO PAISES.DAT"<<endl;
            return false; }

        datInicioPais=fopen("DatosInicioPaises.dat","rb");
        if(datInicioPais==NULL){cout<<"NO SE PUDO CARGAR EL ARCHIVO"<<endl;
                            fclose(datInicioPais);
                            return false;}
     while(fread(&obj,sizeof obj,1,datInicioPais)==1){

                fwrite(&obj,sizeof obj,1,cPais); }

    fclose(cPais);
    fclose(datInicioPais);
    return true;
 }


bool Archivos::establecerDatosInicioG(){
      Generos obj1;

     FILE *cGen,*datInicioGen;
      cGen=fopen(ARCHIVO_GENEROS,"wb");
    if(cGen==NULL){
        cout<<"NO SE PUDO VACIAR EL ARCHIVO GENEROS.DAT"<<endl;
        return false;
    }

    datInicioGen=fopen("DatosInicioGeneros.dat","rb");
    if(datInicioGen==NULL){cout<<"NO SE PUDO CARGAR EL ARCHIVO"<<endl;
                            fclose(datInicioGen);
                            return false;}

    while(fread(&obj1,sizeof obj1,1,datInicioGen)==1){

                fwrite(&obj1,sizeof obj1,1,cGen); }

    fclose(cGen);
    fclose(datInicioGen);
    return true;
      }
#endif // ARCHIVOS_H_INCLUDED
