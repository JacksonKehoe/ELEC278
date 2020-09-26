# Makefile for Step 4 (MSVC version)

CC		=	cl
!IFNDEF CFLAGS
CFLAGS		=	/nologo /WX /Iinclude /DWIN32
!ENDIF
LD		=	cl
LDFLAGS		=	/nologo

main.exe:	main.obj myString.obj
	$(LD) $(LDFLAGS) /Femain main.obj myString.obj

main.obj:	main.c myString.h

myString.obj:	myString.h myString.c
