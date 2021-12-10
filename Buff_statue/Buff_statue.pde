import processing.serial.*;
Serial myPort;
PImage AISES;
PImage CUWIC;
PImage NSBE;
PImage OSTEM;
PImage SAES;
PImage SHPE;
PImage SWE;
PImage WOAA;
char i = 'd';
void setup(){
  size(320,480);
  //load qr codes
  AISES = loadImage("AISES.png");
  CUWIC = loadImage("CUWIC.png");
  NSBE = loadImage("NSBE.png");
  OSTEM = loadImage("OSTEM.png");
  SAES = loadImage("SAES.png");
  SHPE = loadImage("SHPE MAES.png");
  SWE = loadImage ("SWE.png");
  WOAA = loadImage("WOAA.png");
  //String portName = Serial.list()[0]; //change the 0 to a 1 or 2 etc. to match your port
  //myPort = new Serial(this, portName, 9600);
}
void draw(){
  //  if ( myPort.available() > 0) 
  //{  // If data is available,
  //i = myPort.readChar();         
  //} 
  println(i);
  switch(i){
    case'a':
    image(AISES, 0, 0);
    break;
    case'b':
    image(CUWIC, 0, 0);
    break;
    case'c':
    image(NSBE, 0, 0);
    break;
    case'd':
    image(OSTEM, 0, 0);
    break;
      case'e':
    image(SAES, 0, 0);
    break;
    case'f':
    image(SHPE, 0, 0);
    break;
    case'g':
    image(SAES, 0, 0);
    break;
    case'h':
    image(SWE, 0, 0);
    break;
    case'i':
    image(WOAA, 0, 0);
    break;
  }
}
