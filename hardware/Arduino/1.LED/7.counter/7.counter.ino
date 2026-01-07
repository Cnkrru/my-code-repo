//计数器程序

//******************************逻辑******************************//
  /*计数器与开关/控制逻辑相同
  /*state与laststate双变量控制

  /*写了这么多发现，若只是1/0，变化，则只需要一层控制
  /*               若为双层1/0，则为mode变化

  /*两套模板，其实第二套适用更宽广，可以拓展很远
  */

//******************************全局变量******************************//
int i;
int key=13;

int state;
int laststate=1;
int addition=0;

//******************************初始化******************************//
void setup()
{
  for(i=3;i<=9;i++)
 {
  pinMode(i,OUTPUT);
 }
 pinMode(key,INPUT_PULLUP);
}

//******************************内层函数******************************//

  /*受控函数*/
void sys()
{
  state=digitalRead(key);

  if(state==0 && laststate==1)
  {
    clean();
    addition++;
    add();
    laststate=state; 
  }

  if(state==1 && laststate==0)
  {
    laststate=1;
  }
}

  /*计数器函数*/
void add()
{
  if(addition==10)
  {
    addition=0;
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,HIGH);
  }
  else
  {
  switch(addition)
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
  }
  }
}

  /*清屏函数*/
void clean()
{
  for(i=3;i<=9;i++)
 {
  digitalWrite(i,LOW);
 }
}

//******************************主函数******************************//
void loop()
{
  sys();
}
