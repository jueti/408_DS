SORS = main.cpp static_array.cpp
OBJS = main.obj static_array.obj
PCHS = pch.h
CLFLAGS = /nologo /EHsc
LINKFLAGS = /nologo

pch.pch:
    $(CPP) /Yc$(PCHS) $*.cpp

static_array.obj:
    $(CPP) $(CLFLAGS) /Yu$(PCHS) $*.cpp

main.obj:
    $(CPP) $(CLFLAGS) /Yu$(PCHS) $*.cpp


main.exe: $(OBJS)
    link $(LINKFLAGS) $(OBJS)

.PHONY : clean
clean :
    del $(OBJS) static_array.pch main.pch pch.pch pch.obj
