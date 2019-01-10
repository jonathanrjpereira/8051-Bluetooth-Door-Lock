# 8051 Bluetooth Door Lock

**Order PCB:** [PCBWay](https://www.pcbway.com/project/shareproject/Bluetooth_Door_Lock_using_8051.html)

![Block Diagram](/Documentation/Block%20Diagram.PNG?raw=true "Block Diagram")

The  main objective of this project is to unlock a garage door by an android application using a unique password entered through the android application device. Opening and closing & unlocking operation of garage door involves human labor. In this proposed system, the opening and closing & unlocking operation of a garage door is achieved by using an android application. The owner can connect an android application device to the system through Bluetooth, which in turn is connected through a HC-05 Bluetooth Module to a 8051 microcontroller controlled garage door that can open/close the door by entering the password. This method is very
convenient as one doesn’t have to get down of his car to open/close the door physically.
The user first has to pair a Smartphone with the HC-05 module; only then can the android application be used to transmit the password string to the HC-05 module. When the sent data (password entered by the user) matches with the password stored in the 8051 microcontroller, and then the 8051 microcontroller initiates a mechanism to open the door through a L293D motor driver interface.
In the case where the user does not have access to the Smartphone (battery low,  misplaced ,etc), a 4X4 keypad interface will acts as a secondary unlocking device. While entering the password through the 4X4 Keypad, an LCD display will provide visual feedback to the user. This will prevent the user from entering an incorrect password multiple times.
In cases where in the user enters an incorrect password repeatedly within a short period of time(3 incorrect tries per minute), the system automatically stops the acceptance of passwords from both the HC-05 Bluetooth module & the 4X4 keypad for a timeout period of 3 minutes. This will prevent hackers from brute forcing their way through the system. In such a case warning alarm or siren will be triggered by the 8051 microcontroller through a buzzer.
Unlike conventional IR consumer electronics, there is no IR code used to unlock the device because of the use of Bluetooth in the system. This makes it tougher to extract the password during communication & increases the security of the system.


