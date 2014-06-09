#include "Engine.h"

Scene* Engine::active_scene = 0;
MapScene* Engine::map_scene = 0;
SFPlayer Engine::music_player;
SFPlayer Engine::world_sounds;
SFPlayer Engine::cry_player;

unsigned char Engine::game_state = 0;

void Engine::Initialize()
{
	ResourceCache::LoadAll();
	Players::Initialize();
	InitializeAudio();

	//Initialize the scenes
	map_scene = new MapScene();

	SwitchState(States::OVERWORLD);

}

void Engine::Update()
{
	active_scene->Update();
	music_player.Update();
	world_sounds.Update();
	cry_player.Update();
}

void Engine::Render(sf::RenderWindow* window)
{
	active_scene->Render(window);
}

void Engine::SwitchState(unsigned char s)
{
	game_state = s;
	switch (game_state)
	{
	case States::OVERWORLD:
		active_scene = (Scene*)map_scene;
		break;
	}

	active_scene->NotifySwitchedTo();
}

void Engine::Release()
{
	if (map_scene)
	{
		delete map_scene;
		map_scene = 0;
	}
	music_player.Close();
	world_sounds.Close();
}

void Engine::InitializeAudio()
{
	const char* err = music_player.Initialize(ResourceCache::GetResourceLocation(string("audio/music.gbs")).c_str());
	if (err)
	{
#ifdef _DEBUG
		std::cout << "Failed to start music player. " << err << "\n";
#endif
	}
	music_player.SetVolume(70.0f); //it really overpowers stuff

	err = world_sounds.Initialize(ResourceCache::GetResourceLocation(string("audio/world.gbs")).c_str(), true);
	if (err)
	{
#ifdef _DEBUG
		std::cout << "Failed to start world sounds player. " << err << "\n";
#endif
	}

	err = cry_player.Initialize(ResourceCache::GetResourceLocation(string("audio/cries.gbs")).c_str(), true);
	if (err)
	{
#ifdef _DEBUG
		std::cout << "Failed to start cries player. " << err << "\n";
#endif
	}

	/*err = music_player.LoadFile(ResourceCache::GetResourceLocation(string("audio/music.gbs")).c_str());
	if (err)
	{
#ifdef _DEBUG
		std::cout << "Failed to load music. " << err << "\n";
#endif
		return;
	}*/

	music_player.Play(0);
}
