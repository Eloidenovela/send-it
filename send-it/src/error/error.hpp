#pragma once

namespace error {
    namespace files {
        enum error {
            FILE_NOT_OPEN = (-1),
            FILE_NOT_FOUND = (-2)
        };
    }

    namespace args {
        enum error {
            WITHOUT_FILE_TO_SEND = (-1),
            WITHOUT_OPTION_TO_CONTINUE = (-2)
        };
    }
}