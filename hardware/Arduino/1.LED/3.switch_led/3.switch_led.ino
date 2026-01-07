//开关控制led亮灭程序

//******************************逻辑******************************//
  /*state与laststate双变量实现短按可控

  /*以第一次按按钮为例
  /*按下前的按钮状态记为：laststate，1.对应高电位
  /*按下后的按钮状态记为：state，0，对应低电位

  /*按下时，符合第一个if语句
  /*state与laststate状态相反作为判断条件，并将state的状态传给laststate
  /*此时接着长按，state=laststate，引脚输出状态不变

  /*松手时，符合第二个if语句
  /*此时将laststate的状态复原，用于下一次按下

  /*ledstate用于简化亮灭程序
  */

//******************************全局变量部分******************************//
int key=11;
int led=13;

int state;
int laststate=1;
int ledstate=0;

//******************************初始化部分******************************//
void setup()
{
  pinMode(key,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}

//******************************主程序******************************//
void loop()
{
  state=digitalRead(key);
  
  if(state==0 && laststate==1)
  {
    ledstate=!ledstate;
    digitalWrite(led,ledstate);
    laststate=state;
  }
  
  if(state==1 && laststate==0)
  {
    laststate=1;    
  }
}