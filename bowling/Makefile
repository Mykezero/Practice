CPPUTEST_HOME = ../tools/cpputest-3.8

#Set this to @ to keep the makefile quiet
SILENCE = @

OTHER_MAKEFILE_TO_INCLUDE = Makefile_Targets.mk

#---- Outputs ----#
COMPONENT_NAME = test
TARGET_LIB = \
	lib/lib$(COMPONENT_NAME).a
	
TEST_TARGET = \
	$(COMPONENT_NAME)_tests

#--- Inputs ----#
PROJECT_HOME_DIR = .
CPP_PLATFORM = gcc

SRC_DIRS = \
	src

TEST_SRC_DIRS = \
	tests \
	mocks
	
INCLUDE_DIRS =\
  $(CPPUTEST_HOME)/include/ \
  $(TERMBOX_HOME)/include/ \
  include \
  mocks
  
CPPUTEST_USE_EXTENSIONS = Y
CPPUTEST_USE_GCOV = Y
include ../CppUTestCompileFlags.mk
include $(CPPUTEST_HOME)/build/MakefileWorker.mk
