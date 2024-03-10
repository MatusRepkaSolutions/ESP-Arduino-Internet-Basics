//Made by MatusRepkaSolutions - ESP-Arduino-Internet-Basics
#include <WiFi.h>
#include <HTTPClient.h>

// Data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

// Path to the website
String HOST_NAME = "your_site_domain"; //example: "https://github.com"
String PATH_NAME = "/your_.php_page"; //example: "/MatusRepkaSolutions.php" - in our tutorial we use "POST.php"

void setup() {
  Serial.begin(115200);

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

  // Creating a POST request with a message key
  String postData = "message=Hello_There"; // Specify the key "message" for the data. There can't be any space good: "xxx=One_Two" bad: "xxx=One Two".
  HTTPClient http;
  http.begin(HOST_NAME + PATH_NAME);

/* Specify content-type header - this header informs the server about the type of data being sent in the request body.
 In this case, we are specifying "application/x-www-form-urlencoded" as the content type, which indicates that the
 data is encoded as key-value pairs in the URL-encoded format.  */
http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Send an HTTP POST request to the server and retrieve the response status code
  int httpCode = http.POST(postData);

  if (httpCode > 0) {
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println("You said: Hello_There");
      Serial.println("The site says:");
      Serial.println(payload);
    } else {
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);
    }
  } else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();
}

void loop() {
}
