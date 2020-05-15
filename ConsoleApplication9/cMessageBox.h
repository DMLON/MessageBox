#pragma once
#include <Windows.h>
//#include <WinUser.h>
#include <string>
#include <iostream>
using namespace std;


class cMessageBox {
private:
	static wstring ConvertWstringToString(string buffer) {
		wstring buff(buffer.length(), L' ');
		std::copy(buffer.begin(), buffer.end(), buff.begin());
		return buff;
	}
public:
	enum class DialogResult { Ok = IDOK, Yes = IDYES, No = IDNO, Abort = IDABORT, Retry = IDRETRY, Ignore = IDIGNORE, Cancel = IDCANCEL, Continue = IDCONTINUE, TryAgain = IDTRYAGAIN };
	enum class MessageBoxButton { Ok = MB_OK, OkCancel = MB_OKCANCEL, AbortRetryIgnore = MB_ABORTRETRYIGNORE, CancelTryContinue = MB_CANCELTRYCONTINUE, YesNo = MB_YESNO, YesNoCancel = MB_YESNOCANCEL };
	enum class MessageBoxIcon { Question = MB_ICONQUESTION, Warning = MB_ICONEXCLAMATION, Information = MB_ICONINFORMATION, Error = MB_ICONERROR };
	static DialogResult Show(string Message, string Title, MessageBoxButton Buttons, MessageBoxIcon Icon) {
		auto Result = MessageBox(NULL, ConvertWstringToString(Message).c_str(), ConvertWstringToString(Title).c_str(), (unsigned int)Buttons | (unsigned int)Icon); //MB_OK 
		return DialogResult(Result);
	}
};
