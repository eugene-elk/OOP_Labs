#include "exceptions.h"
#include <string>

exc_io::exc_io() : exception("file not found")
{ };

exc_not_inited::exc_not_inited() : exception("file not inited") 
{ };

exc_no_section::exc_no_section() : exception("section not found") 
{ };

exc_no_param::exc_no_param() : exception("param not found")
{ };

exc_unknown_type::exc_unknown_type() : exception("unknown type")
{ };

exc_type_conversion::exc_type_conversion() : exception("type conversion error")
{ };