int pinUltrasonido = 4; // Pin de conexión sensor ultrasonido 
int distancia;

void setup() {
 Serial.begin(9600); // Inicia la comunicación con el puerto serial del computador a 9600 baudios
}

void loop() {
  
int distancia = obtenerDistancia();  //Se iguala la variable distancia al valor de lectura de la función obetenerDistancia

Serial.print(distancia);  //Escribir en el puerto serial del computador la variable "distancia" 
Serial.println(" cm"); //Escribir en el puerto serial del computador el texto que se encuentra dentro de las comillas 
}

int obtenerDistancia()
{
  int d;
  pinMode(pinUltrasonido, OUTPUT);    //Indicar que se usará como salida para generar señal ultrasónica
  digitalWrite(pinUltrasonido, LOW);  //Asegurarse de que no esté generando señal ultrasónico
  delayMicroseconds(2);               //Pequeño tiempo de espera para ecos o ruidos iniciales
  digitalWrite(pinUltrasonido, HIGH); //Generar señal ultrasónica
  delayMicroseconds(10);              //Pequeño tiempo de generación de señal
  digitalWrite(pinUltrasonido, LOW);  //Apagar señal ultrasónica
  pinMode(pinUltrasonido, INPUT);     //Indicar que se usará como entrada para recibir señal ultrasónica ("micrófono")
  d = pulseIn(pinUltrasonido, HIGH);  //Instrucción para medir el tiempo en que la señal ultrasónica rebota y produce HIGH
  d = d / 58;                         //Divisíon entre 58 para pasar de tiempo (microsegundos) a distancia (cm) - Valor a calibrar
  return d;                           //Retorna d para que se pueda almacenar en variable
}