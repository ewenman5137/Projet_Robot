#include <Arduino.h>
#include <NimBLEDevice.h>
#include <XboxSeriesXControllerESP32_asukiaaa.hpp>
#include <XboxControllerNotificationParser.h>

using namespace XboxSeriesXControllerESP32_asukiaaa;

// Déclaration du contrôleur
Core controller;

void setup() {
  Serial.begin(115200); // Initialiser le moniteur série pour le débogage
  Serial1.begin(115200, SERIAL_8N1, 18, 19); // Initialiser Serial1 (TX=18, RX=19)
  Serial.println("Starting Xbox Series X controller example");

  // Initialiser le Bluetooth
  NimBLEDevice::init("");
  Serial.println("Bluetooth initialized");

  // Initialiser la bibliothèque du contrôleur
  controller.begin();
  Serial.println("Controller library initialized");

  // Démarrer le scan pour trouver des périphériques
  controller.startScan();
  Serial.println("Started scanning for devices...");
}

void loop() {
  controller.onLoop();

  // Vérifiez si le contrôleur est connecté
  if (controller.isConnected()) {
    // Utilisez les attributs disponibles dans XboxControllerNotificationParser
    XboxControllerNotificationParser &notif = controller.xboxNotif;


    uint16_t rightTrigger = notif.trigRT;
    uint16_t leftTrigger = notif.trigLT;
    uint16_t leftJoystickX = notif.joyLHori;
    uint16_t leftJoystickY = notif.joyLVert;
    uint16_t rightJoystickX = notif.joyRHori;
    uint16_t rightJoystickY = notif.joyRVert;

    // Capture des boutons
    bool buttonA = notif.btnA;
    bool buttonB = notif.btnB;
    bool buttonX = notif.btnX;
    bool buttonY = notif.btnY;
    bool buttonLB = notif.btnLB;
    bool buttonRB = notif.btnRB;
    bool buttonStart = notif.btnStart;
    bool buttonXbox = notif.btnXbox;

    char message[200];
    snprintf(message, sizeof(message),
      "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,%d, %d, %d,\n",
      rightTrigger, leftTrigger, leftJoystickX, leftJoystickY, rightJoystickX, rightJoystickY, buttonA, buttonB, buttonX, buttonY, buttonLB, buttonRB, buttonStart, buttonXbox);
    Serial.print(message);
  } else {
    Serial.println("Controller is not connected");
  }

  delay(100); // Attendez un peu avant de réessayer
}
