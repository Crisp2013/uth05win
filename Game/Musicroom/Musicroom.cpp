#include ".\MusicRoom.h"
#include "../Game.h"
#include "../../gameLib/CommonFunction/CommonFunctionInput.h"
#include "../../gameLib/CommonFunction/CommonFunctionGraphic.h"
#include "../../gameLib/CommonFunction/CommonFunctionMusicSE.h"
#include "../../gameLib/Graphic/PC98Font.h"
#include "../../gameLib/Graphic/Th5ExtFont.h"
#include <time.h>
#include <math.h>
#include <shlwapi.h>
#include <tchar.h>
#define PI 3.1415926535897932384626433832795
//#define SEL_QUIT TRACK_COUNT + 1
#define MUSIC_POLYGONS 16

namespace th5w {
	char MusicRoom_TH[][40] = { "   ζPe?ϋθΛΩ?  Arrange ver  ",
								"   ζQe?ϋ?  Special MIX  ",
								"   ζRe?ϋ²σ  Special MIX  ",
								"   ζSe?ϋΆz½  Special MIX  ",
								"   ζTe?ϋφ?k MysticSquare  " };
	int music_count[] = { 14+1,18+1,24+1,28+1,23+1 };
	
	char TH01_Title[][40] =    {"No.1           A Sacred Lot         ",
								"No.2            iΜή          ",
								"No.3    The Positive and Negative   ",
								"No.4   Highly Responsive to Prayers ",
								"No.5            ϋφοk          ",
								"No.6             Vg?ΰ           ",
								"No.7        Oriental Magician       ",
								"No.8           jΧΜ¬Ύ         ",
								"No.9               Ύ             ",
								"No.10       the Legend of KAGE      ",
								"No.11    ’΄A?κΐ­»ΜάΕ   ",
								"No.12      Civilization of Magic    ",
								"No.13            ―HVg           ",
								"No.14            ACX           ",
								"            ?CgΙίι          ",
								""};
	char TH02_Title[][40] =    {"No.1      ϋ???ςyΦδΆ  ",
								"No.2      ? ν??Eastern Wind   ",
								"No.3      ?  She's in a temper!!   ",
								"No.4      ?   End of Daylight?    ",
								"No.5      ?  ? βέΜΏ©η??   ",
								"No.6      ?????Ά²E????  ",
								"No.7      ?????πq΅Δ???  ",
								"No.8      Πΰλ¬Aήη³«Ιΰ¦  ",
								"No.9      ?  ? φF?WbN ?    ",
								"No.10     ?ϋ???HΆ  ",
								"No.11         Complete Darkness     ",
								"No.12        ? GLXgu      ",
								"No.13        νΤή·ίΜέιδί   ",
								"No.14          ??μΜX???   ",
								"No.15         ΜbνρΎ?ηρΗ    ",
								"’gp.1         ν?Π«ΰ       ",
								"’gp.2         ?zΏΔ  ?     ",
								"’gp.3         ?I  ?     ",
								"              ?CgΙίι        " };
	char TH03_Title[][40] =   { "No.1       ?²Νσπz¦Δ       ",
								"No.2      ? ? Selection           ",
								"No.3            ϋdφk          ",
								"No.4          Reincarnation         ",
								"No.5            Dim. Dream          ",
								"No.6     Tabula rasa??σ­    ",
								"No.7     ?  Maniacal Princess      ",
								"No.8        ²ΑΈ  ?Lost Dream    ",
								"No.9       ²ΆVY  ?Dream War    ",
								"No.10    ?νI?Fight it out!  ",
								"No.11      ? Sailor of Time        ",
								"No.12       Strawberry Crisis!!     ",
								"No.13        ρκ?’E?       ",
								"No.14          ??ΰ€           ",
								"No.15          ?vΜ²           ",
								"No.16          ϋΜΒ’σ         ",
								"No.17           iΜ          ",
								"No.18         Maple Dream...        ",
								"No.19           μlΜxϊ          ",	
								"No.20            f           ",
								"No.21         Q??I?o?        ",
								"’gp.1          Μ            ",
								"’gp.2     X???Eh??     ",
								"’gp.3       Phantasmagoria       ",
								"              ?CgΙίι        "};
	char TH04_Title[][40] = {	"No.1    Άz½  ? Lotus Land Story ",
								"No.2          Witching Dream        ",
								"No.3          Selene's light        ",
								"No.4   όν?? Decoration Battle ",
								"No.5         Break the Sabbath      ",
								"No.6    gΏΘ  ? Scarlet Phoneme  ",
								"No.7            Bad Apple!!         ",
								"No.8     μν?? Perdition crisis  ",
								"No.9         AX?GXe       ",
								"No.10    ­?zΘ?? Capriccio   ",
								"No.11   ―Μν?? Casket of Star   ",
								"No.12           Lotus Love          ",
								"No.13  °κι°? ?Sleeping Terror ",
								"No.14           Dream Land          ",
								"No.15    H²?? Inanimate Dream   ",
								"No.16      ΦΆ΄ιπ¦Θ’VY     ",
								"No.17  ChΆz?? Icemilk Magic ",
								"No.18   ©ν’’«?? Innocence  ",
								"No.19              Days             ",
								"No.20            Peaceful           ",
								"No.21         Arcadian Dream        ",
								"No.22           ΆzΜZl          ",
								"’gp.1        Lotus Road          ",
								"’gp.2       Dreamy pilot         ",
								"’gp.3      Incomplete Plot       ",
								"’gp.4        Border Land         ",
								"’gp.5   Magic Shop of Raspberry  ",
								"’gp.6       Crescent Dream       ",
								"              ?CgΙίι        " };
	char TH05_Title[][40] = {	"No.1     φ?k?? Mystic Square   ",
								"No.2           Dream Express        ",
								"No.3      ?w?? Magic Square   ",
								"No.4             ²zσ           ",
								"No.5     μV?? Spiritual Heaven  ",
								"No.6         Romantic Children      ",
								"No.7       vX?bN?Ch     ",
								"No.8          CvCY        ",
								"No.9  ΦfΜ?  ? Forbidden Magic",
								"No.10  ?gΜ­?? Crimson Dead!!",
								"No.11   ΨθΜ­?? Judas Kiss  ",
								"No.12       the Last Judgement      ",
								"No.13  ί΅«l??? Doll of Misery",
								"No.14   ’EΜΚΔ?? World's End  ",
								"No.15   ?bΆz?? Infinite Being ",
								"No.16       svcΜΜAX      ",
								"No.17     the Grimoire of Alice     ",
								"No.18              ?Π             ",
								"No.19            Endless            ",
								"No.20          vΜy?           ",
								"No.21         Mystic Dream          ",
								"No.22       Peaceful Romancer       ",
								"No.23         °Μxηή          ",
								"              ?CgΙίι        " };						
	CMusicRoom::CMusicRoom(void)
	{
		m_pBGImage = NULL;
		m_bEnterNameMode = false;
	}

	CMusicRoom::~CMusicRoom(void)
	{
		if (m_pBGImage)
			m_pBGImage->Destroy();
		m_pBGImage = NULL;
	}

	void CMusicRoom::Initialize()
	{
		m_curFrame = 0;
		m_lastKeyState = 0;
		m_curKeyState = 0;
		m_bQuit = false;
		m_curScrFade = 0;

		m_nFilePerPage = 16;
		m_nPage = 5;
		m_listUpperLeftX = 2;
		m_listUpperLeftY = 6;
		SwitchPage(4);
		m_curCursorPos = 0;
		m_curListTop = 0;

		CCommonFunctionGraphic::LoadPIFromDat(&m_pBGImage, NULL, &CGame::s_pCurGame->m_th5Dat1, "MUSIC.PI");
	}

	void CMusicRoom::SwitchPage(int pageIdx)
	{
		m_curPage = pageIdx;
		m_curCursorPos = 0;
		m_curListTop = 0;
		Playmusic();
	}

	void CMusicRoom::Playmusic()
	{
	//	m_nnowPlayingTitle = m_curPage;
		m_nnowPlayingNumber = m_curCursorPos;
	}

	int CMusicRoom::Step()
	{
		m_curFrame++;

		if (m_bQuit)
		{
			if (m_curScrFade > 0)
			{
				m_curScrFade -= 6;
				if (m_curScrFade < 0)
					m_curScrFade = 0;
				return 0;
			}
			else
				return m_quitCode;
		}

		if (m_curScrFade < 100)
		{
		/*	m_curScrFade += 6;
			if (m_curScrFade > 100)*/
				m_curScrFade = 100;
			return 0;
		}

		m_lastKeyState = m_curKeyState;
		m_curKeyState = CCommonFunctionInput::GetAllKeyState();


		if (CCommonFunctionInput::LeftPressed(m_curKeyState, m_lastKeyState))
		{
			SwitchPage((m_curPage + m_nPage - 1) % m_nPage);
		}
		if (CCommonFunctionInput::RightPressed(m_curKeyState, m_lastKeyState))
		{
			SwitchPage((m_curPage + 1) % m_nPage);
		}
		if (CCommonFunctionInput::UpPressed(m_curKeyState, m_lastKeyState))
		{
			m_curCursorPos = (m_curCursorPos + music_count[m_curPage]-1) % (music_count[m_curPage]);
			if (m_curCursorPos < m_curListTop )
				m_curListTop--;
			if ((m_curCursorPos == music_count[m_curPage]-1)&&(m_curPage!=0))
				m_curListTop = music_count[m_curPage]- m_nFilePerPage;

		}
		if (CCommonFunctionInput::DownPressed(m_curKeyState, m_lastKeyState))
		{
			m_curCursorPos = (m_curCursorPos + 1) % (music_count[m_curPage]);
			if (m_curCursorPos == 0)
				m_curListTop = 0;
			if (m_curCursorPos > m_curListTop + m_nFilePerPage -1)
				m_curListTop++;
		}
		if (CCommonFunctionInput::ESCPressed(m_curKeyState, m_lastKeyState)
			|| CCommonFunctionInput::XPressed(m_curKeyState, m_lastKeyState))
		{
			m_bQuit = true;
			m_quitCode = MUSICROOM_END_BACK;
		}
		if (CCommonFunctionInput::ZPressed(m_curKeyState, m_lastKeyState))
		{
			if (music_count[m_curPage] - 1 == m_curCursorPos )
			{
				m_bQuit = true;
				m_quitCode = MUSICROOM_END_BACK;
			}
			else
			{
				Playmusic();
			}
		}
		return 0;
	}

	void CMusicRoom::Draw()
	{
		glClearColor(0, 0, 0, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		if (m_curScrFade == 0)
			return;

		m_pBGImage->Draw(0,0);
		m_pBGImage->Draw(0, 80);
		CCommonFunctionGraphic::DrawRectangle(8, 108, 40,140, 0.19921875f, 0.0f, 0.3984375f);
		CCommonFunctionGraphic::DrawRectangle(284, 108, 316, 140, 0.19921875f, 0.0f, 0.3984375f);

		char strBuf[100];
		float text_color[] = { 1.0f,0.796875f,1.0f };
		float white_color[] = { 1.0f,1.0f,1.0f };
		float list_color[] = { 0.7265625f,0.7265625f,1.0f };
		CPC98Font::DrawString(MusicRoom_TH[m_curPage], 100, 8, 32, white_color[0], white_color[1], white_color[2]);
		CPC98Font::DrawString(MusicRoom_TH[m_curPage], 100, 8 - 1, 32, white_color[0], white_color[1], white_color[2]);
		switch (m_curPage)
		{
		case 0:
			sprintf(strBuf, "%s", TH01_Title[m_nnowPlayingNumber]);
			break;
		case 1:
			sprintf(strBuf, "%s", TH02_Title[m_nnowPlayingNumber]);
			break;
		case 2:
			sprintf(strBuf, "%s", TH03_Title[m_nnowPlayingNumber]);
			break;
		case 3:
			sprintf(strBuf, "%s", TH04_Title[m_nnowPlayingNumber]);
			break;
		case 4:
			sprintf(strBuf, "%s", TH05_Title[m_nnowPlayingNumber]);
			break;
		}
		CPC98Font::DrawString(strBuf, 100, 320, 32, text_color[0], text_color[1], text_color[2]);
		CPC98Font::DrawString(strBuf, 100, 320 - 1, 32, text_color[0], text_color[1], text_color[2]);

		
		for (int i = 0; i < m_nFilePerPage; i++)
		{
			int x = m_listUpperLeftX * 8;
			int y = (m_listUpperLeftY + i) * 16;
			

			float color[] = { 0.5f,1.0f,0.5f };
			float sc[] = { 0.2f,0.2f,0.2f };
			float salpha = 0.5f;
			int soffx = 2, soffy = 2;
			switch (m_curPage)
			{
			case 0:
				sprintf(strBuf, "%s", TH01_Title[i + m_curListTop]);
				break;
			case 1:
				sprintf(strBuf, "%s", TH02_Title[i + m_curListTop]);
				break;
			case 2:
				sprintf(strBuf, "%s", TH03_Title[i + m_curListTop]);
				break;
			case 3:
				sprintf(strBuf, "%s", TH04_Title[i + m_curListTop]);
				break;
			case 4:
				sprintf(strBuf, "%s", TH05_Title[i + m_curListTop]);
				break;
			}
			if (i + m_curListTop == m_curCursorPos)
			{
				CPC98Font::DrawString(strBuf, 100, x, y, white_color[0], white_color[1], white_color[2]);
				CPC98Font::DrawString(strBuf, 100, x - 1, y, white_color[0], white_color[1], white_color[2]);
			}
			else
			{
				CPC98Font::DrawString(strBuf, 100, x, y, list_color[0], list_color[1], list_color[2]);
				CPC98Font::DrawString(strBuf, 100, x - 1, y, list_color[0], list_color[1], list_color[2]);
			}

			x += 6 * 8;

			}
		}

	}






















