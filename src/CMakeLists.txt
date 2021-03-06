project(QGLLearning)

cmake_minimum_required(VERSION 2.6)

#Generation de la documentation doxygen
FIND_PACKAGE(Doxygen)
IF (DOXYGEN_FOUND)
add_custom_target (doxygen ${DOXYGEN_EXECUTABLE} ../doxygen/Doxyfile)
ELSE ()
MESSAGE(STATUS " Doxygen introuvable , pas de generation de documentation possible")
ENDIF (DOXYGEN_FOUND)

find_package(Qt4 REQUIRED)
include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

FIND_PACKAGE(GLUT REQUIRED)

IF(UNIX OR MINGW OR MSYS OR CYGWIN)
ADD_DEFINITIONS("-Wall")
ENDIF(UNIX OR MINGW OR MSYS OR CYGWIN)

file(
	GLOB
	sources		#La variable sources contiendra tout les .cpp
	./*.cpp
)

#Utilisation de moc pour les fichiers .h specifie en parametre
QT4_WRAP_CPP(MOC_FILES glwidget.h qglfunctionenabledisable.h color4f.h vertex.h qglblendfunc.h qglblendequation.h switchwidget.h quad.h 
learningchoicewidget.h learningmanager.h figure.h qglclearcolor.h)

add_executable(
	QGLLearning
	${sources}
	${MOC_FILES}
)

#Configuration de l'édition de liens
target_link_libraries(
	QGLLearning
	${GLUT_glut_LIBRARY}
	${OPENGL_glu_LIBRARY}
	${QT_QTCORE_LIBRARY}
	${QT_QTGUI_LIBRARY}
	${QT_QTOPENGL_LIBRARY}
)

