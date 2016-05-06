CLI = hra2016-cli

#QMAKE = /usr/local/share/Qt-5.2.1/5.2.1/gcc_64/bin/qmake 
QMAKE = qmake


cli:
	@echo "Making some " $(CLI);	
	$(QMAKE) -makefile src/qmake-cli.pro -o cli_makefile
	make -f cli_makefile
	rm *.o cli_makefile
