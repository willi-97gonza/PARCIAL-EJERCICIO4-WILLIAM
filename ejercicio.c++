#include <iostream>
#include <string>
using namespace std;

// Estructura para almacenar los datos de un cliente
struct Cliente {
    string nombre;
    string telefono;
    string correo;
};

// Estructura para almacenar los datos de una venta
struct Venta {
    string cliente;   // Nombre del cliente
    string producto;  // Producto vendido
    int cantidad;     // Cantidad de productos vendidos
    string fecha;     // Fecha de la venta
};

int main() {
    // Variables para almacenar hasta 3 clientes y 3 ventas
    Cliente clientes[3];
    Venta ventas[3];
    
    int numClientes = 0, numVentas = 0;
    
    // Registro de Clientes
    while (numClientes < 3) {
        cout << "Registro de Cliente #" << numClientes + 1 << endl;
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, clientes[numClientes].nombre); // Captura nombre con espacios
        cout << "Ingrese el teléfono del cliente: ";
        cin >> clientes[numClientes].telefono;
        cout << "Ingrese el correo del cliente: ";
        cin >> clientes[numClientes].correo;
        
        numClientes++;
        cout << endl;
    }

    // Registro de Ventas
    while (numVentas < 3) {
        cout << "Registro de Venta #" << numVentas + 1 << endl;
        cout << "Ingrese el nombre del cliente: ";
        cin.ignore(); // Limpiar el buffer de entrada
        getline(cin, ventas[numVentas].cliente); // Captura nombre con espacios
        cout << "Ingrese el producto vendido: ";
        getline(cin, ventas[numVentas].producto); // Captura el nombre del producto con espacios
        cout << "Ingrese la cantidad vendida: ";
        cin >> ventas[numVentas].cantidad;
        cout << "Ingrese la fecha de la venta: ";
        cin >> ventas[numVentas].fecha;
        
        numVentas++;
        cout << endl;
    }
    
    // Consulta de Historial de Ventas
    string clienteConsulta;
    cout << "Ingrese el nombre del cliente para consultar su historial de ventas: ";
    cin.ignore(); // Limpiar el buffer de entrada
    getline(cin, clienteConsulta); // Captura el nombre del cliente con espacios

    cout << "\nHistorial de ventas de " << clienteConsulta << ":\n";
    for (int i = 0; i < numVentas; i++) {
        if (ventas[i].cliente == clienteConsulta) {
            cout << "Producto: " << ventas[i].producto
                 << ", Cantidad: " << ventas[i].cantidad
                 << ", Fecha: " << ventas[i].fecha << endl;
        }
    }
    
    // Mostrar los productos más vendidos
    cout << "\nProductos más vendidos:\n";
    string productos[3];
    int cantidades[3] = {0, 0, 0};
    int numProductos = 0;
    
    for (int i = 0; i < numVentas; i++) {
        bool encontrado = false;
        for (int j = 0; j < numProductos; j++) {
            if (productos[j] == ventas[i].producto) {
                cantidades[j] += ventas[i].cantidad;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            productos[numProductos] = ventas[i].producto;
            cantidades[numProductos] = ventas[i].cantidad;
            numProductos++;
        }
    }
    
    for (int i = 0; i < numProductos; i++) {
        cout << "Producto: " << productos[i] << ", Cantidad vendida: " << cantidades[i] << endl;
    }

    // Mostrar los clientes con más compras
    cout << "\nClientes con más compras:\n";
    string clientesCompras[3];
    int compras[3] = {0, 0, 0};
    int numClientesCompras = 0;
    
    for (int i = 0; i < numVentas; i++) {
        bool encontrado = false;
        for (int j = 0; j < numClientesCompras; j++) {
            if (clientesCompras[j] == ventas[i].cliente) {
                compras[j] += ventas[i].cantidad;
                encontrado = true;
                break;
            }
        }
        if (!encontrado) {
            clientesCompras[numClientesCompras] = ventas[i].cliente;
            compras[numClientesCompras] = ventas[i].cantidad;
            numClientesCompras++;
        }
    }
    
    for (int i = 0; i < numClientesCompras; i++) {
        cout << "Cliente: " << clientesCompras[i] << ", Total comprado: " << compras[i] << " unidades." << endl;
    }

    return 0;
}
