#! /bin/bash

	echo ""
	echo "Nettoyage du projet ..."
	echo ""
	rm -R build
	rm QGLLearning.kdev4
	rm -R .kdev4
	rm src/*.*~
	rm -R doxygen/html
	echo ""
	echo "Fin du nettoyage"
	echo ""
exit
