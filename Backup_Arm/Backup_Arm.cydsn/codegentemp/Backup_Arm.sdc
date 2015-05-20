# THIS FILE IS AUTOMATICALLY GENERATED
# Project: Z:\OneDrive\Tech\GitHub\Backup\Backup_Arm\Backup_Arm.cydsn\Backup_Arm.cyprj
# Date: Wed, 20 May 2015 18:17:14 GMT
#set_units -time ns
create_clock -name {Clock_4(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_8}]]
create_clock -name {Clock_1(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_9}]]
create_clock -name {Clock_2(FFB)} -period 1000 -waveform {0 500} [list [get_pins {ClockBlock/ff_div_10}]]
create_clock -name {CyHFCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/hfclk}]]
create_generated_clock -name {Clock_4} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_generated_clock -name {Clock_1} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_generated_clock -name {Clock_2} -source [get_pins {ClockBlock/hfclk}] -edges {1 25 49} [list]
create_clock -name {CyIMO} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/imo}]]
create_clock -name {CySYSCLK} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/sysclk}]]
create_clock -name {CyILO} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/ilo}]]
create_clock -name {CyLFCLK} -period 31250 -waveform {0 15625} [list [get_pins {ClockBlock/lfclk}]]
create_clock -name {CyRouted1} -period 41.666666666666664 -waveform {0 20.8333333333333} [list [get_pins {ClockBlock/dsi_in_0}]]


# Component constraints for Z:\OneDrive\Tech\GitHub\Backup\Backup_Arm\Backup_Arm.cydsn\TopDesign\TopDesign.cysch
# Project: Z:\OneDrive\Tech\GitHub\Backup\Backup_Arm\Backup_Arm.cydsn\Backup_Arm.cyprj
# Date: Wed, 20 May 2015 18:17:10 GMT
