#pragma once

#include "Factories/IMusicFactory.hpp"
#include "Models/IMusic.hpp"
#include <memory>
#include <string>
#include <map>

namespace Arc {
    class NCursesMusicFactory : public Shared::Factories::IMusicFactory {
        public:
            NCursesMusicFactory() = default;
            ~NCursesMusicFactory() = default;

            std::shared_ptr<Shared::Models::IMusic> create() override;
            void load(std::string path) override;
        
        private:
            std::map<std::string, std::string> _loadedMusic;
    };
}