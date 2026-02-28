# Wireless Power Transfer Using Resonant Inductive Coupling

## Overview
This project demonstrates a wireless power transfer (WPT) system based on resonant inductive coupling. The system was designed, prototyped on a breadboard, and later migrated to a PCB implementation for improved stability and performance.

The transmitter and receiver coils were tuned to operate at resonance to maximize energy transfer efficiency.

## Objectives
- Design and construct a resonant inductive coupling system
- Implement Arduino-based control using embedded C++
- Optimize energy transfer efficiency through frequency tuning
- Transition from breadboard prototype to PCB implementation

## System Architecture
The system consists of:
- Transmitter coil driven by a high-frequency switching stage
- Receiver coil tuned to the same resonant frequency
- Rectification and filtering stage
- Arduino-based control logic

## Hardware Implementation
### Phase 1 – Breadboard Prototype
- Coil testing and tuning
- Initial driver circuit validation
- Manual frequency adjustments

### Phase 2 – PCB Implementation
- Improved layout stability
- Reduced parasitic effects
- Enhanced mechanical integrity

## Firmware
The firmware was developed in embedded C++ using the Arduino framework.

Key features:
- PWM signal generation for driving switching stage
- Frequency adjustment and tuning
- System monitoring (if applicable)

See `/firmware` directory for source code.

## Results
- Achieved stable power transfer over X cm distance
- Output voltage: X V
- Measured efficiency: X %

## Challenges
- Precise frequency tuning
- Coil alignment sensitivity
- Managing heat in switching components

## Future Improvements
- Automatic frequency tracking
- Closed-loop efficiency optimization
- Higher power handling capability

## Author
Electrical & Electronic Engineering Graduate  
Special interest in Embedded Systems and Energy Systems
