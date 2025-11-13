#include "init.h"
//Пин PA3 LED1
void GPIO_Init_Memory() {
    *(uint32_t *)(0x40023800UL + 0x30UL) |= 0x01UL; // Включение тактирования порта GPIOA
    *(uint32_t *)(0x40020000UL + 0x00UL) |= 0x40UL; // Настройка пина PA3 на режим вывода сигнала, регистр MODER
    *(uint32_t *)(0x40020000UL + 0x08UL) |= 0x40UL; // Настройка скорости пина PA3 на среднюю, регистр OSPEEDR
    *(uint32_t *)(0x40020000UL + 0x0CUL) |= 0x00UL; // настройка подтягивающих стягивающих резисторов,регистор PUSHPOL
    *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x80000; // Выключение светодиода PA3, регист GPIO_BSRR
}

//Пин PB5 LED2
void GPIO_Init_With_Miself_Macros (void){
    BIT_SET(RCC_AHB1ENR, RCC_GPIOB_EN);// Включение тактирования порта GPIOB
    BIT_SET(GPIOB_MODER, GPIO_OUTPUT_MODE_PIN_5);// Настройка пина PB5 на режим вывода сигнала, регистр MODER
    BIT_SET(GPIOB_OSPEEDR, GPIO_SPEED_MED_PIN_5);// Настройка скорости пина PB5 на среднюю, регистр OSPEEDR
    BIT_SET(GPIOB_PUPDR, GPIO_OFF);
    BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_5);// Выключение светодиода PB5, регист GPIO_BSRR
}
//Пин PC0 LED3, кнопка 1 PC6, кнопка 2 PC2
void GPIO_Init_CMSIS(void){
    SET_BIT(RCC->AHB1ENR, RCC_AHB1ENR_GPIOCEN); // Включение тактирования порта GPIOC
    SET_BIT(GPIOC->MODER, GPIO_MODER_MODE0_0); // Настройка пина PC0 на режим вывода сигнала, регистр MODER
    CLEAR_BIT(GPIOC->OTYPER, GPIO_OTYPER_OT_0); // 
    SET_BIT(GPIOC->OSPEEDR, GPIO_OSPEEDER_OSPEEDR0_0); // Настройка скорости пина PC0 на среднюю, регистр OSPEEDR
    CLEAR_BIT(GPIOC->PUPDR, GPIO_PUPDR_PUPDR0_0); // 

    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE6); //  PC6 кнопка 1
    CLEAR_BIT(GPIOC->MODER, GPIO_MODER_MODE2); //  PC2  кнопка 2
    CLEAR_BIT(GPIOC->PUPDR, GPIO_PUPDR_PUPDR6); // PC6 
    CLEAR_BIT(GPIOC->PUPDR, GPIO_PUPDR_PUPDR2); // PC2 
}
// Задержка для предотвращения дребезга контактов 
void delay_ms(uint32_t ms) {
    for(uint32_t i = 0; i < ms * 1000; i++) {
        __asm("nop");
    }
}