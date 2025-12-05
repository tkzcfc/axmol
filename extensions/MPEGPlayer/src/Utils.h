#pragma once

#include "axmol.h"

struct plm_t;

namespace mpeg
{

std::tuple<plm_t*, ax::IFileStream*> new_plm_from_file(const std::string& filename);

}  // namespace mpeg
