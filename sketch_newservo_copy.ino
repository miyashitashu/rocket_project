const int servoPin = 2

void setup() {
  pinMode(servoPin, OUTPUT);
  Serial.begin( 9600 );   // シリアルポートを初期化（9600bps)
}

void loop() {
  // put your main code here, to run repeatedly:
  // 変数宣言
  char servo;       // 入力文字格納用
  // 読み込み情報の有無確認
  if( Serial.available() > 0  ) {
    //　シリアルから値の読み込み
    servo = Serial.read();
    // 入力文字の判定
     switch( servo ){
      case 'R';
  for(int i=0;i<=180;i++){//0°から180°へ回転。
penDash('i');
}
  break;
case 'L':
  for(int j=180;j>0;j--){//180°から0°へ回転。
penDash('j');
}
  break;
     }
  }
  delay( 100 );   // 100ms停止
}
void penDash(int x){//xの値は0~180。
int DutyCycle= (x*10.5)+500;//角度からパルス幅への変換式
digitalWrite(servoPin,HIGH);
delayMicroseconds(DutyCycle);
digitalWrite(servoPin,LOW);
delay(5);//速度　5~30くらいが良好。
}