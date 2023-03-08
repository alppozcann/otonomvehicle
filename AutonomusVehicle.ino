// Video Linki: https://youtu.be/22g7Y91TShE

#define S0 2
#define S1 10
#define S2 11
#define S3 12
#define sensorOut 8 // Renk Sensörü pinleri

#define MotorR1 7 // L298N üzerindeki IN1 pini
#define MotorR2 6 //L298N üzerindeki IN2 pini
#define MotorRenable 9  // L298N üzerindeki enA pini
#define MotorL1 5 // L298N üzerindeki IN3 pini
#define MotorL2 4 // L298N üzerindeki IN4 pini
#define MotorLenable 3// L298N üzerindeki enB pini

int Redfrequency = 0;
int Greenfrequency = 0; //Kırmızı ve yeşil renklerin frekanslarını alacağımız değişkeni yarattık
int veri;  // Bluetooth verisi

void setup() {
  pinMode(MotorL1, OUTPUT);
  pinMode(MotorL2, OUTPUT);
  pinMode(MotorLenable, OUTPUT); 
  pinMode(MotorR1, OUTPUT);
  pinMode(MotorR2, OUTPUT);
  pinMode(MotorRenable, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);

  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  Serial.begin(9600);   //Seri haberleşmeyi başlattık            
}
void loop() {
  if(Serial.available()>0){   
    Serial.print("Bağlandı!");      //Seri haberleşmeden veri gelmesini bekliyoruz.
    veri = Serial.read();         //Seri haberleşmeden gelen veriyi okuyoruz.
  }

  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  Redfrequency = pulseIn(sensorOut, LOW); //Kırmızı rengi ölçmeye başladık
  Redfrequency = map(Redfrequency, 385,102,255,0); //Kırmızı rengin değerini daha kolay anlayabilmek için 0 ve 255'e göre ayarladık
  delay(100);
  Greenfrequency = pulseIn(sensorOut, LOW); //Yeşil rengi ölçmeye başladık
  Greenfrequency = map(Greenfrequency, 370,125,255,0); //Yeşil rengin değerini daha kolay anlayabilmek için 0 ve 255'e göre ayarladık
  delay(100);

  if(Redfrequency < 20){ //Kırmızı rengi algılıyorsa dur fonksiyonunu çalıştır.
    dur();
    delay(1000);
}
  if(veri == '1'){ //İleri tuşuna basınca bluetoothdan gelen 1 değerini alırsan ileri fonksiyonunu çalıştır
    ileri();
    delay(1000);
  }
    if(veri == '2'){//Geri tuşuna basınca bluetoothdan gelen 2 değerini alırsan geri fonksiyonunu çalıştır
    geri();
    delay(1000);
  }
    if(veri == '3'){ //Sağ tuşuna basınca bluetoothdan gelen 3 değerini alırsan sag fonksiyonunu çalıştır
    sag();
    delay(1000);
  }
  if(veri == '4'){//Sol tuşuna basınca bluetoothdan gelen 4 değerini alırsan sol fonksiyonunu çalıştır
    sol();
    delay(1000);
  }

}
 

 void ileri(){  // Robotun ileri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRenable, 200); // Sağ motorun hızı 150

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLenable, 200); // Sol motorun hızı 150
  
  
}


void sag(){ // Robotun sağa dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorRenable, 0); // Sağ motorun hızı 0 (Motor duruyor)

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorLenable, 150); // Sol motorun hızı 150
  
  
}
void sol(){ // Robotun sola dönme hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorL1, HIGH); // Sol motorun ileri hareketi aktif
  digitalWrite(MotorL2, LOW); // Sol motorun geri hareketi pasif
  analogWrite(MotorRenable, 0); // Sol motorun hızı 0 (Motor duruyor)

  digitalWrite(MotorR1, HIGH); // Sağ motorun ileri hareketi aktif
  digitalWrite(MotorR2, LOW); // Sağ motorun geri hareketi pasif
  analogWrite(MotorLenable, 150); // Sağ motorun hızı 150
  
  
}


void geri(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi pasif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi aktif
  analogWrite(MotorRenable, 150); // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi aktif
  analogWrite(MotorLenable, 150); // Sol motorun hızı 150
  
}
void dur(){ // Robotun geri yönde hareketi için fonksiyon tanımlıyoruz.

  digitalWrite(MotorR1, LOW); // Sağ motorun ileri hareketi pasif
  digitalWrite(MotorR2, HIGH); // Sağ motorun geri hareketi aktif
  analogWrite(MotorRenable, 0); // Sağ motorun hızı 150

  digitalWrite(MotorL1, LOW); // Sol motorun ileri hareketi pasif
  digitalWrite(MotorL2, HIGH); // Sol motorun geri hareketi aktif
  analogWrite(MotorLenable, 0); // Sol motorun hızı 150
  
}

