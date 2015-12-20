bin_PROGRAMS = test_opengl_math

AM_CPPFLAGS = -I../../includes -I../../ -I../
ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4
AM_CXXFLAGS = -std=gnu++11

test_opengl_math_SOURCES = \
	../main.cpp \
	../test_axis_aligned_2d.cpp \
	../test_combinatorics.cpp \
	../test_curves.cpp \
	../test_math.cpp \
	../test_numbers.cpp \
	../test_operations.cpp \
	../test_planes.cpp \
	../test_type_color.cpp \
	../test_type_matrix.cpp \
	../test_type_point.cpp \
	../test_type_texcoord.cpp \
	../test_type_vector.cpp

test_opengl_math_LDFLAGS = -no-install \
	-L$(abs_top_builddir)/../../build/.libs
