/******************************************************************************
 * 
 * Copyright (C) 2023 Dmitry Plastinin
 * Contact: uncellon@yandex.ru, uncellon@gmail.com, uncellon@mail.ru
 * 
 * This file is part of the UT Logger library.
 * 
 * UT Logger is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License as pubblished by the
 * Free Software Foundation, either version 3 of the License, or (at your 
 * option) any later version.
 * 
 * UT Logger is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or 
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for more
 * details
 * 
 * You should have received a copy of the GNU Lesset General Public License
 * along with UT Logger. If not, see <https://www.gnu.org/licenses/>.
 * 
 *****************************************************************************/

#ifndef UT_TERMINAL_LOGGER_HANDLER_H
#define UT_TERMINAL_LOGGER_HANDLER_H

#include "abstractloggerhandler.h"

#include <iostream>

namespace UT {

class TerminalLoggerHandler : public AbstractLoggerHandler {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual void write(const std::string& message) override {
        std::cout << message << std::endl;
    }

}; // class TerminalLoggerHandler

} // namespace UT

#endif // UT_TERMINAL_LOGGER_HANDLER_H