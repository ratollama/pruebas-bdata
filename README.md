# Pruebas Curso de Big Data
Prubas para el curso de big data, con respecto a las librería a ocupar para desarrollar el proyecto del curso.

## Paralelismo
Pequeña prueba para probar si es útil el uso de paralelismo para leer los datos.
Inicialmente las pruebas se efectúan sobre algoritmos de pruebas. Más adelante está planeado ocupar el mismo XML del proyecto
### Un hilo
Código de ejemplo para desarrollar el concepto de un hilo principal solucionando el problema
### Múltiples hilos
Código de ejemplo programado, a lo vieja escuela, de tal forma que separe el problema ocupando pthreads
### Múltiples hilos - OMP
Código de ejemplo ocupando múltiples hilos mediante OpenMP
### Resultados
Al momento de correr en mi computadora estos son los resultados:
* Un hilo: 0:37.81
* Multiples hilos: 0:16.48
* OpenMP: 0:16.57

## Serialización
Se realizan pruebas sobre los tiempos y uso de memoria para dos librerías.
Los datos tomados para [des]serializar son los usuarios de askUbuntu-
### Boost Serialzation
Librería de boost para serializar objetos.
Se realiza una serialización ocupando el formato binario.
Pros:
* Se pueden serializar estructuras de la std

Contra:
* Es necesario modificar las clases para incluir el método de serialización

### Google protobuf
Librería de google para la transmición de mensajes.
Pros:
* Diseño limpio de las estructuras a serializar
* API de fácil uso

Contra:
* No se pueden serializar estrucuras de la std

### Resultados
#### Serialización

Bibliotecta | Tiempo | Memoria
Boost Serialization | 00:03.58 | 954188
Protobuf | 00:03.35 | 968468

#### Des-Serialización
En el programa se incluye un pequeño calculo por sobre todos los elementos cargados

Bibliotecta | Tiempo | Memoria
Boost Serialization | 0:00.29 | 86260
Protobuf | 0:00.27  | 124500
