#include "MyForm.h"

namespace FarkleUI {
	// Helper function to load resources
	System::Drawing::Bitmap^ LoadResourceImage(String^ name) {

		try {
			// Get resource manager
			System::Resources::ResourceManager^ rm = gcnew System::Resources::ResourceManager(
				L"FarkleUI.Resource",
				System::Reflection::Assembly::GetExecutingAssembly());

			// Get byte array
			array<unsigned char>^ byteArray = (array<unsigned char>^)rm->GetObject(name);

			if (byteArray == nullptr || byteArray->Length == 0)
			{
				throw gcnew Exception("Resource '" + name + "' not found or empty");
			}

			// Convert bytes to bitmap
			System::IO::MemoryStream^ stream = gcnew System::IO::MemoryStream(byteArray);
			System::Drawing::Bitmap^ bitmap = gcnew System::Drawing::Bitmap(stream);
			return bitmap;
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Error loading '" + name + "': " + e->Message);
			// Return red placeholder if image fails to load
			System::Drawing::Bitmap^ placeholder = gcnew System::Drawing::Bitmap(90, 90);
			System::Drawing::Graphics^ g = System::Drawing::Graphics::FromImage(placeholder);
			g->FillRectangle(System::Drawing::Brushes::Red, 0, 0, 90, 90);
			return placeholder;
		}
	}
}

