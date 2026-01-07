//开关倒计时

//******************************逻辑******************************//
  /*简单的依次从9-1输出，清屏即可*/

//******************************全局部分******************************//
int key=11;
int i;

int state;
int laststate=1;

//******************************初始化******************************//
void setup()
{
  for(i=3;i<10;i++)
  {
    pinMode(i,OUTPUT);
  }

  pinMode(key,INPUT_PULLUP);
}

//******************************内层函数******************************//
  /*按钮函数*/
void countdown()
{
  state=digitalRead(key);

  if(state==0 && laststate==1)
  {
    count();
    laststate=state;
  }

  if(state==1 && laststate==0)
  {
    laststate=1;
  }
}

  /*倒计时函数*/
void count()
{

    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    clean();

    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    clean();

    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    clean();

    digitalWrite(3,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(9,HIGH);
    clean();

    digitalWrite(3,HIGH);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    clean();

    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    clean();

    digitalWrite(3,HIGH); 
    digitalWrite(4,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    clean();

    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(6,HIGH);
    clean();

    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    clean();
}
  /*清屏函数*/
void clean()
{
 for(i=3;i<10;i++)
 {
  digitalWrite(i,LOW);
 }
 delay(1000);
}

//******************************主函数******************************//
void loop()
{
  countdown();
}