
#include <Je.h>
#include <Je/EntryPoint.h>

namespace Pg
{
	class Playground final : public Je::Application
	{
	};
}

Je::Application* Je::CreateApplication()
{
	return new Pg::Playground();
}
