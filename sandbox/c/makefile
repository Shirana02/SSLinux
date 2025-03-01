CwdSrc = main
LibSrc = plist term cst

CwdDir = .
LibDir = ../../clib

ObjDir_cwd = ./obj/cwd
ObjDir_lib = ./obj/lib
CwdObj = $(foreach src, $(CwdSrc), $(ObjDir_cwd)/$(src).o)
LibObj = $(foreach src, $(LibSrc), $(ObjDir_lib)/$(src).o)

CC = gcc

memo:
	@echo "\tmake s : setup"
	@echo "\tmake b : build"
	@echo "\tmake r : build and run"
	@echo "\tmake c : clean"

$(ObjDir_cwd)/%.o: $(CwdDir)/%.c
	$(CC) -c -o $@ $< -I$(LibDir)

$(ObjDir_lib)/%.o: $(LibDir)/%.c
	$(CC) -c -o $@ $< -I$(LibDir)

a.out: $(CwdObj) $(LibObj)
	$(CC) $^ -o $@

b: a.out

s:
	mkdir -p $(ObjDir_cwd)
	mkdir -p $(ObjDir_lib)
	
c:
	rm -rd $(ObjDir_cwd)
	rm -rd $(ObjDir_lib)
	rm ./a.out
