# Gestión de pedidos de una panadería


## Introducción
La panadería "Dulce Amanecer" vende productos exclusivamente por internet. Esta panedría esta dirigida a clientes que compren al por mayor (mas de 50 unidades en productos) especialmente para eventos o celebreaciones. Actualmente la panedería no cuenta con un sistema digital de gestion pedidos que tome nota de los productos que ofrece y que lleve cuenta de los pedidos que se han entregado o que todavía estan pendientes. Por ello la panadería desea implementar un software que lleve a cabo esta acción. Y que un operador de la panedería se encargue de ingresar los pedidos de forma manual en la computadora y así gestionar de forma eficiente sus ventas.

### Descripción general del sistema
El sistema presenta una interfaz sencilla en la que se hacen peticiones mediante un menú enumerado.
El usuario del sistema podrá agendar mas de un pedido con una fecha de entrega preestablecida y acordadas entre ambas partes (cliente-vendedor). 
El usuario del sistema podrá hacer consultas sobre: el estado de los pedidos ya regristrados (entregados/pendientes).
El usuario del sistema podrá marcar como entregado el/los pedidos de forma individual (por ejemplo si hay 2 pedidos se pueden seleccionar uno o ambos).
El cliente podrá dar detalles sobre como quiere su producto y se registrará en el pedido.
El usuario del sistema podrá también deshacer una entrega en caso de que haya errores, podrá editar, eliminar y buscar pedidos.

### Objetivo General
Tomar pedidos personalizados con fecha de entrega.

### Objetivos específicos
1. Implementar un sistema de gestión de pedidos personalizados en C++ que permita ingresar productos, cantidades, observaciones y fecha de entrega mediante una interfaz de consola.
2. Diseñar una estructura de almacenamiento sencilla (por ejemplo, uso de arreglos o estructuras) para registrar, visualizar y actualizar la información de los pedidos desde la línea de comandos.
3. Desarrollar una funcionalidad básica para marcar pedidos como entregados, permitiendo su actualización y manteniendo un registro simple del estado de cada pedido.

## HISTORIAS DE USUARIO OBJETIVO ESPECÍFICO 1
### HU-01
**Como** usuario del sistema,  
**quiero** poder ingresar el nombre del producto desde un menú y agregarlo como nuevo pedido,  
**para** registrar correctamente qué producto se ha solicitado.

- El sistema guarda el nombre del producto ingresado sin errores.
- Si el campo está vacío, el sistema muestra un mensaje de advertencia de pedido rechazado o cancelado

### HU-02
**Como** usuario del sistema,  
**quiero** ingresar la cantidad deseada del producto que debe ser mayor a 50,  
**para** que la panadería pueda preparar la cantidad correcta según políticas de la empresa.

- Se permite solo el ingreso de números positivos y mayores a 50.
- Si se ingresa un valor negativo o una letra o un numero menor a 50, el sistema rechaza el dato.

### HU-03
**Como** usuario del sistema,  
**quiero** ingresar observaciones o detalles para un pedido,  
**para** especificar detalles como "sin azúcar".

- El sistema acepta texto adicional en un campo de observaciones.
- Si se excede un límite de caracteres (por ejemplo, 100), se muestra una advertencia.

### HU-04
**Como** usuario del sistema,  
**quiero** ingresar la fecha de entrega del pedido,  
**para** que el pedido esté listo a tiempo.

- El sistema permite ingresar una fecha válida (día/mes/año).
- Si la fecha ingresada no cumple con el formato preestablecido se rechazará el pedido y se mostrará un mensaje de advertencia.

### HU-05
**Como** usuario del sistema,  
**quiero** visualizar todos los campos del pedido antes de confirmarlo,  
**para** asegurarme de que toda la información sea correcta.

- El sistema muestra un resumen del pedido que se visualiza mediante petición en el menú principal.
- Si el usuario cancela el pedido se mostrará un mensaje al respecto.

### HU-06
**Como** usuario del sistema,  
**quiero** poder cancelar un pedido durante el ingreso,  
**para** evitar errores si me equivoqué.

- Si cancelo, el sistema borra todos los datos ingresados.
- Si cancelo a medias, el sistema no guarda un pedido incompleto.


## HISTORIAS DE USUARIO OBJETIVO ESPECÍFICO 2
### HU-07
**Como** usuario del sistema,  
**quiero** que los pedidos se almacenen en una estructura organizada,  
**para** poder acceder a ellos más adelante.

- Cada nuevo pedido se agrega correctamente a la estructura (array o vector).
- Si la estructura está llena, se muestra un mensaje de error.

### HU-08
**Como** usuario del sistema,  
**quiero** visualizar todos los pedidos registrados,  
**para** revisar cuáles están pendientes o entregados.

- Se muestra una lista clara de todos los pedidos.
- Si no hay pedidos, se informa que la lista está vacía.

### HU-09
**Como** usuario del sistema,  
**quiero** buscar un pedido por el nombre del cliente o producto,  
**para** ubicar rápidamente pedidos específicos.

- Se encuentra el pedido si el nombre ingresado coincide con alguno registrado.
- Si no hay coincidencias, se muestra un mensaje indicando "pedido no encontrado".

### HU-10
**Como** usuario del sistema,  
**quiero** modificar la cantidad o fecha de un pedido ya registrado,  
**para** hacer correcciones si hubo errores.

- El sistema permite editar campos específicos del pedido.
- Si se intenta modificar un pedido inexistente, el sistema lo informa.

### HU-11
**Como** usuario del sistema,  
**quiero** eliminar pedidos antiguos o con errores,  
**para** mantener organizada la lista.

- El sistema elimina correctamente el pedido seleccionado.
- Si se intenta eliminar un pedido inválido, no ocurre nada.

### HU-12
**Como** usuario del sistema,  
**quiero** guardar los cambios de manera persistente mientras el programa esté en ejecución,  
**para** evitar pérdida de datos al navegar entre opciones.

- Los datos se mantienen en memoria mientras se usa el programa.
- Si los cambios no se guardan, al volver al menú principal se pierden.


## HISTORIAS DE USUARIO OBJETIVO ESPECÍFICO 3
### HU-13
**Como** usuario del sistema,  
**quiero** ver el estado actual de cada pedido (pendiente o entregado),  
**para** conocer cuáles faltan por entregar.

- El estado se muestra junto a cada pedido.
- Si no hay estado definido, se muestra como "desconocido".

### HU-14
**Como** usuario del sistema,  
**quiero** marcar un pedido como entregado,  
**para** actualizar su estado en el sistema.

- El sistema cambia correctamente el estado a "entregado".
- Si se marca un pedido no existente, el sistema muestra un error.

### HU-15
**Como** usuario del sistema,  
**quiero** poder filtrar solo los pedidos entregados o pendientes,  
**para** revisar entregas fácilmente.

- El sistema permite ver listas filtradas por estado.
- Si no hay pedidos con ese estado, se muestra un mensaje adecuado.

### HU-16
**Como** usuario del sistema,  
**quiero** que el sistema registre la fecha en que se marcó como entregado,  
**para** llevar control de puntualidad.

- La fecha de entrega real se guarda junto al pedido.
- Si no se registra fecha, se muestra como “sin registrar”.

### HU-17
**Como** usuario del sistema,  
**quiero** deshacer el cambio de "entregado" por error,  
**para** corregir si lo marqué accidentalmente.

- El sistema permite cambiar el estado de vuelta a "pendiente".
- Si no existe el pedido, no se permite la edición.

### HU-18
**Como** usuario del sistema,  
**quiero** ver un resumen de pedidos entregados por día,  
**para** tener una visión general de la actividad diaria.

- El sistema muestra un resumen claro agrupado por fechas.
- Si no hay entregas en ese día, se informa con claridad.

