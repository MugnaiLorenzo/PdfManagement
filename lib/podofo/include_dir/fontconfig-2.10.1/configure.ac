dnl 
dnl  fontconfig/configure.in
dnl 
dnl  Copyright © 2003 Keith Packard
dnl 
dnl  Permission to use, copy, modify, distribute, and sell this software and its
dnl  documentation for any purpose is hereby granted without fee, provided that
dnl  the above copyright notice appear in all copies and that both that
dnl  copyright notice and this permission notice appear in supporting
dnl  documentation, and that the name of the author(s) not be used in
dnl  advertising or publicity pertaining to distribution of the software without
dnl  specific, written prior permission.  The authors make no
dnl  representations about the suitability of this software for any purpose.  It
dnl  is provided "as is" without express or implied warranty.
dnl 
dnl  THE AUTHOR(S) DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
dnl  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
dnl  EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY SPECIAL, INDIRECT OR
dnl  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
dnl  DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
dnl  TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
dnl  PERFORMANCE OF THIS SOFTWARE.
dnl
dnl Process this file with autoconf to create configure.

AC_PREREQ(2.61)
AC_INIT(fonts.dtd)

dnl ==========================================================================
dnl                               Versioning              
dnl ==========================================================================

dnl This is the package version number, not the shared library
dnl version.  This same version number must appear in fontconfig/fontconfig.h
dnl Yes, it is a pain to synchronize version numbers.  Unfortunately, it's
dnl not possible to extract the version number here from fontconfig.h
AM_INIT_AUTOMAKE(fontconfig, 2.10.1)
m4_ifdef([AM_SILENT_RULES],[AM_SILENT_RULES([yes])])

dnl libtool versioning

dnl bump revision when fixing bugs
dnl bump current and age, reset revision to zero when adding APIs
dnl bump current, leave age, reset revision to zero when changing/removing APIS
LIBT_CURRENT=7
LIBT_REVISION=2
AC_SUBST(LIBT_CURRENT)
AC_SUBST(LIBT_REVISION)
LIBT_AGE=6

LIBT_VERSION_INFO="$LIBT_CURRENT:$LIBT_REVISION:$LIBT_AGE"
AC_SUBST(LIBT_VERSION_INFO)

LIBT_CURRENT_MINUS_AGE=`expr $LIBT_CURRENT - $LIBT_AGE`
AC_SUBST(LIBT_CURRENT_MINUS_AGE)

dnl ==========================================================================

AC_CONFIG_HEADERS(config.h)

AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S
AC_LIBTOOL_WIN32_DLL
AM_PROG_LIBTOOL
AC_PROG_MAKE_SET
PKG_PROG_PKG_CONFIG

AC_MSG_CHECKING([for RM macro])
_predefined_rm=`make -p -f /dev/null 2>/dev/null|grep '^RM ='|sed -e 's/^RM = //'`
if test "x$_predefined_rm" = "x"; then
	AC_MSG_RESULT([no predefined RM])
	AC_CHECK_PROG(RM, rm, [rm -f])
else
	AC_MSG_RESULT($_predefined_rm)
fi

dnl ==========================================================================

case "$host" in
  *-*-mingw*)
    os_win32=yes
    ;;
  *)
    os_win32=no
esac
AM_CONDITIONAL(OS_WIN32, test "$os_win32" = "yes")

if test "$os_win32" = "yes"; then
  AC_CHECK_PROG(ms_librarian, lib.exe, yes, no)
fi
AM_CONDITIONAL(MS_LIB_AVAILABLE, test x$ms_librarian = xyes)

WARN_CFLAGS=""
if test "x$GCC" = "xyes"; then
	WARN_CFLAGS="-Wall -Wpointer-arith -Wstrict-prototypes \
	-Wmissing-prototypes -Wmissing-declarations \
	-Wnested-externs -fno-strict-aliasing"
	AC_DEFINE_UNQUOTED(HAVE_WARNING_CPP_DIRECTIVE,1,
	[Can use #warning in C files])
fi
AC_SUBST(WARN_CFLAGS)


dnl ==========================================================================

AM_CONDITIONAL(CROSS_COMPILING, test $cross_compiling = yes)
AM_CONDITIONAL(ENABLE_SHARED, test "$enable_shared" = "yes")

dnl ==========================================================================

AC_ARG_WITH(arch,
	[AC_HELP_STRING([--with-arch=ARCH],
			[Force architecture to ARCH])],
	arch="$withval", arch=auto)

if test "x$arch" != xauto; then
	AC_DEFINE_UNQUOTED([FC_ARCHITECTURE], "$arch", [Architecture prefix to use for cache file names])
fi


dnl ==========================================================================

# Checks for header files.
AC_HEADER_DIRENT
AC_HEADER_STDC
AC_CHECK_HEADERS([fcntl.h regex.h stdlib.h string.h unistd.h sys/vfs.h sys/statfs.h sys/param.h sys/mount.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_C_INLINE
AC_C_FLEXIBLE_ARRAY_MEMBER
AC_TYPE_PID_T

# Checks for library functions.
AC_FUNC_VPRINTF
AC_FUNC_MMAP
AC_CHECK_FUNCS([geteuid getuid link memmove memset mkstemp strchr strrchr strtol getopt getopt_long sysconf ftruncate chsize rand random lrand48 random_r rand_r regcomp regerror regexec regfree posix_fadvise fstatvfs fstatfs])

#
if test "x$ac_cv_func_fstatvfs" = "xyes"; then
	AC_CHECK_MEMBERS([struct statvfs.f_basetype, struct statvfs.f_fstypename],,,
		[#include <sys/statvfs.h>])
fi
if test "x$ac_cv_func_fstatfs" = "xyes"; then
	AC_CHECK_MEMBERS([struct statfs.f_flags, struct statfs.f_fstypename],,, [
#ifdef HAVE_SYS_VFS_H
#include <sys/vfs.h>
#endif
#ifdef HAVE_SYS_STATFS_H
#include <sys/statfs.h>
#endif
#ifdef HAVE_SYS_PARAM_H
#include <sys/param.h>
#endif
#ifdef HAVE_SYS_MOUNT_H
#include <sys/mount.h>
#endif])
fi
AC_CHECK_MEMBERS([struct dirent.d_type],,,
	[#include <dirent.h>])
#
# regex
#
if test "x$ac_cv_func_regcomp" = "xyes" -a "x$ac_cv_func_regerror" = "xyes" -a "x$ac_cv_func_regexec" = "xyes" -a "x$ac_cv_func_regfree"; then
	AC_DEFINE(USE_REGEX,,[Use regex])
fi

#
# Checks for iconv
#
AC_ARG_ENABLE(iconv,
	[AC_HELP_STRING([--enable-iconv],
			[Use iconv to support non-Unicode SFNT name])],
	,enable_iconv=no)
AC_ARG_WITH(libiconv,
	[AC_HELP_STRING([--with-libiconv=DIR],
			[Use libiconv in DIR])],
	[if test "x$withval" = "xyes"; then
		libiconv_prefix=$prefix
	 else
		libiconv_prefix=$withval
	 fi],
	[libiconv_prefix=auto])
AC_ARG_WITH(libiconv-includes,
	[AC_HELP_STRING([--with-libiconv-includes=DIR],
			[Use libiconv includes in DIR])],
	[libiconv_includes=$withval],
	[libiconv_includes=auto])
AC_ARG_WITH(libiconv-lib,
	[AC_HELP_STRING([--with-libiconv-lib=DIR],
			[Use libiconv library in DIR])],
	[libiconv_lib=$withval],
	[libiconv_lib=auto])

# if no libiconv,libiconv-includes,libiconv-lib are specified,
# libc's iconv has a priority.
if test "$libiconv_includes" != "auto" -a -r ${libiconv_includes}/iconv.h; then
	libiconv_cflags="-I${libiconv_includes}"
elif test "$libiconv_prefix" != "auto" -a -r ${libiconv_prefix}/include/iconv.h; then
	libiconv_cflags="-I${libiconv_prefix}/include"
else
	libiconv_cflags=""
fi
libiconv_libs=""
if test "x$libiconv_cflags" != "x"; then
	if test "$libiconv_lib" != "auto" -a -d ${libiconv_lib}; then
		libiconv_libs="-L${libiconv_lib} -liconv"
	elif test "$libiconv_prefix" != "auto" -a -d ${libiconv_prefix}/lib; then
		libiconv_libs="-L${libiconv_prefix}/lib -liconv"
	else
		libiconv_libs="-liconv"
	fi
fi

use_iconv=0
if test "x$enable_iconv" != "xno"; then
	AC_MSG_CHECKING([for a usable iconv])
	if test "x$libiconv_cflags" != "x" -o "x$libiconv_libs" != "x"; then
		iconvsaved_CFLAGS="$CFLAGS"
		iconvsaved_LIBS="$LIBS"
		CFLAGS="$CFLAGS $libiconv_cflags"
		LIBS="$LIBS $libiconv_libs"

		AC_TRY_LINK([#include <iconv.h>],
			[iconv_open ("from", "to");],
			[iconv_type="libiconv"
			 use_iconv=1],
			[use_iconv=0])

		CFLAGS="$iconvsaved_CFLAGS"
		LIBS="$iconvsaved_LIBS"
		ICONV_CFLAGS="$libiconv_cflags"
		ICONV_LIBS="$libiconv_libs"
	fi
	if test "x$use_iconv" = "x0"; then
		AC_TRY_LINK([#include <iconv.h>],
			[iconv_open ("from", "to");],
			[iconv_type="libc"
			 use_iconv=1],
			[iconv_type="not found"
			 use_iconv=0])
	fi

	AC_MSG_RESULT([$iconv_type])
	AC_SUBST(ICONV_CFLAGS)
	AC_SUBST(ICONV_LIBS)
fi
AC_DEFINE_UNQUOTED(USE_ICONV,$use_iconv,[Use iconv.])
#
# Checks for FreeType
#
PKG_CHECK_MODULES(FREETYPE, freetype2)

AC_SUBST(FREETYPE_LIBS)
AC_SUBST(FREETYPE_CFLAGS)

fontconfig_save_libs="$LIBS"
fontconfig_save_cflags="$CFLAGS"
LIBS="$LIBS $FREETYPE_LIBS"
CFLAGS="$CFLAGS $FREETYPE_CFLAGS"
AC_CHECK_FUNCS(FT_Get_Next_Char FT_Get_BDF_Property FT_Get_PS_Font_Info FT_Has_PS_Glyph_Names FT_Get_X11_Font_Format FT_Select_Size)
AC_CHECK_MEMBER(FT_Bitmap_Size.y_ppem,
		HAVE_FT_BITMAP_SIZE_Y_PPEM=1,
		HAVE_FT_BITMAP_SIZE_Y_PPEM=0,
[#include <ft2build.h>
#include FT_FREETYPE_H])
AC_DEFINE_UNQUOTED(HAVE_FT_BITMAP_SIZE_Y_PPEM,$HAVE_FT_BITMAP_SIZE_Y_PPEM,
		   [FT_Bitmap_Size structure includes y_ppem field])
CFLAGS="$fontconfig_save_cflags"
LIBS="$fontconfig_save_libs"

#
# Check expat configuration
#
AC_ARG_WITH(expat,
	[AC_HELP_STRING([--with-expat=DIR],
			[Use Expat in DIR])],
	[expat_prefix=$withval],
	[expat_prefix=auto])
AC_ARG_WITH(expat-includes,
	[AC_HELP_STRING([--with-expat-includes=DIR],
			[Use Expat includes in DIR])],
	[expat_includes=$withval],
	[expat_includes=auto])
AC_ARG_WITH(expat-lib,
	[AC_HELP_STRING([--with-expat-lib=DIR])],
	[expat_lib=$withval],
	[expat_lib=auto])

if test "$enable_libxml2" != "yes"; then
	use_pkgconfig_for_expat=yes
	if test "$expat_prefix" = "auto" -a "$expat_includes" = "auto" -a "$expat_lib" = "auto"; then
		PKG_CHECK_MODULES(EXPAT, expat,,use_pkgconfig_for_expat=no)
	else
		use_pkgconfig_for_expat=no
	fi
	if test "x$use_pkgconfig_for_expat" = "xno"; then
		if test "$expat_includes" != "auto" -a -r ${expat_includes}/expat.h; then
			EXPAT_CFLAGS="-I${expat_includes}"
		elif test "$expat_prefix" != "auto" -a -r ${expat_prefix}/include/expat.h; then
			EXPAT_CFLAGS="-I${expat_prefix}/include"
		else
			EXPAT_CFLAGS=""
		fi
		if test "$expat_lib" != "auto"; then
			EXPAT_LIBS="-L${expat_lib} -lexpat"
		elif test "$expat_prefix" != "auto"; then
			EXPAT_LIBS="-L${expat_prefix}/lib -lexpat"
		else
			EXPAT_LIBS="-lexpat"
		fi
	fi

	expatsaved_CPPFLAGS="$CPPFLAGS"
	expatsaved_LIBS="$LIBS"
	CPPFLAGS="$CPPFLAGS $EXPAT_CFLAGS"
	LIBS="$LIBS $EXPAT_LIBS"

	AC_CHECK_HEADER(expat.h)
	if test "$ac_cv_header_expat_h" = "no"; then
		AC_CHECK_HEADER(xmlparse.h)
		if test "$ac_cv_header_xmlparse_h" = "yes"; then
			HAVE_XMLPARSE_H=1
			AC_SUBST(HAVE_XMLPARSE_H)
			AC_DEFINE_UNQUOTED(HAVE_XMLPARSE_H,$HAVE_XMLPARSE_H,
				[Use xmlparse.h instead of expat.h])
		else
			AC_MSG_ERROR([
*** expat is required. or try to use --enable-libxml2])
		fi
	fi
	AC_CHECK_FUNCS(XML_SetDoctypeDeclHandler)
	if test "$ac_cv_func_XML_SetDoctypeDeclHandler" = "no"; then
		AC_MSG_ERROR([
*** expat is required. or try to use --enable-libxml2])
	fi
	CPPFLAGS="$expatsaved_CPPFLAGS"
	LIBS="$expatsaved_LIBS"

	AC_SUBST(EXPAT_CFLAGS)
	AC_SUBST(EXPAT_LIBS)
fi

#
# Check libxml2 configuration
#
AC_ARG_ENABLE(libxml2,
	[AC_HELP_STRING([--enable-libxml2],
			[Use libxml2 instead of Expat])])

if test "$enable_libxml2" = "yes"; then
    PKG_CHECK_MODULES([LIBXML2], [libxml-2.0 >= 2.6])
    AC_DEFINE_UNQUOTED(ENABLE_LIBXML2,1,[Use libxml2 instead of Expat])

    AC_SUBST(LIBXML2_CFLAGS)
    AC_SUBST(LIBXML2_LIBS)

    fc_saved_CFLAGS="$CFLAGS"
    CFLAGS="$CFLAGS $LIBXML2_CFLAGS"
    AC_MSG_CHECKING([SAX1 support in libxml2])
    AC_COMPILE_IFELSE([AC_LANG_SOURCE([[
	#include <libxml/xmlversion.h>
	#if !defined(LIBXML_SAX1_ENABLED)
	#  include "error: No SAX1 support in libxml2"
	#endif
	]])], [AC_MSG_RESULT([found])], [AC_MSG_ERROR([
*** SAX1 support in libxml2 is required. enable it or use expat instead.])])
    CFLAGS="$fc_saved_CFLAGS"
fi

#
# Set default font directory
#

AC_ARG_WITH(default-fonts,
	[AC_HELP_STRING([--with-default-fonts=DIR],
			[Use fonts from DIR when config is busted])],
	default_fonts="$withval", default_fonts=yes)

case "$default_fonts" in
yes)
	if test "$os_win32" = "yes"; then
		FC_DEFAULT_FONTS="WINDOWSFONTDIR"
		AC_DEFINE_UNQUOTED(FC_DEFAULT_FONTS, "WINDOWSFONTDIR", 
				   [Windows font directory])
	else
		FC_DEFAULT_FONTS="/usr/share/fonts"
		AC_DEFINE_UNQUOTED(FC_DEFAULT_FONTS, "/usr/share/fonts", 
				   [System font directory])
	fi
	;;
*)
	FC_DEFAULT_FONTS="$default_fonts"
	AC_DEFINE_UNQUOTED(FC_DEFAULT_FONTS, "$default_fonts",
			   [System font directory])
	;;
esac

AC_SUBST(FC_DEFAULT_FONTS)

#
# Add more fonts if available.  By default, add only the directories
# with outline fonts; those with bitmaps can be added as desired in
# local.conf or ~/.fonts.conf
#
AC_ARG_WITH(add-fonts,
	[AC_HELP_STRING([--with-add-fonts=DIR1,DIR2,...],
			[Find additional fonts in DIR1,DIR2,... ])],
	add_fonts="$withval", add_fonts=yes)

case "$add_fonts" in
yes)
	FC_ADD_FONTS=""
	for dir in /usr/X11R6/lib/X11 /usr/X11/lib/X11 /usr/lib/X11; do
		case x"$FC_ADD_FONTS" in
		x)
			sub="$dir/fonts"
			if test -d "$sub"; then
				case x$FC_ADD_FONTS in
				x)
					FC_ADD_FONTS="$sub"
					;;
				*)
					FC_ADD_FONTS="$FC_ADD_FONTS,$sub"
					;;
				esac
			fi
			;;
		esac
	done
	AC_DEFINE_UNQUOTED(FC_ADD_FONTS,"$add_fonts",[Additional font directories])
	;;
no)
	FC_ADD_FONTS=""
	;;
*)
	FC_ADD_FONTS="$add_fonts"
	AC_DEFINE_UNQUOTED(FC_ADD_FONTS,"$add_fonts",[Additional font directories])
	;;
esac

AC_SUBST(FC_ADD_FONTS)

FC_FONTPATH=""

case "$FC_ADD_FONTS" in
"")
	;;
*)
	FC_FONTPATH=`echo $FC_ADD_FONTS | 
			sed -e 's/^/<dir>/' -e 's/$/<\/dir>/' -e 's/,/<\/dir> <dir>/g'`
	;;
esac

AC_SUBST(FC_FONTPATH)

#
# Set default cache directory path
#
AC_ARG_WITH(cache-dir,
	[AC_HELP_STRING([--with-cache-dir=DIR],
			[Use DIR to store cache files [default=LOCALSTATEDIR/cache/fontconfig]])],
	fc_cachedir="$withval", fc_cachedir=yes)

case $fc_cachedir in
no|yes)
	if test "$os_win32" = "yes"; then
		fc_cachedir="WINDOWSTEMPDIR_FONTCONFIG_CACHE"
	else
		fc_cachedir='${localstatedir}/cache/${PACKAGE}'
	fi
	;;
*)
	;;
esac
AC_SUBST(fc_cachedir)
FC_CACHEDIR=${fc_cachedir}
AC_SUBST(FC_CACHEDIR)

FC_FONTDATE=`LC_ALL=C date`

AC_SUBST(FC_FONTDATE)

#
# Set configuration paths
#

AC_ARG_WITH(templatedir,
	[AC_HELP_STRING([--with-templatedir=DIR],
			[Use DIR to store the configuration template files [default=DATADIR/fontconfig/conf.avail]])],
	[templatedir="$withval"],
	[templatedir=yes])
AC_ARG_WITH(baseconfigdir,
	[AC_HELP_STRING([--with-baseconfigdir=DIR],
			[Use DIR to store the base configuration files [default=SYSCONFDIR/fonts]])],
	[baseconfigdir="$withval"],
	[baseconfigdir=yes])
AC_ARG_WITH(configdir,
	[AC_HELP_STRING([--with-configdir=DIR],
			[Use DIR to store active configuration files [default=BASECONFIGDIR/conf.d]])],
	[configdir="$withval"],
	[configdir=yes])
AC_ARG_WITH(xmldir,
	[AC_HELP_STRING([--with-xmldir=DIR],
			[Use DIR to store XML schema files [default=DATADIR/xml/fontconfig]])],
	[xmldir="$withval"],
	[xmldir=yes])

case "$templatedir" in
no|yes)
	templatedir='${datadir}'/fontconfig/conf.avail
	;;
*)
	;;
esac
case "$baseconfigdir" in
no|yes)
	baseconfigdir='${sysconfdir}'/fonts
	;;
*)
	;;
esac
case "$configdir" in
no|yes)
	configdir='${baseconfigdir}'/conf.d
	;;
*)
	;;
esac
case "$xmldir" in
no|yes)
	xmldir='${datadir}'/xml/fontconfig
	;;
*)
	;;
esac

TEMPLATEDIR=${templatedir}
BASECONFIGDIR=${baseconfigdir}
CONFIGDIR=${configdir}
XMLDIR=${xmldir}
AC_SUBST(templatedir)
AC_SUBST(TEMPLATEDIR)
AC_SUBST(baseconfigdir)
AC_SUBST(BASECONFIGDIR)
AC_SUBST(configdir)
AC_SUBST(CONFIGDIR)
AC_SUBST(xmldir)
AC_SUBST(XMLDIR)

#
# Let people not build/install docs if they don't have docbook
#

AC_CHECK_PROG(HASDOCBOOK, docbook2html, yes, no)

AM_CONDITIONAL(USEDOCBOOK, test "x$HASDOCBOOK" = xyes)

default_docs="yes"
#
# Check if docs exist or can be created
#
if test x$HASDOCBOOK = xno; then
	if test -f $srcdir/doc/fonts-conf.5; then
		:
	else
		default_docs="no"
	fi
fi

AC_ARG_ENABLE(docs,
	[AC_HELP_STRING([--disable-docs],
			[Don't build and install documentation])],
	,
	enable_docs=$default_docs)

AM_CONDITIONAL(ENABLE_DOCS, test "x$enable_docs" = xyes)

if test "x$enable_docs" = xyes; then
	DOCSRC="doc"
	tmp=funcs.$$
	cat $srcdir/doc/*.fncs | awk '
	/^@TITLE@/	{ if (!done) { printf ("%s\n", $2); done = 1; } }
	/^@FUNC@/	{ if (!done) { printf ("%s\n", $2); done = 1; } }
	/^@@/		{ done = 0; }' > $tmp
	DOCMAN3=`cat $tmp | awk '{ printf ("%s.3 ", $1); }'`
	echo DOCMAN3 $DOCMAN3
	rm -f $tmp
else
	DOCSRC=""
	DOCMAN3=""
fi

AC_SUBST(DOCSRC)
AC_SUBST(DOCMAN3)


dnl Figure out what cache format suffix to use for this architecture
AC_C_BIGENDIAN
AC_CHECK_SIZEOF([void *])
AC_CHECK_ALIGNOF([double])

dnl include the header file for workaround of miscalculating size on autoconf
dnl particularly for fat binaries
AH_BOTTOM([#include "config-fixups.h"])

AC_OUTPUT([
Makefile
fontconfig/Makefile
fc-lang/Makefile
fc-glyphname/Makefile
fc-case/Makefile
src/Makefile
conf.d/Makefile
fc-cache/Makefile
fc-cat/Makefile
fc-list/Makefile
fc-match/Makefile
fc-pattern/Makefile
fc-query/Makefile
fc-scan/Makefile
doc/Makefile
doc/version.sgml
test/Makefile
fontconfig.spec
fontconfig.pc
fontconfig-zip
])
