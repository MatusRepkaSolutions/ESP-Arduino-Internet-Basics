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
  /* Creating a POST request for your IP and MAC adress
  There can't be any space good: "xxx=One_Two" bad: "xxx=One Two".*/
  String postData = "ip=" + WiFi.localIP().toString() + "&mac=" + WiFi.macAddress(); 
  Serial.println("Your POST request: ");
  Serial.println(postData);

  HTTPClient http;
  http.begin(HOST_NAME + PATH_NAME);

/* Specify content-type header - this header informs the server about the type of data being sent in the request body.
 In this case, we are specifying "application/x-www-form-urlencoded" as the content type, which indicates that the
 data is encoded as key-value pairs in the URL-encoded format.  */
http.addHeader("Content-Type", "application/x-www-form-urlencoded");

  // Send an HTTP POST request to the server and retrieve the response status code
  int httpCode = http.POST(postData);

/* Check if a valid HTTP response is received from the server. If successful (HTTP_CODE_OK), 
print the response received from the website. Otherwise, handle and print the HTTP error code. */
  if (httpCode > 0) {
    // print the response received from the website, stored in the 'payload' variable".
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
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
