//按钮控制随机数生成器

//******************************逻辑******************************//
  /*格式与先前的部分一致，     先前的：开关函数→模式函数→工作函数       现在的，开关函数→模式函数→状态判断函数(工作函数) 
  /*不同的是：工作层外需要套套一层缓冲函数：状态变化函数，需要给清屏函数和随机数生成函数划分millis（）时间区域
  /*划分区域，通过switch函数以及状态循环来实现
  */

//******************************全局部分******************************//
int pin;
int num;
int i;
int key=11;

int state;
int laststate=1;
bool automode=0;

unsigned long nowtime=0;
unsigned long lasttime=0;
int nowstate=0;


//******************************初始化******************************//
void setup()
{
  for(pin=3;pin<=9;pin++)
  {
    pinMode(pin,OUTPUT);
  }

  pinMode(key,INPUT_PULLUP);
}

//******************************内层函数******************************//

  /*按钮切换函数*/
void switchkey()
{
  state=digitalRead(key);
  if(state==0 && laststate==1)
  {
    automode=!automode;
    laststate=state;
    autoswitch();
  }

  if(state==1 && laststate==0)
  {
    laststate=1;
  }
}

  /*模式切换函数*/
void autoswitch()
{
  if(automode==0)
  {
   mie();
  }
  else
  {
    mathswitch();
  }
}

  /*状态变化函数*/
void mathswitch()
{
  switch(nowstate)
  {
    case 0:
    nowtime=millis();
    if(nowtime-lasttime>=500)
    {
      mie();
      nowstate=1;
      lasttime=nowtime;
    }
    break;

    case 1:
    nowtime=millis();
    if(nowtime-lasttime>=1000)
    {
      randommath();
      nowstate=0;
      lasttime=nowtime;
    }
    break;

  }
}

  /*随机数函数*/
void randommath()
{
  mie();
 num=random(0,10);
 switch(num)
 {
    case 1:
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    break;

    case 2:
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    break;

    case  3:
    digitalWrite(3,HIGH); 
    digitalWrite(4,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    break;

    case 4:
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    break;

    case 5:
    digitalWrite(3,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    break;

    case 6:
    digitalWrite(3,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(9,HIGH);
    break;

    case 7:
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    break;

    case 8:
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;

    case 9:
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    break;

    default:
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
 }
}

  /*灭屏函数*/
void mie()
{
  for(i=3;i<=9;i++)
  {
    digitalWrite(i,LOW);
  }
}

//******************************主函数******************************//
void loop()
{
 switchkey();
}