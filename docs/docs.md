---
title: " USTH Smart Garden "
author: \textbf{Member} \newline
        HOANG Duc Minh \newline 
        DO Duy Huy Hoang \newline
        \newline
        \textit{University of Science and Technology Hanoi} \newline 
        \textit{ICT Department}
date: "2019-05-06"
logo: "logo.pdf"
logo-width: 200
titlepage: true
footer-left: Dev
...

\newpage{}
\tableofcontents
\newpage{}

## I. Introduction

Gardening is very interesting, so We thought about making a project in gardening. Nowadays smart garden systems are very popular because people enjoy them. However our challenge is to make the project very simple so that anyone can implement this.
As it turns out, projects based around the Arduino open hardware development board are an excellent place to start.
A soil moisture sensor can read the amount of moisture present in the soil surrounding it. It's an ideal for monitoring an urban garden, or your pet plant's water level. This is a must have component for a IOT garden / Agriculture!

## II. Sensors 

We are now having two different type of sensor: 

  * Capacitive Soil Moisture Sensor - SKU_SEN0193
  * Analog Soil Moisture Sensor - SKU_SEN0114

### A. Capacitive Soil Moisture Sensor - SKU_SEN0193

  \begin{figure}
  \centering
  {\includegraphics[width=4in]{image1.png}}
  \caption{Capacitive Soil Moisture Sensor}
  \end{figure}

This product measures soil moisture levels by capacitive sensing, rather than resistive sensing like other types of moisture sensor. It is made of a corrosion resistant material giving it a long service life. Insert it into soil and impress your friends with the real-time soil moisture data!
The product includes an on-board voltage regulator which gives it an operating voltage range of 3.3 ~ 5.5V. It is compatible with low-voltage MCUs (both 3.3V and 5V logic). To make it compatible with a Raspberry Pi, an ADC converter is required.

For example, we can use an Arduino to read the value directly from the sensor.

**FEATURES**

* Supports Gravity 3-Pin Interface
* Analog Output

**APPLICATIONS**

* Gardening & Farming
* Moisture Detection
* Intelligent Agriculture

**Specification**

* Operating Voltage: 3.3 ~ 5.5 VDC
* Output Voltage: 0 ~ 3.0VDC
* Operating Current: 5mA
* Interface: PH2.0-3P
* Dimensions: 3.86 x 0.905 inches (L x W)
* Weight: 15g

**Schematic**
  \begin{figure}
  \centering
  {\includegraphics[width=5in]{schematic.png}}
  \caption{Schematic}
  \end{figure}

\newpage{}

**Connection**
  \begin{figure}
  \centering
  {\includegraphics[width=7in]{capa.png}}
  \caption{Connection Example with Arduino Uno}
  \end{figure}

| Aduino Uno    | Capacitive Soil Moisture Sensor |
|---------------|---------------------------------|
| GND           | GND ( Black wire )              |
| 5V            | Red Wire                        |
| Analog output | Blue Wire                       |

\newpage{}

**Calibration Range**
\
The components on this board are NOT waterproof, do not expose to moisture further than the red
line. (If you want to protect components from the elements, try using a length of wide heat shrink
tubing around the upper-section of the board.) There is an inverse ratio between the sensor output
value and soil moisture. 

  \begin{figure}
  \centering
  {\includegraphics[width=2.4in]{/home/huyhoang8398/SmartGarden/docs/SEN0193-test.png}}
  \caption{Calibration Range}
  \end{figure}
* The final output value is affected by probe insertion depth and how tight the soil packed around it is.
* The range will be divided into three sections: dry, wet, water. Their related values are:
  * Dry: (520 430]
  * Wet: (430 350]
  * Water: (350 260]

**Sample Code**
\
Our Sample Code can be found [**here**](https://github.com/huyhoang8398/SmartGarden/blob/master/Capacitive_Soil_Moisture_Sensor_SKU_SEN0193/ExampleCode/ExampleCode.c)

\newpage{}

### B. Analog Soil Moisture Sensor - SKU_SEN0114
  \begin{figure}
  \centering
  {\includegraphics[width=2.7in]{/home/huyhoang8398/SmartGarden/docs/IMGP5217.jpg}}
  \caption{Analog Soil Moisture Sensor}
  \end{figure}

This Gravity: **Analog Soil Moisture Sensor** For Arduino can read the amount of moisture present in the soil surrounding it. It's a low tech sensor, but ideal for monitoring an urban garden, or your pet plant's water level. This is a must have tool for a connected garden!
The new soil moisture sensor uses Immersion Gold which protects the nickel from oxidation. Electroless nickel immersion gold (ENIG)  has several advantages over more conventional (and cheaper) surface platings such as HASL (solder), including excellent surface planarity (particularly helpful for PCB's with large BGA packages), good oxidation resistance, and usability for untreated contact surfaces such as membrane switches and contact points.
\
\
This soil moisture arduino sensor uses the two probes to pass current through the soil, and then it reads that resistance to get the moisture level. More water makes the soil conduct electricity more easily (less resistance), while dry soil conducts electricity poorly (more resistance). This sensor will be helpful to remind you to water your indoor plants or to monitor the soil moisture in your garden. 

**Note**: If you are going to place the sensor to very humid soil, that would make it very easy to get the sensor surface erosion within several days, hence we suggest to use this one Analog Capacitive Soil Moisture Sensor- Corrosion Resistant instead.


\newpage{}
**Specification**

* Power supply: 3.3V ~ 5V
* Output voltage signal: 0 ~ 4.2V
* Current: 35mA
* Pin definition:
	* Blue: Analog output
	* Black: GND
	* Red: Power
* Size: 60x20x5mm
* value range:
	* 0~300: dry soil
	* 300~700: humid soil
	* 700~950: in water 

**Schematic**
  \begin{figure}
  \centering
  {\includegraphics[width=5in]{analogschematic.png}}
  \caption{Schematic}
  \end{figure}

\newpage{}

**Connection**
  \begin{figure}
  \centering
  {\includegraphics[width=2.3in]{/home/huyhoang8398/SmartGarden/docs/SEN0114_Dia.png}}
  \caption{Connection Example with Arduino Uno}
  \end{figure}

| Aduino Uno    | Analog Soil Moisture Sensor |
|---------------|---------------------------------|
| GND           | GND ( Black wire )              |
| 5V            | Red Wire                        |
| Analog output | Blue Wire                       |


**Calibration Range**

* The range will be divided into three sections: dry soil, wet soil, in water. Their related values are:
  * 0 ~ 300 - dry soil
  * 300~700 - humid soil
  * 700~950 - in water

\newpage{}
**Sample Code**
\
Our Sample Code can be found [**here**](https://github.com/huyhoang8398/SmartGarden/blob/master/Analog_Soil_Moisture_Sensor_SKU_SEN0114/SampleCode/SampleCode.ino)

## III. Database
  \begin{figure}
  \centering
  {\includegraphics[width=5in]{/home/huyhoang8398/SmartGarden/docs/db.png}}
  \caption{Database}
  \end{figure}

**Note:** This database architecture was built up on our current knowledge of the system. It may change in the future due to practical usage

In the Database, It contains 4 table which is Sensors_Type, Sensor_List, Individual_Sensor, and Data table.
\
We created Sensor_Type table to classify different sensor like (Moisture, Heat, accelerator,..) with their own ID.
\
The table Sensor_List contains all the Sensor ID, e.g: SKU_SEN0114 - stand for Analog Soil Moisture Sensor. 
\
The table Individual_Sensor contains all the sensors and each sensor have its own index value and also their location.
\
The table Data contains value and the time that we read that value from sensor. 

## IV. Server 
On the server side we use a small cronjob to automatically run the php script to receive data from client and update to the database.
\
We would have a website to display the graph of the data.
  \begin{figure}
  \centering
  {\includegraphics[width=6.7in]{/home/huyhoang8398/SmartGarden/docs/graph.png}}
  \caption{Data Visualization}
  \end{figure}

## V. Client 

We have a small python script and It is controlled by a cron job. Basically It will read the directly output from the arduino and send back to the server by using HTTP GET request.
