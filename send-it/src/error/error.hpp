#pragma once

namespace error {
    namespace files {
        enum error {
            FILE_NOT_OPEN,
            FILE_NOT_FOUND
        };
    }

    namespace args {
        enum error {
            WITHOUT_FILE_TO_SEND,
            WITHOUT_OPTION_TO_CONTINUE
        };
    }
}