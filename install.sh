#! /bin/bash

	echo ""
	echo "Installation de QGLLearning pour Ubuntu ..."
	echo ""
	echo "Installation de cmake si nécessaire ..."
	echo ""
	apt-get install cmake
	echo ""
	echo "Installation de qt si nécessaire ..."
	echo ""
	apt-get install qt4-dev-tools
	echo ""
	echo "Installation de QGLLearning ..."
	echo ""
	mkdir build
	cd build
	cmake ../src/ -G "Unix Makefiles"
	make
	echo ""
	echo "Fin de l'installation , tapez cd build et ./QGLLearning pour lancer l'application."
	echo ""
		
exit
