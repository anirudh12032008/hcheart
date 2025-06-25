# Connected Hearts

## Journal Title - Connected hearts
Heart shaped pcb with esp32 as the main heart, 15 RGB led, a buzzer, a display, buttons, 1or 2 3.7V cell . Basically I would need atleast 2 PCBs. The esp32 will be connected to cloud with the help of a external serer hosted on cloud and both of the esp will pull code from it frequently. It would act as a messaging device when one can enter there msg and it would be displayed on both of the PCB, which makes it cool.
Created at - 20 June 2025

## June 20 :- Led Chaser 
Started with making a simple cd4017 and 555 timer led chaser thats in the shape of a heart
worked on it in KiCad, intially searched on web for the details, found multiple projects related to it even started drafting the pcb
![cd](https://github.com/user-attachments/assets/aace643b-2cb4-48fe-96c0-aa6b6306788c)
Time Spent - 3hr

## June 21:- ATTiny85 integration
I realised that this wouldn't be consider a good project as there is no such new things and such projects are already available., so to make it unique I started to work with attiny85 which could allow me to add more variations in colors and also help me create some logics. Also wrote the program for the attiny to work on and tested it on wokwi
![s2](https://github.com/user-attachments/assets/12eef54b-b7ad-4ae9-97b5-5f2272edc7a4)
![s1](https://github.com/user-attachments/assets/151ad38e-4a87-436a-83f1-278225c16f89)
![s3](https://github.com/user-attachments/assets/d36a2879-220d-4956-8b2c-578cf798397c)
Time Spent - 5hr (till 2 am June22)

## June 22:- Used ESP32 and created the PCB
After knowing that this would be a very limited project I switched to ESP32 as my MC to take the project to next level. This time I had to make things perfect so I started with wokring in KiCad but then I realised my graphics card is broken so I had to switch to easy eda I continued in easy eda along with finding the accutual components to not make it everything SMD I want to create everything by myself. Integrated buzzer, disply, 15 rgb, a few btn and a cell with tp4056. Had to redo the circuit twice due to that KiCAD!!! but succesfully created the schematic and got it reviewed by some hackclubbers on slack and took there suggestions. arranged everything in the pcb and the challenging part was to get the accurate dxf file as in easy eda you cant scale it so had to switch to fusion to edit the dxf then imported it fitted everything in and then completed the routing. after sharing on slack I got some suggestions and motivation to push this project further, im too tired now so ill work on this tommorow. ( succesfully completed the weekend ) 
![sch](https://github.com/user-attachments/assets/8bb6bb81-f036-46d9-9304-c3f311a17adf)
![25](https://github.com/user-attachments/assets/69a10142-64d8-4142-841f-e84a59581213)
![24](https://github.com/user-attachments/assets/8537128c-d191-4751-9ba3-cf4eaad58f9a)
![23](https://github.com/user-attachments/assets/5c4b09ea-decf-4ab1-8955-244fe0c27121)
Time Spent - 6 Hr


## June 24:- Redesigned the PCB
Replaced the OLED with a bigger one, used 4 push buttons instead of one. added a few little things like holes and also using some silk art, designed the whole PCB so that It could fit in a custom case. Researched on the components that have to be used. Shrinked the size of the PCB so re fitted everything in it. Tommorow ill start working on a 3d case to make this project mor cool
![243](https://github.com/user-attachments/assets/ac164056-b8dd-4c51-b6ff-d62275bec2cb)
![242](https://github.com/user-attachments/assets/94a7cc08-ec70-4921-8a8a-6f83a15ca59f)
![241](https://github.com/user-attachments/assets/531e148d-b078-4bd2-af99-fcffcdbe0a41)

Time Spent - 4.5 Hr

## June 25: Created the 3D case and firmware
So I locked in today because I wanted to complete the project and submit it for the design contest, the 3D Case designing was a bit challenging as I had to make sure that everything was in place and the buttons were rechable and there were proper holes for buzzer oled charging esp32. Then I started working on the firmware to quickly draft a basic firware to test the hardwares.![v1 v4](https://github.com/user-attachments/assets/086d91b2-cac3-47ac-9e0b-2a6f8ce1170d)
![2](https://github.com/user-attachments/assets/01150ef7-b8d3-400b-93f0-c3e2edf8c441)
![3](https://github.com/user-attachments/assets/4ca8422f-5c8e-4a9c-935e-1169d11b282e)
![5](https://github.com/user-attachments/assets/2fe3555d-dfeb-4996-b5f8-f589979cb588)
![6](https://github.com/user-attachments/assets/8c318ebd-9aea-4dde-b524-f4493dc0100c)

Time Spent - 7Hr
