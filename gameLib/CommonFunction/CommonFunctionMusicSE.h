#pragma once
#include "../th5DatFile/th5DatFile.h"
#include "../PMDPlayer/PMDPlayer.h"

namespace th5w{

class CCommonFunctionMusicSE
{
public:
	static bool LoadMusicToPMDFromDat(Cth5DatFile *pDatFile,char *musicFileName);
	static bool LoadMusicFromDat(Cth5DatFile *pDatFile, char *musicFileName);
	static bool Play();
public:
	CCommonFunctionMusicSE(void);
	~CCommonFunctionMusicSE(void);
};

}
