#include "../Inc/init.h"

int main(void)
{
    GPIO_Init_Memory();
    GPIO_Init_With_Miself_Macros();
    GPIO_Init_CMSIS();

    uint8_t led_number = 0;  // Номер светодиода
    uint8_t led_count = 0;   // Количество включаемых светодиодов
    uint8_t but_press_1 = 0; // Кнопка 1 нажата
    uint8_t but_press_2 = 0; // Кнопка 2 нажата

    while (1)
    {
        uint32_t button_1 = READ_BIT(GPIOC->IDR, GPIO_IDR_ID6); // Чтение состояния кнопки 1
        uint32_t button_2 = READ_BIT(GPIOC->IDR, GPIO_IDR_ID2); // Чтение состояния кнопки 2

        if (button_2 && !but_press_2)
        {
            but_press_2 = 1;
            delay_ms(500); // Задержка для предотвращения дребезга контактов

            led_count++;
            if (led_count > 3)
            {
                led_count = 0;
            }
        }

        if (!button_2)
        {
            but_press_2 = 0;
        }

        if (button_1 && !but_press_1)
        {
            but_press_1 = 1;
            delay_ms(500); // Задержка для предотвращения дребезга контактов

            if (led_count == 1 || led_count == 0)
            {
                // Включается 1 светодиод
                if (led_number == 0)
                {
                    // LED1 (PA3)
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00000008UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // то что было
                    // SET_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // CLEAR_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // CLEAR_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
                else if (led_number == 1)
                {
                    // LED2 (PC0)
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00080000UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // CLEAR_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // SET_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // CLEAR_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
                else if (led_number == 2)
                {
                    // LED3 (PB5)
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00080000UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // CLEAR_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // CLEAR_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // SET_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
            }
            else if (led_count == 2)
            {
                // Включаются 2 светодиода циклически
                if (led_number == 0)
                {
                    //   LED1 и LED2
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00000008UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // SET_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // SET_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // CLEAR_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
                else if (led_number == 1)
                {
                    //    LED2 и LED3
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00080000UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // CLEAR_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // SET_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // SET_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
                else if (led_number == 2)
                {
                    //   LED3 и LED1
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00000008UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // SET_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // CLEAR_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // SET_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
            }
            else if (led_count == 3)
            {
                // Включаются все 3 светодиода
                if (led_number == 1)
                {
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BS3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BS0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00000008UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_SET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BS5);

                    // SET_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // SET_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // SET_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
                else
                {
                    SET_BIT(GPIOA->BSRR, GPIO_BSRR_BR3);
                    SET_BIT(GPIOC->BSRR, GPIO_BSRR_BR0);
                    SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // другое
                    // *(uint32_t *)(0x40020000UL + 0x18UL) |= 0x00080000UL;
                    // BIT_SET(GPIOB_BSRR, GPIO_PIN_RESET_5);
                    // SET_BIT(GPIOB->BSRR, GPIO_BSRR_BR5);

                    // CLEAR_BIT(GPIOA->ODR, GPIO_ODR_OD3);
                    // CLEAR_BIT(GPIOC->ODR, GPIO_ODR_OD0);
                    // CLEAR_BIT(GPIOB->ODR, GPIO_ODR_OD5);
                }
            }

            led_number++;
            if (led_number > 2)
            {
                led_number = 0;
            }
        }

        if (!button_1)
        {
            but_press_1 = 0;
        }
    }
}
