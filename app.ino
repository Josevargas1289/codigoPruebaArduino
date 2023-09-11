#include <MX1508.h>
 // Esta instrucción incluye un fichero que nos permite manejar el DRIVER del motor con instrucciones fáciles 
DRV8833 driver = DRV8833(); // Esta instrucción indica la creación del DRIVER virtual dentro del programa 

// Declaración de variables enteras globales para nombrar los pines: 

int motorA1 = 5 ; //Pin de conexión de los motores.  
int motorA2 = 6;
int motorB1 = 11;
int motorB2 = 3;

int Pot = 0; // Pin de ubicación del potenciómetro 
int valor; 

void setup() {
  // Código de configuración que se ejecuta una sola vez:
  
  // Configurar los pines como entradas o como salidas
  
  Serial.begin(9600); // Inicia la comunicación con el puerto serial del computador a 9600 baudios
  driver.attachMotorA(motorA1, motorA2); // Esta instrucción especial ya configura los pines del motor A como salidas
  driver.attachMotorB(motorB1, motorB2); // Esta instrucción especial ya configura los pines del motor B como salidas
}

void loop() {
  // Código que se ejecuta de manera repetida:
  
  valor= analogRead(Pot)/4; //// En cada ciclo que se repite, leer el valor del pin del potenciómetro y almacenarlo en una variable llamada valor
  driver.motorAForward(valor); // La velocidad de los motores A y B estará indicada por "valor"
  driver.motorBForward(valor);
  Serial.println(valor); //Escribir en el puerto serial del computador la variable "valor" 
  }