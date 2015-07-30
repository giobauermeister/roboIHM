##RoboIHM
#This is a Qt demo application for controlling a robotic arm built with servos

##Overview##

This article demonstrates the capability of QT framework on Toradex computer modules, and also, the use of the cortex M4 core on Toradex Colibri VF61 module. Making use of the Multicore Comunication Library(MCC), the Qt application sends message to the M4 core, that in turn, controls a robotic arm built with servos. The repository also includes a eCos Firmware(a binary file) which will be loaded by the Qt Application.    

##Steps to run the demo##

Please follow this article to setup Qt development environment.

$http://developer.toradex.com/how-to/how-to-set-up-qt-creator-to-cross-compile-for-embedded-linux

Download source code from this git repository.

##OpenEmbedded

That example probably will be included on meta-toradex-extra on:

 $https://github.com/toradex

To add that packege you have to add on local.conf

$IMAGE_INSTALL_append = " qt-robo-demo "

By default that recipe configure the screen size to 800x480.

You have also the option to use 1024x600, to do it change the file:

$vi meta-toradex-extra/recipes-qt/qt-automotive-cluster-demo/qt-automotive-cluster-demo_0.1.bb

$--EXTRA_QMAKEVARS_PRE += "CONFIG+=no-webcam"  
$++EXTRA_QMAKEVARS_PRE += "CONFIG+=no-webcam DEFINES+=RESOLUTION_1024x600"

In order to make loading of the eCos firmware possible the Linux memory
resources need to be restricted using U-Boot arguments:

    Colibri VFxx # set memargs mem=240M
    
Also make sure the device tree is still loaded in a reachable memory area:

    Colibri VFxx # set fdt_high 0x88000000
