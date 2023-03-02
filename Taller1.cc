#include <iostream>
#include <stdlib.h>

using namespace std;

struct Paciente {
    string nombre;
    int numero_documento;
    Paciente* siguiente; // apuntador al siguiente paciente en la lista
};

int main() {
    Paciente* inicio = NULL; // apuntador al inicio de la lista

    // bucle para ingresar pacientes
    char continuar = 's';
    while (continuar == 's') {
        // crear un nuevo paciente
        Paciente* nuevo_paciente = new Paciente;

        // solicitar datos del paciente
        cout << "Ingrese el nombre del paciente: ";
        getline(cin, nuevo_paciente->nombre);
        cout << "Ingrese el número de documento del paciente: ";
        cin >> nuevo_paciente->numero_documento;

        // agregar el paciente a la lista
        nuevo_paciente->siguiente = inicio;
        inicio = nuevo_paciente;

        // preguntar si desea ingresar otro paciente
        cout << "¿Desea ingresar otro paciente? (s/n): ";
        cin >> continuar;
        cin.ignore(); // ignorar el salto de línea dejado por cin
    }

    // mostrar lista de pacientes
    cout << "Lista de pacientes:" << endl;
    int num_paciente = 1;
    for (Paciente* p = inicio; p != NULL; p = p->siguiente) {
        cout << num_paciente << ". " << p->nombre << " (Documento: " << p->numero_documento << ")" << endl;
        num_paciente++;
    }

    // liberar memoria de la lista
    Paciente* p = inicio;
    while (p != NULL) {
        Paciente* temp = p;
        p = p->siguiente;
        delete temp;
    }

    return 0;
}
