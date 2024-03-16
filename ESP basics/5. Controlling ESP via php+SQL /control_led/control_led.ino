//mady by MatusRepkaSolutions
#include <WiFi.h>
#include <HTTPClient.h>

//data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

//path to the website
String HOST_NAME = "your_domain"; //example: "https://github.com"
String PATH_NAME = "path1"; //in our tutorial we use "update_data_LED.php"
String PATH_NAME2 = "path2"; //in our tutorial we use "LED_status.php"

/* Time between each request.
This determines the response time of your ESP to any change on the website,
in this example we go for 250ms, but you can go lower, becareful though, not to DDOS your website. */
unsigned long lastTime = 0;
unsigned long timerDelay = 250;

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
//A simple condition to send request after period you set up.
  if ((millis() - lastTime) > timerDelay) {
    //Line 69 is unnesesary, but it is just so that you realize, what we are sending
    String queryString = "?ip=" + WiFi.localIP().toString() + "&mac=" + WiFi.macAddress();
    
    HTTPClient http;
    /*create a path for your ESP to send data to. 
    Example: //http.www.github.com/update_data.php/?ip=XXXXXXX&mac=XXXXXXXXXX */
    http.begin(HOST_NAME + PATH_NAME2 + queryString);
    int httpCode = http.GET();


    /* Check if a valid HTTP response is received from the server. If successful (HTTP_CODE_OK), 
    print the response received from the website. Otherwise, handle and print the HTTP error code. */
    if (httpCode > 0) { 
      if (httpCode == HTTP_CODE_OK) {
        /*Store the response under variable "response".
        Since ESP can't directly recieve and integer, its better to just code in strings.*/
        String response = http.getString();
        Serial.println(response);
        String condition = "ON"; //set a condition

        if (response.equals(condition)) {
          //the response was indeed "ON" and the LED will turn on
          digitalWrite(18, HIGH);
        } else {
          //the response was not "ON" and the LED will turn off
          digitalWrite(18, LOW);
        }
      } else {
        //something went wrong
        Serial.printf("[HTTP] GET... code: %d\n", httpCode);
      }

      http.end();
      lastTime = millis();
    }
  }
}
