# CD61-CD66-nixie-clock
A CD61/CD66 nixie clock, based on Greatscott! IN-14 clock design
![image](https://github.com/dzastsed/CD61-CD66-nixie-clock/assets/63074962/ec3a7a2a-ae73-4c7e-8dee-cce5dd0d87ef)
*I've finally made something that actually works!*

Inspired by and based on Greatscott's work: https://www.instructables.com/Make-Your-Own-Retro-Nixie-Clock-With-an-RTC/

The design almost works as-is, just needs 3 bodge wires because I followed the design directly (a V2 PCB redesign is planned sometime in the future to address this.).

# Quirks

![IMG_20230715_1122362](https://github.com/dzastsed/CD61-CD66-nixie-clock/assets/63074962/e703b76a-5252-49ce-ac1c-22fa48506d18)
*Bodge wires that were mentioned. (Point 11 goes to A3, point A6 goes to 2, and point A7 goes to TXO.) (cleanup pending)*

Removes the requirement of using pulldown resistor on point 11 (initially I wanted to do that, but couldn't get it working, so relocated output to A3).

# Nixie powering tips

I had found very little information on Hitachi CD61 nixies that I used here, but they seem to be siblings of NEC/Rodan CD66, one of which I also had (AKA Siemens ZM1242) - the pinout and looks match, and they had some more documentation. I calculated that powering them at 170 volts with 20k resistor attached should be the sweet spot. 

![image](https://github.com/dzastsed/CD61-CD66-nixie-clock/assets/63074962/46c15c17-8979-4a19-a33f-87dc6e3cfa2c)

![image](https://github.com/dzastsed/CD61-CD66-nixie-clock/assets/63074962/6aaf6df4-852d-47e8-ade1-27accd6f668e)

*Like, seriously, they look almost the same.*

# Assembling

Follow the guide on instructables and youtube:
https://www.instructables.com/Make-Your-Own-Retro-Nixie-Clock-With-an-RTC/
https://youtu.be/ObgmVNV1Kfg


# Code
Included code is also adapted for this board layout. NixieClockTest.ino should count up from 0 to 9. 

NixieClock.ino works just as a generic clock, like Greatscott programmed, and nothing more. 

NixieClock-scramblin.ino has scrambling code implemented to prevent cathode poisoning. It scrambles every time you turn it on, and when minutes are at 31, and lasts 30 seconds. You can see that here: 

https://github.com/dzastsed/CD61-CD66-nixie-clock/assets/63074962/8c647b59-98be-4068-b4ca-615b0ee81baa

# PCB files

There are also two gerber files included, one is without customized silkscreen, other is the "meme" edition I and my friends made. Board layout is exactly the same, just the silkscreen differs.

![image](https://github.com/dzastsed/CD61-CD66-nixie-clock/assets/63074962/0f0428b1-b2e8-42e6-b75c-df0b53595dd4)

*Looks of the meme edition*

Sadly I lost the project files when reinstalling my computer, so I cannot attach the schematic. However, the one from Greatscott! instructables page works just fine (link here: https://content.instructables.com/FL2/WNOE/K3XFLL97/FL2WNOEK3XFLL97.png) . Only difference would be 20K resistors instead of 10K on nixie power rails, and unslotted pot which connects to A3 on arduino.

# Future plans 

V2 redesign to fit in different RTC module that I have and remove bodge requirements. Maybe also will add port for quick UART diagnostics and reprogramming.

3D modelled case for the clock.

New guide (will come with V2 redesign)

# Credits
TheMobas0 - for help on making the scramble code

Greatsccott! - original board design
