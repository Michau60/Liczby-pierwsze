#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
// [STAThread]

int main(array<System::String^>^ args)
{
	// Enabling Windows XP visual effects before any controls are created

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Create the main window and run it

	Dyn::MyForm form;
	Application::Run(% form);

	return 0;
}