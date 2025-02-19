//вариант асинхронного запуска внешнего исполняемого файла с двумя параметрами
//================================================================================================
if (fileExt != ".bmp") {
	// путь к exe-файлу и аргументы командной строки
	const wchar_t* filePath = L"magick";
	AnsiString QuoteFname = AnsiString("\"") + fname1 + "\"";
	UnicodeString argsAS = QuoteFname + L" C:\\Windows\\Temp\\atlas_foto.bmp";
	const wchar_t* args = argsAS.w_str();
	// Запусk процесс с помощью ShellExecute
	HINSTANCE hInst = ShellExecuteW(NULL, NULL, filePath, args, NULL, SW_SHOW);
	if (hInst <= (HINSTANCE)32)
	{
		// Если ShellExecute вернула значение <= 32, выведите сообщение об ошибке
		ShowMessage("Ошибка при загрузке файла.");
		return;
	}
}


//вариант синхронного запуска внешнего исполняемого файла(команды) с двумя параметрами с ожиданием полного исполнения и завершения работы команды и ее процессса
//=================================================================================================================================================================
if (fileExt != ".bmp") {
	UnicodeString filePath1 = L"magick";
	AnsiString QuoteFname = AnsiString("\"") + fname1 + "\"";
	UnicodeString argsAS = QuoteFname + L" C:\\Windows\\Temp\\atlas_foto.bmp";

	// Преобразуем аргументы в C-строку
	wchar_t* commandLine = (filePath1 + L" " + argsAS).w_str();

	STARTUPINFO si = { sizeof(si) };
	PROCESS_INFORMATION pi;
	if (CreateProcess(nullptr,   // Имя модуля (nullptr значит использовать командную строку)
		commandLine,             // Командная строка
		nullptr,                 // Процесс безопасности
		nullptr,                 // Поток безопасности
		FALSE,                   // Не наследовать дескрипторы
		0,                       // Флаги создания
		nullptr,                 // Переменные окружения
		nullptr,                 // Текущая директория
		&si,                     // Структура информации о запуске
		&pi       ))
	{
		WaitForSingleObject(pi.hProcess, INFINITE);

		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}
}
