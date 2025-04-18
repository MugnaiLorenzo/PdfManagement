#
# fontconfig/src/Makefile.am
#
# Copyright © 2003 Keith Packard
#
# Permission to use, copy, modify, distribute, and sell this software and its
# documentation for any purpose is hereby granted without fee, provided that
# the above copyright notice appear in all copies and that both that
# copyright notice and this permission notice appear in supporting
# documentation, and that the name of the author(s) not be used in
# advertising or publicity pertaining to distribution of the software without
# specific, written prior permission.  The authors make no
# representations about the suitability of this software for any purpose.  It
# is provided "as is" without express or implied warranty.
#
# THE AUTHOR(S) DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
# INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
# EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY SPECIAL, INDIRECT OR
# CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
# DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
# TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
# PERFORMANCE OF THIS SOFTWARE.

if OS_WIN32

export_symbols = -export-symbols fontconfig.def

fontconfig_def_dependency = fontconfig.def

# gcc import library install/uninstall

install-libtool-import-lib: 
	$(INSTALL) .libs/libfontconfig.dll.a $(DESTDIR)$(libdir)
	$(INSTALL) fontconfig.def $(DESTDIR)$(libdir)/fontconfig.def

uninstall-libtool-import-lib:
	$(RM) $(DESTDIR)$(libdir)/libfontconfig.dll.a $(DESTDIR)$(libdir)/fontconfig.def

else

install-libtool-import-lib:
uninstall-libtool-import-lib:

fontconfig_def_dependency = 

endif

if MS_LIB_AVAILABLE

# Microsoft import library install/uninstall

noinst_DATA = fontconfig.lib

fontconfig.lib : libfontconfig.la
	lib -name:libfontconfig-@LIBT_CURRENT_MINUS_AGE@.dll -def:fontconfig.def -out:$@

install-ms-import-lib:
	$(INSTALL) fontconfig.lib $(DESTDIR)$(libdir)

uninstall-ms-import-lib:
	$(RM) $(DESTDIR)$(libdir)/fontconfig.lib

else

install-ms-import-lib:
uninstall-ms-import-lib:

endif

INCLUDES = 						\
	-I$(top_srcdir)					\
	-I$(top_srcdir)/src				\
	$(FREETYPE_CFLAGS)				\
	$(ICONV_CFLAGS)					\
	$(LIBXML2_CFLAGS)				\
	$(EXPAT_CFLAGS)					\
	$(WARN_CFLAGS)					\
	-DFC_CACHEDIR='"$(FC_CACHEDIR)"'                \
	-DFONTCONFIG_PATH='"$(BASECONFIGDIR)"'

EXTRA_DIST = makealias

noinst_HEADERS=fcint.h fcftint.h fcdeprecate.h

ALIAS_FILES = fcalias.h fcaliastail.h fcftalias.h fcftaliastail.h

BUILT_SOURCES = $(ALIAS_FILES) \
	../fc-case/fccase.h \
	../fc-glyphname/fcglyphname.h \
	../fc-lang/fclang.h

noinst_PROGRAMS = fcarch

../fc-case/fccase.h:
	cd ../fc-case && $(MAKE) $(AM_MAKEFLAGS) fccase.h
../fc-glyphname/fcglyphname.h:
	cd ../fc-glyphname && $(MAKE) $(AM_MAKEFLAGS) fcglyphname.h
../fc-lang/fclang.h:
	cd ../fc-lang && $(MAKE) $(AM_MAKEFLAGS) fclang.h

libfontconfig_la_SOURCES = \
	fcarch.h \
	fcatomic.c \
	fcblanks.c \
	fccache.c \
	fccfg.c \
	fccharset.c \
	fcdbg.c \
	fcdefault.c \
	fcdir.c \
	fcformat.c \
	fcfreetype.c \
	fcfs.c \
	fcinit.c \
	fclang.c \
	fclist.c \
	fcmatch.c \
	fcmatrix.c \
	fcname.c \
	fcpat.c \
	fcserialize.c \
	fcstat.c \
	fcstr.c \
	fcxml.c \
	ftglue.h \
	ftglue.c

lib_LTLIBRARIES = libfontconfig.la

libfontconfig_la_LDFLAGS =			\
	-version-info @LIBT_VERSION_INFO@ -no-undefined $(export_symbols)

libfontconfig_la_LIBADD = $(ICONV_LIBS) $(FREETYPE_LIBS) $(LIBXML2_LIBS) $(EXPAT_LIBS)

libfontconfig_la_DEPENDENCIES = $(fontconfig_def_dependency)

if ENABLE_SHARED
install-data-local: install-ms-import-lib install-libtool-import-lib

uninstall-local: uninstall-ms-import-lib uninstall-libtool-import-lib
endif

PUBLIC_FILES = \
	$(top_srcdir)/fontconfig/fontconfig.h \
	$(top_srcdir)/src/fcdeprecate.h \
	$(top_srcdir)/fontconfig/fcprivate.h

PUBLIC_FT_FILES = \
	$(top_srcdir)/fontconfig/fcfreetype.h

fcaliastail.h: fcalias.h

fcalias.h: $(top_srcdir)/src/makealias $(PUBLIC_FILES)
	$(AM_V_GEN) sh $(top_srcdir)/src/makealias "$(top_srcdir)/src" fcalias.h fcaliastail.h $(PUBLIC_FILES)

fcftaliastail.h: fcftalias.h

fcftalias.h: $(top_srcdir)/src/makealias $(PUBLIC_FT_FILES)
	$(AM_V_GEN) sh $(top_srcdir)/src/makealias "$(top_srcdir)/src" fcftalias.h fcftaliastail.h $(PUBLIC_FT_FILES)

CLEANFILES = $(ALIAS_FILES)

fontconfig.def: $(PUBLIC_FILES) $(PUBLIC_FT_FILES)
	echo Generating $@
	(echo EXPORTS; \
	(cat $(PUBLIC_FILES) $(PUBLIC_FT_FILES) || echo 'FcERROR ()' ) | \
	grep '^Fc[^ ]* *(' | sed -e 's/ *(.*$$//' -e 's/^/	/' | \
	sort; \
	echo LIBRARY libfontconfig-@LIBT_CURRENT_MINUS_AGE@.dll; \
	echo VERSION @LIBT_CURRENT@.@LIBT_REVISION@) >$@
	@ ! grep -q FcERROR $@ || ($(RM) $@; false)
