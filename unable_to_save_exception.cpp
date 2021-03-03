#include "unable_to_save_exception.h"

UnableToSaveException::UnableToSaveException() : std::ios_base::failure("Unable to save to the file\n") {}