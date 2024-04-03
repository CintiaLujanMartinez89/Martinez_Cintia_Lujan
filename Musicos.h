#ifndef MUSICOS_H_INCLUDED
#define MUSICOS_H_INCLUDED

#include <iostream>

class Musicos: public Persona{
protected:

    int claustro;//(1: docente; 2 alumno; 3 no docente; 4 graduado)
    int instrumentoPrincipal;
    int tipoDeMusica;
    float matricula;


public:

    //////////////////GETS////////////////////////////

   int  getClaustro(){return claustro;}
   int getInstrumentoPrincipal(){return instrumentoPrincipal;}
   int getTipoDeMusica(){return tipoDeMusica;}
    float getMatricula(){return matricula;}


    ///////////////////SETTERS/////////////////////////

   void setClaustro(const int c){claustro=c;}
  void setInstrumentoPrincipal(const int inst){instrumentoPrincipal=inst;}
   void setTipoDeMusica(const int tMusi){tipoDeMusica=tMusi;}

    void setMatricula(const float mat){ matricula=mat;}

//////////////////metodos//////////////////////
 void Cargar(int);



};
  void Musicos::Cargar(int dni){
int c=0;
bool validado=false;
       Persona::Cargar(dni);///PONGO PERSONA PORQUE ES EL AMBITO DEL CARGAR QUE QUIERO LLAMAR
        cout<<"CLAUSTRO (1: docente; 2 alumno; 3 no docente; 4 graduado): ";
        cin>>claustro;
       while(((claustro<1) || (claustro>4))& (c<2)){
              cout<<"****INGRESE UN CLAUSTRO VALIDO (1: docente; 2 alumno; 3 no docente; 4 graduado): "<<endl;
               cin>>claustro;
               c++;
               if(c==2){return;}
        }

        cout<<"INSTRUMENTO PRINCIPAL : ";
        cin>>instrumentoPrincipal;
    validado= validarInstrumentoPrincipal(instrumentoPrincipal);
            if(validado==false){
                    return ;
        }

        cout<<"TIPO DE MUSICA: ";
        cin>>tipoDeMusica;
        validado= validarGenero(tipoDeMusica);
            if(validado==false){
            return ;
        }

        cout<<"MATRICULA: ";
            cin>>matricula;
        while (matricula<0){
            cout<<"****INGRESE UN MONTO DE MATRICULA MAYOR O IGUAL A CERO: "<<endl;
             cin>>matricula;
        }



}




#endif // MUSICOS_H_INCLUDED
