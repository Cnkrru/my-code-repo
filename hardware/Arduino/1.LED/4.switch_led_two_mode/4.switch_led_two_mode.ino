//开关控制led亮灭程序

//******************************逻辑******************************//
  /*问题：为什么与开关控制灯亮与灭不同
  /*解答：亮灭是1/0二者变化，而该程序为0与0/1两个工作模式的变化，相当于1/0变化里嵌套一层1/0变化，所以多一层判断：模式切换函数

  /*问题：为什么使用millis函数而不用delay
  /*解答：delay函数造成的延时会导致切换功能失效，当你想切换模式时，他可能处于delay状态，此时无法切换
          delay像是整体中插入一块，而millis像是整体中取出一块作为模式工作时间

          //这个问题不是很懂，如有疑问，还请另请高明

  /*最外层按钮切换函数和之前的一样，只是变量变了
  /*第二层是模式切换函数（受第一层函数控制）
  /*第三层就是两种工作模式

  /*millis函数使用模板
  nowtime=millis（）;
  if（nowtime-lasttime>函数体工作时间）
  {
    函数体
    lasttime=nowtime;
  }          
  /*逻辑，每次都是取millis（）的时间为“现在时间，
          而上一次的“现在时间”作为这一次的过去时间
  */

//******************************全局变量部分******************************//
int key=11;
int led=13;

int state;
int laststate=1;
int ledstate=0;
bool automode=0;

unsigned long lasttime=0;
unsigned long nowtime=0;

//******************************初始化部分******************************//
void setup()
{
  pinMode(key,INPUT_PULLUP);
  pinMode(led,OUTPUT);
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
    liangmie();
  }
}

  /*灭灯函数*/
void mie()
{
  digitalWrite(led,LOW);
}

  /*亮灭函数*/
void liangmie()
{
  nowtime=millis();
 if(nowtime-lasttime>3000)
 {
  ledstate=!ledstate;
  digitalWrite(led,ledstate);
  lasttime=nowtime;
 }
}
//******************************主程序******************************//
void loop()
{
 switchkey();
}