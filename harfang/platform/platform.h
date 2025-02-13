// HARFANG(R) Copyright (C) 2021 Emmanuel Julien, NWNC HARFANG. Released under GPL/LGPL/Commercial Licence, see licence.txt for details.

#pragma once

#include <string>

namespace hg {

/// Return the platform locale.
std::string GetPlatformLocale();

/// Open a file dialog
bool OpenFolderDialog(const std::string &title, std::string &output, const std::string &initial_dir = {});
/// Open a file dialog
bool OpenFileDialog(const std::string &title, const std::string &filter, std::string &output, const std::string &initial_dir = {});
/// Open a save file dialog
bool SaveFileDialog(const std::string &title, const std::string &filter, std::string &output, const std::string &initial_dir = {});

/// Platform specific initialization.
bool InitPlatform();

/// Drop to the debugger, throws an exception otherwise.
void DebugBreak();

} // namespace hg
