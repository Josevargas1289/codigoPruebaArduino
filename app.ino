int zumbador = 8;
int sonido =1; 
int valorSonido; 

void setup() {
   // Código de configuración que se ejecuta una sola vez:
  
  // Configurar los pines como entradas o como salidas
  
  pinMode (zumbador, OUTPUT);
}
void loop() {
  // Código que se ejecuta de manera repetida:
  
  valorSonido = analogRead (sonido);
  
  if (valorSonido >= 50) {  
    tone(zumbador,500); //El método tone le indica al zumbador emitir un sonido a una frecuencia de 500Hz, se puede variar el valor entre más bajo sonidos más graves y entre más alto sonidos más agudos           
    delay(2000);
 }
 else {                      
  noTone(zumbador);  //El método noTone le indica al zumbador no emitir ningún sonido
 }
}