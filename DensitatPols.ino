/* Test sensor de microparticules Sharp GP2Y1010AU0F */

int SensorPin = 0; // Arduino A0 pin
int LedPin = 2;    // Arduino D2

void setup()
{
  Serial.begin(9600);
  pinMode(LedPin,OUTPUT);
}

void loop()
{
  digitalWrite(LedPin,LOW); // encén el LED
  delayMicroseconds(280);

  float DadaSensor = analogRead(SensorPin); // llegeix el pin analògic

  delayMicroseconds(40);
  digitalWrite(LedPin,HIGH); // apaga el LED
  delayMicroseconds(9680);

  float Tensio = DadaSensor * (5.0 / 1024.0); // recupera la tensió

  float DensitatPols = 0.17 * Tensio - 0.1;  // linear eqaution taken from http://www.howmuchsnow.com/arduino/airquality/

  Serial.print("Valor del senyal (0-1023): ");
  Serial.print(DadaSensor);

  Serial.print(" - Tensio: ");
  Serial.print(Tensio);

  Serial.print(" - Densitat de pols: ");
  Serial.print(DensitatPols); // unitat: mg/m3
  Serial.println(" mg/m3");

  delay(1000);
}
