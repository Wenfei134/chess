ifeq ($(OS),Windows_NT)
	include Makefile_Windows
else
	include Makefile_Mac
endif