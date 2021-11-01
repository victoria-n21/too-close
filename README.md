# too-close
Tired of people not respecting the 6ft apart rule even though COVID-19 is still going around? Always just hated people standing too close to you? I've got a monitor for that!
(Scaled down to 6in)

This project continuously monitors the distance of a person or object from the ultrasonic sensor. The LCD displays the distance (measured in inches) and displays a smiley face
":)" if you are more than 6in away and the buzzer remains silent. If this person or object moves within 6in of the sensor, the LCD will say "TOO CLOSE" and triggers buzzer to go off until they move back. It's enough to annoy pretty much anyone! 

The messages can be changed to anything you need, even custom messages (see guide). <br/>
The units for the distance measurement can be adjusted using the correct conversion (see code comments). <br/>
The buzzer's pitch can be also be changed, or you can even create specific patterns for it to play (see code comments). 

This project was done on the Arduino Mega2560, but can be adjusted to other Arduino boards (Open Arduino IDE --> Tools --> Board).

Happy building! 
