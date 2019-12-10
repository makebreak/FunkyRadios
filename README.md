# FunkyRadios
Make Radios Communicate to Start Funky Music and Disco Lights

# Project Summary 

This is a project I did for a Physical Computing class with Danne Woo in Spring 2018. 

I built a radio system that can be used in live performances. I used two Adafruit Feather m0 RFM69 radios and uploaded code to them using the Arduino IDE that we learned to use in class.

The transmitter radio (Tx) sends a simple message to the receiver radio (Rx), which is connected to a computer.

I wrote a simple python program to run during the performance. The program reads the serial port connected to the Rx. The python program waits for a certain message to show up on the serial port. When this happens, it then calls another python program, which makes the computer screen flash with many colors and triggers a song, “Funky Town.”

# Process

You need to solder the pins and the antenna and install the correct libraries for the Arduino IDE.

To make the radios communicate, I changed some of the inputs in the code from the RadioHead library. The debugging process was frustrating at first but ultimately rewarding.

Once they are communicating, the rest of the process is easy. You can modify the code to send your specific message to the serial port.

I also used a python library, Pygame, to write the code for the flashing screen and audio output.

This was a challenging and very rewarding project, and I would like to thank my professor Danne Woo, as well as Mark Kleeb and Roy Vanegas for their guidance and advice!
