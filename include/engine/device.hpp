/*
    <one line to give the library's name and an idea of what it does.>
    Copyright (C) 2012  David Cavazos <davido262@gmail.com>

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/


#ifndef DEVICE_HPP
#define DEVICE_HPP

#include <string>
#include "inputmanager.hpp"

enum device_t {
    DEVICE_SDL_OPENGL_LEGACY,
    DEVICE_SDL_OPENGL_CORE
};

class DeviceManager;

class Device {
friend class DeviceManager;
public:
    Device();
    virtual ~Device() {}

    InputManager& getInputManager();

    virtual size_t videoMemKB() = 0;
    virtual void setTitle(const std::string& title) = 0;
    virtual void setFullscreen(const bool useFullscreen = true) = 0;
    virtual void setResolution(const size_t width, const size_t height) = 0;
    virtual void processEvents(bool& isRunning) = 0;
    virtual void getPointerInfo(int& x, int& y) = 0;

protected:
    size_t m_width;
    size_t m_height;
    size_t m_depth;
    static InputManager ms_inputManager;

    virtual void initialize() = 0;
    virtual void shutdown() = 0;
};



inline InputManager& Device::getInputManager() {
    return ms_inputManager;
}

#endif // DEVICE_HPP