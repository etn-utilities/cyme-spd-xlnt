// Copyright (c) 2014-2021 Thomas Fussell
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

#include <helpers/test_suite.hpp>
#include <iostream>

#include <xlnt/workbook/workbook.hpp>
#include <xlnt/worksheet/column_properties.hpp>
#include <xlnt/worksheet/row_properties.hpp>
#include <xlnt/worksheet/worksheet.hpp>

void print_summary(const test_status &results)
{
    std::cout << "\n\n";

    std::cout << "Run: " << results.tests_run << '\n';
    std::cout << "Passed: " << results.tests_passed << '\n';
    std::cout << "Failed: " << results.tests_failed << '\n'
              << '\n';

    for (auto failure : results.failures)
    {
        std::cout << failure << "\n\n";
    }
}

int main()
{
    // test_status overall_status = test_suite::go();

    // print_summary(overall_status);

    // return static_cast<int>(overall_status.tests_failed);

    xlnt::workbook wb;
    auto sheet = wb.active_sheet();

    wb.add_image("C:\\Users\\e0627741\\Pictures\\test.jpg", "test.jpg");

    sheet.row_properties(2).height = 250;
    sheet.row_properties(2).custom_height = true;

    sheet.column_properties(2).width = 250;
    sheet.column_properties(2).custom_width = true;

    sheet.column_properties(4).width = 72;
    sheet.column_properties(4).custom_width = true;

    sheet.add_drawing("Img1", xlnt::path{"test.jpg"}, xlnt::range_reference("B2:B2"), 1920, 871);

    wb.save(xlnt::path{"C:\\Users\\e0627741\\Downloads\\XLNTTT\\aaxlnttest.xlsx"});
}
