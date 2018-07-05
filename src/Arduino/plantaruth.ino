#include <Ultrasonic.h> // Inclusão de biblioteca
#include <LiquidCrystal.h>

// Declaração de defines para o sensor e para o Led
#define TRIGGER_PIN  8
#define ECHO_PIN     10
#define UMIDADE      A0
#define LDR          A1
//lcd(2,3,4,5,6,7)
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

Ultrasonic ultrasonico(TRIGGER_PIN, ECHO_PIN);

void setup()
{
  Serial.begin(9600);
  pinMode(UMIDADE, INPUT);
  Serial.println("Lendo dados...");
  lcd.begin(16,2);
}

void loop()
{
  float umidade = 1024 - analogRead(UMIDADE);
  float iluminacao = analogRead(LDR);

  long microsec = ultrasonico.timing(); //Leitura de MS do sensor ultrassonico
  float distanciaObjetoCM = ultrasonico.convert(microsec, Ultrasonic::CM); //Distancia em CM do sensor

  //SERIAL DE UMIDADE:
  // < 200 = seco
  // < 600 = moderado
  // < 1024 = umido
  Serial.print("\nUmidade:");
  Serial.print(umidade);

  
  //SERIAL DE DISTANCIA
  Serial.print("\nDistancia de um objeto: ");
  Serial.print(distanciaObjetoCM);

  
  //SERIAL DE ILUMINACAO
  Serial.print("\nQuantidade de iluminacao: ");
  Serial.print(iluminacao);
  Serial.print("\n\n\n");

  //LCD...
  lcd.clear();

  
  lcd.setCursor(0,0);
  if(distanciaObjetoCM < 100)
  {
    lcd.print("OLA!");
  }

  
  lcd.setCursor(0,1);
  if(iluminacao < 250)
  {
    lcd.print("Que luz gostosa!");
  }
  else
  {
    lcd.print("Escuro...medo...");
  }
  delay(500);
}

