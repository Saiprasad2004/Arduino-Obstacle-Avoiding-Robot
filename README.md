# Arduino-Obstacle-Avoiding-Robot
An autonomous obstacle avoiding robot using Arduino Uno, HC-SR04 ultrasonic sensor, SG90 servo motor, and L298N motor driver.

## Overview
This project implements an autonomous obstacle avoiding robot using Arduino Uno. The robot detects obstacles using an HC-SR04 ultrasonic sensor mounted on a servo motor and automatically changes its direction to avoid collisions.

## Features
- Autonomous navigation
- Obstacle detection and avoidance
- Servo based environmental scanning
- Bidirectional motor control using L298N

## Components Used
- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- L298N Motor Driver
- BO Motors
- Chassis
- 2S 18650 Battery Pack

## Working Principle
1. Robot continuously moves forward.
2. Ultrasonic sensor measures distance.
3. If an obstacle is detected, the robot stops.
4. Servo scans left and right.
5. Robot chooses the direction with more free space.

## Hardware Connections

| Component | Arduino Pin |
|-----------|-------------|
| Trig | D2 |
| Echo | D8 |
| Servo | D12 |
| ENA | D5 |
| ENB | D6 |
| IN1 | D7 |
| IN2 | D4 |
| IN3 | D10 |
| IN4 | D11 |

## Future Improvements
- PID based motion control
- Bluetooth/Wi-Fi control
- Mapping and SLAM
- Camera integration

## Author
Pasupula Sai Prasad
