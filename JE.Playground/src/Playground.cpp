
#include <Je.h>

namespace Pg
{
	class Playground : public Je::Application
	{
	};
}

Je::Application* Je::CreateApplication()
{
	return new Pg::Playground();
}
