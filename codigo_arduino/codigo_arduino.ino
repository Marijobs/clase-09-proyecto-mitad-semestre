// Proyecto mitad semestre temporizador
// Antonia Alvear, María José Becerra, Colomba Del Río
// 10/05/2022
// hecho con Arduino Uno y IDE 1.8.19
// hecho en base a ejemplo clase 5
// Temporizador intervalos de entrenamiento funcional

// incluir archivo en otra pestaña
#include "notas.h"

// declarar arreglo de enteros
// para melodia de 4 notas
int melodia[] = {
  NOTA_DO6, NOTA_SOL5, NOTA_DO6, NOTA_SOL5
  
};

// Nota_DO6 corresponde al inicio del tiempo de trabajo
// Nota_SOL5 corresponde al inicio del tiempo de descanso 


// declarar arreglo de enteros
// para duracion de 4 notas
int duraciones[] = {
  1,2,1,2
};

// multiplicador de la duracion
// a mayor numero, mas rapido
int multiplicadorDuracion = 1;

// pausa entre notas
// pausa de 30s entre notas Nota_DO6 y Nota_SOL5 indica tiempo de trabajo
// calculo para 30s = 30000 milisegundos 
// 30000 = 1000*multiplicador pausa
// 30000/1000 = 30
// pausa de 15s entre notas Nota_SOL5 y Nota_DO6 indica tiempo de descanso

// calculo para 15s = 15000 milisegundos
// 15000 = duracion nota*30
// 15000/30 = duracion nota = 500
// duracion nota = 1000 / (duraciones[nota] * multiplicadorDuracion)
// 500 = 1000 / (duraciones[nota]*1)
// 500 = 1000 / duraciones[nota]
// duraciones[nota]*500 = 1000
// duraciones[nota] = 1000/500
// duraciones[nota] = 2
float multiplicadorPausa = 30;


// pin de conexion del parlante
int pinParlante = 8;

// setup() ocurre una vez, al principio
void setup() {

  // bucle for
  // iterador es nota y parte en 0
  // repetir hasta que nota < 4
  // en cada iteracion aumentar nota en 1
  for (int nota = 0; nota < 4 ; nota++) {

    // duracion de la nota en milisegundos
    int duracionNota = 1000 / (duraciones[nota] * multiplicadorDuracion);

    // tone(pin, frecuencia, duracion)
    tone(pinParlante, melodia[nota], duracionNota);

    // pausa entre notas
    int pausa = duracionNota * multiplicadorPausa;

    // pausar para mantener nota
    delay(pausa);

    // silenciar nota
    noTone(pinParlante);

  }
}



// loop() ocurre después de setup(), en bucle
void loop() {

  // nada

}
