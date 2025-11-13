#include "stm32f4xx.h"
#include "stm32f429xx.h"

#include <stdint.h>

#define RCC_AHB1ENR                 *(uint32_t *)(0x40023800UL + 0x30UL)
#define RCC_GPIOB_EN                0x02UL

#define GPIOB_MODER                 *(uint32_t *)(0x40020400UL + 0x00UL)
#define GPIOB_OSPEEDR               *(uint32_t *)(0x40020400UL + 0x08UL)
#define GPIOB_PUPDR                 *(uint32_t *)(0x40020400UL + 0x0CUL)
#define GPIOB_BSRR                  *(uint32_t *)(0x40020400UL + 0x18UL)

#define GPIO_OUTPUT_MODE_PIN_5       0x400UL //01 00 00 00 00 00 маска для MODE
#define GPIO_SPEED_MED_PIN_5         0x400UL //01 00 00 00 00 00 маска для SPEED
#define GPIO_PIN_RESET_5             0x200000UL //10 000 со сдвигом 16 маска для BSRR
#define GPIO_PIN_SET_5               0x20UL //10 0000 маска для BSRR
#define GPIO_OFF                     0x00UL

#define BIT_SET(REG, BIT) ((REG) |= (BIT))
#define BIT_READ(REG, BIT) ((REG) & (BIT))

void GPIO_Init_With_Miself_Macros(void);
void GPIO_Init_Memory(void);
void GPIO_Init_CMSIS(void);
void delay_ms(uint32_t ms);







// #define RCC_GPIOC_EN                0x04UL

// #define GPIOС_OSPEEDR               *(uint32_t *)(0x40020800UL + 0x08UL)
// #define GPIOС_MODER                 *(uint32_t *)(0x40020800UL + 0x00UL) 
// #define GPIOС_PUPDR                 *(uint32_t *)(0x40020800UL + 0x0CUL)
// #define GPIOС_BSRR                  *(uint32_t *)(0x40020800UL + 0x18UL)



// #define GPIOC_IDR                   *(uint32_t *)(0x40020800UL + 0x10UL)
