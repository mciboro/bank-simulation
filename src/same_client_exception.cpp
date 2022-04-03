#include "same_client_exception.h"

SameClientException::SameClientException() : invalid_argument("You can't do transfer to yourself\n\n") {}