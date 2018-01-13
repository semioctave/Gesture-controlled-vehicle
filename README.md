# Gesture-controlled-vehicle
___

## Introduction

Gestures are read using Gyroscope Sensors & Arduino NANO attached to the gloves.
The encoded data is sent wirelessly to Arduino UNO which processes the data and moves the vehicle in the direction corresponding to that encoded data.

___

## Components Used

1. Arduino Uno & Adruino Nano <br/>
2. MPU6050 Module<br/>
3. 433Mhz RF Transmitter Reciver Pair <br/>
4. Robotic Chassis
5. Wheels
6. DC Motor
7. Power Banks
8. Motor Driver
9. Breadboard , LED & Resistor

___

## Working

MPU6050 module which Consists of Gyroscope as Well as Accelarometer is used for detecting the Gesture.
Module converts the orientation into digital signals. These digital signals are send to MCU using I2C bus, which is
used to communicate low devices. These raw signal are coverted into Euler's angle and further used for processing & detecting
the gesture. Gesture is further encoded into integer and these integers are transmitted to Arduino UNO using RF Transmitter and Receiver pair. Now Depending on the Gesture the action is Taken.
___

## Applications

<b> * </b> Above system can be used in electric wheel and transmitter circuitary can be integrated to Smart-Watches.<br/>
<b> * </b> Above system can be used in controlling Drones.

___
