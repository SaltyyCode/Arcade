/*
** EPITECH PROJECT, 2024
** OOP
** File description:
** Arcade project
*/

#pragma once

#include <string>
#include <memory>
#include <dlfcn.h>
#include <vector>
#include <filesystem>
#include "LibraryType.hpp"

namespace Arc
{
class LibraryObject
{
public:
    LibraryObject(const std::string &path) : _path(path)
    {
        _handle = dlopen(path.c_str(), RTLD_LAZY);
        if (_handle == nullptr) {
            std::cerr << dlerror() << std::endl;
            return;
        }
        auto nameh = reinterpret_cast<const char *(*)()>(dlsym(_handle, "name"));
        if (nameh == nullptr) {
            std::cerr << dlerror() << std::endl;
            return;
        }
        _name = nameh();
        auto typeh = reinterpret_cast<LibraryType::Ltype (*)()>(dlsym(_handle, "type"));
        if (typeh == nullptr) {
            std::cerr << dlerror() << std::endl;
            return;
        }
        _type = typeh();
        _loaded = true;
    };

    ~LibraryObject()
    {
        if (_handle)
            dlclose(_handle);
    };

    template<typename T>
    std::shared_ptr<T> get()
    {
        if (_loaded == false)
            return nullptr;
        auto h = reinterpret_cast<T *(*)()>(dlsym(_handle, "entryPoint"));
        if (h == nullptr) {
            std::cerr << dlerror() << std::endl;
            return nullptr;
        }
        return std::shared_ptr<T>(h());
    };

    bool isLoaded() { return _loaded; };
    std::string &path() { return _path; };
    std::string &name() { return _name; };
    LibraryType::Ltype &type() { return _type; };

private:
    bool _loaded = false;
    std::string _path = "";
    std::string _name = "";
    LibraryType::Ltype _type = LibraryType::UNKNOWN;
    void *_handle = nullptr;
};

class LibraryLoader
{
public:
    LibraryLoader(const std::string &path, bool tty)
    {
        if (std::filesystem::exists(path) == false)
            return;
        for (const auto &entry : std::filesystem::directory_iterator(path)) {
            auto obj = std::make_shared<LibraryObject>(entry.path().string());
            if (tty && obj->type() == LibraryType::GRAPHIC && obj->name() != "NCurses")
                continue;
            if (obj->isLoaded() == true)
                _libs.push_back(obj);
        }
    };
    ~LibraryLoader() = default;
    std::shared_ptr<LibraryObject> load(const std::string &path, const LibraryType::Ltype &type)
    {
        for (auto lib : _libs) {
            if (lib->path() == path && lib->type() == type)
                return lib;
        }
        return nullptr;
    };

    std::vector<std::shared_ptr<LibraryObject>> getLibs() const { return _libs; };
private:
    std::vector<std::shared_ptr<LibraryObject>> _libs = {};
};
} // namespace Arc
