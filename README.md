# DES02-PiRacer-Instrument-Cluster
Developing a Vehicle Speedometer for the Waveshare PiRacer AI Autonomous Racing Robot Car.

<br />
<br />

## Index
- Index
  - [:loudspeaker:  Introduction](#loudspeaker--introduction)
  - [:wrench:  Equipments Used](#wrench--equipments-used)
  - [:memo:  Documentations](#memo--documentations)
  - [:oncoming_automobile:  Our Final Product in Action](#oncoming_automobile--our-final-product-in-action)
  - [:purple_heart:  Credits](#purple_heart--credits)

<br />
<br />

## :loudspeaker:  Introduction
This project is part of [The SEA-ME Study Curriculum](https://github.com/SEA-ME).
> The PiRacer instrument cluster Qt application project is aimed at creating a real-time speedometer for a PiRacer car. The application will run on a Raspberry Pi and receive speed data from a speed sensor via the in-vehicle communication using Controller Area Network (CAN) protocol. This project will provide an opportunity for students to gain practical experience in software engineering, specifically in the areas of embedded systems, software architecture, and communication protocols. The project will also allow students to gain knowledge of the GUI frameworks (eg. Qt), that are widely used in the automotive industry for developing many embedded applications. The successful completion of this project will demonstrate the students' ability to design and implement a real-world software solution, and their ability to effectively communicate their results.

You will find the full Project Description [here](https://github.com/SEA-ME/DES_Instrument-Cluster)

<br />
<br />

## :wrench:  Equipments Used
Below is a List showing the Equipments used for this Project:

- Waveshare PiRacer (Standard Edition) [ [OEM Link](https://www.waveshare.com/piracer-ai-kit.htm) ]
- Raspberry Pi 4 (Model B 8GB RAM) [ [OEM Link](https://www.raspberrypi.com/products/raspberry-pi-4-model-b/) ]
- SEEED Studio 2-Channel MCP2518FD CAN-BUS(FD) HAT for Raspberry Pi [ [OEM Link](https://www.seeedstudio.com/CAN-BUS-FD-HAT-for-Raspberry-Pi-p-4742.html) ]
- Arduino Nano V3, ATmega 328, Mini-USB [ [OEM Link](https://store.arduino.cc/en-de/products/arduino-nano) ]
- MCP2515 CAN BUS Module Compatible with Arduino
- 32GB SanDisk Micro SD Card
- 7.9inch DSI LCD (400 x 1280, 60Hz)
- Joystick

<br />
<br />

## :memo:  Documentations
- [High-level Data Flow Explanation](/docs/Architecture.md)
- [Setting Environment](/docs/environment.md)
- [How Configure Github Action CI/CD](https://github.com/sejoonkimmm/Car-instrument/wiki/How-Configure-Cross-compile-on-Github-action---Docker%3F)
- [CAN Communication Setup](/docs/CAN_Communication.md)
- [Getting The Battery Level](/docs/Battery_Level.md)

<br />
<br />

## :oncoming_automobile:  Our Final Product in Action
<img src="./docs/imgs/final.gif" width="70%" height="70%">

<br />
<br />


## Tech Stack 🛠

<table>
  <tr>
    <td align="center" width="96">
      <a href="https://www.raspberrypi.org/">
        <img src="https://www.raspberrypi.org/app/uploads/2018/03/RPi-Logo-Reg-SCREEN.png" width="48" height="48" alt="Raspberry Pi" />
      </a>
      <br>Raspberry Pi
    </td>
    <td align="center" width="96">
      <a href="https://www.linux.org/">
        <img src="https://upload.wikimedia.org/wikipedia/commons/3/35/Tux.svg" width="48" height="48" alt="Linux" />
      </a>
      <br>Linux
    </td>
    <td align="center" width="96">
      <a href="https://www.docker.com/">
        <img src="https://www.docker.com/wp-content/uploads/2022/03/Moby-logo.png" width="48" height="48" alt="Docker" />
      </a>
      <br>Docker
    </td>
    <td align="center" width="96">
      <a href="https://github.com/features/actions">
        <img src="https://github.githubassets.com/images/modules/site/features/actions-icon-actions.svg" width="48" height="48" alt="GitHub Actions" />
      </a>
      <br>GitHub Actions
    </td>
    <td align="center" width="96">
      <a href="https://www.arduino.cc/">
        <img src="https://upload.wikimedia.org/wikipedia/commons/8/87/Arduino_Logo.svg" width="48" height="48" alt="Arduino" />
      </a>
      <br>Arduino
    </td>
    <td align="center" width="96">
      <a href="https://www.qt.io/">
        <img src="https://upload.wikimedia.org/wikipedia/commons/0/0b/Qt_logo_2016.svg" width="48" height="48" alt="C++ (Qt)" />
      </a>
      <br>C++ (Qt)
    </td>
  </tr>
</table>

<br />
<br />


## :purple_heart:  Credits
- [Arduino CAN Shield Tutorial](https://wiki.seeedstudio.com/CAN-BUS_Shield_V2.0/)
- [2 Channel CAN BUS FD Shield for Raspberry Pi](https://wiki.seeedstudio.com/2-Channel-CAN-BUS-FD-Shield-for-Raspberry-Pi/)

<br />
<br />
