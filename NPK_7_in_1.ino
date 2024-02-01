#include <SoftwareSerial.h>

#define RE 7
#define DE 6

const uint32_t TIMEOUT = 500UL;

const byte moist[] = {0x01, 0x03, 0x00, 0x00, 0x00, 0x01, 0x84, 0x0A};
const byte temp[] = {0x01, 0x03, 0x00, 0x01, 0x00, 0x01, 0xD5, 0xCA};
const byte EC[] = {0x01, 0x03, 0x00, 0x02, 0x00, 0x01, 0x25, 0xCA};
const byte PH[] = {0x01, 0x03, 0x00, 0x03, 0x00, 0x01, 0x74, 0x0A};

const byte nitro[] = {0x01, 0x03, 0x00, 0x04, 0x00, 0x01, 0xc5, 0xcb};
const byte phos[] = {0x01, 0x03, 0x00, 0x05, 0x00, 0x01, 0x94, 0x0b};
const byte pota[] = {0x01, 0x03, 0x00, 0x06, 0x00, 0x01, 0x64, 0x0b};


byte values[11];
SoftwareSerial mod(2, 3); // Rx pin, Tx pin

void setup() {
  //  Serial.begin(9600);
  Serial.begin(4800);
  mod.begin(4800);
  pinMode(RE, OUTPUT);
  pinMode(DE, OUTPUT);

  delay(500);
}

void loop() {
  byte val1, val2, val3, val4, val5, val6, val7;

  Serial.println("Moisture: ");
  val1 = moisture();
  float Val1 = val1 * 0.1;
  delay(1000);
  //Serial.print(val1);
  Serial.print(Val1);
  Serial.println(" %");
  Serial.println("-----");
  //delay(1000);

  Serial.println("Temperature: ");
  val2 = temperature();
  float Val2 = val2 * 0.1;
  delay(1000);
  //Serial.print(val2);
  Serial.print(Val2);
  Serial.println(" *C");
  Serial.println("-----");
  //delay(1000);

  Serial.println("Conductivity: ");
  val3 = conductivity();
  delay(1000);
  Serial.print(val3);
  Serial.println(" us/cm");
  Serial.println("-----");

  Serial.println("Ph: ");
  val4 = ph();
  float Val4 = val4 * 0.1;
  delay(1000);
  //Serial.print(val4);
  Serial.print(Val4);
  Serial.println(" ph");
  Serial.println("-----");

  Serial.println("Nitrogen (N): ");
  val5 = nitrogen();
  float Val5 = val5 * 0.1;
  delay(1000);
  //Serial.print(val4);
  Serial.print(Val5);
  Serial.println(" mg/kg");
  Serial.println("-----");

  Serial.println("Phosphorous (P): ");
  val6 = phosphorous();
  float Val6 = val6 * 0.1;
  delay(1000);
  //Serial.print(val4);
  Serial.print(Val6);
  Serial.println(" mg/kg");
  Serial.println("-----");

  Serial.println("Potassium (K): ");
  val7 = potassium();
  float Val7 = val7 * 0.1;
  delay(1000);
  //Serial.print(val4);
  Serial.print(Val7);
  Serial.println(" mg/kg");
  Serial.println("-----");

  delay(5000);
}

int16_t moisture() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(moist, sizeof(moist));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}

int16_t temperature() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(temp, sizeof(temp));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}

int16_t conductivity() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(EC, sizeof(EC));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}

int16_t ph() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(PH, sizeof(PH));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}
int16_t nitrogen() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(nitro, sizeof(nitro));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}
int16_t phosphorous() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(phos, sizeof(phos));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}

int16_t potassium() {
  uint32_t startTime = 0;
  uint8_t  byteCount = 0;

  digitalWrite(DE, HIGH);
  digitalWrite(RE, HIGH);
  delay(10);
  mod.write(pota, sizeof(pota));
  mod.flush();
  digitalWrite(DE, LOW);
  digitalWrite(RE, LOW);

  startTime = millis();
  while ( millis() - startTime <= TIMEOUT ) {
    if (mod.available() && byteCount < sizeof(values) ) {
      values[byteCount++] = mod.read();
      printHexByte(values[byteCount - 1]);
    }
  }
  Serial.println();
  return (int16_t)(values[4] << 8 | values[5]);

}

void printHexByte(byte b)
{
  Serial.print((b >> 4) & 0xF, HEX);
  Serial.print(b & 0xF, HEX);
  Serial.print(' ');
}