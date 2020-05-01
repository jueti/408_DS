# Static Array

可以用的编译方法太多了，如下所示：

**msbuild (Debug)**

```powershell
msbuild
```

**msbuild (Release)**

```powershell
msbuild -p:Configuration=Release
```

**msbuild (Debug)(clean)**

```powershell
msbuild -t:clean
```

**msbuild (Release)(clean)**

```powershell
msbuild -p:Configuration=Release -t:clean
```

**nmake (Release)**

```powershell
nmake
```

**nmake (clean)**

```powershell
nmake clean
```

**devenv (Debug)(build)**

```powershell
devenv static_array.sln /build
```

**devenv (Release)(build)**

```powershell
devenv static_array.sln /build Release
```

**devenv (Debug)(clean)**

```powershell
devenv static_array.sln /Clean
```

**devenv (Release)(clean)**

```powershell
devenv static_array.sln /Clean Release
```
