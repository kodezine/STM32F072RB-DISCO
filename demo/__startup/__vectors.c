#include <stdint.h>
#include "stm32f030x8.h"
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6100100)
    #include "__vectors_ac6.h"
#elif defined(__GNUC__)
    #if defined(__clang__)
        #include "__vectors_llvm.h"
    #else
        //#include "__vectors_gcc.h"
    #endif
#endif
#include "system_ARMCM0.h"
#include "cmsis_compiler.h"

/******************************************************************************
 * @file     startup_<Device>.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device <Device>
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);
__NO_RETURN void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak));
// void MemManage_Handler                  (void) __attribute__ ((weak, alias("Default_Handler")));
// void BusFault_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
// void UsageFault_Handler                 (void) __attribute__ ((weak, alias("Default_Handler")));
// void SecureFault_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler(void) __attribute__((weak, alias("Default_Handler")));
// void DebugMon_Handler                   (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler(void) __attribute__((weak, alias("Default_Handler")));

/* Add your device specific interrupt handler */
/*---------------------------------------------------------------------------
  ISR
 *---------------------------------------------------------------------------*/
void WWDG_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ_017(void) __attribute__((weak, alias("Default_Handler")));
void RTC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_15_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ_024(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel2_3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Channel4_5_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void ADC1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_UP_TRG_COM_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ_031(void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM6_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void IRQ_034(void) __attribute__((weak, alias("Default_Handler")));
void TIM14_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM15_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM16_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void TIM17_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void I2C2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler(void) __attribute__((weak, alias("Default_Handler")));
/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[64];
const VECTOR_TABLE_Type __VECTOR_TABLE[64] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP),                 /*     Initial Stack Pointer */
    (VECTOR_TABLE_Type)&Reset_Handler,                  /*     Reset Handler */
    (VECTOR_TABLE_Type)&NMI_Handler,                    /* -14 NMI Handler */
    (VECTOR_TABLE_Type)&HardFault_Handler,              /* -13 Hard Fault Handler */
    (VECTOR_TABLE_Type)0,                               /* -12 MPU Fault Handler */
    (VECTOR_TABLE_Type)0,                               /* -11 Bus Fault Handler */
    (VECTOR_TABLE_Type)0,                               /* -10 Usage Fault Handler */
    (VECTOR_TABLE_Type)0,                               /*  -9 Secure Fault Handler */
    (VECTOR_TABLE_Type)0,                               /*     Reserved */
    (VECTOR_TABLE_Type)0,                               /*     Reserved */
    (VECTOR_TABLE_Type)0,                               /*     Reserved */
    (VECTOR_TABLE_Type)&SVC_Handler,                    /*  -5 SVCall Handler */
    (VECTOR_TABLE_Type)0,                               /*  -4 Debug Monitor Handler */
    (VECTOR_TABLE_Type)0,                               /*     Reserved */
    (VECTOR_TABLE_Type)&PendSV_Handler,                 /*  -2 PendSV Handler */
    (VECTOR_TABLE_Type)&SysTick_Handler,                /*  -1 SysTick Handler */
    (VECTOR_TABLE_Type)&WWDG_IRQHandler,                /* 016 Window WatchDog              */
    (VECTOR_TABLE_Type)0,                               /* 017 Reserved                     */
    (VECTOR_TABLE_Type)&RTC_IRQHandler,                 /* 018 RTC through the EXTI line    */
    (VECTOR_TABLE_Type)&FLASH_IRQHandler,               /* 019 FLASH                        */
    (VECTOR_TABLE_Type)&RCC_IRQHandler,                 /* 020 RCC                          */
    (VECTOR_TABLE_Type)&EXTI0_1_IRQHandler,             /* 021 EXTI Line 0 and 1            */
    (VECTOR_TABLE_Type)&EXTI2_3_IRQHandler,             /* 022 EXTI Line 2 and 3            */
    (VECTOR_TABLE_Type)&EXTI4_15_IRQHandler,            /* 023 EXTI Line 4 to 15            */
    (VECTOR_TABLE_Type)0,                               /* 024 Reserved                     */
    (VECTOR_TABLE_Type)&DMA1_Channel1_IRQHandler,       /* 025 DMA1 Channel 1               */
    (VECTOR_TABLE_Type)&DMA1_Channel2_3_IRQHandler,     /* 026 DMA1 Channel 2 and Channel 3 */
    (VECTOR_TABLE_Type)&DMA1_Channel4_5_IRQHandler,     /* 027 DMA1 Channel 4 and Channel 5 */
    (VECTOR_TABLE_Type)&ADC1_IRQHandler,                /* 028 ADC1                         */
    (VECTOR_TABLE_Type)&TIM1_BRK_UP_TRG_COM_IRQHandler, /* 029 TIM1 Break, Update, Trigger and Commutation */
    (VECTOR_TABLE_Type)&TIM1_CC_IRQHandler,             /* 030 TIM1 Capture Compare         */
    (VECTOR_TABLE_Type)0,                               /* 031 Reserved                     */
    (VECTOR_TABLE_Type)&TIM3_IRQHandler,                /* 032 TIM3                         */
    (VECTOR_TABLE_Type)&TIM6_IRQHandler,                /* 033 TIM6                         */
    (VECTOR_TABLE_Type)0,                               /* 034 Reserved                     */
    (VECTOR_TABLE_Type)&TIM14_IRQHandler,               /* 035 TIM14                        */
    (VECTOR_TABLE_Type)&TIM15_IRQHandler,               /* 036 TIM15                        */
    (VECTOR_TABLE_Type)&TIM16_IRQHandler,               /* 037 TIM16                        */
    (VECTOR_TABLE_Type)&TIM17_IRQHandler,               /* 038 TIM17                        */
    (VECTOR_TABLE_Type)&I2C1_IRQHandler,                /* 039 I2C1                         */
    (VECTOR_TABLE_Type)&I2C2_IRQHandler,                /* 040 I2C2                         */
    (VECTOR_TABLE_Type)&SPI1_IRQHandler,                /* 041 SPI1                         */
    (VECTOR_TABLE_Type)&SPI2_IRQHandler,                /* 042 SPI2                         */
    (VECTOR_TABLE_Type)&USART1_IRQHandler,              /* 043 USART1                       */
    (VECTOR_TABLE_Type)&USART2_IRQHandler,              /* 044 USART2                       */
    (VECTOR_TABLE_Type)0,                               /* 045 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 046 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 047 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 048 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 049 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 050 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 051 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 052 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 053 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 054 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 055 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 056 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 057 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 058 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 059 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 060 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 061 Reserved                     */
    (VECTOR_TABLE_Type)0,                               /* 062 Reserved                     */
    (VECTOR_TABLE_Type)0                                /* 063 Reserved                     */
};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    __set_PSP((uint32_t)(&__INITIAL_SP));

/* ToDo: Initialize stack limit register for Armv8-M Main Extension based processors*/
//    __set_MSP((uint32_t)(&__STACK_LIMIT));
//    __set_PSP((uint32_t)(&__STACK_LIMIT));

/* ToDo: Add stack sealing for Armv8-M based processors */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();      /* CMSIS System Initialization */
    __PROGRAM_START(); /* Enter PreMain (C library entry point) */
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
    while (1)
        ;
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
    while (1)
        ;
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
