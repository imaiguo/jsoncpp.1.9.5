
# build on Windows use MSVC

```bash
> cmd
> vcvars64
> mkdir build & cd build
> cmake .. -G Ninja -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=D:\devtools\jsoncpp.1.9.5
> ninja
> ninja install
```