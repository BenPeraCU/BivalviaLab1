################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
%.obj: ../%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"/home/doxxy/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O2 --include_path="/home/doxxy/ti/ccs1020/ccs/ccs_base/arm/include" --include_path="/home/doxxy/ti/ccs1020/ccs/ccs_base/arm/include/CMSIS" --include_path="/home/doxxy/Dropbox/School/ECEN2440-Applications_of_Embeded_Systems/Labs/Lab2/BivalviaLab1/Bivalvia_Lab2" --include_path="/home/doxxy/ti/ccs1020/ccs/tools/compiler/ti-cgt-arm_20.2.2.LTS/include" --advice:power=all --define=__MSP432P401R__ --define=ccs --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="$(basename $(<F)).d_raw" $(GEN_OPTS__FLAG) "$(shell echo $<)"
	@echo 'Finished building: "$<"'
	@echo ' '


