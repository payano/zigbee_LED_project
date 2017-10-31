EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:IRF3205
LIBS:stm32-nucleo_pinout
LIBS:mrf24j40ma
LIBS:ds-001
LIBS:switches
LIBS:PotHoles
LIBS:buttonswitch
LIBS:drill_hole
LIBS:schema_v1-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	1100 2950 1500 2950
$Comp
L LED D1
U 1 1 59E6E88D
P 2600 1000
F 0 "D1" H 2600 1100 50  0000 C CNN
F 1 "LED" H 2600 900 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 2600 1000 50  0001 C CNN
F 3 "" H 2600 1000 50  0000 C CNN
	1    2600 1000
	0    -1   -1   0   
$EndComp
Text GLabel 2800 2500 2    60   Input ~ 0
12V
Text GLabel 2750 4150 2    60   Input ~ 0
Button_1
Text GLabel 2750 4000 2    60   Input ~ 0
Slider_1
Text GLabel 2750 3850 2    60   Input ~ 0
Button_2
Text GLabel 2750 3700 2    60   Input ~ 0
Slider_2
Text GLabel 2750 3250 2    60   Input ~ 0
RGB_R
Text GLabel 1100 3250 0    60   Input ~ 0
RGB_G
Text GLabel 1100 3700 0    60   Input ~ 0
RGB_B
Text GLabel 1100 4600 0    60   Input ~ 0
PANEL
$Comp
L STM32-Nucleo_Pinout U1
U 1 1 59E6F47A
P 1950 2300
F 0 "U1" H 1950 -100 60  0000 C CNN
F 1 "STM32-Nucleo_Pinout" H 1950 2250 60  0000 C CNN
F 2 "stm32nucleo:STM32-Nucleo_Pinout" H 1800 2350 60  0001 C CNN
F 3 "" H 1800 2350 60  0001 C CNN
	1    1950 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 4000 2400 4000
Wire Wire Line
	2750 4150 2400 4150
Wire Wire Line
	2750 3850 2400 3850
Text GLabel 2750 3550 2    60   Input ~ 0
TEMP_SENSOR
Wire Wire Line
	2750 3550 2400 3550
Text GLabel 2750 3400 2    60   Input ~ 0
SPI_MISO
Wire Wire Line
	2750 3400 2400 3400
Wire Wire Line
	2750 3250 2400 3250
Wire Wire Line
	2800 2500 2400 2500
Wire Wire Line
	1100 3250 1500 3250
Wire Wire Line
	1100 3700 1500 3700
Wire Wire Line
	1100 4600 1500 4600
Text GLabel 2750 4450 2    60   Input ~ 0
3.3V
Wire Wire Line
	2750 4450 2400 4450
Text GLabel 1100 2500 0    60   Input ~ 0
SPI_INT
Text GLabel 1100 4150 0    60   Input ~ 0
SPI_CS
Wire Wire Line
	1100 2500 1500 2500
Wire Wire Line
	1100 4150 1500 4150
$Comp
L BC547 Q1
U 1 1 59E70340
P 1500 1750
F 0 "Q1" H 1700 1825 50  0000 L CNN
F 1 "BC547" H 1700 1750 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 1700 1675 50  0000 L CIN
F 3 "" H 1500 1750 50  0000 L CNN
	1    1500 1750
	1    0    0    -1  
$EndComp
$Comp
L MosfetIRF U2
U 1 1 59E7056D
P 2600 1450
F 0 "U2" H 2750 1254 60  0000 C CNN
F 1 "MosfetIRF" H 2600 1650 60  0000 C CNN
F 2 "library:IRF3205" H 2600 1450 60  0001 C CNN
F 3 "" H 2600 1450 60  0000 C CNN
	1    2600 1450
	1    0    0    1   
$EndComp
$Comp
L R R1
U 1 1 59E70669
P 1150 1750
F 0 "R1" V 1230 1750 50  0000 C CNN
F 1 "1k" V 1150 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 1080 1750 50  0001 C CNN
F 3 "" H 1150 1750 50  0000 C CNN
	1    1150 1750
	0    1    1    0   
$EndComp
Text GLabel 850  1750 0    60   Input ~ 0
PANEL
Wire Wire Line
	850  1750 1000 1750
Text GLabel 1600 800  1    60   Input ~ 0
12V
$Comp
L R R2
U 1 1 59E71BF5
P 1600 1350
F 0 "R2" V 1680 1350 50  0000 C CNN
F 1 "12k" V 1600 1350 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 1530 1350 50  0001 C CNN
F 3 "" H 1600 1350 50  0000 C CNN
	1    1600 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 1500 1600 1550
Wire Wire Line
	1600 800  1600 1200
Wire Wire Line
	1600 1950 1600 2100
$Comp
L R R3
U 1 1 59E71EE9
P 2100 1750
F 0 "R3" V 2180 1750 50  0000 C CNN
F 1 "39k" V 2100 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 2030 1750 50  0001 C CNN
F 3 "" H 2100 1750 50  0000 C CNN
	1    2100 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	2100 1900 2100 2050
Wire Wire Line
	2100 2050 1600 2050
Wire Wire Line
	1600 1500 2200 1500
Wire Wire Line
	2100 1500 2100 1600
Connection ~ 2100 1500
Wire Wire Line
	2600 1150 2600 1200
Connection ~ 1600 850 
Wire Wire Line
	2400 2650 2800 2650
$Comp
L R R8
U 1 1 59E78E23
P 6700 1850
F 0 "R8" V 6780 1850 50  0000 C CNN
F 1 "1k" V 6700 1850 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 6630 1850 50  0001 C CNN
F 3 "" H 6700 1850 50  0000 C CNN
	1    6700 1850
	0    1    1    0   
$EndComp
$Comp
L BC547 Q3
U 1 1 59E78EDF
P 7050 1850
F 0 "Q3" H 7250 1925 50  0000 L CNN
F 1 "BC547" H 7250 1850 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 7250 1775 50  0000 L CIN
F 3 "" H 7050 1850 50  0000 L CNN
	1    7050 1850
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 59E78F94
P 7150 1400
F 0 "R9" V 7230 1400 50  0000 C CNN
F 1 "12k" V 7150 1400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 7080 1400 50  0001 C CNN
F 3 "" H 7150 1400 50  0000 C CNN
	1    7150 1400
	1    0    0    -1  
$EndComp
Text GLabel 7150 850  1    60   Input ~ 0
12V
$Comp
L LED D7
U 1 1 59E79090
P 7850 1100
F 0 "D7" H 7850 1200 50  0000 C CNN
F 1 "LED" H 7850 1000 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 7850 1100 50  0001 C CNN
F 3 "" H 7850 1100 50  0000 C CNN
	1    7850 1100
	0    -1   -1   0   
$EndComp
$Comp
L MosfetIRF U6
U 1 1 59E79140
P 7850 1550
F 0 "U6" H 8000 1354 60  0000 C CNN
F 1 "MosfetIRF" H 7850 1750 60  0000 C CNN
F 2 "library:IRF3205" H 7850 1550 60  0001 C CNN
F 3 "" H 7850 1550 60  0000 C CNN
	1    7850 1550
	1    0    0    1   
$EndComp
Wire Wire Line
	7150 1550 7150 1650
Wire Wire Line
	7450 1600 7150 1600
Connection ~ 7150 1600
Wire Wire Line
	6550 1850 6450 1850
Wire Wire Line
	7850 900  7850 950 
$Comp
L R R10
U 1 1 59E7A7D5
P 7450 1750
F 0 "R10" V 7530 1750 50  0000 C CNN
F 1 "39k" V 7450 1750 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 7380 1750 50  0001 C CNN
F 3 "" H 7450 1750 50  0000 C CNN
	1    7450 1750
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 1900 7450 2100
Wire Wire Line
	7150 2050 7150 2150
Connection ~ 7150 2100
Connection ~ 1600 2050
Wire Wire Line
	7850 1250 7850 1300
Text GLabel 9200 1900 0    60   Input ~ 0
RGB_B
$Comp
L BC547 Q4
U 1 1 59E7D2A9
P 9800 1900
F 0 "Q4" H 10000 1975 50  0000 L CNN
F 1 "BC547" H 10000 1900 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 10000 1825 50  0000 L CIN
F 3 "" H 9800 1900 50  0000 L CNN
	1    9800 1900
	1    0    0    -1  
$EndComp
$Comp
L R R11
U 1 1 59E7D360
P 9400 1900
F 0 "R11" V 9480 1900 50  0000 C CNN
F 1 "1k" V 9400 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 9330 1900 50  0001 C CNN
F 3 "" H 9400 1900 50  0000 C CNN
	1    9400 1900
	0    1    1    0   
$EndComp
$Comp
L R R12
U 1 1 59E7D438
P 9900 1400
F 0 "R12" V 9980 1400 50  0000 C CNN
F 1 "12k" V 9900 1400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 9830 1400 50  0001 C CNN
F 3 "" H 9900 1400 50  0000 C CNN
	1    9900 1400
	1    0    0    -1  
$EndComp
Text GLabel 9900 850  1    60   Input ~ 0
12V
$Comp
L MosfetIRF U7
U 1 1 59E7D619
P 10600 1550
F 0 "U7" H 10750 1354 60  0000 C CNN
F 1 "MosfetIRF" H 10600 1750 60  0000 C CNN
F 2 "library:IRF3205" H 10600 1550 60  0001 C CNN
F 3 "" H 10600 1550 60  0000 C CNN
	1    10600 1550
	1    0    0    1   
$EndComp
$Comp
L LED D10
U 1 1 59E7D6ED
P 10600 1050
F 0 "D10" H 10600 1150 50  0000 C CNN
F 1 "LED" H 10600 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 10600 1050 50  0001 C CNN
F 3 "" H 10600 1050 50  0000 C CNN
	1    10600 1050
	0    -1   -1   0   
$EndComp
$Comp
L R R13
U 1 1 59E7D791
P 10150 1900
F 0 "R13" V 10230 1900 50  0000 C CNN
F 1 "39k" V 10150 1900 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 10080 1900 50  0001 C CNN
F 3 "" H 10150 1900 50  0000 C CNN
	1    10150 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9900 1550 9900 1700
Wire Wire Line
	9900 1600 10200 1600
Connection ~ 9900 1600
Wire Wire Line
	10600 1200 10600 1300
Connection ~ 9900 900 
Wire Wire Line
	9900 1250 9900 850 
Wire Wire Line
	9200 1900 9250 1900
Wire Wire Line
	9550 1900 9600 1900
Wire Wire Line
	10150 1750 10150 1600
Connection ~ 10150 1600
Wire Wire Line
	10150 2050 10150 2150
Wire Wire Line
	10150 2150 9900 2150
Wire Wire Line
	9900 2100 9900 2200
Connection ~ 9900 2150
$Comp
L mrf24j40ma U5
U 1 1 59E7FB30
P 5450 3200
F 0 "U5" H 5400 2200 60  0000 C CNN
F 1 "mrf24j40ma" H 5400 3200 60  0000 C CNN
F 2 "mrf24j40ma:mrf24j40ma" H 5450 3200 60  0001 C CNN
F 3 "" H 5450 3200 60  0001 C CNN
	1    5450 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5850 3350 5850 3500
Wire Wire Line
	5850 3400 6150 3400
Connection ~ 5850 3400
Text GLabel 6200 4100 2    60   Input ~ 0
SPI_MISO
Wire Wire Line
	6200 4100 5850 4100
Text GLabel 1100 4450 0    60   Input ~ 0
SPI_MOSI
Wire Wire Line
	1100 4450 1500 4450
Text GLabel 4550 3950 0    60   Input ~ 0
SPI_MOSI
Wire Wire Line
	4550 3950 4950 3950
Text GLabel 6200 3950 2    60   Input ~ 0
SPI_CS
Wire Wire Line
	6200 3950 5850 3950
Text GLabel 6200 3650 2    60   Input ~ 0
3.3V
Wire Wire Line
	6200 3650 5850 3650
Text GLabel 4500 3500 0    60   Input ~ 0
MRF_RESET
Text GLabel 2750 4600 2    60   Input ~ 0
SPI_SCK
Wire Wire Line
	2400 4600 2750 4600
Text GLabel 4550 4100 0    60   Input ~ 0
SPI_SCK
Wire Wire Line
	4550 4100 4950 4100
Text GLabel 4500 3800 0    60   Input ~ 0
SPI_INT
Wire Wire Line
	4500 3800 4950 3800
$Comp
L Screw_Terminal_1x02 J1
U 1 1 59E82932
P 900 5350
F 0 "J1" H 900 5600 50  0000 C TNN
F 1 "Screw_Terminal_1x02" V 750 5350 50  0000 C TNN
F 2 "potHoles:P_Led_Holes" H 900 5125 50  0001 C CNN
F 3 "" H 875 5350 50  0001 C CNN
	1    900  5350
	1    0    0    -1  
$EndComp
Text GLabel 1400 5250 2    60   Input ~ 0
12V
Wire Wire Line
	1100 5250 1400 5250
Text GLabel 2350 5300 0    60   Input ~ 0
12V
$Comp
L R R4
U 1 1 59E83B01
P 2550 5300
F 0 "R4" V 2630 5300 50  0000 C CNN
F 1 "12k" V 2550 5300 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 2480 5300 50  0001 C CNN
F 3 "" H 2550 5300 50  0000 C CNN
	1    2550 5300
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2350 5300 2400 5300
Wire Wire Line
	2700 5300 2800 5300
Wire Wire Line
	3100 5300 3150 5300
$Comp
L DS-001 U3
U 1 1 59E76DBD
P 4700 4750
F 0 "U3" H 4700 3950 60  0000 C CNN
F 1 "DS-001" H 4700 4750 60  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 4700 4750 60  0001 C CNN
F 3 "" H 4700 4750 60  0001 C CNN
	1    4700 4750
	1    0    0    -1  
$EndComp
Text GLabel 5150 5450 2    60   Input ~ 0
TEMP_SENSOR
Wire Wire Line
	4300 5050 4300 5100
Text GLabel 5250 5050 2    60   Input ~ 0
3.3V
Wire Wire Line
	5250 5050 5100 5050
Wire Wire Line
	3000 1500 3000 1550
Wire Wire Line
	7150 850  7150 1250
Wire Wire Line
	7150 900  8250 900 
Connection ~ 7150 900 
Wire Wire Line
	1400 5450 1100 5450
Text GLabel 800  6550 0    60   Input ~ 0
3.3V
Text GLabel 1400 7100 3    60   Input ~ 0
Slider_1
Text GLabel 2950 7100 3    60   Input ~ 0
Slider_2
Text GLabel 2400 6550 0    60   Input ~ 0
3.3V
Text GLabel 4500 6150 0    60   Input ~ 0
3.3V
Text GLabel 5350 6150 2    60   Input ~ 0
Button_1
Text GLabel 5400 6550 2    60   Input ~ 0
Button_2
Text GLabel 4500 6550 0    60   Input ~ 0
3.3V
Wire Wire Line
	4500 6550 4700 6550
Wire Wire Line
	5300 6550 5400 6550
Wire Wire Line
	11000 1600 11050 1600
Wire Wire Line
	11050 1600 11050 1650
$Comp
L Pot_Holes Pot1
U 1 1 59E97474
P 1350 6400
F 0 "Pot1" H 1600 5800 60  0000 C CNN
F 1 "Pot_Holes" H 1400 6450 60  0000 C CNN
F 2 "potHoles:Pot_Holes" H 1350 6400 60  0001 C CNN
F 3 "" H 1350 6400 60  0001 C CNN
	1    1350 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	800  6550 1000 6550
Wire Wire Line
	1800 6550 1900 6550
Wire Wire Line
	1900 6550 1900 6600
Wire Wire Line
	1400 7000 1400 7100
$Comp
L Pot_Holes Pot2
U 1 1 59E981AC
P 2900 6400
F 0 "Pot2" H 3150 5800 60  0000 C CNN
F 1 "Pot_Holes" H 2950 6450 60  0000 C CNN
F 2 "potHoles:Pot_Holes" H 2900 6400 60  0001 C CNN
F 3 "" H 2900 6400 60  0001 C CNN
	1    2900 6400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 6550 2550 6550
Wire Wire Line
	3350 6550 3500 6550
Wire Wire Line
	3500 6550 3500 6600
Wire Wire Line
	2950 7000 2950 7100
$Comp
L ButtonSwitch B1
U 1 1 59E9A688
P 4950 5950
F 0 "B1" H 4950 5650 60  0000 C CNN
F 1 "ButtonSwitch" H 4950 5950 60  0000 C CNN
F 2 "buttonSwitch:ButtonSwitch" H 4950 5950 60  0001 C CNN
F 3 "" H 4950 5950 60  0001 C CNN
	1    4950 5950
	1    0    0    -1  
$EndComp
$Comp
L ButtonSwitch B2
U 1 1 59E9A954
P 5000 6350
F 0 "B2" H 5000 6050 60  0000 C CNN
F 1 "ButtonSwitch" H 5000 6350 60  0000 C CNN
F 2 "buttonSwitch:ButtonSwitch" H 5000 6350 60  0001 C CNN
F 3 "" H 5000 6350 60  0001 C CNN
	1    5000 6350
	1    0    0    -1  
$EndComp
Connection ~ 7450 2100
$Comp
L GNDREF #PWR01
U 1 1 59E9DC8E
P 3000 1550
F 0 "#PWR01" H 3000 1300 50  0001 C CNN
F 1 "GNDREF" H 3000 1400 50  0000 C CNN
F 2 "" H 3000 1550 50  0000 C CNN
F 3 "" H 3000 1550 50  0000 C CNN
	1    3000 1550
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR02
U 1 1 59E9DE1E
P 1600 2100
F 0 "#PWR02" H 1600 1850 50  0001 C CNN
F 1 "GNDREF" H 1600 1950 50  0000 C CNN
F 2 "" H 1600 2100 50  0000 C CNN
F 3 "" H 1600 2100 50  0000 C CNN
	1    1600 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 2100 7150 2100
$Comp
L GNDREF #PWR03
U 1 1 59E9E778
P 7150 2150
F 0 "#PWR03" H 7150 1900 50  0001 C CNN
F 1 "GNDREF" H 7150 2000 50  0000 C CNN
F 2 "" H 7150 2150 50  0000 C CNN
F 3 "" H 7150 2150 50  0000 C CNN
	1    7150 2150
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR04
U 1 1 59E9E80D
P 8250 1650
F 0 "#PWR04" H 8250 1400 50  0001 C CNN
F 1 "GNDREF" H 8250 1500 50  0000 C CNN
F 2 "" H 8250 1650 50  0000 C CNN
F 3 "" H 8250 1650 50  0000 C CNN
	1    8250 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8250 1600 8250 1650
$Comp
L LED D4
U 1 1 59EA0390
P 5400 1050
F 0 "D4" H 5400 1150 50  0000 C CNN
F 1 "LED" H 5550 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 5400 1050 50  0001 C CNN
F 3 "" H 5400 1050 50  0000 C CNN
	1    5400 1050
	0    -1   -1   0   
$EndComp
$Comp
L BC547 Q2
U 1 1 59EA0396
P 4300 1800
F 0 "Q2" H 4500 1875 50  0000 L CNN
F 1 "BC547" H 4500 1800 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Wide" H 4500 1725 50  0000 L CIN
F 3 "" H 4300 1800 50  0000 L CNN
	1    4300 1800
	1    0    0    -1  
$EndComp
$Comp
L MosfetIRF U4
U 1 1 59EA039C
P 5400 1500
F 0 "U4" H 5550 1304 60  0000 C CNN
F 1 "MosfetIRF" H 5400 1700 60  0000 C CNN
F 2 "library:IRF3205" H 5400 1500 60  0001 C CNN
F 3 "" H 5400 1500 60  0000 C CNN
	1    5400 1500
	1    0    0    1   
$EndComp
$Comp
L R R5
U 1 1 59EA03A2
P 3950 1800
F 0 "R5" V 4030 1800 50  0000 C CNN
F 1 "1k" V 3950 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 3880 1800 50  0001 C CNN
F 3 "" H 3950 1800 50  0000 C CNN
	1    3950 1800
	0    1    1    0   
$EndComp
Wire Wire Line
	3650 1800 3800 1800
Text GLabel 4400 850  1    60   Input ~ 0
12V
$Comp
L R R6
U 1 1 59EA03AB
P 4400 1400
F 0 "R6" V 4480 1400 50  0000 C CNN
F 1 "12k" V 4400 1400 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 4330 1400 50  0001 C CNN
F 3 "" H 4400 1400 50  0000 C CNN
	1    4400 1400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4400 1550 4400 1600
Wire Wire Line
	4400 850  4400 1250
Wire Wire Line
	4400 2000 4400 2150
$Comp
L R R7
U 1 1 59EA03B4
P 4900 1800
F 0 "R7" V 4980 1800 50  0000 C CNN
F 1 "39k" V 4900 1800 50  0000 C CNN
F 2 "Resistors_SMD:R_1206" V 4830 1800 50  0001 C CNN
F 3 "" H 4900 1800 50  0000 C CNN
	1    4900 1800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1950 4900 2100
Wire Wire Line
	4900 2100 4400 2100
Wire Wire Line
	4400 1550 5000 1550
Wire Wire Line
	4900 1550 4900 1650
Connection ~ 4900 1550
Connection ~ 4400 900 
Wire Wire Line
	4400 900  5800 900 
Connection ~ 4400 2100
Wire Wire Line
	5800 1550 5800 1600
$Comp
L GNDREF #PWR05
U 1 1 59EA03C4
P 5800 1600
F 0 "#PWR05" H 5800 1350 50  0001 C CNN
F 1 "GNDREF" H 5800 1450 50  0000 C CNN
F 2 "" H 5800 1600 50  0000 C CNN
F 3 "" H 5800 1600 50  0000 C CNN
	1    5800 1600
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR06
U 1 1 59EA03CA
P 4400 2150
F 0 "#PWR06" H 4400 1900 50  0001 C CNN
F 1 "GNDREF" H 4400 2000 50  0000 C CNN
F 2 "" H 4400 2150 50  0000 C CNN
F 3 "" H 4400 2150 50  0000 C CNN
	1    4400 2150
	1    0    0    -1  
$EndComp
Text GLabel 3650 1800 0    60   Input ~ 0
RGB_R
Wire Wire Line
	4700 5450 5150 5450
Wire Wire Line
	4500 6150 4650 6150
Wire Wire Line
	5250 6150 5350 6150
Wire Wire Line
	2400 3700 2750 3700
$Comp
L GNDREF #PWR07
U 1 1 59EA6FA1
P 4600 3200
F 0 "#PWR07" H 4600 2950 50  0001 C CNN
F 1 "GNDREF" H 4600 3050 50  0000 C CNN
F 2 "" H 4600 3200 50  0000 C CNN
F 3 "" H 4600 3200 50  0000 C CNN
	1    4600 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3200 4950 3200
Wire Wire Line
	4950 3200 4950 3350
$Comp
L GNDREF #PWR08
U 1 1 59EB051E
P 9900 2200
F 0 "#PWR08" H 9900 1950 50  0001 C CNN
F 1 "GNDREF" H 9900 2050 50  0000 C CNN
F 2 "" H 9900 2200 50  0000 C CNN
F 3 "" H 9900 2200 50  0000 C CNN
	1    9900 2200
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR09
U 1 1 59EB058F
P 11050 1650
F 0 "#PWR09" H 11050 1400 50  0001 C CNN
F 1 "GNDREF" H 11050 1500 50  0000 C CNN
F 2 "" H 11050 1650 50  0000 C CNN
F 3 "" H 11050 1650 50  0000 C CNN
	1    11050 1650
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR010
U 1 1 59EB0975
P 2800 2650
F 0 "#PWR010" H 2800 2400 50  0001 C CNN
F 1 "GNDREF" H 2800 2500 50  0000 C CNN
F 2 "" H 2800 2650 50  0000 C CNN
F 3 "" H 2800 2650 50  0000 C CNN
	1    2800 2650
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR011
U 1 1 59EB0A09
P 1100 2950
F 0 "#PWR011" H 1100 2700 50  0001 C CNN
F 1 "GNDREF" H 1100 2800 50  0000 C CNN
F 2 "" H 1100 2950 50  0000 C CNN
F 3 "" H 1100 2950 50  0000 C CNN
	1    1100 2950
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR012
U 1 1 59EB0A9D
P 6150 3400
F 0 "#PWR012" H 6150 3150 50  0001 C CNN
F 1 "GNDREF" H 6150 3250 50  0000 C CNN
F 2 "" H 6150 3400 50  0000 C CNN
F 3 "" H 6150 3400 50  0000 C CNN
	1    6150 3400
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR013
U 1 1 59EB0FFD
P 1900 6600
F 0 "#PWR013" H 1900 6350 50  0001 C CNN
F 1 "GNDREF" H 1900 6450 50  0000 C CNN
F 2 "" H 1900 6600 50  0000 C CNN
F 3 "" H 1900 6600 50  0000 C CNN
	1    1900 6600
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR014
U 1 1 59EB106E
P 3500 6600
F 0 "#PWR014" H 3500 6350 50  0001 C CNN
F 1 "GNDREF" H 3500 6450 50  0000 C CNN
F 2 "" H 3500 6600 50  0000 C CNN
F 3 "" H 3500 6600 50  0000 C CNN
	1    3500 6600
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR015
U 1 1 59EB1867
P 4300 5100
F 0 "#PWR015" H 4300 4850 50  0001 C CNN
F 1 "GNDREF" H 4300 4950 50  0000 C CNN
F 2 "" H 4300 5100 50  0000 C CNN
F 3 "" H 4300 5100 50  0000 C CNN
	1    4300 5100
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR016
U 1 1 59EB191C
P 3150 5300
F 0 "#PWR016" H 3150 5050 50  0001 C CNN
F 1 "GNDREF" H 3150 5150 50  0000 C CNN
F 2 "" H 3150 5300 50  0000 C CNN
F 3 "" H 3150 5300 50  0000 C CNN
	1    3150 5300
	1    0    0    -1  
$EndComp
$Comp
L GNDREF #PWR017
U 1 1 59EB19D1
P 1400 5450
F 0 "#PWR017" H 1400 5200 50  0001 C CNN
F 1 "GNDREF" H 1400 5300 50  0000 C CNN
F 2 "" H 1400 5450 50  0000 C CNN
F 3 "" H 1400 5450 50  0000 C CNN
	1    1400 5450
	1    0    0    -1  
$EndComp
Text GLabel 6450 1850 0    60   Input ~ 0
RGB_G
$Comp
L LED D2
U 1 1 59EF3CD5
P 2950 1050
F 0 "D2" H 2950 1150 50  0000 C CNN
F 1 "LED" H 2950 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 2950 1050 50  0001 C CNN
F 3 "" H 2950 1050 50  0000 C CNN
	1    2950 1050
	0    -1   -1   0   
$EndComp
$Comp
L LED D5
U 1 1 59EF3E36
P 5600 1050
F 0 "D5" H 5600 1150 50  0000 C CNN
F 1 "LED" H 5750 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 5600 1050 50  0001 C CNN
F 3 "" H 5600 1050 50  0000 C CNN
	1    5600 1050
	0    -1   -1   0   
$EndComp
$Comp
L LED D6
U 1 1 59EF3EBD
P 5800 1050
F 0 "D6" H 5800 1150 50  0000 C CNN
F 1 "LED" H 5800 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 5800 1050 50  0001 C CNN
F 3 "" H 5800 1050 50  0000 C CNN
	1    5800 1050
	0    -1   -1   0   
$EndComp
$Comp
L LED D8
U 1 1 59EF4536
P 8050 1100
F 0 "D8" H 8050 1200 50  0000 C CNN
F 1 "LED" H 8050 1000 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 8050 1100 50  0001 C CNN
F 3 "" H 8050 1100 50  0000 C CNN
	1    8050 1100
	0    -1   -1   0   
$EndComp
$Comp
L LED D9
U 1 1 59EF45BC
P 8250 1100
F 0 "D9" H 8250 1200 50  0000 C CNN
F 1 "LED" H 8250 1000 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 8250 1100 50  0001 C CNN
F 3 "" H 8250 1100 50  0000 C CNN
	1    8250 1100
	0    -1   -1   0   
$EndComp
$Comp
L LED D11
U 1 1 59EF4EF4
P 10800 1050
F 0 "D11" H 10800 1150 50  0000 C CNN
F 1 "LED" H 10800 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 10800 1050 50  0001 C CNN
F 3 "" H 10800 1050 50  0000 C CNN
	1    10800 1050
	0    -1   -1   0   
$EndComp
$Comp
L LED D12
U 1 1 59EF4F84
P 11000 1050
F 0 "D12" H 11000 1150 50  0000 C CNN
F 1 "LED" H 11000 950 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 11000 1050 50  0001 C CNN
F 3 "" H 11000 1050 50  0000 C CNN
	1    11000 1050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	8050 900  8050 950 
Connection ~ 7850 900 
Wire Wire Line
	8250 900  8250 950 
Connection ~ 8050 900 
Wire Wire Line
	8250 1250 8250 1300
Wire Wire Line
	8250 1300 7850 1300
Wire Wire Line
	8050 1250 8050 1300
Connection ~ 8050 1300
Connection ~ 10600 900 
Wire Wire Line
	10600 1250 11000 1250
Wire Wire Line
	11000 1250 11000 1200
Connection ~ 10600 1250
Wire Wire Line
	10800 1200 10800 1250
Connection ~ 10800 1250
Wire Wire Line
	9900 900  11000 900 
Connection ~ 10800 900 
Connection ~ 5400 900 
Connection ~ 5600 900 
Connection ~ 5600 1200
Wire Wire Line
	5400 1200 5800 1200
Wire Wire Line
	5400 1200 5400 1250
Wire Wire Line
	2600 1200 2950 1200
Connection ~ 2600 850 
Wire Wire Line
	4500 3500 4950 3500
Wire Wire Line
	1600 850  2950 850 
Wire Wire Line
	2950 850  2950 900 
$Comp
L LED D3
U 1 1 59F00E5B
P 2950 5300
F 0 "D3" H 2950 5400 50  0000 C CNN
F 1 "LED" H 2950 5200 50  0000 C CNN
F 2 "LEDs:LED-8MM" H 2950 5300 50  0001 C CNN
F 3 "" H 2950 5300 50  0000 C CNN
	1    2950 5300
	-1   0    0    1   
$EndComp
$Comp
L Drill_Hole Z1
U 1 1 59F0A015
P 6900 4900
F 0 "Z1" H 6900 4550 60  0000 C CNN
F 1 "Drill_Hole" H 6950 4950 60  0000 C CNN
F 2 "DrillHole:Drill_Hole" H 6900 4900 60  0001 C CNN
F 3 "" H 6900 4900 60  0001 C CNN
	1    6900 4900
	1    0    0    -1  
$EndComp
$Comp
L Drill_Hole Z2
U 1 1 59F0A164
P 7400 4900
F 0 "Z2" H 7400 4550 60  0000 C CNN
F 1 "Drill_Hole" H 7450 4950 60  0000 C CNN
F 2 "DrillHole:Drill_Hole" H 7400 4900 60  0001 C CNN
F 3 "" H 7400 4900 60  0001 C CNN
	1    7400 4900
	1    0    0    -1  
$EndComp
$EndSCHEMATC