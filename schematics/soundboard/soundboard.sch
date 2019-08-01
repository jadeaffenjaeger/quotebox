EESchema Schematic File Version 4
LIBS:soundboard-cache
EELAYER 29 0
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
$Comp
L stm8:STM8SF103 U2
U 1 1 5CBE08D9
P 6650 3850
F 0 "U2" H 6625 4965 50  0000 C CNN
F 1 "STM8SF103" H 6625 4874 50  0000 C CNN
F 2 "dfplayer:STM8S103" H 7100 3450 50  0001 C CNN
F 3 "" H 7100 3450 50  0001 C CNN
	1    6650 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J1
U 1 1 5CBE3458
P 3350 2100
F 0 "J1" H 3378 2076 50  0000 L CNN
F 1 "Battery" H 3378 1985 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 3350 2100 50  0001 C CNN
F 3 "~" H 3350 2100 50  0001 C CNN
	1    3350 2100
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x02_Female J2
U 1 1 5CBE41BF
P 4400 4750
F 0 "J2" H 4428 4726 50  0000 L CNN
F 1 "Speaker" H 4428 4635 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 4400 4750 50  0001 C CNN
F 3 "~" H 4400 4750 50  0001 C CNN
	1    4400 4750
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0101
U 1 1 5CBE4BF2
P 2950 2000
F 0 "#PWR0101" H 2950 1850 50  0001 C CNN
F 1 "VCC" H 2967 2173 50  0000 C CNN
F 2 "" H 2950 2000 50  0001 C CNN
F 3 "" H 2950 2000 50  0001 C CNN
	1    2950 2000
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 5CBE5070
P 2950 2300
F 0 "#PWR0102" H 2950 2050 50  0001 C CNN
F 1 "GND" H 2955 2127 50  0000 C CNN
F 2 "" H 2950 2300 50  0001 C CNN
F 3 "" H 2950 2300 50  0001 C CNN
	1    2950 2300
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 2000 2950 2100
Wire Wire Line
	2950 2100 3150 2100
Wire Wire Line
	3150 2200 2950 2200
Wire Wire Line
	2950 2200 2950 2300
$Comp
L power:VCC #PWR0103
U 1 1 5CBE7BF2
P 3650 3100
F 0 "#PWR0103" H 3650 2950 50  0001 C CNN
F 1 "VCC" H 3667 3273 50  0000 C CNN
F 2 "" H 3650 3100 50  0001 C CNN
F 3 "" H 3650 3100 50  0001 C CNN
	1    3650 3100
	1    0    0    -1  
$EndComp
$Comp
L power:VCC #PWR0104
U 1 1 5CBE8423
P 7300 3550
F 0 "#PWR0104" H 7300 3400 50  0001 C CNN
F 1 "VCC" H 7317 3723 50  0000 C CNN
F 2 "" H 7300 3550 50  0001 C CNN
F 3 "" H 7300 3550 50  0001 C CNN
	1    7300 3550
	1    0    0    -1  
$EndComp
Wire Wire Line
	7100 3300 7100 3550
Wire Wire Line
	7100 3550 7300 3550
Wire Wire Line
	6150 4450 3950 4450
Wire Wire Line
	3950 4450 3950 3600
Wire Wire Line
	3950 3600 4200 3600
Wire Wire Line
	4200 3700 4050 3700
Wire Wire Line
	4050 3700 4050 4550
Wire Wire Line
	4050 4550 6150 4550
Wire Wire Line
	3650 3400 4200 3400
Wire Wire Line
	3650 3300 3650 3400
Wire Wire Line
	3650 3300 4200 3300
Wire Wire Line
	3650 3200 3650 3100
Wire Wire Line
	3650 3200 4200 3200
$Comp
L Transistor_FET:IRLZ44N Q1
U 1 1 5CBECFE0
P 2850 3850
F 0 "Q1" H 3056 3896 50  0000 L CNN
F 1 "IRLZ44N" H 3056 3805 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-220-3_Vertical" H 3100 3775 50  0001 L CIN
F 3 "http://www.irf.com/product-info/datasheets/data/irlz44n.pdf" H 2850 3850 50  0001 L CNN
	1    2850 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 3400 2950 3400
Wire Wire Line
	2950 3400 2950 3650
Connection ~ 3650 3400
$Comp
L power:GND #PWR0105
U 1 1 5CBF1486
P 2950 4400
F 0 "#PWR0105" H 2950 4150 50  0001 C CNN
F 1 "GND" H 2955 4227 50  0000 C CNN
F 2 "" H 2950 4400 50  0001 C CNN
F 3 "" H 2950 4400 50  0001 C CNN
	1    2950 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 4050 2950 4400
Text Label 5650 4350 2    50   ~ 0
FET
Text Label 2350 3850 2    50   ~ 0
FET
Wire Wire Line
	2350 3850 2650 3850
Wire Wire Line
	4200 4100 3750 4100
Wire Wire Line
	3750 4100 3750 4850
Wire Wire Line
	3750 4850 4200 4850
Wire Wire Line
	4200 4750 3850 4750
Wire Wire Line
	3850 4750 3850 4200
Wire Wire Line
	3850 4200 4200 4200
$Comp
L dfplayer:DFPlayerMini U1
U 1 1 5CBE0421
P 4700 3850
F 0 "U1" H 4625 4765 50  0000 C CNN
F 1 "DFPlayerMini" H 4625 4674 50  0000 C CNN
F 2 "dfplayer:DFPlayer" H 4650 3800 50  0001 C CNN
F 3 "" H 4650 3800 50  0001 C CNN
	1    4700 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 3200 5750 3200
Wire Wire Line
	5750 3200 5750 3000
Wire Wire Line
	5750 3000 6150 3000
Wire Wire Line
	5650 4350 6150 4350
$EndSCHEMATC
