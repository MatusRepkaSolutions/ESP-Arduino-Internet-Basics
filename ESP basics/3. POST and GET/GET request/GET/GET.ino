#include <WiFi.h>
#include <HTTPClient.h>

//data to connect to the WiFi network
const char* ssid = "your_WiFi_name";
const char* password = "your_WiFi_password";

//path to the website
String HOST_NAME = "your_site_domain"; //example: "https://github.com"
String PATH_NAME = "/your_.php_page"; //example: "/MatusRepkaSolutions.php"

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


  //creating a GET request, for more about GET visit https://www.w3schools.com/tags/ref_httpmethods.asp
  String queryString = "?message=Hello_There"; //There can't be any space good: "?xxx=One_Two" bad: "?xxx=One Two"
  HTTPClient http; //start the HTTP client

/* set the target URL for the HTTP request that the ESP will use, combining the host name, path name, and query string. 
For example: https://github.com/MatusRepkaCodes/?massage=Hello_There */
  http.begin(HOST_NAME + PATH_NAME + queryString);

//send an HTTP GET request to the server and retrieve the response status code.
  int httpCode = http.GET(); 

/* Check if a valid HTTP response is received from the server. If successful (HTTP_CODE_OK), 
print the response received from the website. Otherwise, handle and print the HTTP error code. */
  if (httpCode > 0) {
    // print the response received from the website, stored in the 'payload' variable".
    if (httpCode == HTTP_CODE_OK) {
      String payload = http.getString();
      Serial.println("You said: Hello_There");
      Serial.println("The site says:");
      Serial.println(payload);
    } else {
      //if there is a problem with the connection, this will tell you the error code
      Serial.printf("[HTTP] GET... code: %d\n", httpCode);
    }
  } else {
    //if there is a problem with the connection, this will tell you the error code
    Serial.printf("[HTTP] GET... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  http.end();
}

void loop() {
}
