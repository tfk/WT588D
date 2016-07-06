# WT588D
WT588D-library for Arduino using one-line mode.

This library has been tested with a [Arduino Micro](https://www.arduino.cc/en/Main/ArduinoBoardMicro) and a WT588D-U-32M module.
By using the one-line mode you need to connect only 3 wires(RESET, SDA, BUSY) to the board instead 5 wires(RESET, SDA, BUSY, CS, CLK) when using the three-line mode. 
Both protocol-descriptions can be found in the [Specification](http://e-radionica.com/productdata/WT588D%20CHIP&MODULE%20DETAILED%20INFORMATION.pdf).

##Configure the WT588D board

The [user-manual](http://www.elechouse.com/elechouse/images/product/MP3%20WT588D%20USB%20module/WT588D%20software%20user%20manual.pdf) describes the configuration and upload process in detail.  

1. *Convert existing soundfile*
	
	The board doesnt support arbitary file-formats so you may need to convert your exisiting soundfile. 
	Example: Using sox to convert the file in.wav to a 16 Bit (-b 16), 22kHz (-r 22k), mono (-c 1) out.wav-File. 
	
	`sox "in.wav" -b 16 -r 22k -c 1 "out.wav"`

2. *Configure the board-settings*

	There are only two releavant setting, which are important to this library. First you need to enable one-line serial mode (see section 2.5.1 of the software-user-manual). Second you need to set busy-mode to LOW as the library has methods to wait for the busy-signal. 

3. *Place the soundfiles to the desired equations*

4. *Compile settings and soundfiles*

	A bin file with the settings and the sound-data will be created, that we will copy to the board in step 5.
	
5. *Transfer data to the soundboard*

	See section 2.12 of the user-manual.
	
## Installing the WT588D Library

1. Create a directory WT588D inside your libraries subdirectory of your sketchbook directory. 
2. Copy the the WT588D.h and WT588D.cpp to the WT588D subdirectory.
3. Start the Arduino IDE.
4. Create a new sketch and add the WT588D library via Sketch > Import > Library.


	
	 