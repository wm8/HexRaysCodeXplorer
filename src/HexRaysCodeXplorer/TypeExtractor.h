/*	Copyright (c) 2013-2015
	REhints <info@rehints.com>
	All rights reserved.
	
	==============================================================================
	
	This file is part of HexRaysCodeXplorer

 	HexRaysCodeXplorer is free software: you can redistribute it and/or modify it
 	under the terms of the GNU General Public License as published by
 	the Free Software Foundation, either version 3 of the License, or
 	(at your option) any later version.

 	This program is distributed in the hope that it will be useful, but
 	WITHOUT ANY WARRANTY; without even the implied warranty of
 	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 	General Public License for more details.

 	You should have received a copy of the GNU General Public License
 	along with this program.  If not, see <http://www.gnu.org/licenses/>.

	==============================================================================
*/

#ifndef __H_TYPEEXTRACTOR__
#define __H_TYPEEXTRACTOR__

#pragma once

#include "ObjectExplorer.h"

struct vfunc_struct
{
	ea_t addr;
	qstring name;
	vfunc_struct(ea_t _addr, qstring _name)
	{
		addr = _addr;
		name = _name;
	}
};
struct vtable_struct
{
	ea_t addr;
	qstring name;
	qvector<vfunc_struct*> functions;
};

bool idaapi extract_all_types(void *ud);
bool idaapi extract_all_types_my(void* ud, qvector<vtable_struct*>& tables);
bool idaapi find_var(void *ud);
bool idaapi find_var(cfuncptr_t cfunc, const qstring& vtbl_name, qstring &var_name);
tid_t idaapi merge_types(const qvector<qstring>& types_to_merge, const qstring& type_name);

#endif