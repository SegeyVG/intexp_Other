//������� ������������ ������� �������� ������������ ����� � ����� �����������
//================================================================================================
if (fileExt != ".bmp") {
	// ���� � exe-����� � ��������� ��������� ������
	const wchar_t* filePath = L"magick";
	AnsiString QuoteFname = AnsiString("\"") + fname1 + "\"";
	UnicodeString argsAS = QuoteFname + L" C:\\Windows\\Temp\\atlas_foto.bmp";
	const wchar_t* args = argsAS.w_str();
	// �����k ������� � ������� ShellExecute
	HINSTANCE hInst = ShellExecuteW(NULL, NULL, filePath, args, NULL, SW_SHOW);
	if (hInst <= (HINSTANCE)32)
	{
		// ���� ShellExecute ������� �������� <= 32, �������� ��������� �� ������
		ShowMessage("������ ��� �������� �����.");
		return;
	}
}


//������� ����������� ������� �������� ������������ �����(�������) � ����� ����������� � ��������� ������� ���������� � ���������� ������ ������� � �� ���������
//=================================================================================================================================================================
if (fileExt != ".bmp") {
	UnicodeString filePath1 = L"magick";
	AnsiString QuoteFname = AnsiString("\"") + fname1 + "\"";
	UnicodeString argsAS = QuoteFname + L" C:\\Windows\\Temp\\atlas_foto.bmp";

	// ����������� ��������� � C-������
	wchar_t* commandLine = (filePath1 + L" " + argsAS).w_str();

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(nullptr,   // ��� ������ (nullptr ������ ������������ ��������� ������)
		commandLine,             // ��������� ������
		nullptr,                 // ������� ������������
		nullptr,                 // ����� ������������
		FALSE,                   // �� ����������� �����������
		0,                       // ����� ��������
		nullptr,                 // ���������� ���������
		nullptr,                 // ������� ����������
		&si,                     // ��������� ���������� � �������
		&pi       ))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}
