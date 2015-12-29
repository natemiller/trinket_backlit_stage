# Trinket-based Backlit Stage
This project was a simple challenge to create a small and cheap means of under-lighting of back-lighting specimens or samples viewed under a dissecting scope. The requirements were for the stage to provide uniform, bright back-lighting with a wide, but short base so as to not interfere with the working range of most dissecting scopes. Different specimens and different features may be better viewed at different light intensities or at at different light wavelengths so the system was designed to provide 15 different colors/brightnesses. For fun, a shifting raindbow setting was also added, which cycles slowly through a rainbow of colors.

The code was loaded onto a 5V Adafruit Trinket microcontroller ($5)and a short length (5 LEDS) of WS2801 RGB LEDs. These LEDs are nice because they produce a slightly more diffuse light at a wider angle, as well as being individually addressible and having each LED performing the PWM. This saves space in the code. 

Different colors are specified in RGB and are selected by pressing a momentary button to cycle through the different colors.
For the rainbow setting I modified the rainbow function in the example code for the "strandtest" included with the WS2801 library. This code utilized a delay function which prevented the user from exiting the rainbow setting with a button press. I rewrote the rainbow function to use a standard millis() timer, eliminating the need for the delay().

Images of the actual build will eventually be available on www.nate-miller.org.
