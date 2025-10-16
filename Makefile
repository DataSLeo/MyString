CC = gcc
FLAGINCLUDE = -Iinclude
FLAGBUILD = -Lbuild

CRITERION = -lcriterion
MYSTRING = -lmystring

LIBSTATIC = libmystring.a

BUILDDIR = build
TESTDIR = test
SRCDIR = src

FILESSRC = $(wildcard $(SRCDIR)/*.c)
TOOBJECT = $(patsubst $(SRCDIR)/%.c, $(BUILDDIR)/%.o, $(FILESSRC))

FILESTEST = $(wildcard $(TESTDIR)/**/*.c)
TOMAKETEST = $(patsubst %.c, %.out, $(FILESTEST))

CLEANTEST = rm -rf $(TOMAKETEST)





all: dir $(TOOBJECT) staticlib

staticlib: dir $(TOOBJECT)
	@ar rcs $(BUILDDIR)/$(LIBSTATIC) $(TOOBJECT)


dir: 
	@mkdir -p $(BUILDDIR)

tests: staticlib $(TOMAKETEST) 

test: tests
	@for t in $(TOMAKETEST); do \
		./$$t || exit 1; \
	done
	@$(CLEANTEST)





$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $^ $(FLAGINCLUDE) -o $@	

%.out: %.c
	@$(CC) $< $(FLAGINCLUDE) $(FLAGBUILD) $(CRITERION) $(MYSTRING) -o $@

clean:
	@rm -rf $(BUILDDIR) $(TOMAKETEST)