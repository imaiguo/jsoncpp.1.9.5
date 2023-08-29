incDir      :=/opt/commonlib/jsoncpp/include
appName		:=jsonDemo
buildDir	:=../build/
objDir		:=$(buildDir)obj/
binDir		:=$(buildDir)bin/

libDir		:=$(buildDir)bin/
libDir		+=/opt/commonlib/jsoncpp/libs/linux-gcc-5.4.0
cxxSrc		:=$(shell find * -name "*.cpp")


cc			:= g++

ccflag		:=$(foreach includedir,$(incDir),-I$(includedir)) -m64 -std=c++11 -O2
lkflag		:=$(addprefix -L,$(libDir)) -O2

cxxObj		:=$(patsubst %.cpp,%.o,$(cxxSrc))
allObj		:=$(addprefix $(objDir),$(cxxObj))


$(appName):$(cxxObj)
	$(cc) -o $(binDir)$@ $(allObj) $(lkflag)  -ljson_linux-gcc-5.4.0_libmt  -L$(binDir) $(LDFLAGS)
	
	
%.o:$(appSrc)%.cpp | buildDir
	$(cc) -fPIC -c $< -o $(objDir)$@   $(ccflag)
	
buildDir:
	@mkdir -p $(objDir)
	@mkdir -p $(binDir)