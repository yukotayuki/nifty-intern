#include <UH.h>
UH uh;

bool shock = false;
int voltage;
int channel;

void setup() {
  // シリアル通信の初期化
  Serial.begin(9600);
  // EMSの初期化
  uh.initEMS();
  
  // EMSパラメータをセット
  voltage = 12;               // min: 0  max: 12
  uh.stimuTimeCount = 650;   // min: 0  max: 650

  // PICK ELECTRODE TO DELIVER EMS
  channel = 0; 
    // channel 0: Contracts Hand
    // channel 1: Pulls in Fingers (Index/Middle/Ring)
    // channel 2: Pulls in Fingers (Middle/Ring/Pinky)
    // channel 3: Pulls in Fingers (Ring/Pinky)
    // channel 4: Releases Hand
    // channel 5: extends Index Finger
    // channel 6: Tingle on forearm
    // channel 7: Pulls in Fingers (Index/Middle)
}

void loop() {
  if(shock == true){
     uh.setStimulationChannel(channel);
     uh.setStimulationTime();
     uh.setStimulationVoltage(voltage);
     uh.setStimulationVoltage(voltage);
     for(int i=0;i<50;i++){uh.keepVoltage(voltage);} 
     Serial.print("\nstimulate!\n\n");
  }
  
  uh.updateEMS();
  
  if(Serial.available() > 0){
    char c = Serial.read();
    if(c == 'e'){
      shock = true;
      Serial.print("ok");
    }
  }


}

