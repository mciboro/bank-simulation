#include "debt_exception.h"

DebtException::DebtException() : std::out_of_range("Operation cannot be done, because sender doesn't have enough funds\n\n") {};