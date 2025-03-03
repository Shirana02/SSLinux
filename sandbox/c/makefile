CwdSrc = main
LibSrc = plist term cst

CwdDir = .
LibSrcDir = ../../clib/src
LibHdrDir = ../../clib/hdr

ObjDir_cwd = ./obj/cwd
ObjDir_lib = ./obj/lib
CwdObj = $(foreach src, $(CwdSrc), $(ObjDir_cwd)/$(src).o)
LibObj = $(foreach src, $(LibSrc), $(ObjDir_lib)/$(src).o)

CC = gcc

memo:
	@echo "\tmake s : setup"
	@echo "\tmake b : build"
	@echo "\tmake c : clean"

$(ObjDir_cwd)/%.o: $(CwdDir)/%.c
	$(CC) -c -o $@ $< -I$(LibHdrDir)

$(ObjDir_lib)/%.o: $(LibSrcDir)/%.c
	$(CC) -c -o $@ $< -I$(LibHdrDir)

a.out: $(CwdObj) $(LibObj)
	$(CC) $^ -o $@

s:
	mkdir -p $(ObjDir_cwd)
	mkdir -p $(ObjDir_lib)
	
b: a.out

c:
	rm -rd $(ObjDir_cwd)
	rm -rd $(ObjDir_lib)
	rm ./a.out
