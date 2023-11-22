
UNAME_S := $(shell uname -s)



ifeq ($(UNAME_S),Linux)
	CARP = linux
else
	CARP = mac
endif

all:
		$(MAKE) -C $(CARP)
