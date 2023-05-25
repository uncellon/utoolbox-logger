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

#include "defaultmessagelayout.h"

#include <ctime>

namespace UT {

std::string DefaultMessageLayout::build(const std::any params[]) {
    std::string prefix, message;

    if (params[0].type() == typeid(std::string)) {
        prefix = std::any_cast<std::string>(params[0]);
    } else if (params[0].type() == typeid(const char*)) {
        prefix = std::any_cast<const char*>(params[0]);
    }

    if (params[1].type() == typeid(std::string)) {
        message = std::any_cast<std::string>(params[1]);
    } else if (params[1].type() == typeid(const char*)) {
        message = std::any_cast<const char*>(params[1]);
    }

    std::string currentDate = formatCurrentDate(), currentTime = formatCurrentTime();
    return currentDate + " " + currentTime + " [" + prefix + "] - " + message;
}

/******************************************************************************
 * Methods (Protected)
 *****************************************************************************/

std::string DefaultMessageLayout::formatCurrentTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char hour[3], min[3], sec[3]; // Two digits and null-terminator
    sprintf(hour, "%02d", ltm->tm_hour);
    sprintf(min, "%02d", ltm->tm_min);
    sprintf(sec, "%02d", ltm->tm_sec);
    return std::string(hour) + ":" + min + ":" + sec;
}

std::string DefaultMessageLayout::formatCurrentDate() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    char day[3], month[3]; // Two digits and null-terminator
    sprintf(day, "%02hhu", ltm->tm_mday);
    sprintf(month, "%02hhu", ltm->tm_mon + 1);
    return std::to_string(1900 + ltm->tm_year) + "-" + month + "-" + day;
}

} // namespace UT
