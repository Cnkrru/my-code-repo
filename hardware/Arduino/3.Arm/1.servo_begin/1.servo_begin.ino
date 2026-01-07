//舵机第一个程序:单舵机控制程序

//由于是复写，所以写begin时，其实功能已经写的比较多了

//******************************逻辑******************************//
  /*初始化（确定初始角度）→avaliable作为第一层函数判断缓存→server中三种情况时的工作状态→其余为子函数
//******************************全局******************************//
#include<Servo.h>
Servo servo1;

int jiaodu=90;
int nowjiaodu;
int nextjiaodu;
//******************************初始化******************************//
void setup()
{
  servo1.attach(9);
  Serial.begin(9600);
  jiaodubegin();
}

  /*舵机初始化函数*/
void jiaodubegin()
{
  servo1.write(jiaodu);
  Serial.println("舵机初始化完成")
}

//******************************内层函数******************************//
void begin()
{
  /*串口控制模板*/
  if(Serial.available()>0)
  {
    server();
  }
}

  /*舵机工作板块*/
void server()
{

  nowjiaodu=servo1.read();
  nextjiaodu=Serial.parseInt();
  
  if(nextjiaodu>nowjiaodu && nextjiaodu<=180 && nextjiaodu>=0)
  {
    anglehigh();
  }
  else if(nextjiaodu<nowjiaodu && nextjiaodu<=180 && nextjiaodu>=0)
  {
    anglelow();
  }
  else if(nextjiaodu>180 || nextjiaodu<0)
  {
    error();
  }
  else if(nextjiaodu==nowjiaodu)
  {
    serialstate();
  }
}

  /*报错函数*/
void error()
{
  Serial.println("Warning!请输入符合范围的角度")
}

  /*不变函数*/
void serialstate()
{
  Serial.println("无需变化，请输入其他角度");
}
  /*递增函数*/
void anglehigh()
{
  for(jiaodu=nowjiaodu;jiaodu<=nextjiaodu;jiaodu++)
  {
    servo1.write(jiaodu);
    delay(20);
    serial();
    nowjiaodu=jiaodu;
  }
}

  /*递减函数*/
void anglelow()
{
  for(jiaodu=nowjiaodu;jiaodu>=nextjiaodu;jiaodu--)
  {
    servo1.write(jiaodu);
    delay(20);
    serial();
    nowjiaodu=jiaodu;
  }
}

  /*读取当前状态的函数*/
void serial()
{
  Serial.print("当前角度为：");
  Serial.println(jiaodu);
}
//******************************主函数******************************//
void loop()
{
  begin();
}