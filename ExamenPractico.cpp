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
    
    for(int i = 0; i < 3; i++)
    {
        cout<<"Ingrese la carga "<<i + 1<<" (en Newtons): "<<endl;
        cin>> elemento.cargas[i];
    }

    cout<<"Ingrese la capacidad maxima: "<<endl;
    cin>> elemento.capMAx;
}

void maxElem(Elemento elementos[], int &cantidad)
{

    do
    {
        cout<<"Ingrese la cantidad de elementos (Max. 10): ";
        cin>>cantidad;

       if(cantidad > elementosMAx)
       {
        cout<<"Cantidad de elementos invalido, intente de nuevo"<<endl;
       } 
       
    } while (cantidad > elementosMAx || cantidad < 1);

    for(int i = 0; i < cantidad; i++)
    {
        registrarElemento(elementos[i]);
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
    if(elemento.facUt >= 0.00 && elemento.facUt <= 0.50 ){
        elemento.estSeg = "SEGURO";
    }
    else if(elemento.facUt > 0.50 && elemento.facUt <= 0.80 ){
        elemento.estSeg = "PRECAUCION";
    }
    else if(elemento.facUt > 0.80 && elemento.facUt <= 1.00 ){
        elemento.estSeg = "RIESGO";
    }
    else if(elemento.facUt > 1.00){
        elemento.estSeg = "SOBRECARGA";
    }
}

Elemento* obtenerElementoCritico(Elemento elementos[],int cantidad){
    Elemento *elementoCritico = &elementos[0];

    for(int i=1; i < cantidad; i++){
        if(elementos[i].facUt > elementoCritico->facUt){
            elementoCritico = &elementos[i];
        }
    }
    return elementoCritico;
}

void mostrarElemento(Elemento *elemento) {
    cout << "***elemento con mayor factor de utilizacion***" << endl;
    cout << "Codigo: " << elemento->codigo << endl;
    cout << "Nombre: " << elemento->nombre << endl;
    cout << "Longitud: " << elemento->longitud << endl;
    cout << "Carga 1: " << elemento->cargas[0] << endl;
    cout << "Carga 2: " << elemento->cargas[1] << endl;
    cout << "Carga 3: " << elemento->cargas[2] << endl;
    cout << "Capacidad maxima: " << elemento->capMAx << endl;
    cout << "Factor de utilizacion: " << elemento->facUt << endl;
    cout << "Estado: " << elemento->estSeg << endl;
}


int main(){
    Elemento elementos[elementosMAx];
    int cantidad;
    maxElem(elementos,cantidad);

    for(int i = 0; i < cantidad; i++){
        calcularFactor(&elementos[i]);
        determinarSeguridad(elementos[i]);
    }
    
    Elemento* elemComprometido = obtenerElementoCritico(elementos, cantidad);
    mostrarElemento(elemComprometido);

    return 0;
}