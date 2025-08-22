//
// Created by lenovo on 20/08/2025.
//

#ifndef CAFE_H
#define CAFE_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

// --- Constantes de precios ---
/**
 * @brief Precio del producto Tinto.
 */
const int PRECIO_TINTO = 1500;

/**
 * @brief Precio del producto Cappuccino.
 */
const int PRECIO_CAPPUCCINO = 4500;

/**
 * @brief Precio del producto Pandebono.
 */
const int PRECIO_PANDEBONO = 3000;

/**
 * @brief Precio del producto Sándwich.
 */
const int PRECIO_SANDWICH = 8500;

/**
 * @brief Precio del producto Empanada.
 */
const int PRECIO_EMPANADA = 1800;

/**
 * @brief Precio del producto Papa Rellena.
 */
const int PRECIO_PAPA_RELLENA = 4000;

// --- Descuentos (% expresado de 0.0 a 1.0) ---
/**
 * @brief Descuento aplicado a estudiantes (10%).
 */
const double DESCUENTO_ESTUDIANTE = 0.10;

/**
 * @brief Descuento aplicado a profesores (5%).
 */
const double DESCUENTO_PROFESOR = 0.05;

/**
 * @brief Descuento aplicado a visitantes (0%).
 */
const double DESCUENTO_VISITANTE = 0.00;

/**
 * @brief Descuento aplicado a administrativos (15%).
 */
const double DESCUENTO_ADMIN = 0.15;

/**
 * @brief Máximo número de ítems distintos que se pueden registrar en un pedido.
 */
const int MAX_ITEMS = 50;

// --- Declaraciones de funciones ---
void mostrarCartaProductos();
int leerCodigoProducto();
int leerCantidadProducto();
int obtenerPrecioPorCodigo(int codigoProducto);
string obtenerNombreProducto(int codigoProducto);
void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados);
double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados);
int leerTipoUsuario();
double obtenerPorcentajeDescuento(int tipoUsuario);
double calcularTotal(double subtotal, double porcentajeDescuento);
void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento);
void prediligenciarProductosDemo(int codigos[], int cantidades[], int& cantidadItemsRegistrados);

/**
 * @brief Muestra el producto más caro del pedido.
 */
void mostrarProductoMasCaro(const int codigos[], const int cantidades[], int cantidadItemsRegistrados);

/**
 * @brief Elimina un producto del pedido dado su código.
 */
void eliminarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados);

#endif //CAFE_H
