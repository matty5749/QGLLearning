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
	echo "Installation de qt si nécessaire ..."
	echo ""

	apt-get install qt4-dev-tools

	echo ""
	echo "Installation de KDevelop si nécessaire ..."
	echo ""

	apt-get install kdevelop

	echo ""
	echo "Creation du repertoire build ..."
	echo ""
	
#exit pour reprendre des droits users standard...
	mkdir build
	
	echo ""
	echo "Installation de QGLLearning ..."
	echo ""
	
	cd build
	cmake ../src/ -G "KDevelop3"
	make
	
	echo ""
	echo "Fin de l'installation , tapez cd build et ./QGLLearning pour lancer l'application.Pensez à changer le proprietaire du dossier build : sudo -R chown nomLogin build/ "
	echo ""
		
exit
