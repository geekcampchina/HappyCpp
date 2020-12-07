﻿// Copyright (c) 2016, Fifi Lyu. All rights reserved.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to
// deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.

#include "happycpp/log.h"
#include <log4cplus/configurator.h>
#include <log4cplus/helpers/loglog.h>
#include <log4cplus/helpers/fileinfo.h>
#include <log4cplus/initializer.h>

using namespace std;
using namespace log4cplus;
using namespace log4cplus::helpers;

namespace happycpp {
    namespace log {
        HappyLogPtr HappyLog::_instance = nullptr;

        HappyLog::HappyLog() {
            _logger = Logger::getRoot();
        }

        HappyLog::HappyLog(const string &profile) {
            PropertyConfigurator::doConfigure(LOG4CPLUS_TEXT(profile));
            _logger = Logger::getRoot();
        }

        HappyLogPtr HappyLog::getInstance() {
            if (_instance == nullptr) {
                shared_ptr<HappyLog> tmpInstance(new HappyLog());

                _instance = tmpInstance;
            }

            return _instance;
        }

        HappyLogPtr HappyLog::getInstance(const string &profile) {
            if (_instance == nullptr) {
                shared_ptr<HappyLog> tmpInstance(new HappyLog(profile));

                _instance = tmpInstance;
            }

            return _instance;
        }

        HappyLogPtr HappyLog::getInstance(const boost::filesystem::path &profile) {
            return getInstance(profile.string());
        }

        void HappyLog::enterFunc(const std::string &funcName) {
            LOG4CPLUS_TRACE(_logger, LOG4CPLUS_TEXT("Enter function: ") << funcName);
        }

        void HappyLog::exitFunc(const std::string &funcName) {
            LOG4CPLUS_TRACE(_logger, LOG4CPLUS_TEXT("Exit function: ") << funcName);
        }

        void HappyLog::error(const string &s) {
            LOG4CPLUS_ERROR(_logger, LOG4CPLUS_TEXT(s));
        }

        void HappyLog::warn(const string &s) {
            LOG4CPLUS_WARN(_logger, LOG4CPLUS_TEXT(s));
        }

        void HappyLog::info(const string &s) {
            LOG4CPLUS_INFO(_logger, LOG4CPLUS_TEXT(s));
        }

        void HappyLog::debug(const string &s) {
            LOG4CPLUS_DEBUG(_logger, LOG4CPLUS_TEXT(s));
        }

        void HappyLog::trace(const string &s) {
            LOG4CPLUS_TRACE(_logger, LOG4CPLUS_TEXT(s));
        }
    } /* namespace log */
} /* namespace happycpp */
