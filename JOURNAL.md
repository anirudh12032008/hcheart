# Connected Hearts

## Journal Title - Connected hearts
Author - Anirudh Sahu
Heart shaped pcb with esp32 as the main heart, 15 RGB led, a buzzer, a display, buttons, 1or 2 3.7V cell . Basically I would need atleast 2 PCBs. The esp32 will be connected to cloud with the help of a external serer hosted on cloud and both of the esp will pull code from it frequently. It would act as a messaging device when one can enter there msg and it would be displayed on both of the PCB, which makes it cool.

Created at - 20 June 2025
Total Time - 26hr

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


## Day 6
So, today I received my PCB and when I saw the PCB, the obvious flaw that I came to notice is that I was having the wrong MCU. I was having the ESP32 with 30 pins but in the PCB it was of 38 pins and I was really screwed up because I couldn't really return it as I just opened 3 packets of ESP32. So, yeah, I was in a really doubtful situation but I had only one choice. I first searched the internet to find any relevant resources but I couldn't find any. So, my next attempt was to manually fix this design flaw.
So, now I begin fixing what I broke again. So, it was really a major design flaw that I used the 38 pins ESP32 while I bought the 30 pins ESP32. But, it's fine, not fine actually. But, I removed some of the pins from the ESP32 that I was having. Like, those were conflicting with maybe GND or VC. So, I just completely removed them up from the MCU itself. And, I got some red enamel copper wire. So, I used that to create the tracers and jumper wires. And yeah, after troubleshooting a lot of things, most of the things were going right. I had a few issues related to the VCP itself, but after some troubleshooting, it was quite good. So, the ESP did boot up.
I found another major design flaw that the 5V was being used for almost all of the components instead of the 3.3V, which could fry up some of the things. Most of them were rated for 3.3V itself. So I cut the threads for the 5V and I attached the jumper wire to connect the 3V with and after troubleshooting it was good.
The display module was fucked up while soldering it, because I needed to desolder it, as for the 5V problem I thought that it was not necessary. Maybe there was something wrong with the display only, so I began removing it. I thought that it would be as easy as it was inserting it up. But, after doing so, I realized it was completely messed, and I had no options.
So, when I tried removing it, I kind of broke some of the shoulder pads, and it was all really messy, but still I got a bit lucky, because I used another display, and the joints were still not great, but after keeping it at a tilted angle, it worked, and if it works, we shouldn't disturb it and let it just work. So, yeah, currently it's working, the display is working, and I inserted all of the RGB LEDs, and twisted them up, and soldered it, and also I added the buttons there.
![photo_6102760546496530534_w](https://github.com/user-attachments/assets/1c7ce306-ad3b-4cb2-911a-d5d5046fbd24)
![photo_6102760546496530535_w](https://github.com/user-attachments/assets/3b6d32f7-01f2-4f78-bc90-f72f985006da)
![photo_6102760546496530530_w](https://github.com/user-attachments/assets/dbf6e0ef-94df-48cb-910b-75ef8b589438)
![photo_6102760546496530533_w](https://github.com/user-attachments/assets/7002a03d-617d-46b1-8817-261a682706b3)
![photo_6102760546496530532_w](https://github.com/user-attachments/assets/711eef13-e6dc-4a2b-9fde-2f102e594051)
time spent - 10hr

## Day 7 
Something big was really coming for me. As the RGB LED had really small spacing between their pads. And I wasn't using a fine tip for it. I tried using it but it wasn't working pretty well. So I just used normal tip for the soldering. And I messed up because they were really so close that if I apply solder to one, another one gets automatically connected. I used some desoldering flux but it wasn't really worth it and wasn't really working. Somehow I did manage it and with my multimeter coming to the rescue, I somehow managed it. And it was really a nice thing because when I was using the multimeter, I was seeing that the GND and VCC are getting connected. So it was really good.
Okay, so I read the battery holder and the TP4056 module. And when I started up, it was booting up, and the buzzers were working, the display was working. Just the LEDs were having really, really low brightness. And when I started up, I knew that I needed to use a transistor instead of directly using GPIO pins to give them the current. But as the PCB is already done, I couldn't really modify it now, and I don't even have some 2N double NNN transistors. So, I don't really have a choice right now. And after the TP4056 is attached to it, I noticed that some of the SMD components on it were missing, because while soldering, it just got hot and got removed. So, tomorrow I would work on fixing that up.
I began fixing TP-4056 module that was causing me trouble, but I again messed things up. Instead of putting a SMD component in there, another one got heated and got removed. So I needed to remove the whole module itself. And again, just like the OLED, I fixed the problem here itself. It was all a mess. I took help from my mother to hold things up because I wasn't having the helping hands. So somehow I managed to remove it and put a new one, and it works. It really works now
![photo_6102760546496530529_w](https://github.com/user-attachments/assets/7c881a87-1170-4f3e-99a1-23644caf90e8)
![photo_6102760546496530526_w](https://github.com/user-attachments/assets/220b7106-e63f-4782-b08a-bb113e9a5262)
![photo_6102760546496530525_w](https://github.com/user-attachments/assets/a56ac993-d71d-489e-917a-f052f951a594)
Time - 8hr

## Day 8 
I began working with the coding part to actually code the logic and create a web server and share the data along it. So I began writing the code and as it's Arduino IDE, it was taking way too much time to compile things up. But after wasting a lot of hours, I finally got it working. I have the web interface which would do the work.
Currently with the web interface, I could send the data to display some text on the OLED screen, change the color of the LEDs, and use some of the RGB combinations to generate some custom colors, buzz the buzzer, and also know the status of all the current pressed buttons. So, it pretty much does everything. Other than that, it's just the firmware that may need to be updated, but currently it's fully functional and working, and as I intended, it has the ability to show the text and change colors, and everything works awesome. I added the switch also, because I messed up with the footprint of the switch itself, but it was manageable to put a small side switch there, so yeah, it's done.
no images because its just code
Time - 6hr

## Day 9 Final BUILD
no words only ton of working cutting and glue and yayyyyy
![photo_6102760546496530522_w](https://github.com/user-attachments/assets/e31c785f-457e-4f75-b210-be727d6de781)
![photo_6102760546496530521_w](https://github.com/user-attachments/assets/579edd04-e4be-4823-8ed9-b9967fddaed3)
![photo_6102760546496530490_w](https://github.com/user-attachments/assets/8dc0144c-4a18-4b0c-b638-10b9b014c24f)
