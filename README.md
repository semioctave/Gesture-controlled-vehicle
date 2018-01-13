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

<b>MPU6050 module</b> which Consists of Gyroscope as Well as Accelarometer is used for detecting the Gesture.
Module converts the<b> orientation into digital signals</b>. These digital signals are send to MCU using<b> I2C bus</b>, which is
used to communicate low speed devices. These raw signal are coverted into Euler's angle and further used for processing & detecting
the gesture. Gesture is further encoded into integer and these integers are transmitted to <b>Arduino UNO using RF Transmitter and Receiver pair</b>. Now Depending on the Gesture the action is taken.

In this Program Vehical moves in the direction in which the hand is waved.

___

## Applications

<b> * </b> Above system can be used in electric wheel-chairs and transmitter circuit can be easily integrated to Smart-Watches.<br/>
<b> * </b> Above system can be used to control Drones.

___
