CLI = hra2016-cli
GUI = hra2016

#QMAKE = /usr/local/share/Qt-5.2.1/5.2.1/gcc_64/bin/qmake 
QMAKE = qmake


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
