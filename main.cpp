#include <iostream>
#include "Cafe.h"
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

void mostrarMenuPrincipal()
{
    cout << "===== TecnoCafe - Menu Principal =====\n";
    cout << "1. Registrar producto al pedido\n";
    cout << "2. Ver subtotal del pedido\n";
    cout << "3. Finalizar y pagar\n";
    cout << "4. Prediligenciar productos de demostracion\n";
    cout << "5. Mostrar producto más caro\n";
    cout << "6. Eliminar producto del pedido\n";
    cout << "-1. Salir\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcionMenu()
{
    int opcion;
    cin >> opcion;
    while ((opcion < 1 || opcion > 6) && opcion != -1)
    {
        cout << "Opcion invalida. Intente de nuevo (1-6 o -1 para salir): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }
    return opcion;
}

int main()
{
    int codigos[MAX_ITEMS] = {0};
    int cantidades[MAX_ITEMS] = {0};
    int cantidadItemsRegistrados = 0;

    int opcion = 0;
    do
    {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion)
        {
            case 1:
                registrarProducto(codigos, cantidades, cantidadItemsRegistrados);
                break;
            case 2:
            {
                double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
                cout << fixed << setprecision(2);
                cout << "\nSubtotal actual: $" << subtotal << "\n\n";
                break;
            }
            case 3:
            {
                if (cantidadItemsRegistrados == 0)
                {
                    cout << "\nNo hay productos en el pedido.\n\n";
                    break;
                }
                double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
                int tipoUsuario = leerTipoUsuario();
                double porcentajeDescuento = obtenerPorcentajeDescuento(tipoUsuario);
                mostrarResumenPedido(codigos, cantidades, cantidadItemsRegistrados, porcentajeDescuento);
                double total = calcularTotal(subtotal, porcentajeDescuento);
                cout << fixed << setprecision(2);
                cout << "Total a pagar: $" << total << "\n\n";
                break;
            }
            case 4:
                prediligenciarProductosDemo(codigos, cantidades, cantidadItemsRegistrados);
                break;
            case 5:
                mostrarProductoMasCaro(codigos, cantidades, cantidadItemsRegistrados);
                break;
            case 6:
                eliminarProducto(codigos, cantidades, cantidadItemsRegistrados);
                break;
            case -1:
                cout << "\nSaliendo del sistema. ¡Hasta pronto!\n";
                break;
        }
    }
    while (opcion != -1);

    return 0;
}
