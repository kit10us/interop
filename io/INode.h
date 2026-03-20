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

#if !defined(IO_INODE_H)
#define IO_INODE_H


#include <rm/IResource.h>
#include <list>
#include <memory>

namespace io
{
	class INode
	{
	protected:
	public:
		using ptr = std::shared_ptr<const INode>;
		using weak_ptr = std::weak_ptr<const INode>;
		using list = std::list<ptr>;

		virtual bool IsMatch(std::string filter) const = 0;

		virtual std::string Text() const = 0;
		virtual std::string Value() const = 0;

		template<typename T>
		T Value() const { return {}; };

		virtual list Children(std::string filter = {}) const = 0;
		virtual list Attributes(std::string filter = {}) const = 0;
	};
}


#endif