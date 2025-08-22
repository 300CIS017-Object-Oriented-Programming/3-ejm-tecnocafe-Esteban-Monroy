//
// Created by lenovo on 20/08/2025.
//
#include "Cafe.h"

void mostrarCartaProductos()
{
    cout << "\n--- Carta de productos ---\n";
    cout << "1. Tinto        $" << PRECIO_TINTO << "\n";
    cout << "2. Cappuccino   $" << PRECIO_CAPPUCCINO << "\n";
    cout << "3. Pandebono    $" << PRECIO_PANDEBONO << "\n";
    cout << "4. Sandwich     $" << PRECIO_SANDWICH << "\n";
    cout << "5. Empanada     $" << PRECIO_EMPANADA << "\n";
    cout << "6. Papa Rellena $" << PRECIO_PAPA_RELLENA << "\n";
}

int leerCodigoProducto()
{
    cout << "Ingrese el codigo del producto (1-6): ";
    int codigo;
    cin >> codigo;
    while (codigo < 1 || codigo > 6)
    {
        cout << "Codigo inválido. Intente de nuevo (1-6): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadProducto()
{
    cout << "Ingrese la cantidad (1-20): ";
    int cantidad;
    cin >> cantidad;
    while (cantidad < 1 || cantidad > 20)
    {
        cout << "Cantidad invalida. Intente de nuevo (1-20): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidad;
    }
    return cantidad;
}

int obtenerPrecioPorCodigo(int codigoProducto)
{
    int precio = 0;
    switch (codigoProducto)
    {
        case 1: precio = PRECIO_TINTO; break;
        case 2: precio = PRECIO_CAPPUCCINO; break;
        case 3: precio = PRECIO_PANDEBONO; break;
        case 4: precio = PRECIO_SANDWICH; break;
        case 5: precio = PRECIO_EMPANADA; break;
        case 6: precio = PRECIO_PAPA_RELLENA; break;
        default: precio = 0; break;
    }

    if (precio < 0) {
        cout << "Error: precio invalido detectado.\n";
        return 0;
    }
    return precio;
}

string obtenerNombreProducto(int codigoProducto)
{
    switch (codigoProducto)
    {
        case 1: return "Tinto";
        case 2: return "Cappuccino";
        case 3: return "Pandebono";
        case 4: return "Sándwich";
        case 5: return "Empanada";
        case 6: return "Papa Rellena";
        default: return "Desconocido";
    }
}

void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados >= MAX_ITEMS)
    {
        cout << "No es posible registrar más ítems en el pedido.\n";
        return;
    }
    mostrarCartaProductos();
    int codigo = leerCodigoProducto();
    int cantidad = leerCantidadProducto();

    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {
            cantidades[i] += cantidad;
            cout << "Producto actualizado: " << obtenerNombreProducto(codigo)
                 << " x" << cantidades[i] << " (cantidad acumulada)\n\n";
            return;
        }
    }

    codigos[cantidadItemsRegistrados] = codigo;
    cantidades[cantidadItemsRegistrados] = cantidad;
    cantidadItemsRegistrados++;

    cout << "Producto agregado: " << obtenerNombreProducto(codigo)
         << " x" << cantidad << "\n\n";
}

double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        int precioUnitario = obtenerPrecioPorCodigo(codigos[i]);
        subtotal += precioUnitario * cantidades[i];
    }
    return subtotal;
}

int leerTipoUsuario()
{
    cout << "Tipo de usuario (1=Estudiante, 2=Profesor, 3=Visitante, 4=Administrativo): ";
    int tipo;
    cin >> tipo;
    while (tipo < 1 || tipo > 4)
    {
        cout << "Opción inválida. Intente de nuevo (1-4): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoUsuario)
{
    if (tipoUsuario == 1) return DESCUENTO_ESTUDIANTE;
    if (tipoUsuario == 2) return DESCUENTO_PROFESOR;
    if (tipoUsuario == 3) return DESCUENTO_VISITANTE;
    if (tipoUsuario == 4) return DESCUENTO_ADMIN;
    return 0.0;
}

double calcularTotal(double subtotal, double porcentajeDescuento)
{
    return subtotal * (1.0 - porcentajeDescuento);
}

void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento)
{
    cout << "\n===== Resumen del Pedido =====\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        string nombre = obtenerNombreProducto(codigos[i]);
        int precio = obtenerPrecioPorCodigo(codigos[i]);
        double parcial = precio * cantidades[i];
        subtotal += parcial;
        cout << "- " << nombre << " x" << cantidades[i] << " = $" << parcial << "\n";
    }
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento aplicado: " << (porcentajeDescuento * 100) << "%\n";
}

void prediligenciarProductosDemo(int codigos[], int cantidades[], int & cantidadItemsRegistrados)
{
    cantidadItemsRegistrados = 0;

    codigos[0] = 1; cantidades[0] = 2;  // Tinto
    codigos[1] = 3; cantidades[1] = 3;  // Pandebono
    codigos[2] = 4; cantidades[2] = 1;  // Sandwich
    codigos[3] = 2; cantidades[3] = 2;  // Cappuccino
    codigos[4] = 5; cantidades[4] = 4;  // Empanada
    codigos[5] = 6; cantidades[5] = 2;  // Papa Rellena

    cantidadItemsRegistrados = 6;

    cout << "\nSe han cargado productos de ejemplo en el pedido:\n";
    cout << "- 2 Tintos\n";
    cout << "- 3 Pandebonos\n";
    cout << "- 1 Sándwich\n";
    cout << "- 2 Cappuccinos\n";
    cout << "- 4 Empanadas\n";
    cout << "- 2 Papas Rellenas\n\n";
}

void mostrarProductoMasCaro(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados == 0)
    {
        cout << "\nNo hay productos en el pedido.\n";
        return;
    }

    int codigoMasCaro = codigos[0];
    int precioMasCaro = obtenerPrecioPorCodigo(codigos[0]);

    for (int i = 1; i < cantidadItemsRegistrados; i++)
    {
        int precio = obtenerPrecioPorCodigo(codigos[i]);
        if (precio > precioMasCaro)
        {
            precioMasCaro = precio;
            codigoMasCaro = codigos[i];
        }
    }

    cout << "\nProducto más caro: " << obtenerNombreProducto(codigoMasCaro)
         << " ($" << precioMasCaro << ")\n";
}

void eliminarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados == 0)
    {
        cout << "\nNo hay productos para eliminar.\n";
        return;
    }

    int codigo;
    cout << "Ingrese el código del producto a eliminar: ";
    cin >> codigo;

    int indice = -1;
    for (int i = 0; i < cantidadItemsRegistrados; i++)
    {
        if (codigos[i] == codigo)
        {
            indice = i;
            break;
        }
    }

    if (indice == -1)
    {
        cout << "Producto no encontrado en el pedido.\n";
        return;
    }

    for (int i = indice; i < cantidadItemsRegistrados - 1; i++)
    {
        codigos[i] = codigos[i + 1];
        cantidades[i] = cantidades[i + 1];
    }
    cantidadItemsRegistrados--;

    cout << "Producto eliminado correctamente.\n";
}
