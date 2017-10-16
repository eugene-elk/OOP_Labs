#include "exceptions.h"
#include <string>

exc_empty_multiset::exc_empty_multiset() : exception("multiset is empty")
{ };

exc_io::exc_io() : exception("file not found")
{ };