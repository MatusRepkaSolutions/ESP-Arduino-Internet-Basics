//Made by MatusRepkaSolutions
#include <WiFi.h>
#include <HTTPClient.h>

//data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

//path to the website
String HOST_NAME = "your_domain"; //example: "https://github.com"
String PATH_NAME = "your_path"; //example: "/MatusRepkaSolutions.php" - in our tutorial we use "update_data.php"

void setup() {
  Serial.begin(115200);

//connecting ESP to the WiFi
  Serial.println();
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected"); //once it's connected we can continue

//checking your IP and MAC adress and printing it in Serial Monitor
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.println("MAC address: ");
  Serial.println(WiFi.macAddress());
  //Creating a GET request for your IP and MAC adress
  String queryString = "?ip=" + WiFi.localIP().toString() + "&mac=" + WiFi.macAddress(); // Updated to lowercase
  Serial.println("Your GET request: ");
  Serial.println(queryString);

 HTTPClient http;
  /*create a path for your ESP to send data to. 
  Example: //http.www.github.com/update_data.php/?ip=XXXXXXX&mac=XXXXXXXXXX */
  http.begin(HOST_NAME + PATH_NAME + queryString);
  int httpCode = http.GET();

/* Check if a valid HTTP response is received from the server. If successful (HTTP_CODE_OK), 
print the response received from the website. Otherwise, handle and print the HTTP error code. */
  if (httpCode > 0) {
    // print the response received from the website, stored in the 'payload' variable".
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println(payload);
    } else {
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

void loop() {
}
