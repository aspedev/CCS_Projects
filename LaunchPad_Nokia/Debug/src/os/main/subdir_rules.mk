################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
src/os/main/main.obj: ../src/os/main/main.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_5.2.3/include" --include_path="C:/Marqueses/Embedded/Repository/CCS_Projects/LaunchPad_Nokia/src/bsw/mcal/driverlib" --include_path="C:/Marqueses/Embedded/Repository/CCS_Projects/LaunchPad_Nokia/src/bsw/mcal/inc" -g --gcc --define=ccs="ccs" --define=PART_TM4C123GH6PM --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="src/os/main/main.pp" --obj_directory="src/os/main" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


