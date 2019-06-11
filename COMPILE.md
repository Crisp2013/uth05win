# Compile
*Currently uth05win only supports windows x86 platforms only.* 
  
## Windows (x86)
### Dependencies
* Visual Studio 2015 (or 2017 with 2015 buildTools) [Download](https://visualstudio.com)
* GLEW 2.1.0 (OpenGL) [SourceForge](http://glew.sourceforge.net)
* GuruGuruSMF4 [Download](https://www.vector.co.jp/soft/dl/win95/prog/se302066.html)
* PMDWin [Download](http://c60.la.coocan.jp/)
* PMDWin SDK [Download](http://c60.la.coocan.jp/)

## Compiling
1. Create folder called lib in the root of the repository
2. Download each library dependencies (glew, guruguruSMF4, PMDWinSDK) into lib directory.
  * GuruGuruSMF4.lib -> lib/
  * glew32.lib -> lib/
  * glew32s.lib -> lib/
  * PMDWin.lib -> lib/
3. Download extra dependencies (glew, guruguruSMF4, PMDWin) into root directory.
  * GuruGuruSMF4.dll -> /
  * glew32.dll -> /
  * PMDWin.dll -> /
4. Place original game files (怪綺談1.dat, 怪綺談2.dat, MUSIC.dat and ZUN.com) to the root directory.
  * 怪綺談1.dat -> kaiki1.dat
  * 怪綺談2.dat -> kaiki2.dat
  * MUSIC.dat -> MUSIC.dat
  * ZUN.com -> ZUN.com
5. Open Solution (rt5sandbox.sln)
6. Build it.

## Troubleshooting

### I got an error LNK1104: can not open 'lib/glew32s.lib' while compiling
Create directory lib at root if you don't have, and download glew library from [Here](http://glew.sourceforge.net/) Preferably 2.1.0 (latest version in 2019-01-28) for Win32. extract the archive and copy the glew32s.lib (located at glew-2.1.0/lib/Release/Win32) and paste it into lib directory. and also, copy the glew32.dll (located at glew-2.1.0/bin/Release/Win32) and paste it into root of the repository.

### I got an error LNK1104: can not open 'lib/GuruGuruSMF4.lib' while compiling
go to lib directory at root and download [GuruGuruSMF4]( https://www.vector.co.jp/soft/dl/win95/prog/se302066.html) (Japanese), (Click Green ダウンロードページヘ Button), Copy the GuruGuruSMF4.lib to lib directory and Copy the GuruGuruSMF4.dll to root of the repository.

### I got an error LNK1104: can not open 'lib/glew32.lib' while compiling
Create directory lib at root if you don't have, and download glew library from [Here](http://glew.sourceforge.net/) Preferably 2.1.0 (latest version in 2019-01-28) for Win32. extract the archive and copy the glew32.lib (located at glew-2.1.0/lib/Release/Win32) and paste it into lib directory. and also, copy the glew32.dll (located at glew-2.1.0/bin/Release/Win32) and paste it into root of the repository.

### I got an error LNK1104: can not open 'lib/PMDWin.lib' while compiling
Create directory lib at root if you don't have, and download [PMDWin SDK](http://c60.la.coocan.jp/) (Japanese). extract the archive and copy the PMDWin.lib (located at PMDWin/) to lib directory.

### rt5sandbox.exe gives me an error saying GuruGuruSMF4.dll is missing.
download [GuruGuruSMF4]( https://www.vector.co.jp/soft/dl/win95/prog/se302066.html) (Japanese), (Click Green ダウンロードページヘ Button), Copy the GuruGuruSMF4.dll to root of the repository.

### rt5sandbox.exe gives me an error saying glew32.dll is missing.
download glew library from [Here](http://glew.sourceforge.net/) Preferably 2.1.0 (latest version in 2019-01-28) for Win32. extract the archive and copy the glew32.dll (located at glew-2.1.0/bin/Release/Win32) and paste it into root of the repository.

### rt5sandbox.exe gives me an error saying PMDWin.exe is missing.
download [PMDWin](http://c60.la.coocan.jp/) (Japanese). since the archive is using legacy lzh format, you will need a third-party extractor (such as 7-zip) copy the PMDWin.dll and paste it into root of the repository.

### I got weird "ファイルが書き込めないの～" error and it is not running the game. what is this?
Original Game file dependencies are missing, if you are after the commit [0078a033](https://github.com/Wintiger0222/uth05win/commit/0078a033d9df42b4b67dc9720766e9263e6170ac), you can run the project as Debug mode and find out which file is missing by clicking OK button at the error message.
