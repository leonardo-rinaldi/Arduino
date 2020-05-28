/*
 * Questo è un semplice progetto IOT per avere 3 Output distinti comandati tramite dei
 * pulsanti in una pagina web.
 * La scheda che ho utilizzato è una esp8266MOD-12f
 * L'indirizzo a cui collegarsi per accedere alla pagina è 192.168.1.108 ( è ovviamente
 * possibile cambiarlo).
 * 
 * Per far si che la scheda si colleghi alla rete è necessario configurare il campo ssid
 * e password.
 * 
 * E' inoltre possibile modificare facilmente lo stile e la struttura della pagina web modificando
 * il testo contenuto dalle stringhe head, body e footer.
 * 
 */

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

String ssid     = "ssid";                     //inserisci l'ssid della tua rete
String password = "password";                 //inserisci la password della tua rete

ESP8266WebServer server(80);

//creazione della pagina web HTML e CSS

String head = "<!DOCTYPE html ><html>" 
                "<head>" 
                    "<title>Output wireless</title>"
                    
                      "<style>" 

                "body {"
                    "background-color: #e0e0e0;"
                    "font-family: sans-serif;"
                    "margin: 0px;"
                "}"
                
                "header {"
                    "width: 100%;"
                    "height: 70px;"
                    "background-color: #0d47a1;"
                    "position: fixed;"
                    "top: 0px;"
                   
                "}"
                
                "header p {"
                    "color: white;"
                "}"
                
                ".button {"
                    "width: 60px;"
                    "height: 50px;"
                "}"
                
               
                
                ".contenitore {"
                    "margin-left: 35%;"
                "}"
                
                
                "h1 {"
                    "text-align: center;"
                "}"
                
                "h1:first-child {"
                    "padding-top: 50px;"
                "}"
            
                
                "a {"
                    "padding: 5px;"
                    "text-decoration: none;"
                    
                "}"
                
                ".finestra {"
                    "width: 500px;"
                    "height: 500px;"
                    "background-color: white;"
                    "display: block;"
                    "margin: 0px auto;"
                    "border-radius: 20px;"
                    "margin-top: 100px;"
                    
                "}"
                        "}"
                    
                    
                    
                    "</style></head>";
                    
String body  = "<body>"

                    "<header>"
                    "</header>"
                    
                   "<div class=\"finestra\">"
                  "<h1>Output 1</h1>"

                  "<div class=\"contenitore\">"
                      "<a href=\"/outputUnoOn\"><button class=\"button\">ON</button></a>"  
                      "<a href=\"/outputUnoOff\"><button class=\"button\">OFF</button></a>"
                  "</div>"

                  
                  "<h1>Output 2</h1>"

                  "<div class=\"contenitore\">"
                      "<a href=\"/outputDueOn\"><button class=\"button\">ON</button></a>"  
                      "<a href=\"/outputDueOff\"><button class=\"button\">OFF</button></a>"
                    "</div>"

                   
                   "<h1>Output 3</h1>" 

                   "<div class=\"contenitore\">"
                      "<a href=\"/outputTreOn\"><button class=\"button\">ON</button></a>"  
                      "<a href=\"/outputTreOff\"><button class=\"button\">OFF</button></a>"
                      
                       "</div>"

                       "</div";
                      
String footer= "</body></html>";
String html;



void pagina()    //pagina principale
{
  html = head + body + footer;         //compongo la pagina unendo le varie stringe head, body e footer
  server.send(200, "text/html", html);   
}

void outputUnoOn()    
{
 digitalWrite(D0,HIGH);       //utilizzo il pin D0, è possibile cambiarlo a piacimento
 html = head + body + footer;
 server.send(200, "text/html", html );
}

void outputUnoOff()
{
 digitalWrite(D0,LOW); 
 html = head + body + footer;
 server.send(200, "text/html", html );
}

void outputDueOn()  
{
 digitalWrite(D1,HIGH); 
 html = head + body + footer;
 server.send(200, "text/html", html );
}

void outputDueOff()
{
 digitalWrite(D1,LOW); 
 html = head + body + footer;
 server.send(200, "text/html", html );
}

void outputTreOn()  
{
 digitalWrite(D2,HIGH); 
 html = head + body + footer;
 server.send(200, "text/html", html );
}

void outputTreOff()
{
 digitalWrite(D2,LOW); 
 html = head + body + footer;
 server.send(200, "text/html", html );
}

void setup() {
  Serial.begin(115200);
  
  IPAddress ip(192, 168, 1, 108);       //indirizzo a cui collegarsi nel browser (modificabile in base ale esigenze)
  IPAddress gateway(192, 168, 1, 1); 
  IPAddress subnet(255, 255, 255, 0); 
  WiFi.config(ip, gateway, subnet);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Sei collegato alla rete LAN");
  Serial.println(WiFi.localIP());
  
  pinMode(D0,OUTPUT); 
  digitalWrite(D0,LOW); 
  
  pinMode(D1,OUTPUT);
  digitalWrite(D1,LOW);

  pinMode(D2,OUTPUT);
  digitalWrite(D2,LOW);
  
  server.begin();  
  Serial.println("Server online");

  //gestiamo le azione passate col GET nell'url
  server.on("/",    pagina);             //pagina base
  server.on("/outputUnoOn",  outputUnoOn);  //pagina output on
  server.on("/outputUnoOff", outputUnoOff); //pagina output off
  server.on("/outputDueOn", outputDueOn);
  server.on("/outputDueOff", outputDueOff);
  server.on("/outputTreOn", outputTreOn);
  server.on("/outputTreOff", outputTreOff);
}

void loop() {
  server.handleClient(); 
}
