# Append name of your tests here.

TESTS = check_axis_aligned_2d \
	check_combinatorics \
	check_curves \
	check_math \
	check_numbers \
	check_operations \
	check_planes \
	check_shapes \
	check_type_color \
	check_type_matrix \
	check_type_point \
	check_type_texcoord \
	check_type_vector

check_PROGRAMS = check_axis_aligned_2d \
	check_combinatorics \
	check_curves \
	check_math \
	check_numbers \
	check_operations \
	check_planes \
	check_shapes \
	check_type_color \
	check_type_matrix \
	check_type_point \
	check_type_texcoord \
	check_type_vector

if LINUX
AM_CXXFLAGS = -Werror -Wall -pedantic \
	-I/usr/local/include/
else
AM_CXXFLAGS = -Werror -Wall -pedantic \
	-I/usr/local/include/
endif

# Copy block and rename.
check_axis_aligned_2d_SOURCES = suite.cpp check_axis_aligned_2d.cpp
check_axis_aligned_2d_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_axis_aligned_2d_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_axis_aligned_2d_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_combinatorics_SOURCES = suite.cpp check_combinatorics.cpp
check_combinatorics_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_combinatorics_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_combinatorics_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_curves_SOURCES = suite.cpp check_curves.cpp
check_curves_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_curves_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_curves_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_math_SOURCES = suite.cpp check_math.cpp
check_math_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_math_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_math_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_numbers_SOURCES = suite.cpp check_numbers.cpp
check_numbers_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_numbers_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_numbers_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_operations_SOURCES = suite.cpp check_operations.cpp
check_operations_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_operations_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_operations_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_planes_SOURCES = suite.cpp check_planes.cpp
check_planes_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_planes_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_planes_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_shapes_SOURCES = suite.cpp check_shapes.cpp
check_shapes_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_shapes_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_shapes_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_type_color_SOURCES = suite.cpp check_type_color.cpp
check_type_color_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_type_color_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_type_color_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_type_matrix_SOURCES = suite.cpp check_type_matrix.cpp
check_type_matrix_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_type_matrix_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_type_matrix_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_type_point_SOURCES = suite.cpp check_type_point.cpp
check_type_point_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_type_point_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_type_point_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_type_texcoord_SOURCES = suite.cpp check_type_texcoord.cpp
check_type_texcoord_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_type_texcoord_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_type_texcoord_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

check_type_vector_SOURCES = suite.cpp check_type_vector.cpp
check_type_vector_CXXFLAGS = -I$(top_builddir)/include/ \
	-I$(top_builddir)/tests/include -std=c++11 -Wall -Werror -pedantic
if LINUX
check_type_vector_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck -lsubunit -lm -lrt
else
check_type_vector_LDADD = $(top_builddir)/lib/libopengl_math.la \
	-lcheck
endif

CLEANFILES = *.o
CLEANDIRS = deps/ \
	.lib/

@VALGRIND_CHECK_RULES@
