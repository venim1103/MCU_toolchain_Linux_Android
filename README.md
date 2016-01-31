#Public repository for MCU development in Ubuntu Linux (on Android)

This repository is a simple (=crude) implementation of ready made tools by other people. 
The idea was to make some simple scripts to install and use different MCU building and flashing tools 
inside a Linux Ubuntu environment (mainly for running the compilation environment inside an Android device using the Linux Deploy app for OS installation.)


###Tools made by other people included in this repository:

mblythe86's STM32F3-Discovery Application Template toolchain:
	https://github.com/mblythe86/stm32f3-discovery-basic-template.git

texane's STLINK: stm32 discovery line linux programmer:
	https://github.com/texane/stlink.git
	
(Anatoly Sokolov, Eric Weddington (admin), Joerg Wunsch (admin), 
Paulo Marques and SprinterSB (admin))'s WinAVR:
	http://sourceforge.net/projects/winavr
	
##Setting up

###Android

1.
	Install Android Terminal Emulator:
		PlayStore

2.
	Install meefik's Busybox:
		PlayStore / https://github.com/meefik/busybox

3.
	Install meefik's Linux Deploy:
		Playstore / https://github.com/meefik/linuxdeploy

4.
	Setup Ubuntu (>= 15.04, "Vivid") installation

5. 
	Set up a mount folder called "mount" and add it to usermounts.
		- Add two folders called "avr" and "stm32" inside the mount folder.

6. 
	Run the Linux. (proceed into next part)


###Inside Linux (do these commands):

1. 
	apt-get update 

	apt-get upgrade 

	apt-get -y install git


2. 
	git clone https://github.com/venim1103/public 

	cd public


3. 
	./make_avr 

	./make_stm32 

	./make_stm32_install 


That's it!


##Usage instructions

All uploaded files you edit, build and flash into your machine should be put
into the correct avr or stm32 folder and be named "main.c".


Device:	Command



- Edit the main.c file (using nano):

avr: 
	edit_avr


stm32: 
	edit_stm32



- Copy a "main.c" file from the mounted folder (/mount/avr or /mount/stm32) 
With this command you can edit the file inside your Android environment and then use copy
commands to upload it to your Linux environment for building and flashing.

avr: 
	cp_avr


stm32:
	cp_stm32



- Build the main.c file for the appropriate device (initially set up for stm32f3discovery
and atxmega128b1 devices. You can edit the corresponding Makefiles for other devices)


avr:
	build_avr



stm32:
	build_stm32



- Flash the .hex files into the devices (you can edit the flashing commands to be used
with different devices. Initially set up for stm32f3discovery and atxmega128b1 boards)


avr:
	flash_avr


stm32:
	flash_stm32




That concludes the basic function introduction...

The next step is to explain how to use the debugger commands for the avr and stm32 boards:
gdb_stm32 (and a not yet implemented gdb_avr) commands...


...























