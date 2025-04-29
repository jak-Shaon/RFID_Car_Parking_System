# RFID_Car_Parking_System

This project involves designing an RFID-based car parking system using Arduino UNO, an RFID module, IR sensors, a 20x4 LCD with I2C, an MG90S servo motor, and other essential components. The system automates the entry and exit process for vehicles using RFID authentication.

## How the System Works

* When a vehicle reaches the entrance, **IR Sensor 1** is triggered.
* The **LCD** prompts the driver to scan an **RFID card**.
* If the scanned card is **registered**, the **servo motor opens the gate**, allowing entry.
* If the card is **not registered**, the LCD will display "Access Denied" and the gate remains closed.
* After the vehicle passes through **IR Sensor 2**, the gate automatically **closes after 2 seconds**.
* The system manages **five parking slots**, which can be expanded via software modifications.
* At exit, the servo opens the gate when a vehicle triggers **IR Sensor 2**.
* After the vehicle passes through **IR Sensor 1**, the gate **closes after 2 seconds**.

**Project Overview:** https://drive.google.com/drive/folders/1w6CLjXHKrXReltuMucOTAX9F4Jlpp8rx

![rfid](https://github.com/user-attachments/assets/6e8e4d3b-6cde-41da-a229-8c626466a839)
