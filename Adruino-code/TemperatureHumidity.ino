
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

// Definimos la librerias par la conexion a nuestro servidor
#include "FirebaseESP8266.h"
#include <DHT.h>

// Definimos el pin digital donde se conecta el sensor
#define DHTPIN 4
// Dependiendo del tipo de sensor
#define DHTTYPE DHT11
 
// Inicializamos el sensor DHT11
DHT dht(DHTPIN, DHTTYPE);

// Definimos la direccion host de nuestro servidor
#define FIREBASE_HOST "testesp8266-5d5cc-default-rtdb.firebaseio.com"
// Definimos el token de nuestro servidor
#define FIREBASE_AUTH "RtWpHmsOF9g80kWJq6D2pniXbvFTK4hWjVDUru51"


// Definimos la conexion a punto de acceso wifi 
#define WIFI_SSID "Ariyan"
#define WIFI_PASSWORD "@Ariyan1853@"

WiFiClient client; 
FirebaseData firebaseData;

void setup() {
    Serial.begin(9600);
  
    WiFi.begin (WIFI_SSID, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
      }
      
    Serial.println ("");
    Serial.println ("Se conectó al wifi!");
    Serial.println(WiFi.localIP());
    
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

    dht.begin();
}

void loop() {

     float t = dht.readTemperature();
     int h = dht.readHumidity(); 
     
     Firebase.setString(firebaseData,"temperature", String(t));  
     Firebase.setString(firebaseData,"humidity", String(h));
    
}
