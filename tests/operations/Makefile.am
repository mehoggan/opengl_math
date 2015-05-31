bin_PROGRAMS = unit_test_core_math_operations

AM_CPPFLAGS = "-I$(top_srcdir)/../../../../../"
AM_CPPFLAGS += "-I$(top_srcdir)/../../../../cxxtest-4.2.1/"
ACLOCAL_AMFLAGS = -I m4

CXXTEST = ../../../../cxxtest-4.2.1/bin/cxxtestgen.py

CLEANFILES = runner.cpp runner.o

runner.cpp :
	$(CXXTEST) --error-printer -o runner.cpp $(top_srcdir)/operations.h

install-exec-local :
	$(prefix)/bin/unit_test_core_math_operations && cat results.txt && \
	valgrind --xml=yes --xml-file=valgrind.xml --leak-check=full \
		--show-reachable=yes --error-exitcode=1 \
		$(prefix)/bin/unit_test_core_math_operations

# List your sources
unit_test_core_math_operations_SOURCES = \
	runner.cpp
