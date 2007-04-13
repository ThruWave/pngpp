/**
 * Copyright (C) 2007   Alex Shulgin
 *
 * This file is part of png++ the C++ wrapper for libpng.  Png++ is free
 * software; the exact copying conditions are as follows:
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * 3. The name of the author may not be used to endorse or promote products
 * derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
#ifndef PNGPP_INFO_BASE_HPP_INCLUDED
#define PNGPP_INFO_BASE_HPP_INCLUDED

#include <cassert>
#include "error.hpp"
#include "types.hpp"

namespace png
{

    class info_base
    {
        info_base(info_base const&);
        info_base& operator=(info_base const&);

    public:
        explicit info_base(png_struct* png)
            : m_png(png),
              m_info(png_create_info_struct(png))
        {
        }

        ~info_base(void)
        {
            if (m_png && m_info)
            {
                destroy();
            }
        }

        void destroy(void)
        {
            assert(m_png);
            assert(m_info);
            png_destroy_info_struct(m_png, & m_info);
#ifndef NDEBUG
            m_png = 0;
#endif
        }

        png_info* get_png_struct(void) const
        {
            return m_info;
        }

    protected:
        png_struct* m_png;
        png_info* m_info;
    };

} // namespace png

#endif // PNGPP_INFO_BASE_HPP_INCLUDED
