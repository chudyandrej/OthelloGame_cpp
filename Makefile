####
# Makefile for HRA2016 project
# Author: Andrej Chudy
# Author: Martin Kopec
# Date: 06.05.2016
####

CLI = hra2016-cli
GUI = hra2016

PACKNAME = xchudy03-xkopec42
ALLDIRS	 = ./src/* ./src/*/* ./src/lib/*/* ./doc/ ./examples/
ALLFILES = Makefile README.txt

#path to qmake on merlin
#QMAKE = /usr/local/share/Qt-5.5.1/5.5/gcc_64/bin/qmake 
#
#path to older qmake on merlin
QMAKE = /usr/local/share/Qt-5.2.1/5.2.1/gcc_64/bin/qmake 

#QMAKE = qmake

all: cli gui 


cli:
	@echo "Making CLI " $(CLI);	
	$(QMAKE) -makefile src/qmake-cli.pro -o cli_makefile
	make -f cli_makefile
	rm *.o cli_makefile


gui:
	@echo "Making GUI " $(GUI);	
	$(QMAKE) -makefile src/qmake-gui.pro -o gui_makefile
	make -f gui_makefile
	rm *.o *.h *.cpp gui_makefile


run: 
	@echo "Running CLI version:" $(CLI) "and GUI version:" $(GUI)
	./$(CLI)
	./$(GUI)


doxygen:
	doxygen ./src/dox_conf_file


pack:
	zip $(PACKNAME) $(ALLFILES) $(ALLDIRS)


clean:
	rm -r ./doc
	mkdir doc
	rm hra2016
	rm hra2016-cli
