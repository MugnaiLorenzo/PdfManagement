# 
#  fontconfig/Makefile.am
# 
#  Copyright © 2003 Keith Packard
# 
#  Permission to use, copy, modify, distribute, and sell this software and its
#  documentation for any purpose is hereby granted without fee, provided that
#  the above copyright notice appear in all copies and that both that
#  copyright notice and this permission notice appear in supporting
#  documentation, and that the name of the author(s) not be used in
#  advertising or publicity pertaining to distribution of the software without
#  specific, written prior permission.  The authors make no
#  representations about the suitability of this software for any purpose.  It
#  is provided "as is" without express or implied warranty.
# 
#  THE AUTHOR(S) DISCLAIMS ALL WARRANTIES WITH REGARD TO THIS SOFTWARE,
#  INCLUDING ALL IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS, IN NO
#  EVENT SHALL THE AUTHOR(S) BE LIABLE FOR ANY SPECIAL, INDIRECT OR
#  CONSEQUENTIAL DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE,
#  DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
#  TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
#  PERFORMANCE OF THIS SOFTWARE.

DOCSRC=@DOCSRC@
SUBDIRS=fontconfig fc-case fc-lang fc-glyphname src \
	fc-cache fc-cat fc-list fc-match fc-pattern fc-query fc-scan \
	conf.d $(DOCSRC) test

AUTOMAKE_OPTIONS = dist-bzip2

EXTRA_DIST = \
        fontconfig.pc.in \
        fonts.conf.in \
	fonts.dtd \
        fontconfig.spec.in \
        fontconfig.spec \
	fontconfig-zip.in \
	config-fixups.h
CLEANFILES = fonts.conf
DISTCLEANFILES = config.cache doltcompile
MAINTAINERCLEANFILES = \
	$(srcdir)/aclocal.m4 \
	$(srcdir)/autoscan.log \
	$(srcdir)/compile \
	$(srcdir)/config.guess \
	$(srcdir)/config.h.in \
	$(srcdir)/config.sub \
	$(srcdir)/configure.scan \
	$(srcdir)/depcomp \
	$(srcdir)/install-sh \
	$(srcdir)/ltmain.sh \
	$(srcdir)/missing \
	$(srcdir)/mkinstalldirs \
	`find "$(srcdir)" -type f -name Makefile.in -print`

pkgconfigdir=$(libdir)/pkgconfig
pkgconfig_DATA = fontconfig.pc

baseconfigdir = $(BASECONFIGDIR)
configdir = $(CONFIGDIR)

xmldir = $(XMLDIR)
xml_DATA = fonts.dtd

if CROSS_COMPILING
  RUN_FC_CACHE_TEST=false
else
  RUN_FC_CACHE_TEST=test -z "$(DESTDIR)"
endif

# Creating ChangeLog from git log:

MAINTAINERCLEANFILES += $(srcdir)/ChangeLog
EXTRA_DIST += ChangeLog
ChangeLog: $(srcdir)/ChangeLog
$(srcdir)/ChangeLog:
	if test -d "$(srcdir)/.git"; then \
	  (GIT_DIR=$(top_srcdir)/.git ./missing --run git log --stat) | fmt --split-only > $@.tmp \
	  && mv -f $@.tmp $@ \
	  || ($(RM) $@.tmp; \
	      echo Failed to generate ChangeLog, your ChangeLog may be outdated >&2; \
	      (test -f $@ || echo git-log is required to generate this file >> $@)); \
	else \
	  test -f $@ || \
	  (echo A git checkout and git-log is required to generate ChangeLog >&2 && \
	  echo A git checkout and git-log is required to generate this file >> $@); \
	fi

.PHONY: ChangeLog

fonts.conf: fonts.conf.in Makefile
	sed \
		-e 's,@FC_CACHEDIR\@,$(FC_CACHEDIR),g' \
		-e 's,@FC_DEFAULT_FONTS\@,$(FC_DEFAULT_FONTS),g' \
		-e 's,@FC_FONTPATH\@,$(FC_FONTPATH),g' \
		-e 's,@CONFIGDIR\@,$(CONFIGDIR),g' \
		-e 's,@PACKAGE\@,$(PACKAGE),g' \
		-e 's,@VERSION\@,$(VERSION),g' \
		$(srcdir)/$@.in > $@.tmp && \
	mv $@.tmp $@

install-data-local: fonts.conf
	$(mkinstalldirs) $(DESTDIR)$(baseconfigdir) $(DESTDIR)$(fc_cachedir)
	if [ -f $(DESTDIR)$(baseconfigdir)/fonts.conf ]; then \
	  echo "backing up existing $(DESTDIR)$(baseconfigdir)/fonts.conf"; \
	  mv $(DESTDIR)$(baseconfigdir)/fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf.bak; \
	fi
	if [ -f $(srcdir)/fonts.conf ]; then \
	  echo " $(INSTALL_DATA) $(srcdir)/fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf"; \
	  $(INSTALL_DATA) $(srcdir)/fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf; \
	else if [ -f fonts.conf ]; then \
	  echo " $(INSTALL_DATA) fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf"; \
	  $(INSTALL_DATA) fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf; \
	fi; fi
	@(if $(RUN_FC_CACHE_TEST); then \
	    echo "fc-cache$(EXEEXT) -s -f -v"; \
	    fc-cache/fc-cache$(EXEEXT) -s -f -v; \
	else \
	    echo "***"; \
	    echo "*** Warning: fonts.cache not built"; \
	    echo "***"; \
	    echo "*** Generate this file manually on host system using fc-cache"; \
	    echo "***"; \
	fi)

uninstall-local:
	if [ -f $(srcdir)/fonts.conf ]; then \
	  if cmp -s $(srcdir)/fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf; then \
	     echo " uninstall standard $(DESTDIR)$(baseconfigdir)/fonts.conf"; \
	     $(RM) $(DESTDIR)$(baseconfigdir)/fonts.conf; \
	  fi; \
	else if [ -f fonts.conf ]; then \
	  if cmp -s fonts.conf $(DESTDIR)$(baseconfigdir)/fonts.conf; then \
	     echo " uninstall standard $(DESTDIR)$(baseconfigdir)/fonts.conf"; \
	     $(RM) $(DESTDIR)$(baseconfigdir)/fonts.conf; \
	  fi; \
	fi; fi

debuild debuild-signed: debuild-dirs
	(cd $(distdir)/debian && debuild)

debuild-unsigned: debuild-dirs
	(cd $(distdir)/debian && debuild -us -uc)

debuild-dirs: distdir
	$(RM) $(PACKAGE)_$(VERSION).orig.tar.gz
	$(RM) -r $(distdir).orig
	cp -a $(distdir) $(distdir).orig
	$(RM) -r $(distdir).orig/debian
