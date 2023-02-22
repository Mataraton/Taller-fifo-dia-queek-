#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Paciente {
public:
    Paciente(string nombre, string documento) {
        this->nombre = nombre;
        this->documento = documento;
    }

    string getNombre() {
        return nombre;
    }

    string getDocumento() {
        return documento;
    }

private:
    string nombre;
    string documento;
};

int main() {
    queue<Paciente> pacientes; // Cola para almacenar los pacientes registrados
    int n;

    cout << "Ingrese el numero de pacientes a registrar: ";
    cin >> n;
    cin.ignore(); // Para ignorar el salto de línea dejado por el cin

    // Bucle para solicitar el nombre y el documento del paciente
    for (int i = 0; i < n; i++) {
        string nombre, documento;
        cout << "Ingrese el nombre del paciente " << i+1 << ": ";
        getline(cin, nombre);
        cout << "Ingrese el numero de documento del paciente " << i+1 << ": ";
        getline(cin, documento);

        // Creamos un objeto Paciente con la información ingresada y lo agregamos a la cola de pacientes
        Paciente paciente(nombre, documento);
        pacientes.push(paciente);
    }

    // Mostramos la lista de pacientes en orden de registro
    cout << "Lista de pacientes registrados:" << endl;
    int i = 1;
    while (!pacientes.empty()) {
        Paciente paciente = pacientes.front();
        pacientes.pop();
        cout << i << ". Nombre: " << paciente.getNombre() << ", Documento: " << paciente.getDocumento() << endl;
        i++;
    }

    return 0;
}