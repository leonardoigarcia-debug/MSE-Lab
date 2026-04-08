#include <stdint.h>

#define RCC_BASE (0x40023800UL)
#define RCC_AHB1ENR_OFFSET (RCC_BASE + 0x30UL)
#define RCC_AHB1ENR (*(volatile unsigned int *)(RCC_AHB1ENR_OFFSET))

#define GPIOA_BASE (0x40020000UL)
#define GPIOA_MODER_OFFSET (GPIOA_BASE + 0x00UL)
#define GPIOA_MODER (*(volatile unsigned int *)(GPIOA_MODER_OFFSET))

#define GPIOA_ODR_OFFSET (GPIOA_BASE + 0x14UL)
#define GPIOA_ODR (*(volatile unsigned int *)(GPIOA_ODR_OFFSET))

#define GPIOA_EN (0)
#define CLK_EN (1U)


#define __I 		volatile const
#define __O 		volatile
#define __IO		volatile


#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
    RCC_AHB1ENR |= (CLK_EN << GPIOA_EN);

    GPIOA_MODER |= (1U << 10);
    GPIOA_MODER &= ~(1U << 11);

    for(;;){
        GPIOA_ODR ^= (1U << 5);
        for(int i = 0; i < 80000 ; i++){

        }


    }
}
