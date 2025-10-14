# PARCIAL-EJERCICIO4-WILLIAM

## Ejercicio a Realizar

### Ejercicio 4: Registro de Clientes y Ventas en una Panadería

**Caso de la vida real:**  
Una panadería desea llevar un registro de sus clientes frecuentes y las ventas realizadas. El dueño quiere saber quiénes son sus mejores clientes y qué productos se venden más.

---

### Requerimientos

- Permitir registrar hasta 3 clientes (nombre, teléfono y correo) y hasta 3 ventas (cliente, producto, cantidad y fecha) usando solo variables primitivas.
- Consultar el historial de ventas por cliente.
- Mostrar los productos más vendidos.
- Mostrar los clientes con más compras.
- **No se permite el uso de arreglos, listas, ni estructuras de datos compuestas.**

---

## ¿Qué hice?

Para este ejercicio, implementé un sistema simple para gestionar clientes y ventas en una panadería. Usé **C++** como lenguaje de programación y me aseguré de seguir las restricciones que especificaban que no debía usar estructuras de datos compuestas como arreglos o listas. El programa permite registrar hasta 3 clientes y 3 ventas, y tiene varias funcionalidades como consultar el historial de ventas por cliente, mostrar los productos más vendidos y mostrar los clientes con más compras.

### Funcionalidades implementadas:

1. **Registro de Clientes:**
   - El sistema permite registrar hasta 3 clientes. Cada cliente tiene un nombre, teléfono y correo.  
   - Para ingresar la información de los clientes, utilicé estructuras (`struct`) que me permitieron agrupar los datos relacionados de manera sencilla.

2. **Registro de Ventas:**
   - El sistema permite registrar hasta 3 ventas. Cada venta está asociada con un cliente y tiene información sobre el producto vendido, la cantidad de unidades y la fecha de la venta.
   - Las ventas se vinculan a los clientes mediante el nombre del cliente.

3. **Consulta del Historial de Ventas por Cliente:**
   - Esta funcionalidad permite al usuario consultar todas las ventas realizadas por un cliente específico. Muestra la información de cada venta, como el producto, la cantidad y la fecha de la venta.

4. **Mostrar los Productos Más Vendidos:**
   - El sistema calcula cuáles son los productos más vendidos y muestra el número total de unidades vendidas por cada producto.

5. **Mostrar los Clientes con Más Compras:**
   - El sistema calcula cuál es el cliente que ha comprado más productos en total (según la cantidad de productos comprados en cada venta) y lo muestra al usuario.

---

## ¿Cómo lo hice?

1. **Estructuras (`struct`) para Clientes y Ventas:**
   - Utilicé **estructuras** para almacenar la información de los clientes y las ventas. La estructura `Cliente` tiene campos para almacenar el nombre, teléfono y correo, mientras que la estructura `Venta` tiene campos para almacenar el nombre del cliente, el producto, la cantidad y la fecha de la venta.

2. **Captura de Entradas:**
   - Usé `cin >>` para capturar entradas simples, como el teléfono o la cantidad de productos. Sin embargo, para capturar entradas que pueden contener espacios (como el nombre del cliente o el nombre del producto), utilicé `getline(cin, variable)`.
   - También utilicé `cin.ignore()` para limpiar el buffer de entrada después de cada uso de `cin >>` y evitar problemas al capturar cadenas con espacios.

3. **Control de Flujo:**
   - Para garantizar que no se registraran más de 3 clientes o 3 ventas, utilicé **bucles `while`** que verifican cuántos clientes y ventas se han registrado y detienen la captura de nuevos datos cuando se alcanza el límite.
   - Para las consultas y visualizaciones de los productos más vendidos y los clientes con más compras, utilicé ciclos de **búsqueda y comparación** en los datos para encontrar los elementos más relevantes.

4. **No uso de Arreglos ni Listas:**
   - Dado que el requerimiento era **no utilizar estructuras de datos compuestas**, manejé cada entrada de cliente y venta como variables individuales, lo que me obligó a escribir el código de forma que solo se pudiera almacenar un número limitado de clientes y ventas (hasta 3 de cada uno).

---

## Errores y Soluciones

Durante el desarrollo del proyecto, me encontré con algunos problemas que tuve que solucionar. A continuación, explico los errores más relevantes y cómo los corregí:

### 1. **Problema con la lectura de entradas que contienen espacios:**
   - **Descripción del error:** Al usar `cin >>` para leer datos como el nombre del cliente o el nombre del producto, noté que el programa solo capturaba la primera palabra antes de un espacio. Esto causaba que nombres como "Juan Pérez" o productos como "Pan de ajo" no se leyeran correctamente.
   - **Solución:** Cambié el uso de `cin >>` por `getline(cin, variable)`, lo que me permitió capturar la entrada completa, incluyendo los espacios. Además, agregué `cin.ignore()` después de cada entrada para limpiar el buffer de entrada y evitar que quedaran caracteres extraños que interferían con las capturas posteriores.

### 2. **El programa seguía ejecutándose en segundo plano:**
   - **Descripción del error:** Al intentar ejecutar el programa varias veces, me encontré con el error "The program 'ejercicio' is already running". Esto ocurría porque el programa no se terminaba correctamente entre ejecuciones.
   - **Solución:** Aprendí que necesitaba detener el proceso en ejecución manualmente. Para ello, utilicé `Ctrl + C` en la terminal o, en algunos casos, recurrí al Administrador de Tareas en Windows o al comando `kill` en Linux/Mac para finalizar el proceso antes de volver a compilar.

### 3. **Problema con la compilación debido a la extensión del archivo:**
   - **Descripción del error:** Durante la compilación, el sistema no reconocía correctamente el archivo con la extensión `.C++`, lo que impedía compilarlo.
   - **Solución:** Renombré el archivo a `.cpp`, que es la extensión estándar para archivos C++, lo que resolvió el problema y permitió compilar el programa sin inconvenientes.

### 4. **No validación de la fecha de venta:**
   - **Descripción del error:** La fecha de venta se almacenaba como una cadena de texto sin ningún tipo de validación. Esto permitía que el usuario ingresara fechas de manera incorrecta, como "30/02/2025".
   - **Solución:** Aunque no se requería una validación estricta en este ejercicio, sería una mejora futura agregar una validación de fecha para asegurarse de que la entrada siga un formato consistente (como "DD/MM/AAAA").

---

## Conclusión

Este ejercicio me permitió aplicar varios conceptos fundamentales de programación en C++, como el uso de **estructuras** para organizar datos relacionados, la captura de **entradas de usuario** con `cin` y `getline()`, y el control de **flujos de ejecución** con ciclos y condiciones. Además, me permitió enfrentar varios desafíos comunes, como problemas con las entradas de texto y la gestión de procesos en ejecución.

Aunque el sistema es básico y solo maneja un número limitado de clientes y ventas, fue un excelente ejercicio para entender cómo organizar y gestionar datos en un programa simple. Las soluciones a los errores que encontré me ayudaron a mejorar mis habilidades en la depuración y el manejo de entradas y salidas en C++.
