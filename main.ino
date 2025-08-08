#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <U8g2lib.h>

// Wi-Fi Credentials
const char* ssid = "Dev Bhai OP";
const char* password = "devbhai123omsairam";

// OLED SH1106
U8G2_SH1106_128X64_NONAME_F_HW_I2C oled(U8G2_R0, U8X8_PIN_NONE, 21, 22);

// Pins
const int BTN1 = 4, BTN2 = 12, BTN3 = 35, BTN4 = 15;
const int BUZZER = 5;
const int RED_PIN = 26, GREEN_PIN = 27, BLUE_PIN = 33;

// State
String oledText = "Welcome ji!";
bool buzzNow = false;
int red = 0, green = 0, blue = 0;

AsyncWebServer server(80);

void setRGB(int r, int g, int b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

void displayText(String txt) {
  oled.clearBuffer();
  oled.setFont(u8g2_font_logisoso18_tf); // Bigger font
  int tx = (128 - oled.getStrWidth(txt.c_str())) / 2;
  oled.drawStr(tx < 0 ? 0 : tx, 40, txt.c_str());
  oled.sendBuffer();
}

void setup() {
  Serial.begin(115200);
  oled.begin();
  displayText(oledText);

  pinMode(BTN1, INPUT_PULLUP);
  pinMode(BTN2, INPUT_PULLUP);
  pinMode(BTN3, INPUT);
  pinMode(BTN4, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  setRGB(0, 0, 0);

  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500); Serial.print(".");
  }
  Serial.println("\nConnected! IP: " + WiFi.localIP().toString());

  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
    String html = R"rawliteral(
    <html>
    <body style="font-family:sans-serif">
      <h2>Button States:</h2><pre id='btn'>Loading...</pre>

      <h2>OLED Text:</h2>
      <input type='text' id='msg'><button onclick='sendText()'>Send</button>
      <button onclick='clearText()'>Clear</button>

      <h2>RGB Color (Buttons):</h2>
      <button onclick="setColor('red')">🔴 Red</button>
      <button onclick="setColor('green')">🟢 Green</button>
      <button onclick="setColor('blue')">🔵 Blue</button>
      <button onclick="setColor('white')">⚪ White</button>
      <button onclick="setColor('off')">❌ Off</button>

      <h2>RGB Sliders:</h2>
      R: <input type='range' min='0' max='255' id='r' oninput='sliderRGB()'><br>
      G: <input type='range' min='0' max='255' id='g' oninput='sliderRGB()'><br>
      B: <input type='range' min='0' max='255' id='b' oninput='sliderRGB()'><br>

      <h2>Buzzer:</h2>
      <button onclick="fetch('/buzz')">Buzz!</button>

      <script>
        function sendText() {
          let msg = document.getElementById("msg").value;
          fetch("/oled?msg=" + encodeURIComponent(msg));
        }
        function clearText() {
          fetch("/oled?msg=");
        }
        function setColor(color) {
          fetch("/rgb?color=" + color);
        }
        function sliderRGB() {
          let r = document.getElementById("r").value;
          let g = document.getElementById("g").value;
          let b = document.getElementById("b").value;
          fetch(`/rgb?r=${r}&g=${g}&b=${b}`);
        }
        setInterval(() => {
          fetch("/btn").then(r => r.text()).then(t => {
            document.getElementById("btn").innerText = t;
          });
        }, 1000);
      </script>
    </body></html>
    )rawliteral";
    request->send(200, "text/html", html);
  });

  server.on("/btn", HTTP_GET, [](AsyncWebServerRequest *request) {
    String state = "";
    state += "BTN1: " + String(digitalRead(BTN1) == LOW ? "Pressed" : "Released") + "\n";
    state += "BTN2: " + String(digitalRead(BTN2) == LOW ? "Pressed" : "Released") + "\n";
    state += "BTN3: " + String(digitalRead(BTN3) == HIGH ? "Pressed" : "Released") + "\n";
    state += "BTN4: " + String(digitalRead(BTN4) == LOW ? "Pressed" : "Released") + "\n";
    request->send(200, "text/plain", state);
  });

  server.on("/oled", HTTP_GET, [](AsyncWebServerRequest *request) {
    oledText = request->hasParam("msg") ? request->getParam("msg")->value() : "";
    displayText(oledText);
    request->send(200, "text/plain", "OLED updated");
  });

  server.on("/rgb", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("color")) {
      String color = request->getParam("color")->value();
      if (color == "red") setRGB(255, 0, 0);
      else if (color == "green") setRGB(0, 255, 0);
      else if (color == "blue") setRGB(0, 0, 255);
      else if (color == "white") setRGB(255, 255, 255);
      else setRGB(0, 0, 0); // off
    } else {
      red = request->hasParam("r") ? request->getParam("r")->value().toInt() : red;
      green = request->hasParam("g") ? request->getParam("g")->value().toInt() : green;
      blue = request->hasParam("b") ? request->getParam("b")->value().toInt() : blue;
      setRGB(red, green, blue);
    }
    request->send(200, "text/plain", "RGB updated");
  });

  server.on("/buzz", HTTP_GET, [](AsyncWebServerRequest *request) {
    buzzNow = true;
    request->send(200, "text/plain", "Buzzed!");
  });

  server.begin();
}

void loop() {
  if (buzzNow) {
    digitalWrite(BUZZER, HIGH);
    delay(150);
    digitalWrite(BUZZER, LOW);
    buzzNow = false;
  }
}
