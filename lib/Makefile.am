lib_LTLIBRARIES = libopengl_math.la
pkginclude_HEADERS = \
	$(top_srcdir)/declspec.h \
	$(top_srcdir)/include/opengl_math/bounds/axis_aligned_2d.h \
	$(top_srcdir)/include/opengl_math/bounds/axis_aligned_2d.inl \
	$(top_srcdir)/include/opengl_math/combinatorics/algorithms.h \
	$(top_srcdir)/include/opengl_math/core/enumerations.h \
	$(top_srcdir)/include/opengl_math/core/memory_leaks.h \
	$(top_srcdir)/include/opengl_math/core/platform.h \
	$(top_srcdir)/include/opengl_math/curves/cubic_curve.h \
	$(top_srcdir)/include/opengl_math/curves/cubic_curve.inl \
	$(top_srcdir)/include/opengl_math/curves/curve_sample_3d.h \
	$(top_srcdir)/include/opengl_math/curves/curve_sample_3d.inl \
	$(top_srcdir)/include/opengl_math/math/algebra.h \
	$(top_srcdir)/include/opengl_math/math/clamp.h \
	$(top_srcdir)/include/opengl_math/math/matrix.h \
	$(top_srcdir)/include/opengl_math/math/numbers.h \
	$(top_srcdir)/include/opengl_math/math/sqrt.h \
	$(top_srcdir)/include/opengl_math/math/trig.h \
	$(top_srcdir)/include/opengl_math/math/vector.h \
	$(top_srcdir)/include/opengl_math/matrices/type_matrix_2X2.h \
	$(top_srcdir)/include/opengl_math/matrices/type_matrix_2X2.inl \
	$(top_srcdir)/include/opengl_math/matrices/type_matrix_3X3.h \
	$(top_srcdir)/include/opengl_math/matrices/type_matrix_3X3.inl \
	$(top_srcdir)/include/opengl_math/matrices/type_matrix_4X4.h \
	$(top_srcdir)/include/opengl_math/matrices/type_matrix_4X4.inl \
	$(top_srcdir)/include/opengl_math/planes/plane_3d.h \
	$(top_srcdir)/include/opengl_math/planes/plane_3d.inl \
	$(top_srcdir)/include/opengl_math/primitives/colors/type_color_rgb.h \
	$(top_srcdir)/include/opengl_math/primitives/colors/type_color_rgb.inl \
	$(top_srcdir)/include/opengl_math/primitives/colors/type_color_rgba.h \
	$(top_srcdir)/include/opengl_math/primitives/colors/type_color_rgba.inl \
	$(top_srcdir)/include/opengl_math/primitives/conversions.h \
	$(top_srcdir)/include/opengl_math/primitives/points/type_point_2d.h \
	$(top_srcdir)/include/opengl_math/primitives/points/type_point_2d.inl \
	$(top_srcdir)/include/opengl_math/primitives/points/type_point_3d.h \
	$(top_srcdir)/include/opengl_math/primitives/points/type_point_3d.inl \
	$(top_srcdir)/include/opengl_math/primitives/texcoords/type_texcoord_2d.h \
	$(top_srcdir)/include/opengl_math/primitives/texcoords/type_texcoord_2d.inl \
	$(top_srcdir)/include/opengl_math/primitives/texcoords/type_texcoord_3d.h \
	$(top_srcdir)/include/opengl_math/primitives/texcoords/type_texcoord_3d.inl \
	$(top_srcdir)/include/opengl_math/primitives/texcoords/type_texcoord_4d.h \
	$(top_srcdir)/include/opengl_math/primitives/texcoords/type_texcoord_4d.inl \
	$(top_srcdir)/include/opengl_math/primitives/vectors/type_vector_2d.h \
	$(top_srcdir)/include/opengl_math/primitives/vectors/type_vector_2d.inl \
	$(top_srcdir)/include/opengl_math/primitives/vectors/type_vector_3d.h \
	$(top_srcdir)/include/opengl_math/primitives/vectors/type_vector_3d.inl \
	$(top_srcdir)/include/opengl_math/primitives/vectors/type_vector_4d.h \
	$(top_srcdir)/include/opengl_math/primitives/vectors/type_vector_4d.inl


if LINUX
AM_CXXFLAGS = $(INTI_CFLAGS) -Werror -Wall -pedantic \
	-I/usr/local/include/ -I$(top_srcdir)/include/
else
AM_CXXFLAGS = $(INTI_CFLAGS) -Werror -Wall -pedantic \
	-I/usr/local/include/ -I$(top_srcdir)/include/
endif

ACLOCAL_AMFLAGS = -I m4

libopengl_math_la_SOURCES = \
	dummy.cpp

if LINUX
libopengl_math_la_LDFLAGS = -pthread
libopengl_math_la_LIBADD = $(INIT_LIBS) -lm
else
libopengl_math_la_LDFLAGS =
libopengl_math_la_LIBADD = $(INIT_LIBS)
endif

