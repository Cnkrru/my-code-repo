//模拟信号读取

//******************************逻辑******************************//
  /*这是一段开关控制的可变亮度led灯
  /*可通过串口监视器读取当前亮度状态

//******************************全局部分******************************//
int led=3;
int key=4;

int state;
int laststate=1;

int light=0;
//******************************初始化******************************//
void setup()
{
  pinMode(3,OUTPUT);
  pinMode(4,INPUT_PULLUP);
  Serial.begin(9600);
}

//******************************内层函数******************************//
  /*按钮函数*/
void sys()
{
  state=digitalRead(4);
  
  if(state==0 && laststate==1)
  {
    change();
    laststate=state;
  }

  if(state==1 && laststate==0)
  {
    laststate=1;
  }
}

  /*亮度改变函数*/
void change()
{

  for(light=0;light<=255;light++)
  {
   analogWrite(3,light);
   serialread();
  }

  for(light=255;light>=0;light--)
  {
   analogWrite(3,light);
   serialread();    
  }
}

  /*读取状态函数*/
void serialread()
{
  Serial.print("当前状态为：");
  Serial.println(light);
}

//******************************主函数******************************//
void loop()
{
  sys();
}