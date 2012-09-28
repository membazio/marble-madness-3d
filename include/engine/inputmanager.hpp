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


#ifndef INPUTMANAGER_HPP
#define INPUTMANAGER_HPP

#include <ostream>
#include <string>
#include <vector>
#include <map>
#include "command.hpp"

typedef enum {
    INPUT_KEY_DOWN,
    INPUT_KEY_UP,
    INPUT_MOUSE_BUTTON_DOWN,
    INPUT_MOUSE_BUTTON_UP,
    INPUT_MOUSE_MOTION
} input_t;

typedef struct {
    int x;
    int y;
    int xrel;
    int yrel;
} mouse_motion_t;

class InputManager {
public:
    InputManager();
    friend std::ostream& operator<<(std::ostream& out, const InputManager& rhs);

    const mouse_motion_t& getLastMouseMotion();

    void bindInput(const input_t type, const std::string& command, const size_t code = 0);
    void clearAllBindings();
    void onKeyDown(const size_t code);
    void onKeyUp(const size_t code);
    void onMouseButtonDown(const size_t code);
    void onMouseButtonUp(const size_t code);
    void onMouseMotion(const mouse_motion_t& motion);

private:
    typedef std::map<size_t, Command> input_map_t;
    input_map_t m_keyDownMap;
    input_map_t m_keyUpMap;
    input_map_t m_mouseButtonDownMap;
    input_map_t m_mouseButtonUpMap;
    std::vector<Command> m_mouseMotionList;
    mouse_motion_t m_lastMouseMotion;
};



inline const mouse_motion_t& InputManager::getLastMouseMotion() {
    return m_lastMouseMotion;
}

#endif // INPUTMANAGER_HPP