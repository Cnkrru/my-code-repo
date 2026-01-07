//四舵机机械臂

//******************************逻辑******************************//
  /*第一层：bool判断运行模式

  /*指令模式第一层：available判断函数
  /*指令模式第二层：指令响应函数（4种功能：运行，回归原点，显示当前状态，切换模式）
  /*指令模式第三层：运行中的几种功能（舵机选择，舵机运行4种）

  /*手柄模式：舵机选择→手柄运动函数，切换模式
//******************************全局******************************//
#include<Servo.h>

Servo a_arm;
Servo b_arm;
Servo c_arm;
Servo d_arm;
Servo o;

int bianhao;

int jiaodu=90;
int nowjiaodu;
int nextjiaodu;

int jiaodua;
int jiaodub;
int jiaoduc;
int jiaodud;

bool mode=1;
//******************************初始化******************************//
void setup()
{
  a_arm.attach(9);
  b_arm.attach(7);  
  c_arm.attach(5);
  d_arm.attach(3);
  Serial.begin(9600);

  servobegin();
  serialteach();
}

  /*初始化函数以及复原函数*/
void servobegin()
{
  a_arm.write(jiaodu);
  b_arm.write(jiaodu);
  c_arm.write(jiaodu);
  d_arm.write(jiaodu);
  Serial.println("舵机初始化完成")
}

  /*使用手册*/
void serialteach()
{
  Serial.println("欢迎使用arm");
  Serial.println("**********************************************");
  Serial.println("指令表如下：");
  Serial.println("例如:a130");
  Serial.println("效果:a舵机旋转至130°");
  Serial.println("四个舵机分别对应abcd,角度为0~180");
  Serial.println("例如:q");
  Serial.println("效果:切换工作模式°");
  Serial.println("例如:ah");
  Serial.println("a舵机增加3°");
  Serial.println("模板:舵机编号+h/l");
  Serial.println("备注:h增加角度,l减小角度");
  Serial.println("**********************************************");

}

//******************************内层函数******************************//
  /*模式判断函数*/
void modecase()
{
  if(mode==1)
  {
    go();
  }
  if(mode==0)
  {
    anothersys();
  }
}

  /*available判断函数*/
void go()
{
  if(Serial.available()>0)
  {
    server();
  }
}

  /*指令响应函数*/
void server()
{
  bianhao=Serial.read();
  nextjiaodu=Serial.parseInt();

  if(bianhao=='a' || bianhao=='b' || bianhao=='c' ||bianhao=='d')
  {
    servocase();
    servogo();
  }
  else if(bianhao=='n')
  {
    servobegin();
  }
  else if(bianhao=='o')
  {
    state();
  }
  else if(bianhao=='q')
  {
    mode=0;
    Serial.println("已经切换至手柄模式");
  }
}

  /*读取当前状态函数*/
void state()
{
 jiaodua=a_arm.read();
 jiaodub=b_arm.read(); 
 jiaoduc=c_arm.read();
 jiaodud=d_arm.read();
 Serial.println("此时机械臂状态为：");
 Serial.print("a舵机:");
 Serial.println(jiaodua);
 Serial.print("b舵机:");
 Serial.println(jiaodub);
 Serial.print("c舵机:");
 Serial.println(jiaoduc);
 Serial.print("d舵机:");
 Serial.println(jiaodud);
}

  /*舵机选择函数*/
void servocase()
{
  switch(bianhao)
  {
    case 'a':
    o=a_arm;
    break;

    case 'b':
    o=b_arm;
    break;

    case 'c':
    o=c_arm;
    break;

    case 'd':
    o=d_arm;
    break;
  }
}

  /*舵机功能函数*/
void servogo()
{
  nowjiaodu=o.read();

  if(nowjiaodu<nextjiaodu && nextjiaodu<=180 && nextjiaodu>=0)
  {
    jiaoduhigh();
  }
  else if(nowjiaodu>nextjiaodu && nextjiaodu<=180 && nextjiaodu>=0)
  {
    jiaodulow();
  }
  else if(nextjiaodu==nowjiaodu)
  {
    serialstate();
  }
  else if(nextjiaodu>180 || nextjiaodu<0)
  {
    baocuo()
  }
}

  /*舵机递增函数*/
void jiaoduhigh()
{
  for(jiaodu=nowjiaodu;jiaodu<=nextjiaodu;jiaodu++)
  {
    o.write(jiaodu);
    delay(20);
    nowjiaodu=jiaodu;
  }
}

  /*舵机递减函数*/
void jiaodulow()
{
  for(jiaodu=nowjiaodu;jiaodu>=nextjiaodu;jiaodu--)
  {
    o.write(jiaodu);
    delay(20);
    nowjiaodu=jiaodu;
  }
}

  /*舵机始末位置相同时的反应*/
void serialstate()
{
  Serial.println("无需变化，请输入其他角度");
}

  /*角度不合适的报错函数*/
void baocuo()
{
  Serial.println("warning!!!,请输入正确的角度数值");
}

  /*手柄系统*/
void anothersys()
{
  bianhao=Serial.read();
  /*舵机选择*/
  servocase();
  nowjiaodu=o.read();
  /*手柄运动函数*/
  if(bianhao=='h')
  {
    nextjiaodu=nowjiaodu+3;
    if(nextjiaodu>180)
    {
      baocuo();
    }
    else 
    {
      jiaoduhigh();
    }
  }
  else if(bianhao=='l')
  {
    nextjiaodu=nowjiaodu-3;
    if(nextjiaodu<0)
    {
      baocuo();
    }
    else
    {
      jiaodulow();
    }
  }
  else if(bianhao=='q')
  {
    mode=1;
    Serial.println("已经切换至指令模式");
  }
}
//******************************主函数******************************//
void loop()
{
  modecase();
}