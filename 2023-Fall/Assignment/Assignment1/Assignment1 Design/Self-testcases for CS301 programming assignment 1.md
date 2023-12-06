# Self-testcases for CS301 programming assignment 1

testcases maker:  Zheng Zubin

## Part1:



(1) Decode mode: 

**input**: `00111100`

**expected observation results**:

**LCD output**: `HI`

**LED output**: LED0 blinks once, LED0 blinks once, LED1 blinks once, LED1 blinks once, **LED0 and LED1 blinks two times at the same time**, LED1 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**.



(2) Encode mode: 

**input**: `BUS`

**expected observation results**:

**LCD output**: `101001100111000`

**LED output**: LED1 blinks once, LED0 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, LED1 blinks once, **LED0 and LED1 blinks two times at the same time**,  LED1 blinks once, LED0 blinks once, LED0 blinks once, LED1 blinks once, LED1 blinks once, **LED0 and LED1 blinks two times at the same time**, LED1 blinks once, LED0 blinks once, LED0 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**.



## Part2:



(1) Exception handling:

- Decode mode:

**input**: `011000101`

**expected observation results**:

**LCD output**: `EA Decode Error: 101 `

**LED output**: LED0 blinks once, LED1 blinks once, LED1 blinks once,  **LED0 and LED1 blinks two times at the same time**, LED0 blinks once, LED0 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**, **turn on LED0 and blink LED1 three times at same time**.

- Encode mode: 

**input**: `L05E`

**expected observation results**:

**LCD output**: `11010 Encode Error: 0 Encode Error: 5 011  `

**LED output**: LED1 blinks once, LED1 blinks once, LED0 blinks once, LED1 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**, **turn on LED1 and blink LED0 three times at same time**, **turn on LED1 and blink LED0 three times at same time**, LED0 blinks once, LED1 blinks once, LED1 blinks once, **LED0 and LED1 blinks two times at the same time**.



(2) Case insensitive and trim blank characters in Encode mode:

**input**: `I am Q`

**expected observation results**:

**LCD output**: `1100000010010010001001 `

**LED output**: LED1 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**,  LED0 blinks once, LED0 blinks once, LED0 blinks once,  **LED0 and LED1 blinks two times at the same time**, LED0 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, LED1 blinks once, **LED0 and LED1 blinks two times at the same time**, LED0 blinks once, LED0 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, LED0 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, LED1 blinks once, **LED0 and LED1 blinks two times at the same time**.



(3) Show decode and encode progress:

- Decode mode:

**input**: `001001000`

**expected observation results**:

**LCD output**: 

`%2023/10/24 19:39:46% G  `

`%2023/10/24 19:39:54% A`   

**LED output**: LED0 blinks once, LED0 blinks once, LED1 blinks once, LED0 blinks once, LED0 blinks once, LED1 blinks once,**LED0 and LED1 blinks two times at the same time**, LED0 blinks once, LED0 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**.

- Encode mode: 

**input**: `AT`

**expected observation results**:

**LCD output**: 

`%2023/10/24 19:41:11% 000  `

`%2023/10/24 19:41:16% 1111`  

**LED output**: LED0 blinks once, LED0 blinks once, LED0 blinks once, **LED0 and LED1 blinks two times at the same time**. LED1 blinks once, LED1 blinks once, LED1 blinks once,  LED1 blinks once,  **LED0 and LED1 blinks two times at the same time**. 

