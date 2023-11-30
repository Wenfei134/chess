ifeq ($(OS),Windows_NT)
	include Makefile_Windows
else
	detected_OS := $(shell uname)
	ifeq ($(detected_OS), Linux)
		include Makefile_Linux
	else 
		include Makefile_Mac
	endif
endif
