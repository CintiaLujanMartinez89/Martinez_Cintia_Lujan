#ifndef ARCHIVOMUSICOS_H_INCLUDED
#define ARCHIVOMUSICOS_H_INCLUDED


class ArchivoMusicos:public Musicos{
   protected:
        char nombre[30];

    public:

     ArchivoMusicos(const char *n){
            strcpy(nombre, n);}
//////////////////declaracion de funciones/////////////
        //ALTA
        void agregarRegistro();
        //BAJA
        int buscarMusico(int d);
        Musicos leerMusico(int p);
        bool bajaLogica();
        //MODIFICACION
        bool modificarFecha();
        //LISTADO/S
        void buscarPorDNI();
        bool modificarRegistro(Musicos obj, int p);
        void mostrarRegistros();

};

void ArchivoMusicos::agregarRegistro(){
    cout<<"*******AGREGAR REGISTROS*******"<<endl;
    Musicos obj;
    int DNI;

    FILE *pMus;
    pMus=fopen(nombre, "ab");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;}

    cout<<"DNI: ";
    cin>>DNI;
    int pos=buscarMusico(DNI);
    obj=leerMusico(pos);

    if(obj.getDNI()>0){
          cout<<"EL DNI YA EXISTE EN EL ARCHIVO"<<endl;
    }else if(obj.getDNI()==-3 || obj.getDNI()==-1){
        obj.Cargar(DNI);
        fwrite(&obj, sizeof (Musicos), 1, pMus);
        fclose(pMus);
}
    }


bool ArchivoMusicos::bajaLogica(){
   cout<<"*******ELIMINAR REGISTRO*******"<<endl;
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI A DAR DE BAJA: ";
    cin>>DNI;
    //BUSCAR EL REGISTRO EN EL ARCHIVO Y LO CARGAMOS EN MEMORIA
    int pos = buscarMusico(DNI);
    if(pos==-1){
        cout<<"NO EXISTE MUSICO CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerMusico(pos);
   if(obj.getEstado()==false){
        cout<<"EL MUSICO INGRESADO YA ESTA DADO DE BAJA"<<endl;
        return false;
    }

    obj.setEstado(false);
    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
   bool aux = modificarRegistro(obj, pos);
    return aux;
}

Musicos ArchivoMusicos::leerMusico(int p){
    Musicos obj;
    if(p<0){
        obj.setDNI(-3);
        return obj;
    }
    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
     obj.setDNI(-2);
        return obj;
    }
    fseek(pMus, sizeof obj * p, 0);
    int aux=fread(&obj, sizeof obj, 1, pMus);

    fclose(pMus);

    if(aux==0){
        obj.setDNI(-1); }
    return obj;
}

int ArchivoMusicos::buscarMusico(int d){
    Musicos obj;
    int pos=0;

    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        return -2;
    }
    while(fread(&obj, sizeof obj, 1, pMus)==1){

        if(obj.getDNI() == d){

            fclose(pMus);
            return pos;
        }
        pos++;
    }
	fclose(pMus);
	return -1;
}

void ArchivoMusicos::mostrarRegistros(){
    cout<<"*******REGISTROS*********"<<endl;
    Musicos obj;

    FILE *pMus;
    pMus=fopen(nombre, "rb");
    if(pMus==NULL){
        cout<<"NO SE PUDO CREAR EL ARCHIVO"<<endl;
        return;
    }


	while(fread(&obj, sizeof obj, 1, pMus)==1){

        if(obj.getEstado()){
           obj.Mostrar();
           cout<<"CLAUSTRO: ";
           cout <<obj.getClaustro()<<endl;
              cout<<"INTRUMENTO PRINCIPAL: ";
            //  cout<<obj.getInstrumentoPrincipal()<<endl;
/////////////////////////////////////////////////////////////////////////////////////////
      Instrumentos obj1;
     FILE *pInst;
    pInst=fopen("instrumentos.dat", "rb");

    if(pInst==NULL){
            return;}


    while(fread(&obj1, sizeof obj1, 1, pInst)==1){

        if( obj.getInstrumentoPrincipal()==obj1.getId()){
       cout<<obj1.getNombre()<<endl;

        }
    }

  fclose(pInst);
///////////////////////////////////////////////////////////////////////////////////////////
}

              cout<<"TIPO DE MUSICA: ";
              cout <<obj.getTipoDeMusica()<<endl;
              cout<<"MATRICULA: ";
              cout<<obj.getMatricula()<<endl;
              cout<<"............................."<<endl;
            }

fclose(pMus);
	}



bool ArchivoMusicos::modificarFecha(){

    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI DEL CLIENTE A MODIFICAR: ";
    cin>>DNI;

    int pos = buscarMusico(DNI);
    if(pos==-1){
        cout<<"NO EXISTE MUSICO CON ESE DNI"<<endl;
        return false;
    }
    if(pos==-2){
        cout<<"NO SE PUDO ABRIR EL ARCHIVO"<<endl;
        return false;
    }
    obj = leerMusico(pos);
    if(obj.getEstado()==false){
        cout<<"EL MUSICO INGRESADO ESTA DADO DE BAJA"<<endl;
        return false;
    }
    //MODIFICAMOS LA FECHA
    int dia,mes,anio;
    cout<<"INGRESE LA NUEVA FECHA: ";
    cout<<"DIA: ";
    cin>>dia;
    cout<<"MES: ";
    cin>>mes;
    cout<<"AÑO: ";
    cin>>anio;
    obj.setFechaDeInscripcion(dia,mes,anio);
    //SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO (EN LA MISMA POSICION QUE OCUPABA)
    bool aux = modificarRegistro(obj, pos);
    return aux;
}

bool ArchivoMusicos::modificarRegistro(Musicos obj, int pos){//SOBREESCRIBIR EL REGISTRO EN EL ARCHIVO
                                                            //(EN LA MISMA POSICION QUE OCUPABA)
    FILE *pMus;
    pMus = fopen(nombre, "rb+");
    fseek(pMus, sizeof obj * pos, 0);
    bool aux = fwrite(&obj, sizeof obj, 1, pMus);
    fclose(pMus);
    return aux;
}

void ArchivoMusicos::buscarPorDNI(){
    Musicos obj;
    int DNI;
    cout<<"INGRESE EL DNI A BUSCAR ";
    cin>>DNI;
    int pos=buscarMusico(DNI);
    obj=leerMusico(pos);

    if(obj.getDNI()>0){
        obj.Mostrar();
         cout<<"CLAUSTRO: ";
           cout <<obj.getClaustro()<<endl;
              cout<<"INTRUMENTO PRINCIPAL: ";
              cout<<obj.getInstrumentoPrincipal()<<endl;
              cout<<"TIPO DE MUSICA: ";
              cout <<obj.getTipoDeMusica()<<endl;
              cout<<"MATRICULA: ";
              cout<<obj.getMatricula()<<endl;
              cout<<"............................."<<endl;
    }else if(obj.getDNI()==-3 || obj.getDNI()==-1){

        cout<<"EL DNI NO EXISTE EN EL ARCHIVO"<<endl;
    }else{
        cout<<"ERROR DE ARCHIVO"<<endl;
    }
}


#endif // ARCHIVOMUSICOS_H_INCLUDED
