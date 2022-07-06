# Arduino Simon Memory Game ![Project License Badge](https://img.shields.io/badge/license-MIT-brightgreen) ![Project Tech Badge](https://img.shields.io/badge/platform-Arduino-informational) 

<div align="center">

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)
![Visual Studio Code](https://img.shields.io/badge/Visual%20Studio%20Code-0078d7.svg?style=for-the-badge&logo=visual-studio-code&logoColor=white)

</div>

## Description

A Simon memory game built on Arduino using PlatformIO. This was my first real independent Arduino project done without any tutorials. The ezButton library is used to handle button debounce. 

This project was built on the Arduino Uno R3 but should work on most arduino boards. It takes 4 inputs and 4 outputs. Any simple electronics kits should include the components needed. A complete bill of materials can be found in the `/resources` directory of this project as well as a schematic and breadboard layout. 

***

 ## Table of Contents

  * [Usage](#usage)
  * [Breadboard Layout](#breadboard)
  * [Bill of Materials](#bom)
  * [License](#license)
  * [Questions](#questions)

## Usage

The only files you need to run on the arduino are located in the `/src` directory of the project. You can clone the repository directly or simply copy the files from `/src` and paste them into your own PlatformIO project. You can find more information about PlatformIO [here](https://platformio.org/). 

From there you will need to build the hardware! Follow the breadboard layout below or the schematic located in the `/resources` directory. Once you have the hardware built, connect your arduino to your computer and upload the code. Once uploaded you should be able to press the buttons and see the LEDs come on. To start the game, press all four LEDs at the same time. 

> NOTE: If the game does not start when you are pressing all buttons, reset your Arduino. 

## Breadboard Layout <a id="breadboard"></a>

![Breadboard Layout](https://github.com/Thenlie/simon-game/blob/main/resources/breadboard-layout.PNG) 

> NOTE: This layout and a schematic can be found in the `/resources` directory of this project. 

## Bill of Materials <a id="bom"></a>

|Name          |Quantity|Component      |
|--------------|--------|---------------|
|D1            |1       |Red LED        |
|D2            |1       |Yellow LED     |
|D3            |1       |Green LED      |
|D4            |1       |Blue LED       |
|S1, S2, S3, S4|4       | Pushbutton    |
|U1            |1       | Arduino Uno R3|
|R1, R2, R3, R4|4       |220 Ω Resistor |

## License

<details>

<summary>MIT License</summary>

> Copyright (c) [2022] [Thenlie]
> 
> __Permission is hereby granted, free of charge, to any person obtaining a copy__
> __of this software and associated documentation files (the "Software"), to deal__
> __in the Software without restriction, including without limitation the rights__
> __to use, copy, modify, merge, publish, distribute, sublicense, and/or sell__
> __copies of the Software, and to permit persons to whom the Software is__
> __furnished to do so, subject to the following conditions:__
> 
> The above copyright notice and this permission notice shall be included in all
> copies or substantial portions of the Software.
> 
> THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
> IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
> FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
> AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
> LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
> OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
> SOFTWARE.

</details>

## Questions?

If you have any questions about the project you can reach out to me via email or GitHub with the information below. 

>Email: leithen113@gmail.com 

>GitHub: [Thenlie](https://github.com/Thenlie)
