// ------------
// Blink Name
// ------------

/*-------------

Original code is from https://docs.particle.io/tutorials/hardware-projects/hardware-examples/photon/ the 'Blind an LED' example

Modified by Adam Edwards for SIT210 task 2.1P


This program will blink Adam in Morse code on the inbuilt Photon Particle LED which is D7

-------------*/


// First, we're going to make some variables.
// This is our "shorthand" that we'll use throughout the program:

int led2 = D7; // Instead of writing D7 over and over again, we'll write led2
// This one is the little blue LED on your board. On the Photon it is next to D7, and on the Core it is next to the USB jack.

// This is the first of the functions. 'dot' that is one unit in length. One unit will be 333ms

void dot() {
    digitalWrite(led2, HIGH);
    delay(333);
    digitalWrite(led2, LOW);
}

// A 'dash'. Length is 3 units which will be 999ms

void dash() {
    digitalWrite(led2, HIGH);
    delay(999);
    digitalWrite(led2, LOW);
}

// A 'component gap'. This is the gap between components of a character. Length is one unit so 333ms

void component_gap() {
    delay(333);
}

// 'Character gap'. This is the gap between characters. Length is three units so 999ms

void character_gap() {
    delay(999);
}

// 'Word gap', the gap between words. It is seven units in length aka 2331ms

void word_gap() {
    delay(2331);
}

// In Morse code the letter A is a dot dash .-

void letter_a() {
    dot();
    component_gap();
    dash();
}

// In Morse code the letter D is dash dot dot -..

void letter_d() {
    dash();
    component_gap();
    dot();
    component_gap();
    dot();
}

// Letter M is dash dash --

void letter_m() {
    dash();
    component_gap();
    dash();
}

void word_adam() {
    letter_a();
    character_gap();
    letter_d();
    character_gap();
    letter_a();
    character_gap();
    letter_m();
}

// Configured led2 for output

void setup() {
	pinMode(led2, OUTPUT);
}

// loop the Adam function again and again

void loop() {
    word_adam();
    word_gap();
}
