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

#ifndef UT_DEFAULT_MESSAGE_LAYOUT
#define UT_DEFAULT_MESSAGE_LAYOUT

#include "abstractmessagelayout.h"

namespace UT {

class DefaultMessageLayout : public AbstractMessageLayout {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual std::string build(const std::any params[]) override;

protected:
    /**************************************************************************
     * Methods (Protected)
     *************************************************************************/

    std::string formatCurrentTime();
    std::string formatCurrentDate();

}; // class DefaultMessageLayout

} // namespace UT

#endif // UT_DEFAULT_MESSAGE_LAYOUT