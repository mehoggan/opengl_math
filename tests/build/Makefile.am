bin_PROGRAMS = test_opengl_math

AM_CPPFLAGS = -I../../includes -I../../ -I../
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4
AM_CXXFLAGS = -std=gnu++11

test_opengl_math_SOURCES = \
	../main.cpp \
	../test_mesh_types.cpp

test_opengl_math_LDFLAGS = -no-install \
	-L$(abs_top_builddir)/../../build/.libs
