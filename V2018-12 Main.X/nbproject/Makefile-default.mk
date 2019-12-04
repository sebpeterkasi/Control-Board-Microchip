#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../libs/condition.c ../libs/crc8.c ../libs/event.c ../peripherals/pps/pps.c ../peripherals/timer/timer.c ../peripherals/uart/uart.c ../peripherals/adxl345/adxl345.c ../peripherals/spi/spi.c ../peripherals/led/led.c ../peripherals/oc/oc.c ../peripherals/i2c/i2c.c ../peripherals/ltc2942/ltc2942.c "../USB Stack/usb.c" "../USB Stack/usb_descriptors.c" "../USB Stack/usb_device.c" "../USB Stack/usb_function_cdc.c" ../com.c ../com_pc.c ../main.c ../device.c ../dummy.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/760835715/condition.o ${OBJECTDIR}/_ext/760835715/crc8.o ${OBJECTDIR}/_ext/760835715/event.o ${OBJECTDIR}/_ext/229218164/pps.o ${OBJECTDIR}/_ext/1231840482/timer.o ${OBJECTDIR}/_ext/1484306133/uart.o ${OBJECTDIR}/_ext/1796732374/adxl345.o ${OBJECTDIR}/_ext/229215291/spi.o ${OBJECTDIR}/_ext/229222364/led.o ${OBJECTDIR}/_ext/1100984475/oc.o ${OBJECTDIR}/_ext/229226829/i2c.o ${OBJECTDIR}/_ext/888678663/ltc2942.o ${OBJECTDIR}/_ext/1007145187/usb.o ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o ${OBJECTDIR}/_ext/1007145187/usb_device.o ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o ${OBJECTDIR}/_ext/1472/com.o ${OBJECTDIR}/_ext/1472/com_pc.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/device.o ${OBJECTDIR}/_ext/1472/dummy.o
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/760835715/condition.o.d ${OBJECTDIR}/_ext/760835715/crc8.o.d ${OBJECTDIR}/_ext/760835715/event.o.d ${OBJECTDIR}/_ext/229218164/pps.o.d ${OBJECTDIR}/_ext/1231840482/timer.o.d ${OBJECTDIR}/_ext/1484306133/uart.o.d ${OBJECTDIR}/_ext/1796732374/adxl345.o.d ${OBJECTDIR}/_ext/229215291/spi.o.d ${OBJECTDIR}/_ext/229222364/led.o.d ${OBJECTDIR}/_ext/1100984475/oc.o.d ${OBJECTDIR}/_ext/229226829/i2c.o.d ${OBJECTDIR}/_ext/888678663/ltc2942.o.d ${OBJECTDIR}/_ext/1007145187/usb.o.d ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d ${OBJECTDIR}/_ext/1007145187/usb_device.o.d ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d ${OBJECTDIR}/_ext/1472/com.o.d ${OBJECTDIR}/_ext/1472/com_pc.o.d ${OBJECTDIR}/_ext/1472/main.o.d ${OBJECTDIR}/_ext/1472/device.o.d ${OBJECTDIR}/_ext/1472/dummy.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/760835715/condition.o ${OBJECTDIR}/_ext/760835715/crc8.o ${OBJECTDIR}/_ext/760835715/event.o ${OBJECTDIR}/_ext/229218164/pps.o ${OBJECTDIR}/_ext/1231840482/timer.o ${OBJECTDIR}/_ext/1484306133/uart.o ${OBJECTDIR}/_ext/1796732374/adxl345.o ${OBJECTDIR}/_ext/229215291/spi.o ${OBJECTDIR}/_ext/229222364/led.o ${OBJECTDIR}/_ext/1100984475/oc.o ${OBJECTDIR}/_ext/229226829/i2c.o ${OBJECTDIR}/_ext/888678663/ltc2942.o ${OBJECTDIR}/_ext/1007145187/usb.o ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o ${OBJECTDIR}/_ext/1007145187/usb_device.o ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o ${OBJECTDIR}/_ext/1472/com.o ${OBJECTDIR}/_ext/1472/com_pc.o ${OBJECTDIR}/_ext/1472/main.o ${OBJECTDIR}/_ext/1472/device.o ${OBJECTDIR}/_ext/1472/dummy.o

# Source Files
SOURCEFILES=../libs/condition.c ../libs/crc8.c ../libs/event.c ../peripherals/pps/pps.c ../peripherals/timer/timer.c ../peripherals/uart/uart.c ../peripherals/adxl345/adxl345.c ../peripherals/spi/spi.c ../peripherals/led/led.c ../peripherals/oc/oc.c ../peripherals/i2c/i2c.c ../peripherals/ltc2942/ltc2942.c ../USB Stack/usb.c ../USB Stack/usb_descriptors.c ../USB Stack/usb_device.c ../USB Stack/usb_function_cdc.c ../com.c ../com_pc.c ../main.c ../device.c ../dummy.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=24FJ64GB004
MP_LINKER_FILE_OPTION=,--script=p24FJ64GB004.gld
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/760835715/condition.o: ../libs/condition.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760835715" 
	@${RM} ${OBJECTDIR}/_ext/760835715/condition.o.d 
	@${RM} ${OBJECTDIR}/_ext/760835715/condition.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libs/condition.c  -o ${OBJECTDIR}/_ext/760835715/condition.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/760835715/condition.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/760835715/condition.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/760835715/crc8.o: ../libs/crc8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760835715" 
	@${RM} ${OBJECTDIR}/_ext/760835715/crc8.o.d 
	@${RM} ${OBJECTDIR}/_ext/760835715/crc8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libs/crc8.c  -o ${OBJECTDIR}/_ext/760835715/crc8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/760835715/crc8.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/760835715/crc8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/760835715/event.o: ../libs/event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760835715" 
	@${RM} ${OBJECTDIR}/_ext/760835715/event.o.d 
	@${RM} ${OBJECTDIR}/_ext/760835715/event.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libs/event.c  -o ${OBJECTDIR}/_ext/760835715/event.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/760835715/event.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/760835715/event.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229218164/pps.o: ../peripherals/pps/pps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229218164" 
	@${RM} ${OBJECTDIR}/_ext/229218164/pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/229218164/pps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/pps/pps.c  -o ${OBJECTDIR}/_ext/229218164/pps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229218164/pps.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229218164/pps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1231840482/timer.o: ../peripherals/timer/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1231840482" 
	@${RM} ${OBJECTDIR}/_ext/1231840482/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1231840482/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/timer/timer.c  -o ${OBJECTDIR}/_ext/1231840482/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1231840482/timer.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1231840482/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1484306133/uart.o: ../peripherals/uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1484306133" 
	@${RM} ${OBJECTDIR}/_ext/1484306133/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1484306133/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/uart/uart.c  -o ${OBJECTDIR}/_ext/1484306133/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1484306133/uart.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1484306133/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1796732374/adxl345.o: ../peripherals/adxl345/adxl345.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1796732374" 
	@${RM} ${OBJECTDIR}/_ext/1796732374/adxl345.o.d 
	@${RM} ${OBJECTDIR}/_ext/1796732374/adxl345.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/adxl345/adxl345.c  -o ${OBJECTDIR}/_ext/1796732374/adxl345.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1796732374/adxl345.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1796732374/adxl345.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229215291/spi.o: ../peripherals/spi/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229215291" 
	@${RM} ${OBJECTDIR}/_ext/229215291/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/229215291/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/spi/spi.c  -o ${OBJECTDIR}/_ext/229215291/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229215291/spi.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229215291/spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229222364/led.o: ../peripherals/led/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229222364" 
	@${RM} ${OBJECTDIR}/_ext/229222364/led.o.d 
	@${RM} ${OBJECTDIR}/_ext/229222364/led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/led/led.c  -o ${OBJECTDIR}/_ext/229222364/led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229222364/led.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229222364/led.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1100984475/oc.o: ../peripherals/oc/oc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1100984475" 
	@${RM} ${OBJECTDIR}/_ext/1100984475/oc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1100984475/oc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/oc/oc.c  -o ${OBJECTDIR}/_ext/1100984475/oc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1100984475/oc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1100984475/oc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229226829/i2c.o: ../peripherals/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229226829" 
	@${RM} ${OBJECTDIR}/_ext/229226829/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/229226829/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/i2c/i2c.c  -o ${OBJECTDIR}/_ext/229226829/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229226829/i2c.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229226829/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/888678663/ltc2942.o: ../peripherals/ltc2942/ltc2942.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/888678663" 
	@${RM} ${OBJECTDIR}/_ext/888678663/ltc2942.o.d 
	@${RM} ${OBJECTDIR}/_ext/888678663/ltc2942.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/ltc2942/ltc2942.c  -o ${OBJECTDIR}/_ext/888678663/ltc2942.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/888678663/ltc2942.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/888678663/ltc2942.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb.o: ../USB\ Stack/usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb.c"  -o ${OBJECTDIR}/_ext/1007145187/usb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb_descriptors.o: ../USB\ Stack/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb_descriptors.c"  -o ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb_device.o: ../USB\ Stack/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb_device.c"  -o ${OBJECTDIR}/_ext/1007145187/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb_device.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb_device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o: ../USB\ Stack/usb_function_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb_function_cdc.c"  -o ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/com.o: ../com.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/com.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/com.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../com.c  -o ${OBJECTDIR}/_ext/1472/com.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/com.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/com.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/com_pc.o: ../com_pc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/com_pc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/com_pc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../com_pc.c  -o ${OBJECTDIR}/_ext/1472/com_pc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/com_pc.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/com_pc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/device.o: ../device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/device.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../device.c  -o ${OBJECTDIR}/_ext/1472/device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/device.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dummy.o: ../dummy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dummy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dummy.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dummy.c  -o ${OBJECTDIR}/_ext/1472/dummy.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dummy.o.d"      -g -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1    -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dummy.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
else
${OBJECTDIR}/_ext/760835715/condition.o: ../libs/condition.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760835715" 
	@${RM} ${OBJECTDIR}/_ext/760835715/condition.o.d 
	@${RM} ${OBJECTDIR}/_ext/760835715/condition.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libs/condition.c  -o ${OBJECTDIR}/_ext/760835715/condition.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/760835715/condition.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/760835715/condition.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/760835715/crc8.o: ../libs/crc8.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760835715" 
	@${RM} ${OBJECTDIR}/_ext/760835715/crc8.o.d 
	@${RM} ${OBJECTDIR}/_ext/760835715/crc8.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libs/crc8.c  -o ${OBJECTDIR}/_ext/760835715/crc8.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/760835715/crc8.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/760835715/crc8.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/760835715/event.o: ../libs/event.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/760835715" 
	@${RM} ${OBJECTDIR}/_ext/760835715/event.o.d 
	@${RM} ${OBJECTDIR}/_ext/760835715/event.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../libs/event.c  -o ${OBJECTDIR}/_ext/760835715/event.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/760835715/event.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/760835715/event.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229218164/pps.o: ../peripherals/pps/pps.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229218164" 
	@${RM} ${OBJECTDIR}/_ext/229218164/pps.o.d 
	@${RM} ${OBJECTDIR}/_ext/229218164/pps.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/pps/pps.c  -o ${OBJECTDIR}/_ext/229218164/pps.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229218164/pps.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229218164/pps.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1231840482/timer.o: ../peripherals/timer/timer.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1231840482" 
	@${RM} ${OBJECTDIR}/_ext/1231840482/timer.o.d 
	@${RM} ${OBJECTDIR}/_ext/1231840482/timer.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/timer/timer.c  -o ${OBJECTDIR}/_ext/1231840482/timer.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1231840482/timer.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1231840482/timer.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1484306133/uart.o: ../peripherals/uart/uart.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1484306133" 
	@${RM} ${OBJECTDIR}/_ext/1484306133/uart.o.d 
	@${RM} ${OBJECTDIR}/_ext/1484306133/uart.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/uart/uart.c  -o ${OBJECTDIR}/_ext/1484306133/uart.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1484306133/uart.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1484306133/uart.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1796732374/adxl345.o: ../peripherals/adxl345/adxl345.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1796732374" 
	@${RM} ${OBJECTDIR}/_ext/1796732374/adxl345.o.d 
	@${RM} ${OBJECTDIR}/_ext/1796732374/adxl345.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/adxl345/adxl345.c  -o ${OBJECTDIR}/_ext/1796732374/adxl345.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1796732374/adxl345.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1796732374/adxl345.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229215291/spi.o: ../peripherals/spi/spi.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229215291" 
	@${RM} ${OBJECTDIR}/_ext/229215291/spi.o.d 
	@${RM} ${OBJECTDIR}/_ext/229215291/spi.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/spi/spi.c  -o ${OBJECTDIR}/_ext/229215291/spi.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229215291/spi.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229215291/spi.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229222364/led.o: ../peripherals/led/led.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229222364" 
	@${RM} ${OBJECTDIR}/_ext/229222364/led.o.d 
	@${RM} ${OBJECTDIR}/_ext/229222364/led.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/led/led.c  -o ${OBJECTDIR}/_ext/229222364/led.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229222364/led.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229222364/led.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1100984475/oc.o: ../peripherals/oc/oc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1100984475" 
	@${RM} ${OBJECTDIR}/_ext/1100984475/oc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1100984475/oc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/oc/oc.c  -o ${OBJECTDIR}/_ext/1100984475/oc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1100984475/oc.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1100984475/oc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/229226829/i2c.o: ../peripherals/i2c/i2c.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/229226829" 
	@${RM} ${OBJECTDIR}/_ext/229226829/i2c.o.d 
	@${RM} ${OBJECTDIR}/_ext/229226829/i2c.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/i2c/i2c.c  -o ${OBJECTDIR}/_ext/229226829/i2c.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/229226829/i2c.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/229226829/i2c.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/888678663/ltc2942.o: ../peripherals/ltc2942/ltc2942.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/888678663" 
	@${RM} ${OBJECTDIR}/_ext/888678663/ltc2942.o.d 
	@${RM} ${OBJECTDIR}/_ext/888678663/ltc2942.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../peripherals/ltc2942/ltc2942.c  -o ${OBJECTDIR}/_ext/888678663/ltc2942.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/888678663/ltc2942.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/888678663/ltc2942.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb.o: ../USB\ Stack/usb.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb.c"  -o ${OBJECTDIR}/_ext/1007145187/usb.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb_descriptors.o: ../USB\ Stack/usb_descriptors.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb_descriptors.c"  -o ${OBJECTDIR}/_ext/1007145187/usb_descriptors.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb_descriptors.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb_device.o: ../USB\ Stack/usb_device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_device.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb_device.c"  -o ${OBJECTDIR}/_ext/1007145187/usb_device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb_device.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb_device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o: ../USB\ Stack/usb_function_cdc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1007145187" 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  "../USB Stack/usb_function_cdc.c"  -o ${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1007145187/usb_function_cdc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/com.o: ../com.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/com.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/com.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../com.c  -o ${OBJECTDIR}/_ext/1472/com.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/com.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/com.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/com_pc.o: ../com_pc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/com_pc.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/com_pc.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../com_pc.c  -o ${OBJECTDIR}/_ext/1472/com_pc.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/com_pc.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/com_pc.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/main.o: ../main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../main.c  -o ${OBJECTDIR}/_ext/1472/main.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/main.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/main.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/device.o: ../device.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/device.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/device.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../device.c  -o ${OBJECTDIR}/_ext/1472/device.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/device.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/device.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
${OBJECTDIR}/_ext/1472/dummy.o: ../dummy.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1472" 
	@${RM} ${OBJECTDIR}/_ext/1472/dummy.o.d 
	@${RM} ${OBJECTDIR}/_ext/1472/dummy.o 
	${MP_CC} $(MP_EXTRA_CC_PRE)  ../dummy.c  -o ${OBJECTDIR}/_ext/1472/dummy.o  -c -mcpu=$(MP_PROCESSOR_OPTION)  -MMD -MF "${OBJECTDIR}/_ext/1472/dummy.o.d"        -g -omf=elf -legacy-libc  -O0 -msmart-io=1 -Wall -msfr-warn=off  
	@${FIXDEPS} "${OBJECTDIR}/_ext/1472/dummy.o.d" $(SILENT)  -rsi ${MP_CC_DIR}../ 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemblePreproc
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -D__DEBUG -D__MPLAB_DEBUGGER_ICD3=1  -omf=elf -legacy-libc   -mreserve=data@0x800:0x81F -mreserve=data@0x820:0x821 -mreserve=data@0x822:0x823 -mreserve=data@0x824:0x825 -mreserve=data@0x826:0x84F   -Wl,,--defsym=__MPLAB_BUILD=1,--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,--defsym=__MPLAB_DEBUGGER_ICD3=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -o dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}      -mcpu=$(MP_PROCESSOR_OPTION)        -omf=elf -legacy-libc  -Wl,,--defsym=__MPLAB_BUILD=1,$(MP_LINKER_FILE_OPTION),--heap=1024,--stack=16,--check-sections,--data-init,--pack-data,--handles,--isr,--no-gc-sections,--fill-upper=0,--stackguard=16,--no-force-link,--smart-io,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--report-mem$(MP_EXTRA_LD_POST) 
	${MP_CC_DIR}\\xc16-bin2hex dist/${CND_CONF}/${IMAGE_TYPE}/V2015-12_Main.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} -a  -omf=elf  
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
