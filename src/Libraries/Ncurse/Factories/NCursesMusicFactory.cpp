#include "Factories/NCursesMusicFactory.hpp"
#include "Models/NCursesMusic.hpp"

namespace Arc {

    void NCursesMusicFactory::load(std::string path)
    {
        if (_loadedMusic.find(path) == _loadedMusic.end()) {
            _loadedMusic[path] = path;
        }
    }
    
    std::shared_ptr<Shared::Models::IMusic> NCursesMusicFactory::create()
    {
        return std::make_shared<NCursesMusic>();
    }
}