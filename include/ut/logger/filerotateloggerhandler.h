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

#ifndef UT_FILE_ROTATE_LOGGER_HANDLER_H
#define UT_FILE_ROTATE_LOGGER_HANDLER_H

#include "fileloggerhandler.h"

#include <filesystem>
#include <fstream>

namespace UT {

class FileRotateLoggerHandler : public FileLoggerHandler {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual void write(const std::string& message) override {
        std::ofstream fout(mLogPath, std::ios_base::app);

        // Rotate log file
        if (message.size() + fout.tellp() > mMaxLogBytes) {
            fout.close();
            
            std::filesystem::remove(mLogPath + "." + std::to_string(mMaxLogs - 1));
            if (mMaxLogs == 1) {
                std::filesystem::remove(mLogPath);
                return;
            }
            for (int i = mMaxLogs - 1; i > 0; --i) {
                if (!std::filesystem::exists(mLogPath + "." + std::to_string(i))) {
                    continue;
                }        
                std::filesystem::rename(mLogPath + "." + std::to_string(i),
                                        mLogPath + "." + std::to_string(i + 1));
            }
            std::filesystem::rename(mLogPath, mLogPath + "." + std::to_string(1));

            fout.open(mLogPath, std::ios_base::app);
        }
        
        fout << message << std::endl;
        fout.close();
    }

    /**************************************************************************
     * Accessors / Mutators
     *************************************************************************/

    unsigned int getMaxLogBytes() const;
    void setMaxLogBytes(unsigned int bytes);

    unsigned int getMaxLogs() const;
    void setMaxLogs(unsigned int limit);

protected:
    /**************************************************************************
     * Members
     *************************************************************************/

    unsigned int mMaxLogBytes = 0;
    unsigned int mMaxLogs = 0;

}; // class FileRotateLoggerHandler

/******************************************************************************
 * Inline definition: Accessors / Mutators
 *****************************************************************************/

inline unsigned int FileRotateLoggerHandler::getMaxLogBytes() const { return mMaxLogBytes; }
inline void FileRotateLoggerHandler::setMaxLogBytes(unsigned int bytes) { mMaxLogBytes = bytes; }

inline unsigned int FileRotateLoggerHandler::getMaxLogs() const { return mMaxLogs; }
inline void FileRotateLoggerHandler::setMaxLogs(unsigned int limit) { mMaxLogs = limit; }

} // namespace UT

#endif // UT_FILE_ROTATE_LOGGER_HANDLER_H