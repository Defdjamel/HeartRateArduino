/*
 */
#define USE_ARDUINO_INTERRUPTS false
#include <PulseSensorPlayground.h>

/*
   The format of our output.

   Set this to PROCESSING_VISUALIZER if you're going to run
    the Processing Visualizer Sketch.
    See https://github.com/WorldFamousElectronics/PulseSensor_Amped_Processing_Visualizer

   Set this to SERIAL_PLOTTER if you're going to run
    the Arduino IDE's Serial Plotter.
*/
const int OUTPUT_TYPE = SERIAL_PLOTTER;

const int PULSE_INPUT = A0;  //PIN A0 is on Signal of Pulse sensor
const int PULSE_BLINK = 13;    // Pin 13 is the on-board LED
const int THRESHOLD = 516;   // A ajuster en fonction de votre montage
/*
   samplesUntilReport = the number of samples remaining to read
   until we want to report a sample over the serial connection.

   We want to report a sample value over the serial port
   only once every 20 milliseconds (10 samples) to avoid
   doing Serial output faster than the Arduino can send.
*/
byte samplesUntilReport;
const byte SAMPLES_PER_SERIAL_SAMPLE = 10;

/*
   All the PulseSensor Playground functions.
*/
PulseSensorPlayground pulseSensor;


/*LEDS
 */
int ledPins[] = {
  2, 3, 4, 5, 6, 7,8,9,10,11
};       // an array of pin numbers to which LEDs are attached
int pinCount = 10;  

//Valeur minimal du rythme cardiaque a afficher sur les leds
const byte bpmMin = 40;
const byte bpmMax = 110;

//SETUP
void setup() {
  
  Serial.begin(115200);

  // Configure the PulseSensor manager.
  pulseSensor.analogInput(PULSE_INPUT);
  pulseSensor.blinkOnPulse(PULSE_BLINK);
  pulseSensor.setSerial(Serial);
  pulseSensor.setOutputType(OUTPUT_TYPE);
  pulseSensor.setThreshold(THRESHOLD);

 //LEDS SETUP in Outupu
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    pinMode(ledPins[thisPin], OUTPUT);
  }

  // Now that everything is ready, start reading the PulseSensor signal.
  if (!pulseSensor.begin()) {//FAILED
    /*
       PulseSensor initialization failed,
       likely because our Arduino platform interrupts
       aren't supported yet.

       If your Sketch hangs here, try changing USE_PS_INTERRUPT to false.
    */
    for(;;) {
      // Flash the led to show things didn't work.
      digitalWrite(PULSE_BLINK, LOW);
      delay(50);
      digitalWrite(PULSE_BLINK, HIGH);
      delay(50);
    }
  }
 
}

void loop() {

  /*
     See if a sample is ready from the PulseSensor.

     If USE_INTERRUPTS is true, the PulseSensor Playground
     will automatically read and process samples from
     the PulseSensor.

     If USE_INTERRUPTS is false, this call to sawNewSample()
     will, if enough time has passed, read and process a
     sample (analog voltage) from the PulseSensor.
  */
  if (pulseSensor.sawNewSample()) {
    /*
       Every so often, send the latest Sample.
       We don't print every sample, because our baud rate
       won't support that much I/O.
    */
    if (--samplesUntilReport == (byte) 0) {
      samplesUntilReport = SAMPLES_PER_SERIAL_SAMPLE;

      pulseSensor.outputSample();

      /*
         At about the beginning of every heartbeat,
         report the heart rate and inter-beat-interval.
      */
      if (pulseSensor.sawStartOfBeat()) {
        pulseSensor.outputBeat();
        int myBPM = pulseSensor.getBeatsPerMinute();

        Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
        Serial.print("BPM: ");                        // Print phrase "BPM: " 
        Serial.println(myBPM);  

          if ( myBPM >= bpmMin && myBPM <= bpmMax ) {
           int purcent  = map(myBPM, bpmMin , bpmMax, 0, 100);
           lightLed100(purcent);
           delay(100);
           lightLed100(0);
           }else{
                 lightLed100(0);
           }
       }
    }
  }

  /******
     Don't add code here, because it could slow the sampling
     from the PulseSensor.
  ******/
}


//Led on in purcentage
void lightLed100(int pourcent) {
  //put to LOW first
  for (int thisPin = 0; thisPin < pinCount; thisPin++) {
    digitalWrite(ledPins[thisPin], LOW);
  }
 int pinsToHigh  = map(pourcent, 0 , 100, 0, pinCount);
  for (int thisPin = 0; thisPin < pinsToHigh; thisPin++) {
    digitalWrite(ledPins[thisPin], HIGH);
  }
  
}
