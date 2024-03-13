/** 
  * @brief General Purpose I/O
  */



#define MMIO32(addr)	   (*(volatile uint32_t *)(addr))


//#define 	PERIPH_BASE   		(0x40000000U) 
#define 	PERIPH_BASE_APB1   	(PERIPH_BASE + 0x00000) 
#define 	PERIPH_BASE_APB2   	(PERIPH_BASE + 0x10000) 
#define 	PERIPH_BASE_AHB1   	(PERIPH_BASE + 0x20000)

#define 	GPIOA   (PERIPH_BASE_AHB1 + 0x0000)  
#define 	GPIOB   (PERIPH_BASE_AHB1 + 0x0400)  
#define 	GPIOC   (PERIPH_BASE_AHB1 + 0x0800)  
#define 	GPIOD   (PERIPH_BASE_AHB1 + 0x0C00)  
#define 	GPIOE   (PERIPH_BASE_AHB1 + 0x1000)  
#define 	GPIOH   (PERIPH_BASE_AHB1 + 0x1C00)  

/* MODER
00: Input (reset state)
01: General purpose output mode
10: Alternate function mode
11: Analog mode
*/
#define GPIO_MODER(port)   MMIO32((port) + 0x00)
#define 	GPIOA_MODER   GPIO_MODER(GPIOA) 
#define 	GPIOB_MODER   GPIO_MODER(GPIOB) 
#define 	GPIOC_MODER   GPIO_MODER(GPIOC) 
#define 	GPIOD_MODER   GPIO_MODER(GPIOD) 
#define 	GPIOE_MODER   GPIO_MODER(GPIOE) 
#define 	GPIOH_MODER   GPIO_MODER(GPIOH)

/* OUTPUT TYPE REGISTER
0 = OUTPUT PUSH PULL
1 = OUTPUT OPEN DRAIN
*/
#define GPIO_OTYPER(port) MMIO32((port) + 0x04)
#define   GPIOA_OTYPER  GPIO_OTYPER(GPIOA)
#define   GPIOB_OTYPER  GPIO_OTYPER(GPIOB)
#define   GPIOC_OTYPER  GPIO_OTYPER(GPIOC)
#define   GPIOD_OTYPER  GPIO_OTYPER(GPIOD)
#define   GPIOE_OTYPER  GPIO_OTYPER(GPIOE)
#define   GPIOH_OTYPER  GPIO_OTYPER(GPIOH)


/* PUPDR 0x0C
00: No pull-up, pull-down
01: Pull-up
10: Pull-down
11: Reserved
*/
#define GPIO_PUPDR(port) MMIO32((port) + 0x0C)
#define   GPIOA_PUPDR  GPIO_PUPDR(GPIOA)
#define   GPIOB_PUPDR  GPIO_PUPDR(GPIOB)
#define   GPIOC_PUPDR  GPIO_PUPDR(GPIOC)
#define   GPIOD_PUPDR  GPIO_PUPDR(GPIOD)
#define   GPIOE_PUPDR  GPIO_PUPDR(GPIOE)
#define   GPIOH_PUPDR  GPIO_PUPDR(GPIOH)

#define GPIO_IDR(port)  MMIO32((port) + 0x10)
#define   GPIOA_IDR  GPIO_IDR(GPIOA)
#define   GPIOB_IDR  GPIO_IDR(GPIOB)
#define   GPIOC_IDR  GPIO_IDR(GPIOC)
#define   GPIOD_IDR  GPIO_IDR(GPIOD)
#define   GPIOE_IDR  GPIO_IDR(GPIOE)
#define   GPIOH_IDR  GPIO_IDR(GPIOH)


#define GPIO_ODR(port)  MMIO32((port) + 0x14)
#define   GPIOA_ODR  GPIO_ODR(GPIOA)
#define   GPIOB_ODR  GPIO_ODR(GPIOB)
#define   GPIOC_ODR  GPIO_ODR(GPIOC)
#define   GPIOD_ODR  GPIO_ODR(GPIOD)
#define   GPIOE_ODR  GPIO_ODR(GPIOE)
#define   GPIOH_ODR  GPIO_ODR(GPIOH)
