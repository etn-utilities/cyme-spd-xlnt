// Copyright (c) 2022
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE
//
// @license: http://www.opensource.org/licenses/mit-license.php
// @author: see AUTHORS file

#pragma once

#include <string>
#include <vector>

#include <xlnt/xlnt_config.hpp>
#include <xlnt/packaging/relationship.hpp>
#include <xlnt/utils/optional.hpp>

namespace xml {
class parser;
class serializer;
} // namespace xml

namespace xlnt {

class worksheet;

namespace drawing {

struct XLNT_API position
{
    int col;
    int colOff; // In EMUs (1 cm = 360000 EMUs)
    int row;
    int rowOff; // In EMUs (1 cm = 360000 EMUs)
};

enum class alignment {
    left,
    right,
    center
};

/// <summary>
/// The drawing class encapsulates the information
/// captured for a single object within the spreadsheetDrawing schema.
/// </summary>
class XLNT_API drawing
{
public:
    void from(position pos)
    {
        from_ = std::move(pos);
    }
    position from() const
    {
        return from_;
    }

    void to(position pos)
    {
        to_ = std::move(pos);
    }
    position to() const
    {
        return to_;
    }

    void name(std::string str)
    {
        name_ = std::move(str);
    }
    const std::string &name() const
    {
        return name_;
    }

    void id(std::string str)
    {
        id_ = std::move(str);
    }
    const std::string &id() const
    {
        return id_;
    }

    void relationship(xlnt::relationship rel)
    {
        relationship_ = std::move(rel);
    }
    const xlnt::relationship &relationship() const
    {
        return relationship_;
    }

private:
    position from_;
    position to_;
    std::string name_;
    std::string id_;
    xlnt::relationship relationship_;
};

} // namespace drawing
} // namespace xlnt
