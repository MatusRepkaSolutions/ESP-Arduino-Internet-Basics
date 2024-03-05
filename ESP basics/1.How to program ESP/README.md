# Tutorial to get ESP running

If you use Arduino IDE like most people, you will fastly find out, you cant just upload your ArduinoIDE code to ESP.
To make this work you first need to follow these steps:

## Steps to get ESP running on ArduinoIDE
1. Open your ArduinoIDE > File > Preferences > Settings > 
And in the "Additional boards manager URLs:" paste this link: https://dl.espressif.com/dl/package_esp32_index.json

| Step 1                                                 | Step 2                                        |
| ----------------------------------------------------- | --------------------------------------------- |
| <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/a2fafa5e-cb6d-4139-a881-c5c384dadf7e" alt="Step 1"> | <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/dfbcf07b-1b26-41b1-bb5a-4f45e626f092" alt="Step 2" style="width:100%;"> |

2. Now go to: Tools > Board: > Boards Manager... > in the search field type "ESP" > install esp32 by Espressif Systems

| Step 1                                                 | Step 2                                        |
| ----------------------------------------------------- | --------------------------------------------- |
| <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/dccfeb13-57e9-4c50-8f65-44046dac3127" alt="Step 1"> | <img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/f070b30e-a26a-460a-876c-ac8511bb4d40" alt="Step 2" style="width:100%;"> |

## You are ready

After you finished all the steps above, you are ready to program your ESP, all you need to remember are these two crucial steps:
- You have to press and hold the "boot" button during whole uploading of your code
- If the code is sucefully uploaded, you have to press the reset button, to inicialize the new code
  - Both buttons are located right next to the microUSB port
 <p align="center">
<img src="https://github.com/MatusRepkaSolutions/ESP-Arduino-Internet-Basics/assets/162296215/9cd565ef-4adf-4193-8acb-b840c0d1e5bb" alt="boot and reset button">
<p align="center">Boot and Reset button on ESP32.</p></p>
