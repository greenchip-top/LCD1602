# LCD1602
#### **Overview**

1602 LCD is very widely used in applications, The original 1602 LCD used HD44780 controller. Now 1602 modules of various manufacturers basically use compatible IC, so the characteristics are basically the same.

#### **Basic Characteristics and Technical Parameters**

Display capacity is 16 × 2 characters;
The working voltage of the chip is 4.5 ～ 5.5V;
Working current is 2.0mA (5.0V);
The best working voltage of the module is 5.0V;
Character size is 2.95 × 4.35 (W × H) mm;

#### **LCD Interface Pin Definition**

| Numbering | Symbol | Pin description          | Numbering | Symbol | Pin description    |
| --------- | ------ | ------------------------ | --------- | ------ | ------------------ |
| 1         | VSS    | Power ground             | 9         | D2     | Date I/O           |
| 2         | VDD    | Power positive           | 10        | D3     | Date I/O           |
| 3         | VL     | LCD display bias signal  | 11        | D4     | Date I/O           |
| 4         | RS     | Data / command selection | 12        | D5     | Date I/O           |
| 5         | R/W    | Read / write selection   | 13        | D6     | Date I/O           |
| 6         | E      | Enable signal            | 14        | D7     | Date I/O           |
| 7         | D0     | Date I/O                 | 15        | BLA    | Backlight positive |
| 8         | D1     | Date I/O                 | 16        | BLK    | Backlight negative |

#### **Interface Description**

Two sets of power supplies: one is the power supply of the module, and the other is the power supply of the backlight board.Generally, it uses 5V power supply, and the backlight can work with 3.3V power supply.

VL is a pin to adjust the contrast, which is adjusted by the series potentiometer. Note: The contrast resistance of different LCD is different, it is best to connect a potentiometer for testing;

RS is a kind of command / data selection pin on many LCD. When the pin level is high, data operation will be performed; when the pin level is low, command operation will be performed;

RW is also a read-write selection pin on many LCD. A high level on this pin indicates that the LCD is to be read, and a low level indicates that the LCD is to be written.

When the signal of pin E is stable on the bus, it will give a positive pulse notice to read the data away. When the pin is high level, the bus is not allowed to change;

D0—D7 8-bit bidirectional parallel bus, used to transfer commands and data;

BLA is backlight positive, BLK is backlight negative;

#### **Basic Operation of Liquid Crystal**

| Read status       | import | RS=L, R/W=H, E=H                                 | Output | DO~D7=Status word |
| ----------------- | ------ | ------------------------------------------------ | ------ | ----------------- |
| Write instruction | import | RS=L, R/W=L, DO~D7=Instruction code,E=High pulse | Output | none              |
| Read data         | import | RS=H, R/W=H, E=H                                 | Output | DO~D7=data        |
| Write data        | import | RS=H, R/W=L, DO~D7=data, E=High pulse            | Output | none              |

#### **Hardware Related**

Need equipment
Arduino UNO control board: 1
1602 LCD display: 1
Breadboard: 1
Breadboard jumper: several

#### **Connection Diagram**

The connection diagram of 1602 directly communicated with Arduino is divided into the following two types:

Four-bit connection

![image](https://github.com/greenchip-top/LCD1602/blob/master/image/4.png?raw=true)

Eight-bit connection

![image](https://github.com/greenchip-top/LCD1602/blob/master/image/8.png?raw=true)