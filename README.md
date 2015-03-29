# pruebas-bdata
Prubas para el curso de big data, con respecto a las librería a ocupar para desarrollar el proyecto del curso.

## Paralelismo
Pequeña prueba para probar si es útil el uso de paralelismo para leer los datos.
Inicialmente las pruebas se efectúan sobre algoritmos de pruebas. Más adelante está planeado ocupar el mismo XML del proyecto
### Pruebas
#### Un hilo
Código de ejemplo para desarrollar el concepto de un hilo principal solucionando el problema
#### Múltiples hilos
Código de ejemplo programado, a lo vieja escuela, de tal forma que separe el problema ocupando pthreads
### Múltiples hilos - OMP
Código de ejemplo ocupando múltiples hilos mediante OpenMP
### Resultados
Al momento de correr en mi computadora estos son los resultados:
* Un hilo: 0:37.81
* Multiples hilos: 0:16.48
* OpenMP: 0:16.57
