#include <GFButton.h>
#include <MatrizLed.h>

// Create two button instances on pins 2 & 3
GFButton buttonStop(4);
GFButton buttonRight(2);
GFButton buttonLeft(7);

/*
 * Texto que aparece por la derecha y sale por la izquierda
 */

MatrizLed pantalla;

void setup() {
  pantalla.begin(12, 11, 10, 2); // dataPin, clkPin, csPin, numero de matrices de 8x8
  pantalla.rotar(false);
    // Prepare serial interface
  Serial.begin(9600);
 
  // Show dialog to serial monitor
  Serial.println(F("----------------------------------------------------"));
  Serial.println(F("            GFBUTTON LIBRARY TEST PROGRAM           "));
  Serial.println(F("             http://www.geekfactory.mx             "));
  Serial.println(F("----------------------------------------------------"));
}

void loop() { 
  if (buttonStop.isPressed()) {
    Serial.println(F("On button is pressed"));
    // Turn on the led
    pantalla.borrar();
    pantalla.escribirFraseScroll("stop", 200); // Texto, milisegundos entre frames 
  }
  if (buttonRight.isPressed()) {
    Serial.println(F("On button is pressed"));
    // Turn on the led
    pantalla.borrar();
    pantalla.escribirFraseScroll("right", 200); // Texto, milisegundos entre frames 
  }
  if (buttonLeft.isPressed()) {
    Serial.println(F("On button is pressed"));
    // Turn on the led
    pantalla.borrar();
    pantalla.escribirFraseScroll("left", 200); // Texto, milisegundos entre frames 
  }

  
}
