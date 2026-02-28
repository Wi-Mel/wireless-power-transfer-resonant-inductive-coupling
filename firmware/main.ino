/*
 * Arduino 100kHz Complementary Outputs on Pin 9 (OC1A) and Pin 10 (OC1B)
 * Both at 50% duty cycle, 180° out of phase.
 *
 * Fast PWM mode using Timer1 with ICR1 as TOP.
 *
 * F_CPU = 16,000,000 Hz
 * Desired frequency = 100,000 Hz
 * 
 * Formula for Fast PWM frequency:
 *    F_PWM = F_CPU / (Prescaler * (1 + TOP))
 * We use prescaler = 1 and TOP = 159:
 *    => 16e6 / (1 * (159 + 1)) = 100,000 Hz
 *
 * For a 50% duty cycle: Compare match = TOP/2 = 80.
 * 
 * On OC1A (pin 9): Non-inverting => low from 0..80, high 80..159
 * On OC1B (pin 10): Inverting => high from 0..80, low 80..159
 * => Exactly 180° out of phase.
 */

void setup()
{
  // Set pin 9 and pin 10 as outputs
  pinMode(9, OUTPUT);   // OC1A
  pinMode(10, OUTPUT);  // OC1B

  // Clear control registers
  TCCR1A = 0;
  TCCR1B = 0;

  // Set Fast PWM mode with ICR1 as TOP => WGM13=1, WGM12=1, WGM11=1, WGM10=0 (Mode 14)
  TCCR1A |= (1 << WGM11);
  TCCR1B |= (1 << WGM12) | (1 << WGM13);

  // Set Compare Output modes:
  //   - OC1A in Non-inverting mode => COM1A1=1, COM1A0=0
  //   - OC1B in Inverting mode => COM1B1=1, COM1B0=1
  TCCR1A |= (1 << COM1A1);                 // Non-inverting on OC1A
  TCCR1A |= (1 << COM1B1) | (1 << COM1B0); // Inverting on OC1B

  // Set TOP and Compare registers
  ICR1  = 159;  // TOP for 100kHz
  OCR1A = 80;   // 50% duty on channel A
  OCR1B = 80;   // 50% duty on channel B

  // Prescaler = 1 => CS10=1
  TCCR1B |= (1 << CS10);
}

void loop()
{
  // Nothing required here; hardware PWM is handled by Timer1
}


