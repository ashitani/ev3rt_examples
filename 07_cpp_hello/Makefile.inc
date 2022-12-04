SRCLANG := c++
ifdef CONFIG_EV3RT_APPLICATION
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile
endif
