@echo off

set build_options=-DBUILD_WIN32=1
set compile_flags=-nologo /Zi /FC /EHsc
set linker_flags = -incremental:no -opt:ref /Debug:fastlink

if not exist build mkdir build
pushd build

start /b /wait "" "cl.exe" %build_options% %compile_flags% ../code/main.cpp /link %linker_flags% /out:jobbuilder.exe

popd