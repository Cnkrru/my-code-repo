//随机数生成器

//******************************逻辑******************************//
  /*使用随机数函数给变量赋值，switch函数根据此变量做出反应
  /*两个内层函数，一个随机数函数，一个清屏函数
  */

//*******************************************全局部分*****************************//
int pin;
int num;
//*********************************************初始化****************************//
void setup()
{
  for(pin=3;pin<10;pin++)
  {
    pinMode(pin,OUTPUT);
  }
}
//**************************************内部函数********************************//
void clean()
{
 for(pin=3;pin<10;pin++)
 {
  digitalWrite(pin,LOW);
 }
 delay(1000);
}
//*******************************************主函数******************************//
//   3
//8     4
//   9
//7     5
//   6
void loop()
{
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
 delay(1000);
 clean();
}