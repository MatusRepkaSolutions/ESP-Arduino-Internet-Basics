//made by MatusRepkaSolutions
#include <WiFi.h>
#include <HTTPClient.h>

// Data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

// Path to the website
String HOST_NAME = "your_domain"; //example: "https://github.com"
String PATH_NAME = "path"; //in our tutorial we use "send.php"

bool x=0; //button logic

void setup() {
  Serial.begin(115200);

  // Button logic
  pinMode(32, OUTPUT); 
  pinMode(18, INPUT); 
  
  // Connecting ESP to the WiFi
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
}

void loop() {

  //button logic
  digitalWrite(32, HIGH);
  bool buttonState = digitalRead(18);
  delay(500);

  if (buttonState == HIGH) {
    Serial.println("Sending an e-mail");
    HTTPClient http;
    http.begin(HOST_NAME + PATH_NAME);

    // Specify content-type header
    http.addHeader("Content-Type", "application/x-www-form-urlencoded");

    /* Prepare data for POST request - the email recipment.
    Change this to address you want to send the e-mail to.*/
    String postData = "MAIL=example@mail.com";

    // Send POST request
    int httpCode = http.POST(postData);
    
    if (httpCode == HTTP_CODE_OK) {
      Serial.println("E-mail sent.");
    } else {
      Serial.println("E-mail has not been sent.");
    }
    http.end();
    delay(2000);
  }
}
