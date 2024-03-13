#include "main.h"



/**
 * Main program.
 * board; blackpill version 3
 * MCU: STM32F401CC
 * SRAM:  96 KiB
 * FLASH: 384 KiB
 * 
 * Tutorial, toggle LED when KEY is pressed
 * 
 */
int main(void) {
  // Enable the GPIOA dan GPIOC peripheral in 'RCC_AHBENR'. PA0 - key button; PC13 - led
  RCC_AHB1ENR |= (RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIOCEN) ;

  // pa0 KEY input;
  // pa0 - R1 330R -switch (KEY) - gnd; must be pull-up
  // pc13 LED output  
  // pc13 -led katoda-R1k-3v3 pulldown to light the led -- output opendrain
  #define KEY_btn_bit  (uint16_t)  0
  #define LED_bit      (uint16_t)  13

  GPIOA_MODER |= 0b00;
  GPIOC_MODER |= 0b01 << LED_bit*2; // 01=output, bit 26-27

  //OTy 1=output opendrain
  GPIOC_OTYPER |= 1U << 13;

// BUTTON KEY pulled up
  #define PUPDR_PULL_UP 0b01
  #define PUPDR_PULL_DN 0b10
/*  00: No pull-up, pull-down
    01: Pull-up
    10: Pull-down
    11: Reserved
*/

  GPIOA_PUPDR |= PUPDR_PULL_UP << KEY_btn_bit;


  bool pressed = false;
  uint32_t keyEvt;

  while(1){
    keyEvt = ~GPIOA_IDR & (1 << KEY_btn_bit); //si 8
    
    if(keyEvt ){                              // si 3
      if (!pressed)
        GPIOC_ODR ^= (1 << LED_bit);  
        
      pressed = true;                           //si 3
      }
    else 
      pressed = false;                   //si 3

  }
  

}
