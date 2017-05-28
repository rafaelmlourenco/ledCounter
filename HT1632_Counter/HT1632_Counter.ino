#include <HT1632.h>
#include <font_8x5.h>
#include <font_8x4.h>
#include <images.h>

int switchState = 0;
bool isConnected = true;

unsigned long startTime = 0;
unsigned long currentTime = 0;

String READY_MSG = "ready";
String STATUS_FLAG = "status:";
String END_FLAG = "end:";
String CURRENT_TIME_FLAG = "currentTime:";
String START_TIME_FLAG = "startTime:";
String OK_FLAG = "ok:";
String KO_FLAG = "ko:";

String CMD_FLAG = "cmd:";
String COUNT_CMD = "count:";
String UP_CMD = "up";
String DOWN_CMD = "down";
String SET_CMD = "set:";
String RESET_CMD = "reset";

String rcvString;

int i = 0;
int count = 0;
int COUNT_DIGITS = 3;
int wd;

bool lastState = false;
bool contentHasChanged = false;
bool isTextScrolling = false;
int txtIndex = 0;
String currentText = "####";
String newIdeaText = "NEW IDEA!";

bool testMode = false;

void setup () {
  //Initialize Serial Port (USB)
  Serial.begin(115200);
  
  HT1632.begin(9, 10, 11);
  currentText = getCountText();
  setContentHasChanged(true);
  Serial.println(STATUS_FLAG + READY_MSG);
}

void loop () {
// START - Arduino Nano
//   while (!Serial)
//  {
//    // Do nothing... Wait for serial connection...
//    isConnected = false;
//  }
//
//  // put your main code here, to run repeatedly:
//  if (!isConnected)
//  {
//    isConnected = true;
//    Serial.println(STATUS_FLAG + READY_MSG);
//  }
// END - Arduino Nano 

  if (Serial.available() > 0)
  {
    handleSerialMsg();
  }
  if(contentHasChanged){
    updateLEDMatrix();
  }
//  if(testMode){
//    count++;
//    currentText = getCountText();
//    setContentHasChanged(true);
//    delay(1000);
//  }
}

void drawTextFromString(String str){
  char *displayText = getCharText(str);
  wd = HT1632.getTextWidth(displayText, FONT_8X5_END, FONT_8X5_HEIGHT);
  HT1632.clear();
  HT1632.drawText(displayText, (OUT_SIZE - wd)/2, 0, FONT_8X5, FONT_8X5_END, FONT_8X5_HEIGHT);
  HT1632.render();
  free(displayText);
}

void drawScrollTextFromString(String str){
  char *displayText = getCharText(str);
  wd = HT1632.getTextWidth(displayText, FONT_8X5_END, FONT_8X5_HEIGHT);
  HT1632.clear();
  HT1632.drawText(displayText, (OUT_SIZE - (txtIndex + 1)), 0, FONT_8X5, FONT_8X5_END, FONT_8X5_HEIGHT);
  HT1632.render();
  free(displayText);
}

void updateLEDMatrix(){
    if(isTextScrolling){
      drawScrollTextFromString(currentText);
      txtIndex = (txtIndex+1)%(wd + OUT_SIZE);
      if(txtIndex == 0){
        isTextScrolling = false;
        currentText = getCountText();
        //testMode = true;
        setContentHasChanged(true);
      } else {
        delay(100);
      }
    } else { 
      drawTextFromString(currentText);
      setContentHasChanged(false);
    }
}

char* getCharText(String str){
  int len = str.length() + 1;
  char *cArray = (char*) malloc(sizeof(String)*len);
  str.toCharArray(cArray, len);
  return cArray;
}

void showScrollingMsg(){
  isTextScrolling = true;
  currentText = newIdeaText;
  setContentHasChanged(true);
}

void up(){
  count++;
  showScrollingMsg();
  //drawCountText();
}

void down(){
  if(count > 0){
    count--;
    //showScrollingMsg();
    drawCountText();
  }

}
void set(int number){
  if(number > 0){
    count = number;
    showScrollingMsg();
    //drawCountText();
  }
}
void reset(){
  count = 0;
  //showScrollingMsg();
  drawCountText();
}

void drawCountText(){
  currentText = getCountText();
  setContentHasChanged(true);
}

String getCountText(){
  int lzn = leadingZerosNumber(count,0); 
  Serial.println(lzn);
  String countText = "";
  for(int i = 0; i < lzn; i++){
    countText = countText + "0";
  }
  countText = countText + String(count);
  return countText;
}

int leadingZerosNumber(int number, int i){
  Serial.println(number);
  if(number > 0){
    number = number / 10;
    i++;
    return leadingZerosNumber(number,i);
  } 
  if(number == 0 && i == 0){
    i = 1;
  }
  return COUNT_DIGITS-i;
}

void setContentHasChanged(bool newState){
  lastState = contentHasChanged;
  contentHasChanged = newState;
}

void scrollText(){
  //  HT1632.clear();
  //  HT1632.drawText(disp, OUT_SIZE - i, 2, FONT_5X4, FONT_5X4_END, FONT_5X4_HEIGHT);
  //  HT1632.render();
  //  
  //  i = (i+1)%(wd + OUT_SIZE);
  //  
  //  delay(100);
}

void handleSerialMsg()
{
  rcvString = Serial.readString();
  if (rcvString.startsWith(CMD_FLAG))
  {
    String cmd = rcvString.substring(CMD_FLAG.length());
      if (cmd.startsWith(COUNT_CMD))
      {
        if(handleCountCmd(cmd)){
          return;
        } 
      }
  }
  sendError(rcvString);
}

bool handleCountCmd(String cmd){
   String countCmd = cmd.substring(COUNT_CMD.length());
   if(countCmd.startsWith(UP_CMD)){
      up();
      return true;
   } else {
      if(countCmd.startsWith(DOWN_CMD)) {
        down();
        return true;
      } else {
        if(countCmd.startsWith(RESET_CMD)){
          reset();
          return true;
        } else {
          if(countCmd.startsWith(SET_CMD)){
            String count = countCmd.substring(SET_CMD.length());
            set(count.toInt());
            return true;
          }
        }
      }
   }
   return false;
}

void sendError(String msg) {
  Serial.println(KO_FLAG + msg);
}
