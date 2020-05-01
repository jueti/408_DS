main.exe: stdafx.obj main.obj static_array.obj
    link.exe -nologo  main.obj static_array.obj stdafx.obj
    del *.obj

stdafx.obj:
    cl.exe -nologo -D"NDEBUG" -O2 -c -Yc -Fpstdafx.pch -Fostdafx.obj stdafx.c

main.obj: stdafx.pch
    cl.exe -nologo -D"NDEBUG" -O2 -c -Yustdafx.h -Fpstdafx.pch -Fomain.obj main.c

static_array.obj: stdafx.pch
    cl.exe -nologo -D"NDEBUG" -O2 -c -Yustdafx.h -Fpstdafx.pch -Fostatic_array.obj static_array.c

clean:
    del *.obj >nul 2>&1
    del *.pch >nul 2>&1
    del *.exe >nul 2>&1
