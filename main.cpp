/** Main 
@brief Use the joystick to avoid the oncoming obstacles and collect the coins to gain points
@brief Collect enough 3D Powerups to enter the 3D bonus level
@brief NOTE - printf functions have been commented out to reduce in-game lag

*/
///////// Include class file directories ////////
#include "mbed.h"
#include "N5110.h"
#include "Gamepad.h"
#include "Glider.h"
#include "CarEngine.h"

///////// Definitions ////////
#define GAME_SPEED 3 //Defines speed of the game, defaults set at 3

///////// Create objects ////////
N5110 lcd(PTC9,PTC0,PTC7,PTD2,PTD1,PTC11); //LCD screen
CarEngine eng; //Object for engine
Gamepad pad; //Object for gamepad
Ticker ticker; // Object for ticker

///////// Define Functions ////////
void lane1();
void init();
void render();
void start();

///////// Define Values ////////
int yc=0; //Starting value for position of lanes
int fps = 8; //Frames per second of game
int tick = 0; //Tick for timing the game - set initial tick to be 0

///////// Struct ////////
struct UserInput {
    Direction d;
    float mag;
};


///////// Enter Main ////////
int main()
{
    init(); //Initialise starting conditions
    start(); //Startup Menu
    render(); //Render starting frame
    wait(1.0f/fps);

    //ticker.attach(&lane1,0.1);

    while (1) {

        eng.read_input(pad); //Read input from gamepad
        eng.update(pad, lcd); //Return values from the engine
        render(); //Render frame depending on engine values
        tick++; //Adds tick in every loop
        //printf ("%d", tick); //Prints tick value to the serial monitor
        wait(1.0f/fps); //Wait
        
        //Pauses game if start button is pressed
        if ( pad.check_event(Gamepad::START_PRESSED) == true) {
            //printf ("%s \n", "Start Button Pressed");
            lcd.clear();
            lcd.refresh();
            start();
        }
    }
}
///////// Function to initilaise the objects, set the screen mode and brightness ////////
void init()
{
    // need to initialise LCD and Gamepad
    lcd.init();
    lcd.normalMode();      // normal colour mode
    lcd.setBrightness(1.0); // put LED backlight on full brightness (100%)
    pad.init();
    // initialise the game
    eng.init(GAME_SPEED);
    //printf("%s", "Main Initialised");

}
///////// Function to clear the screen and render the draw functions from the engine////////
void render()
{
    // clear screen, re-draw and refresh
    lcd.clear();
    eng.draw(lcd);
    lane1();
    lcd.refresh();
    //printf("%s", "Main Render");
}
///////// Function to draw the 2D lanes ////////
void lane1()
{
    //Outside Curbs
    for (int y = -7; y < WIDTH ; y+=1) {
        lcd.setPixel(15,y + yc);
        lcd.setPixel(69,y + yc);
    }
    for (int y = -8; y < WIDTH ; y+=4) {
        lcd.setPixel(15,y + yc,false);
        lcd.setPixel(69,y + yc,false);
    }
    //Inside lane markings
    for (int y = -7; y < WIDTH ; y+=1) {
        lcd.setPixel(33,y+yc);
        lcd.setPixel(51,y+yc);
    }
    for (int y = -8; y < WIDTH ; y+=11) {
        lcd.setPixel(33,y+yc,false );
        lcd.setPixel(51,y+yc,false);
    }
    for (int y = -9; y < WIDTH ; y+=11) {
        lcd.setPixel(33,y+yc,false );
        lcd.setPixel(51,y+yc,false);
    }
    for (int y = -10; y < WIDTH ; y+=11) {
        lcd.setPixel(33,y+yc,false );
        lcd.setPixel(51,y+yc,false);
    }

    yc=yc+1; //yc changes starting point
    if (yc == 11) {
        yc=0;
        //printf("%d", yc);
    }
    //printf("%s", "Lane1 Call Initialised");
}
///////// Startup Menu ////////
void start()
{
    //printf("%s", "Start Menu"); 
    //displays strings across the screen - ("String", x, y) - y is quantised into 6 vertical sections for the characters to be displayed
    lcd.printString("     Lanes    ",0,1);
    lcd.printString("  Press Start ",0,4);
    lcd.refresh();

    // wait flashing LEDs until start button is pressed
    while ( pad.check_event(Gamepad::START_PRESSED) == false) {
        pad.leds_on();
        wait(0.1);
        pad.leds_off();
        wait(0.1);
    }

}
