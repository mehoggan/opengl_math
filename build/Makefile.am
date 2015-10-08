lib_LTLIBRARIES = libopengl_math.la

AM_CPPFLAGS = -I../includes -I../
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4
AM_CXXFLAGS = -std=gnu++11

# List your sources
libopengl_math_la_SOURCES = \
	../src/dummy.cpp

# List version info and other linker flags.
libopengl_math_la_LDFLAGS = -version-info 1:0:0 -L/usr/lib64/nvidia/xorg \
	-lX11 -glx -pthread


