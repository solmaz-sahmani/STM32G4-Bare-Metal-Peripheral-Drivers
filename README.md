# STM32G4-Bare-Metal-Peripheral-Drivers
All drivers are written using CMSIS only, with no HAL/LL layers and no external dependencies.
This repository is ideal for:

    Embedded developers who want full control of the MCU
    Real‑time, low‑latency or safety‑critical systems
    Educational deep‑dives into STM32 peripherals
    Projects requiring minimal memory footprint
    Learning how each peripheral is configured directly at the register level

# Features

This project provides reusable, clean and highly modular drivers for STM32G431 peripherals:

    RCC (Clock Configuration Driver)
    GPIO (Digital I/O + Alternate Functions)
    USART/UART (Polling, Interrupt, DMA-Friendly Architecture)
    DMA (Basic + Circular Buffer concepts)
    SysTick Timer (Delay, System Tick Handling)
    NVIC Abstractions
    Utility macros & inline register helpers

Each driver:

    Uses bare‑metal register access only
    Comes with clear initialization APIs
    Has separate board configuration layers
    Supports multiple peripheral instances
    Is designed in a professional embedded architecture
