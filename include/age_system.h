#ifndef AAPPLICATION_H
#define AAPPLICATION_H
#include <QApplication>
#include <../include/age_widget.h>
#include <../include/age_luawidget.h>
#define AGE_NATIVE 0
#define AGE_LUA 1
namespace AGE2D
{

enum SystemID
{
    WINDOWS = 1,
    ANDROID_BUILT_IN = 2,
    ANDROID_EXTERNAL_STORAGE = 3,
    ANDROID_MOUNT_DISK=4,
    IOS = 5,
    MAC = 6,
    LINUX = 7
};
class ASystem
{
public:
    static void Init(int argc, char *argv[],int init_mode=0);
	static int Go();
	static void SetSize(int width, int height);

	static int Random(int min,int max);
    static QTextEdit * GetLuaEdit();
	static int GetWidth();
	static int GetHeight();
	static int GetWidthOffset();
	static int GetHeightOffset();
	static AWidget * GetWidget();
	static int IsEngineInitialized();
	static int TimeStep();
	static double FrameRate();
    static void ShowLuaEdit();
    static void HideLuaEdit();
    static void AddDebugInfo(QString str);
    static void SetLuaEditSize(int x,int y);
	friend class AWidget;
    static QString Path(const char * str);
    static QString Path(QString str);
    static int GetExecuteMode();
private:
	ASystem();
    static int execute_mode;
	static int m_width;
	static int m_height;
	static int m_widthOffset;
	static int m_heightOffset;
	static bool is_init;
	static QApplication * m_application;
	static AWidget * m_widget;
    static QTextEdit * m_lua_textEdit;
    static QString m_debug_string;
    static int system_id;
};
}
#endif // AAPPLICATION_H





