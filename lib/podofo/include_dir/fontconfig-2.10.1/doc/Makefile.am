# -*- encoding: utf-8 -*-
#
# fontconfig/doc/Makefile.am
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

NULL =
EXTRA_DIST =			\
	$(BUILT_DOCS)		\
	$(DOC_FUNCS_FNCS)	\
	$(DOC_FUNCS_SGML)	\
	$(HTML_DIR)/*		\
	$(SGML_FILES)		\
	$(check_SCRIPTS)	\
	confdir.sgml.in		\
	func.sgml		\
	$(NULL)
MAINTAINERCLEANFILES =		\
	$(DOC_FUNCS_SGML)	\
	$(NULL)
CLEANFILES =			\
	$(BUILT_DOCS)		\
	$(LOCAL_SGML_FILES)	\
	confdir.sgml		\
	func.refs		\
	$(NULL)
BUILT_SOURCES =			\
	$(NULL)
SUFFIXES =	\
	.fncs	\
	.sgml	\
	.txt	\
	.html	\
	$(NULL)
TESTS =				\
	check-missing-doc	\
	$(NULL)
TESTS_ENVIRONMENT=top_srcdir=${top_srcdir} sh
#
DOC2HTML = docbook2html
DOC2TXT  = docbook2txt
DOC2MAN  = docbook2man
DOC2PDF  = docbook2pdf

DOC_FUNCS_FNCS =		\
	fcatomic.fncs		\
	fcblanks.fncs		\
	fccache.fncs		\
	fccharset.fncs		\
	fcconfig.fncs		\
	fcconstant.fncs		\
	fcdircache.fncs		\
	fcfile.fncs		\
	fcfontset.fncs		\
	fcformat.fncs		\
	fcfreetype.fncs		\
	fcinit.fncs		\
	fclangset.fncs		\
	fcmatrix.fncs		\
	fcobjectset.fncs	\
	fcobjecttype.fncs	\
	fcpattern.fncs		\
	fcstring.fncs		\
	fcstrset.fncs		\
	fcvalue.fncs		\
	$(NULL)
SGML_FILES =			\
	fontconfig-user.sgml	\
	fontconfig-devel.sgml	\
	$(NULL)
LOCAL_SGML_FILES =			\
	local-fontconfig-user.sgml	\
	local-fontconfig-devel.sgml	\
	$(NULL)

DOC_FUNCS_SGML = $(DOC_FUNCS_FNCS:.fncs=.sgml)
BUILT_DOCS =		\
	$(HTML_FILES)	\
	$(PDF_FILES)	\
	$(TXT_FILES)	\
	$(man3_MANS)	\
	$(man5_MANS)	\
	$(NULL)
DOCS_DEPS =			\
	$(DOC_FUNCS_SGML)	\
	confdir.sgml		\
	version.sgml		\
	$(NULL)

TXT_FILES = $(SGML_FILES:.sgml=.txt)
PDF_FILES = $(SGML_FILES:.sgml=.pdf)
HTML_FILES =			\
	fontconfig-user.html	\
	$(NULL)
HTML_DIR = fontconfig-devel
#
noinst_PROGRAMS =	\
	$(NULL)
##
edit_sgml_SOURCES =	\
	edit-sgml.c	\
	$(NULL)
#
check_SCRIPTS =			\
	check-missing-doc	\
	$(NULL)
#
man3_MANS =		\
	$(DOCMAN3)	\
	$(NULL)
man5_MANS =		\
	fonts-conf.5	\
	$(NULL)
#
doc_DATA =		\
	$(TXT_FILES)	\
	$(PDF_FILES)	\
	$(HTML_FILES)	\
	$(NULL)
#
htmldocdir = $(docdir)/$(HTML_DIR)
htmldoc_DATA =		\
	$(NULL)

if USEDOCBOOK
BUILT_SOURCES +=		\
	$(LOCAL_SGML_FILES)	\
	$(NULL)
noinst_PROGRAMS +=	\
	edit-sgml	\
	$(NULL)
htmldoc_DATA += $(HTML_DIR)/*

##
if CROSS_COMPILING
.fncs.sgml:
	@echo Warning: cannot rebuild $@ when cross-compiling
else
.fncs.sgml:
	$(AM_V_GEN) $(RM) $@; \
	$(builddir)/edit-sgml$(EXEEXT) $(srcdir)/func.sgml < '$(srcdir)/$*.fncs' > $*.sgml
endif
.sgml.txt:
	$(AM_V_GEN) $(RM) $@; \
	$(DOC2TXT) $*.sgml
.sgml.pdf:
	$(AM_V_GEN) $(RM) $@; \
	$(DOC2PDF) $*.sgml
.sgml.html:
	$(AM_V_GEN) $(RM) $@; \
	$(DOC2HTML) -u $*.sgml > $@
##
fonts-conf.5: local-fontconfig-user.sgml version.sgml confdir.sgml
	$(AM_V_GEN) $(RM) $@; \
	$(DOC2MAN) local-fontconfig-user.sgml && \
	$(RM) manpage.*
##
$(man3_MANS): func.refs
func.refs: local-fontconfig-devel.sgml $(DOCS_DEPS)
	$(AM_V_GEN) $(RM) $@; \
	[ "x$(builddir)" != "x$(srcdir)" ] &&		\
	for f in $(DOC_FUNCS_SGML); do			\
		$(RM) $(builddir)/$$f || :;		\
		$(LN_S) $(srcdir)/$$f $(builddir)/$$f;	\
	done || :; \
	$(DOC2MAN) -o devel-man local-fontconfig-devel.sgml && \
	mv devel-man/manpage.refs func.refs &&	\
	mv devel-man/*.3 . &&			\
	$(RM) devel-man/manpage.* &&		\
	rmdir devel-man
confdir.sgml: $(srcdir)/confdir.sgml.in
	$(AM_V_GEN) sed -e 's,@CONFDIR\@,${CONFDIR},' $(srcdir)/$@.in | awk '{if (NR > 1) printf("\n"); printf("%s", $$0);}' > $@
##
$(DOC_FUNCS_SGML): $(DOC_FUNCS_FNCS) edit-sgml$(EXEEXT) $(srcdir)/func.sgml
$(TXT_FILES): $(DOCS_DEPS)
$(PDF_FILES): $(DOCS_DEPS)
$(HTML_FILES): $(DOCS_DEPS)
$(HTML_DIR)/*: $(HTML_DIR)
$(HTML_DIR): local-fontconfig-devel.sgml $(DOCS_DEPS)
	$(AM_V_GEN) $(RM) -r $@; \
	$(DOC2HTML) -V '%use-id-as-filename%' -o $@ local-fontconfig-devel.sgml
local-fontconfig-user.sgml: $(srcdir)/fontconfig-user.sgml
	$(AM_V_GEN) $(LN_S) $(srcdir)/fontconfig-user.sgml $@;	\
	[ ! -f $(builddir)/fontconfig-user.sgml ] && cp -a $(srcdir)/fontconfig-user.sgml $(builddir)/fontconfig-user.sgml || :
local-fontconfig-devel.sgml: $(srcdir)/fontconfig-devel.sgml
	$(AM_V_GEN) $(LN_S) $(srcdir)/fontconfig-devel.sgml $@;	\
	[ ! -f $(builddir)/fontconfig-devel.sgml ] && cp -a $(srcdir)/fontconfig-devel.sgml $(builddir)/fontconfig-devel.sgml || :
#
all-local: $(BUILT_DOCS) $(HTML_DIR)/*
clean-local:
	$(RM) -r $(HTML_DIR) devel-man
	[ "x$(builddir)" != "x$(srcdir)" ] && $(RM) $(builddir)/fontconfig-user.sgml $(builddir)/fontconfig-devel.sgml || :
else
htmldoc_DATA += $(srcdir)/$(HTML_DIR)/*
all-local:
clean-local:
endif
