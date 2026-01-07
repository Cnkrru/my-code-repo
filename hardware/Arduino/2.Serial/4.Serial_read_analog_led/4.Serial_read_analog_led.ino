//串口监视器控制led

//******************************逻辑******************************//
   /*判断缓存→根据缓存内容做出对应行为→不同行为的函数
//******************************全局部分******************************//
int led=3;

int serialread;
int nowstate;

int light=0;
//******************************初始化******************************//
void setup()
{
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}
//******************************内层函数******************************//
  /*缓存读取函数*/
void sys()
{
  serialread=Serial.available();

  if(serialread>0)
  {
    server();
  }
}

  /*指令判断函数*/
void server()
{
  nowstate=Serial.parseInt();
  switch(nowstate)
  {
    case 1:
    lighthigh();
    break;

    case 0:
    lightlow();
    break;
  }
}

  /*递增函数*/
void lighthigh()
{
  if(light>=0 && light<255)
  {
    light++;
    analogWrite(led,light);
    delay(20);
  }
}

  /*递减函数*/
void lightlow()
{
  if(light>0 && light<=255)
  {
    light--;
    analogWrite(led,light);
    delay(20);
  }
}

//******************************主函数******************************//
void loop()
{
  sys();
}