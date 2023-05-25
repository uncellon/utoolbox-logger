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

#ifndef HLK_LOGGER_H
#define HLK_LOGGER_H

#include "abstractloggerhandler.h"
#include "abstractmessagelayout.h"

#include <map>
#include <mutex>
#include <vector>
#include <memory>
#include <any>

namespace UT {

class Logger {
public:
    struct Log {
        std::shared_ptr<AbstractMessageLayout> layout;
        std::vector<std::shared_ptr<AbstractLoggerHandler>> handlers;
    };

    /**************************************************************************
     * Constructors / Destructors
     *************************************************************************/

    Logger() {
        // m_layout = std::shared_ptr<TMessageLayout>(new TMessageLayout());
    }

    ~Logger() {
        mHandlers.clear();
    }

    /**************************************************************************
     * Methods
     *************************************************************************/

    static void create(
        const std::string& name, 
        std::shared_ptr<AbstractMessageLayout> layout, 
        std::vector<std::shared_ptr<AbstractLoggerHandler>> handlers) {
        mLoggersByNames[name] = { layout, handlers };
    }

    template<class... TArgs>
    static void write(const std::string& name, TArgs... args) {
        std::any anys[] { std::forward<TArgs>(args)... };

        auto& log = mLoggersByNames[name];

        auto message = log.layout->build(anys);

        for (auto& handler : log.handlers) {
            handler->write(message);
        }
    }

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    void setMessageLayout(std::shared_ptr<AbstractMessageLayout> layout) {
        mMessageLayout = layout;
    }

protected:
    /**************************************************************************
     * Members
     *************************************************************************/

    std::shared_ptr<AbstractMessageLayout> mMessageLayout;
    std::vector<std::shared_ptr<AbstractLoggerHandler>> mHandlers;

    static std::map<std::string, Log> mLoggersByNames;

}; // class Logger

} // namespace UT

#endif // HLK_LOGGER_H