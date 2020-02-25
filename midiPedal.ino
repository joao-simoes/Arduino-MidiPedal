#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

//FX VARS
//Dist
int potDistTone = A0;
//int potDistDist = A1;
//int potDistLevel = A2;
int ftSwitchDist = 2;
int ledDist = 3;
int prevValueDistTone = 0;
int prevValueDistDist = 0;
int prevValueDistLevel = 0;
bool fxStateDist = false;

void setup()
{
  pinMode(ledDist, OUTPUT);
  pinMode(ftSwitchDist, INPUT);
  pinMode(potDistTone, INPUT);
  MIDI.begin(MIDI_CHANNEL_OFF);
}

void loop()
{
//DISTORTION--------------------------------------------------------------------------------------------------
  //FOOTSWITCH DIST--------------------------------------------------------------------------------------------------
  if ((digitalRead(ftSwitchDist) == LOW) && (fxStateDist == false)){ //IF IS OFF
      MIDI.sendNoteOn(40, 127, 1); //NOTE ON
      MIDI.sendNoteOff(40, 0, 1); //NOTE OFF
      fxStateDist = true; //FX STATE TO ON
      while (digitalRead(ftSwitchDist) == LOW){ //WHILE FOOT STILL ON PEDAL DONT DO ANYTHING
      }
    }    
    else if ((digitalRead(ftSwitchDist) == LOW) && (fxStateDist == true)) { //IF IS ON
      MIDI.sendNoteOn(40, 127, 1);//NOTE ON
      MIDI.sendNoteOff(40, 0, 1);//NOTE OFF
      fxStateDist = false;//FX STATE TO OFF
      while (digitalRead(ftSwitchDist) == LOW){ //WHILE FOOT STILL ON PEDAL DONT DO ANYTHING
      }
    }

  //KNOB DIST TONE
  if(analogRead(potDistTone)/8 != prevValueDistTone) { //IF THE VALUE OF THE KNOB CHANGES
    MIDI.sendControlChange(40,analogRead(potDistTone)/8,2); //SEND THE NEW VALUE
    prevValueDistTone = analogRead(potDistTone)/8; //STORE THE CURRENT TO COMPARE LATER
  }

  //KNOB DIST AMOUNT

  //KNOB DIST VOLUME
//DISTORTION--------------------------------------------------------------------------------------------------
}
