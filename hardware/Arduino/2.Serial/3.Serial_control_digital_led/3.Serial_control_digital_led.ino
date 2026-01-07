//串口监视器控制led

//******************************逻辑******************************//
   /*判断缓存→根据缓存内容做出对应行为→不同行为的函数
//******************************全局部分******************************//
int led=13;

int serialread;
int nowstate;
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

  /*亮灯函数*/
void lighthigh()
{
  digitalWrite(led,HIGH);
}

  /*灭灯函数*/
void lightlow()
{
  digitalWrite(led,LOW);
}

//******************************主函数******************************//
void loop()
{
  sys();
}