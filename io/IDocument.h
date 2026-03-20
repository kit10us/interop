/*
 * Interop Library
 * https://github.com/kit10us/interop
 * Copyright (c) 2002, Kit10 Studios LLC
 *
 * This file is part of Unify Library (a.k.a. IO)
 *
 * IO is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * IO is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with IO.  If not, see <https://www.gnu.org/licenses/>.
 */

#if !defined(IO_IDOCUMENT_H)
#define IO_IDOCUMENT_H


#include <rm/IResource.h>
#include <io/INode.h>
#include <memory>
#include <filesystem>

namespace io
{
	class IDocument : public rm::IResource
	{
	public:
		using ptr = std::shared_ptr<IDocument>;

		virtual INode::ptr Root() const = 0;
	};
}


#endif