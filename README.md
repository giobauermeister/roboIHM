##RoboIHM
#This is a Qt demo application for controlling a robotic arm built with servos

##Overview##

This article demonstrates the capability of QT framework on Toradex computer modules, and also, the use of the cortex M4 core on Toradex Colibri VF61 module. Making use of the Multicore Comunication Library(MCC), the Qt application sends message to the M4 core, that in turn, controls a robotic arm built with servos. The repository also includes a eCos Firmware(a binary file) which will be loaded by the Qt Application.    

##Steps to run the demo##

Please follow this article to setup Qt development environment.

http://developer.toradex.com/how-to/how-to-set-up-qt-creator-to-cross-compile-for-embedded-linux

Download source code from this git repository.

##OpenEmbedded

That example probably will be included on meta-toradex-extra on:

 https://github.com/toradex

To add that packege you have to add on local.conf

 IMAGE_INSTALL_append = " qt-robo-demo "

By default that recipe configure the screen size to 800x480.

You have also the option to use 1024x600, to do it change the file:

    vi meta-toradex-extra/recipes-qt/qt-automotive-cluster-demo/qt-automotive-cluster-demo_0.1.bb

--EXTRA_QMAKEVARS_PRE += "CONFIG+=no-webcam"  
++EXTRA_QMAKEVARS_PRE += "CONFIG+=no-webcam DEFINES+=RESOLUTION_1024x600"

In order to make loading of the eCos firmware possible the Linux memory
resources need to be restricted using U-Boot arguments:

    Colibri VFxx # set memargs mem=240M
    
Also make sure the device tree is still loaded in a reachable memory area:

    Colibri VFxx # set fdt_high 0x88000000

For powering all up, we used two wall adapters, one 5V power supply for the robotic arm and one 12V for the module/carrierboard. The arm has 4 servos, each one connected to a gpio on the Iris carrier board extension header(X16). We also used a small homemade adapter for connecting and powering all the 4 servos together with the 5V power supply. 

| Iris Ext Header(X16)  | Servo Signal Input |
| --------------------- | ------------------ |
| pin 15 (SODIMM 103)   | Arm     Servo      |
| pin 16 (SODIMM 101)   | Base    Servo      |
| pin 17 (SODIMM  97)   | Claw    Servo      |
| pin 19 (SODIMM  79)   | Forearm Servo      |


<a href="https://drive.google.com/uc?export=view&id=0B7uO0jJfbFQIY1B5UDEtTE5PQlVXSEVXanlWZW4xYVhuR2pN"><img src="https://drive.google.com/uc?export=view&id=0B7uO0jJfbFQIY1B5UDEtTE5PQlVXSEVXanlWZW4xYVhuR2pN" style="width: 50px; max-width: 50%; height: 50px" /></a>











   
   
