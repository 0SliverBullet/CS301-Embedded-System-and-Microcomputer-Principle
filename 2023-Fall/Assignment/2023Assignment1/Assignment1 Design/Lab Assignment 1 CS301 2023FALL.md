# Lab Assignment 1 CS301 2023FALL

You are Jim Moriarty and want to contact with Sherlock Holmes. But you do not want other people (John Watson, Mycroft Holmes, etc) know the contents of the message you send, so you must encode the message in some way. You decide that the message will be encoded by the famous **Huffman code**. However, manual Huffman encoding is too cumbersome, so you want to write a **Huffman Encoding and Decoding Machine(HEDM)** to facilitate communication with Sherlock. Of course, we suppose that Sherlock Holmes is smart enough to know how to decode, you do not worry about it.

**Huffman code** is a type of variable-length encoding that is based on the actual character frequencies in a given document. The following document is a speech made by Sherlock at John's wedding, which you found in Baker Street 221B. We roughly believe that this document represents Sherlock's language habits.

|                                                              |
| ------------------------------------------------------------ |
| *I‘m afraid John, i can't congratulate you. All emotions, and in particular love, stand oppose to the pure, cold reason i hold above all things. A wedding is, in my considered opinion, nothing short of celebration of all that is false and specious and irrational and sentimental in this ailing and morally compromised world. Today we honor the deathwatch beetle that is the doom of our society, and in time, one feels certain, our entire species. But anyway, let's talk about John. If i burden myself with a little helpmate during my adventures, this is not out of sentiment or caprice, it is that he has many fine qualities of his own that the have overlooked in his obsession with me. Indeed my reputation i have for mental acuity and sharpness comes in truth, from the extraordinary contrast John so selflessly provides. It is a fact i believe, that brides tend to favour exceptionally plain bridesmaids for their big day. There is a certain analogy there i feel. And contrast is, after all, God's own plan to enhance the beauty of his creation. Or it would be if God were not a ludicrous fantasy designed to proved a career opportunity for the family idiot.  The point i try to make is, that i am the most unpleasant, rude, ignorant, and all-round obnoxious arsehole, that anyone could possibly have the misfortune to meet. I am dismissive of the virtuous, unaware of the beautiful and uncomprehending in the front of the happy. So if i didn't understand i was being asked to be best man, it is because i have never expected to be anybody's best friend, and certainly not the best friend of the bravest and kindest and wisest human being I have ever had the good fortune of knowing. John i am a ridiculous man, redeemed only by the warmth and constancy of your friendship. But as i am apparently your best friend, i can't congratulate you on your choice of companion. Actually now i can. Mary, when i say you deserve this man, it is the highest compliment of which i am capable. John, you have endured war and injury and tragic loss. So sorry again about that last one. So know this, today you sit between the woman you have made your wife and the man you have saved. In short the two people who love you most all in this world. And i know I speak for Mary as well when i say, we'll never let you down and we have a lifetime ahead to prove that.* |



You need to write a **HEDM** based on the actual character frequencies in the above document. To save your time and ensure the uniqueness of Huffman encoding, we conducted a preliminary analysis of the Huffman tree. The coding rules are shown below:

| **Character** | Frequency | Huffman Code | **Character** | Frequency | Huffman Code |
| :-----------: | :-------: | :----------: | :-----------: | :-------: | :----------: |
|       A       |    168    |    `000`     |       N       |    147    |    `1011`    |
|       B       |    32     |   `101001`   |       O       |    160    |    `1110`    |
|       C       |    44     |   `00101`    |       P       |    36     |   `101011`   |
|       D       |    84     |   `11011`    |       Q       |     1     | `0010001001` |
|       E       |    200    |    `011`     |       R       |    97     |    `0101`    |
|       F       |    44     |   `01000`    |       S       |    107    |    `1000`    |
|       G       |    21     |   `001001`   |       T       |    165    |    `1111`    |
|       H       |    88     |    `0011`    |       U       |    59     |   `10011`    |
|       I       |    149    |    `1100`    |       V       |    27     |   `101000`   |
|       J       |     6     |  `00100011`  |       W       |    33     |   `101010`   |
|       K       |     9     |  `0010000`   |       X       |     4     | `001000101`  |
|       L       |    74     |   `11010`    |       Y       |    52     |   `10010`    |
|       M       |    47     |   `01001`    |       Z       |     0     | `0010001000` |



## **Part 1 (80%)**

In this part, you need to realize the information transfer with the STM32 Development Board. You should use **ISP serial port** to download your projects.

1. HEDM basic configuration (10%):

   - When receiving information, use keys to send Huffman Code, for example use KEY0 as **0**, KEY1 as **1**  and KEY_WAKEUP as **Confirmation/Mode Switch** key. When representing information, use led light to show Huffman Code, for example use LED0 as **0**, LED1 as **1**. At the same time, use LCD screen to display the information, for example divide the LCD screen into two parts: in decoding mode, when the KEY0 and KEY1 buttons are pressed, the LCD screen displays the input content in real-time; When the input is completed and the Confirmation key is pressed, the LCD screen displays the decoding result. The LCD display is the same when encoding.  
   - Realize button anti-shake function.

2. Processing single alphabet Huffman Code (20%):

   - When receiving **0** after pressing Confirmation key, blink LED0 one time;
   - When receiving **1** after pressing Confirmation key, blink LED1 one time;
   - When receiving successive **0** and **1** after pressing Confirmation key, LED0 and LED1 should blink in order. For example, when receiving the message `1011` , blink LED1 one time, then blink LED0 one time, finally blink LED1 two times. (Note that the LED0 and LED1 cannot flash at the same time when receiving successive **0** and **1**)

3. Processing multiple alphabet Huffman Code (10%):

   - Notes that we **do not** use any other characters to represent the end of alphabet Huffman Code when there are multiple alphabet Huffman Codes, so your design should have the function that gives a reminder to represent the end of alphabet Huffman Code, i.e. when detecting the end of a single alphabet Huffman Code from multiple alphabet Huffman Codes, blink LED0 and LED1 two times at the same time.
   - For example, the Huffman Code of `HELLO` is `001101111010110101110`, blink LED0 and LED1 two times at the same time after representing `0011`, `011`, `11010`, `11010`, `1110`  respectively.

4. Decode and encode Huffman Code (40%):

   - Decode: After receiving the Huffman Code from keys, send the **decoded characters** to LCD screen. Then LED0 and LED1 should blink in the order of Huffman Code.
   - Encode: After receiving the alphabet (English letters) to be translated from keys, send the **encoded Huffman** **Code** to LCD screen. Then LED0 and LED1 should blink in the order of Huffman Code. Design mechanism to represent the English letters (including uppercase and lowercase). For example, one case is that If you take use of hexadecimal notation (other bases can also be used), based on KEY0 and KEY1 keys, you can represent a two digit hexadecimal number, which can be converted into English letters in ASCII code.
   - Design mechanism to switch between Encode and Decode modes. For example, one case is that after receiving **null message** from keys, it switch current mode to the other mode. Please show the current HEDM mode on LCD screen.

   

## Part 2 (20%)

In this section, you can design own requirements that you think are reasonable, and we will score them according to the level of creativity and difficulty. The following are some examples:

1. Exception handling (10%)

   - Decode: Abnormal input like invalid Huffman code like `0`. Send error message and corresponding error Huffman Code to LCD screen, for example `Decode Error: 0`. Then **turn on LED0** and **blink LED1 three times** at same time. 

   - Encode: Non-alphabetic character input like `1, @` . Send error message and corresponding error non-alphabetic character to LCD screen, for example `Encode Error: 1` . Then **turn on LED1** and **blink LED0 three times** at same time. After that, continue to process the next character to be translated.

2. Case insensitive and trim blank characters in Encode mode (10%):

   - With phrase `SUSTECH STUDENT`,  `SUSTech student` and `SUSTECHSTUDENT` are both OK to encode.

3. Show decode and encode progress (5%):

   - Decode: Send the corresponding message before the light blinks according to the corresponding Huffman code. For example, when decode `001101111010110101110` , first send the message `%time% H` to LCD screen, and blink the led according Huffman Code `0011` , then send the message `%time% E` to LCD screen, and blink the led according Huffman Code `011` and so on. `%time%` is the current time.
   - Encode: Send the corresponding message before the light blinks according to the corresponding Letter to be translated. For example, when decode `HELLO`, first send the message `%time% 0011` to LCD screen, and blink the led according Huffman Code `0011`, then send the message `%time% 011` to LCD screen, and blink the led according Huffman Code `011` and so on. `%time%` is the current time.

4. Display information on successful or failed encoding and decoding (5%):

   - Show a small picture (not characters) on LCD to say successful or failed encoding and decoding.

5. Use LCD screen as input device, not keys (20%):

   - Redesign layout of LCD screen to ensure there are enough space for input and output display.

    

## **Submission demands**

1. Finish the assignment before DDL.

2. Package the whole project into a compressed package and submit on Blackboard site.