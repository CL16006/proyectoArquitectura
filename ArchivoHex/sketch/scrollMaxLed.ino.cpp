#include <Arduino.h>
#line 1 "C:\\Users\\milto\\Desktop\\Ciclo II 2021\\Arquitectura de computadoras\\proyecto proteus arduino\\proyectoArquitectura\\scrollMaxLed\\scrollMaxLed.ino"
#include <GFButton.h>
#include <MatrizLed.h>

// Create two button instances on pins 2 & 3
GFButton intermitentes(4);
GFButton buttonRight(2);
GFButton buttonLeft(7);
GFButton buttonStop(6);

//Variables controladoras
int activado = 0;
int contador1 = 4;
int contador2 = 3;

/*
 * Texto que aparece por la derecha y sale por la izquierda
 */

MatrizLed pantalla;

#line 21 "C:\\Users\\milto\\Desktop\\Ciclo II 2021\\Arquitectura de computadoras\\proyecto proteus arduino\\proyectoArquitectura\\scrollMaxLed\\scrollMaxLed.ino"
void setup();
#line 28 "C:\\Users\\milto\\Desktop\\Ciclo II 2021\\Arquitectura de computadoras\\proyecto proteus arduino\\proyectoArquitectura\\scrollMaxLed\\scrollMaxLed.ino"
void loop();
#line 144 "C:\\Users\\milto\\Desktop\\Ciclo II 2021\\Arquitectura de computadoras\\proyecto proteus arduino\\proyectoArquitectura\\scrollMaxLed\\scrollMaxLed.ino"
void freno();
#line 220 "C:\\Users\\milto\\Desktop\\Ciclo II 2021\\Arquitectura de computadoras\\proyecto proteus arduino\\proyectoArquitectura\\scrollMaxLed\\scrollMaxLed.ino"
void intermitente();
#line 21 "C:\\Users\\milto\\Desktop\\Ciclo II 2021\\Arquitectura de computadoras\\proyecto proteus arduino\\proyectoArquitectura\\scrollMaxLed\\scrollMaxLed.ino"
void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
  pantalla.rotar(false);
    // Prepare serial interface
  Serial.begin(9600);
}

void loop() { 

  if (buttonStop.wasPressed()) {//FRENO
    pantalla.borrar();
  }
    
  if (intermitentes.isPressed()) {//INTERMITENTES
   
   intermitente();
  }
  
  if (buttonRight.isPressed()) {//DERECHA
    
      for(int i =0; i<16; i++){
        pantalla.borrar();

        pantalla.setLed(0, i, 4, true);
        pantalla.setLed(0, i, 3, true);
        pantalla.setLed(0, i-1, 5, true);
        pantalla.setLed(0, i-1, 2, true);
        pantalla.setLed(0, i-2, 6, true);
        pantalla.setLed(0, i-2, 1, true);
        pantalla.setLed(0, i-3, 7, true);
        pantalla.setLed(0, i-3, 0, true);
        
        pantalla.setLed(0, i-1, 4, true);
        pantalla.setLed(0, i-1, 3, true);
        pantalla.setLed(0, i-2, 5, true);
        pantalla.setLed(0, i-2, 2, true);
        pantalla.setLed(0, i-3, 6, true);
        pantalla.setLed(0, i-3, 1, true);
        pantalla.setLed(0, i-4, 7, true);
        pantalla.setLed(0, i-4, 0, true);

        pantalla.setLed(0, i-2, 4, true);
        pantalla.setLed(0, i-2, 3, true);
        pantalla.setLed(0, i-3, 5, true);
        pantalla.setLed(0, i-3, 2, true);
        pantalla.setLed(0, i-4, 6, true);
        pantalla.setLed(0, i-4, 1, true);
        pantalla.setLed(0, i-5, 7, true);
        pantalla.setLed(0, i-5, 0, true);

        pantalla.setLed(0, i-3, 4, true);
        pantalla.setLed(0, i-3, 3, true);
        pantalla.setLed(0, i-4, 5, true);
        pantalla.setLed(0, i-4, 2, true);
        pantalla.setLed(0, i-5, 6, true);
        pantalla.setLed(0, i-5, 1, true);
        pantalla.setLed(0, i-6, 7, true);
        pantalla.setLed(0, i-6, 0, true);

        delay(10);
          
         
      }
    
  }

  
  if (buttonLeft.isPressed()) {//IZQUIERDA
     
      for(int i =7; i>-10; i--){
        pantalla.borrar();

        pantalla.setLed(0, i, 4, true);
        pantalla.setLed(0, i, 3, true);
        pantalla.setLed(0, i+1, 5, true);
        pantalla.setLed(0, i+1, 2, true);
        pantalla.setLed(0, i+2, 6, true);
        pantalla.setLed(0, i+2, 1, true);
        pantalla.setLed(0, i+3, 7, true);
        pantalla.setLed(0, i+3, 0, true);
        
        pantalla.setLed(0, i+1, 4, true);
        pantalla.setLed(0, i+1, 3, true);
        pantalla.setLed(0, i+2, 5, true);
        pantalla.setLed(0, i+2, 2, true);
        pantalla.setLed(0, i+3, 6, true);
        pantalla.setLed(0, i+3, 1, true);
        pantalla.setLed(0, i+4, 7, true);
        pantalla.setLed(0, i+4, 0, true);

        pantalla.setLed(0, i+2, 4, true);
        pantalla.setLed(0, i+2, 3, true);
        pantalla.setLed(0, i+3, 5, true);
        pantalla.setLed(0, i+3, 2, true);
        pantalla.setLed(0, i+4, 6, true);
        pantalla.setLed(0, i+4, 1, true);
        pantalla.setLed(0, i+5, 7, true);
        pantalla.setLed(0, i+5, 0, true);

        pantalla.setLed(0, i+3, 4, true);
        pantalla.setLed(0, i+3, 3, true);
        pantalla.setLed(0, i+4, 5, true);
        pantalla.setLed(0, i+4, 2, true);
        pantalla.setLed(0, i+5, 6, true);
        pantalla.setLed(0, i+5, 1, true);
        pantalla.setLed(0, i+6, 7, true);
        pantalla.setLed(0, i+6, 0, true);

        delay(10);
          
         
      }
    
  }
  if (buttonStop.isPressed()) {//FRENO
     freno();  
  }else{
      pantalla.borrar();
  }

  
}

void freno(){//Funcion de luces para freno
     
     pantalla.setLed(0, 0, 0, true);
     pantalla.setLed(0, 0, 1, true);
     pantalla.setLed(0, 0, 2, true);
     pantalla.setLed(0, 0, 3, true);
     pantalla.setLed(0, 0, 4, true);
     pantalla.setLed(0, 0, 5, true);
     pantalla.setLed(0, 0, 6, true);
     pantalla.setLed(0, 0, 7, true);

     pantalla.setLed(0, 7, 0, true);
     pantalla.setLed(0, 7, 1, true);
     pantalla.setLed(0, 7, 2, true);
     pantalla.setLed(0, 7, 3, true);
     pantalla.setLed(0, 7, 4, true);
     pantalla.setLed(0, 7, 5, true);
     pantalla.setLed(0, 7, 6, true);
     pantalla.setLed(0, 7, 7, true);

     pantalla.setLed(0, 1, 0, true);
     pantalla.setLed(0, 1, 1, true);
     pantalla.setLed(0, 1, 2, true);
     pantalla.setLed(0, 1, 3, true);
     pantalla.setLed(0, 1, 4, true);
     pantalla.setLed(0, 1, 5, true);
     pantalla.setLed(0, 1, 6, true);
     pantalla.setLed(0, 1, 7, true);

     pantalla.setLed(0, 6, 0, true);
     pantalla.setLed(0, 6, 1, true);
     pantalla.setLed(0, 6, 2, true);
     pantalla.setLed(0, 6, 3, true);
     pantalla.setLed(0, 6, 4, true);
     pantalla.setLed(0, 6, 5, true);
     pantalla.setLed(0, 6, 6, true);
     pantalla.setLed(0, 6, 7, true);

     pantalla.setLed(0, 2, 0, true);
     pantalla.setLed(0, 2, 1, true);
     pantalla.setLed(0, 2, 2, true);
     pantalla.setLed(0, 2, 3, true);
     pantalla.setLed(0, 2, 4, true);
     pantalla.setLed(0, 2, 5, true);
     pantalla.setLed(0, 2, 6, true);
     pantalla.setLed(0, 2, 7, true);

     pantalla.setLed(0, 5, 0, true);
     pantalla.setLed(0, 5, 1, true);
     pantalla.setLed(0, 5, 2, true);
     pantalla.setLed(0, 5, 3, true);
     pantalla.setLed(0, 5, 4, true);
     pantalla.setLed(0, 5, 5, true);
     pantalla.setLed(0, 5, 6, true);
     pantalla.setLed(0, 5, 7, true);

     pantalla.setLed(0, 3, 0, true);
     pantalla.setLed(0, 3, 1, true);
     pantalla.setLed(0, 3, 2, true);
     pantalla.setLed(0, 3, 3, true);
     pantalla.setLed(0, 3, 4, true);
     pantalla.setLed(0, 3, 5, true);
     pantalla.setLed(0, 3, 6, true);
     pantalla.setLed(0, 3, 7, true);

     pantalla.setLed(0, 4, 0, true);
     pantalla.setLed(0, 4, 1, true);
     pantalla.setLed(0, 4, 2, true);
     pantalla.setLed(0, 4, 3, true);
     pantalla.setLed(0, 4, 4, true);
     pantalla.setLed(0, 4, 5, true);
     pantalla.setLed(0, 4, 6, true);
     pantalla.setLed(0, 4, 7, true);

}

void intermitente(){//Funcion de luces intermitentes
     
     pantalla.setLed(0, 0, 0, true);
     pantalla.setLed(0, 0, 1, true);
     pantalla.setLed(0, 0, 2, true);
     pantalla.setLed(0, 0, 3, true);
     pantalla.setLed(0, 0, 4, true);
     pantalla.setLed(0, 0, 5, true);
     pantalla.setLed(0, 0, 6, true);
     pantalla.setLed(0, 0, 7, true);

     pantalla.setLed(0, 7, 0, true);
     pantalla.setLed(0, 7, 1, true);
     pantalla.setLed(0, 7, 2, true);
     pantalla.setLed(0, 7, 3, true);
     pantalla.setLed(0, 7, 4, true);
     pantalla.setLed(0, 7, 5, true);
     pantalla.setLed(0, 7, 6, true);
     pantalla.setLed(0, 7, 7, true);

     pantalla.setLed(0, 1, 0, true);
     pantalla.setLed(0, 1, 1, true);
     pantalla.setLed(0, 1, 2, true);
     pantalla.setLed(0, 1, 3, true);
     pantalla.setLed(0, 1, 4, true);
     pantalla.setLed(0, 1, 5, true);
     pantalla.setLed(0, 1, 6, true);
     pantalla.setLed(0, 1, 7, true);

     pantalla.setLed(0, 6, 0, true);
     pantalla.setLed(0, 6, 1, true);
     pantalla.setLed(0, 6, 2, true);
     pantalla.setLed(0, 6, 3, true);
     pantalla.setLed(0, 6, 4, true);
     pantalla.setLed(0, 6, 5, true);
     pantalla.setLed(0, 6, 6, true);
     pantalla.setLed(0, 6, 7, true);

     pantalla.setLed(0, 2, 0, true);
     pantalla.setLed(0, 2, 1, true);
     pantalla.setLed(0, 2, 2, true);
     pantalla.setLed(0, 2, 3, true);
     pantalla.setLed(0, 2, 4, true);
     pantalla.setLed(0, 2, 5, true);
     pantalla.setLed(0, 2, 6, true);
     pantalla.setLed(0, 2, 7, true);

     pantalla.setLed(0, 5, 0, true);
     pantalla.setLed(0, 5, 1, true);
     pantalla.setLed(0, 5, 2, true);
     pantalla.setLed(0, 5, 3, true);
     pantalla.setLed(0, 5, 4, true);
     pantalla.setLed(0, 5, 5, true);
     pantalla.setLed(0, 5, 6, true);
     pantalla.setLed(0, 5, 7, true);

     pantalla.setLed(0, 3, 0, true);
     pantalla.setLed(0, 3, 1, true);
     pantalla.setLed(0, 3, 2, true);
     pantalla.setLed(0, 3, 3, true);
     pantalla.setLed(0, 3, 4, true);
     pantalla.setLed(0, 3, 5, true);
     pantalla.setLed(0, 3, 6, true);
     pantalla.setLed(0, 3, 7, true);

     pantalla.setLed(0, 4, 0, true);
     pantalla.setLed(0, 4, 1, true);
     pantalla.setLed(0, 4, 2, true);
     pantalla.setLed(0, 4, 3, true);
     pantalla.setLed(0, 4, 4, true);
     pantalla.setLed(0, 4, 5, true);
     pantalla.setLed(0, 4, 6, true);
     pantalla.setLed(0, 4, 7, true);

     

     

     

    delay(200);

    pantalla.borrar();

    delay(100);
}

