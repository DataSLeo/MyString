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
TOTEST = $(patsubst %.c, %.out, $(FILESTEST))

CLEANTEST = rm -rf $(TOTEST)





all: dir $(TOOBJECT) staticlib

staticlib: dir $(TOOBJECT)
	@ar rcs $(BUILDDIR)/$(LIBSTATIC) $(TOOBJECT)


dir: 
	@mkdir -p $(BUILDDIR)

tests: staticlib $(TOTEST) 

test: clean tests
	@for t in $(TOTEST); do \
		./$$t || exit 1; \
	done
	@$(CLEANTEST)





$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@$(CC) -c $^ $(FLAGINCLUDE) -o $@	

%.out: %.c
	@$(CC) $< $(FLAGINCLUDE) $(FLAGBUILD) $(CRITERION) $(MYSTRING) -o $@

clean:
	@rm -rf $(BUILDDIR) $(TOTEST)