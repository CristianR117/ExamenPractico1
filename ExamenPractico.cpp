#include <iostream>

using namespace std;

struct Elemento{
    int codigo;
    string nombre;
    float longitud;
    float cargas[3];
    float capMAx;
    float facUt;
    string estSeg;
};
const int elementosMAx = 10;

void registrarElemento(Elemento &elemento){

    cout<<"***Bienvenido al registro de elementos***"<<endl;
    cout<<"Ingrese el codigo: "<<endl;
    cin>>ws>> elemento.codigo;
    cout<<"Ingrese el nombre: "<<endl;
    cin>> elemento.nombre;
    cout<<"Ingrese su longitud: "<<endl;
    cin>> elemento.longitud;
    
    for(int i = 1; i <= 3; i++)
    {
        cout<<"Ingrese la carga "<<i<<" (en Newtons): "<<endl;
        cin>> elemento.cargas[i];
    }

    cout<<"Ingrese la capacidad maxima: "<<endl;
    cin>> elemento.capMAx;
}

void maxElem()
{
    int cant = 0;

    do
    {
        cout<<"Ingrese la cantidad de elementos (Max. 10): ";
        cin>>cant;

       if(cant > elementosMAx)
       {
        cout<<"Cantidad de elementos invalido, intente de nuevo"<<endl;
       } 
       
    } while (cant > 10 || cant < 1);

    for(int i = 0; i < cant; i++)
    {
        Elemento elem;
        registrarElemento(elem);
    }
    
}

float calcularFactor(Elemento *elemento){
    float suma = 0;
    float *p = elemento ->cargas; //Recibir un puntero a un Elemento

    for(int i= 0; i<3; i++){
        suma += *p;
        p++;
    }

    float cargaProm = suma/3;

    float CalcFacUt = cargaProm / elemento->capMAx;

    elemento->facUt = CalcFacUt;

    return CalcFacUt;
}

void determinarSeguridad(Elemento &elemento){
    if(elemento.facUt > 0.00 && elemento.facUt <= 0.50 ){
        cout<<"SEGURO"<<endl;
    }
    else if(elemento.facUt > 0.50 && elemento.facUt <= 0.80 ){
        cout<<"PRECAUCION"<<endl;
    }
    else if(elemento.facUt > 0.80 && elemento.facUt <= 1.00 ){
        cout<<"RIESGO"<<endl;
    }
    else if(elemento.facUt > 1.00){
        cout<<"SOBRECARGA"<<endl;
    }
}



int main(){
    maxElem();

    return 0;
}