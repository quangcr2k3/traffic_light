//chân ST_CP của 74HC595 cột số 13
int latchPin13 = 12;
//chân SH_CP của 74HC595 cột số 13
int clockPin13 = 13;
//Chân DS của 74HC595 cột số 13
int dataPin13 = 11;
int redLedPin13 = 5; // Chân kết nối đèn LED đỏ cột số 13
int yellowLedPin13 = 6; // Chân kết nối đèn LED vàng cột số 13
int greenLedPin13 = 7; // Chân kết nối đèn LED xanh cột số 13

//chân ST_CP của 74HC595 cột số 24
int latchPin24 = 9;
//chân SH_CP của 74HC595 cột số 24
int clockPin24 = 8;
//Chân DS của 74HC595 cột số 24
int dataPin24 = 10;
int redLedPin24 = 2; // Chân kết nối đèn LED đỏ cột số 24
int yellowLedPin24 = 3; // Chân kết nối đèn LED vàng cột số 24
int greenLedPin24 = 4; // Chân kết nối đèn LED xanh cột số 24

// Mảng chứa các giá trị segment cho LED 7 đoạn từ 0-9
const byte Seg[10] = {
  0b11000000, //0 - các thanh từ a-f sáng
  0b11111001, //1 - chỉ có 2 thanh b,c sáng
  0b10100100, //2
  0b10110000, //3
  0b10011001, //4
  0b10010010, //5
  0b10000010, //6
  0b11111000, //7
  0b10000000, //8
  0b10010000  //9
};

void setup() {
  pinMode(latchPin13, OUTPUT);
  pinMode(clockPin13, OUTPUT);
  pinMode(dataPin13, OUTPUT);
  pinMode(redLedPin13, OUTPUT);
  pinMode(yellowLedPin13, OUTPUT);
  pinMode(greenLedPin13, OUTPUT);
  
  pinMode(latchPin24, OUTPUT);
  pinMode(clockPin24, OUTPUT);
  pinMode(dataPin24, OUTPUT);
  pinMode(redLedPin24, OUTPUT);
  pinMode(yellowLedPin24, OUTPUT);
  pinMode(greenLedPin24, OUTPUT);
}

void loop() {

  LED7doan13_countdown(30); // Chu kì Led 7 thanh cột 13 đếm ngược từ 30 về 0
  
  LED7doan24_countdown(30); // Chu kì Led 7 thanh cột 24 đếm ngược từ 30 về 0
  
}

void LED7doan13_countdown(int value) {
  for (int i = value; i >= 0; i--) {
    turnOffLed13();
  	turnOnRedLed13();
    LED7doan13(i); // Hiển thị giá trị i lên Led 7 thanh
    if (i-5>=0) { 
      	turnOffLed24();
      	turnOnGreenLed24();
    	LED7doan24(i-5);
    }
    else {
      	turnOffLed24();
      	turnOnYellowLed24();
    	LED7doan24(i);
    }
    delay(1000); // Đợi 1 giây trước khi hiển thị giá trị kế tiếp
  }
}

void LED7doan24_countdown(int value) {
  for (int i = value; i >= 0; i--) {
    turnOffLed24();
  	turnOnRedLed24();
    LED7doan24(i); // Hiển thị giá trị i lên Led 7 thanh
    if (i-5>=0) {
      	turnOffLed13();
      	turnOnGreenLed13();
    	LED7doan13(i-5);
    }
    else {
      	turnOffLed13();
      	turnOnYellowLed13();
    	LED7doan13(i);
    }
    delay(1000); // Đợi 1 giây trước khi hiển thị giá trị kế tiếp
  }
}


void LED7doan13(int value) {
  if (value > 99) {
    return; // Hàm chỉ hỗ trợ hiển thị giá trị từ 0-99
  }
  
  byte tensDigit = value / 10; // Lấy chữ số hàng chục
  byte onesDigit = value % 10; // Lấy chữ số hàng đơn vị
  
  digitalWrite(latchPin13, LOW);
  
  shiftOut(dataPin13, clockPin13, MSBFIRST, Seg[tensDigit]); // Hiển thị chữ số hàng chục
  shiftOut(dataPin13, clockPin13, MSBFIRST, Seg[onesDigit]); // Hiển thị chữ số hàng đơn vị
    
  digitalWrite(latchPin13, HIGH);
}

void LED7doan24(int value) {
  if (value > 99) {
    return; // Hàm chỉ hỗ trợ hiển thị giá trị từ 0-99
  }
  
  byte tensDigit = value / 10; // Lấy chữ số hàng chục
  byte onesDigit = value % 10; // Lấy chữ số hàng đơn vị
  
  digitalWrite(latchPin24, LOW);
  
  shiftOut(dataPin24, clockPin24, MSBFIRST, Seg[tensDigit]); // Hiển thị chữ số hàng chục
  shiftOut(dataPin24, clockPin24, MSBFIRST, Seg[onesDigit]); // Hiển thị chữ số hàng đơn vị
    
  digitalWrite(latchPin24, HIGH);
}

void turnOnRedLed13() {
  digitalWrite(redLedPin13, HIGH);
}

void turnOnYellowLed13() {
  digitalWrite(yellowLedPin13, HIGH);
}

void turnOnGreenLed13() {
  digitalWrite(greenLedPin13, HIGH);
}

void turnOffLed13() {
  digitalWrite(redLedPin13, LOW);
  digitalWrite(yellowLedPin13, LOW);
  digitalWrite(greenLedPin13, LOW);
}

void turnOnRedLed24() {
  digitalWrite(redLedPin24, HIGH);
}

void turnOnYellowLed24() {
  digitalWrite(yellowLedPin24, HIGH);
}

void turnOnGreenLed24() {
  digitalWrite(greenLedPin24, HIGH);
}

void turnOffLed24() {
  digitalWrite(redLedPin24, LOW);
  digitalWrite(yellowLedPin24, LOW);
  digitalWrite(greenLedPin24, LOW);
}