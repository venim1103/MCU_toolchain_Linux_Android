#!/bin/bash
st-flash erase
st-flash write /home/venim1103/build/stm32f3-discovery-oma_template/main.bin 0x8000000

